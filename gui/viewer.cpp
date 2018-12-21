#include "viewer.h"
#include <QDebug>
#include <QMimeData>
#include "../core/parser/objfileparser.h"

unsigned int Viewer::m_time = 0;
Viewer::Viewer(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::WindowCloseButtonHint);
    //        setAttribute(Qt::WA_DeleteOnClose);
    setMinimumSize(W,H);
    setMaximumSize(W,H);
    setMouseTracking(true);
    setAcceptDrops(true);

    m_image = new QImage(W,H,QImage::Format_RGB32);
    m_scene = new Scene();

    m_scene->m_mesh.makeCube(); //程序加载时画立方体


    renderImg(W/2,H/2,W/2,H/2);

}

void Viewer::renderImg(int x, int y, int x0, int y0)
{
    temp_timer.restart();

    m_scene->update((double)x/W, (double)y/H ,(double)x0/W, (double)y0/H);

#pragma omp parallel for
    //遍历像素点
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            //获取颜色
            Color color = sample((double)j/W, (double)i/H, m_scene);
            //设置颜色
            m_image->setPixel(j,i,QColor::fromRgb((int)color.r, (int)color.g, (int)color.b).rgb());
        }
    }
    update();
    //    m_time++;

    //    qDebug()<< temp_timer.elapsed();
}

void Viewer::mouseMoveEvent(QMouseEvent *ev)
{
    mouse_curX = ev->x();
    mouse_curY = ev->y();

    renderImg(mouse_curX, mouse_curY,mouse_posX, mouse_posY);

    mouse_posX = mouse_curX;
    mouse_posY = mouse_curY;
}

void Viewer::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),*m_image);
}


void Viewer::dragEnterEvent(QDragEnterEvent *ev)
{
    //如果类型是obj才能接受拖动。否则不接受鼠标事件
    if(!ev->mimeData()->urls()[0].fileName().right(3).compare("obj")) //compare相等的时候返回0
        ev->acceptProposedAction();
    else
        ev->ignore();
}

void Viewer::dropEvent(QDropEvent *ev)
{
    QString path = ev->mimeData()->urls()[0].toLocalFile();//.toLocalFile()是获取拖动文件的本地路径。
    ObjFileParser::setFilePath(path.toStdString());
    ObjFileParser::parse(m_scene->m_mesh);
}

