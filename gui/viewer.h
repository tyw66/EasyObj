#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTime>
#include <QMouseEvent>
#include <QPainter>

#include "case.h"
#include "scene.h"



/**
 * @brief 基于Qt的图形显示控件
 */
class Viewer : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent
     */
    explicit Viewer(QWidget *parent = 0);

    /**
     * @brief 渲染图像
     * @param x 鼠标位置X
     * @param y 鼠标位置y
     */
    void renderImg(int x = 0, int y = 0);

protected:
    /**
     * @brief 处理鼠标移动事件
     * @param ev
     */
    void mouseMoveEvent(QMouseEvent* ev);
    /**
     * @brief 处理重绘事件
     * @param ev
     */
    void paintEvent(QPaintEvent* ev );
    /**
     * @brief dragEnterEvent
     * @param ev
     */
    void dragEnterEvent(QDragEnterEvent* ev);
    /**
     * @brief dropEvent
     * @param ev
     */
    void dropEvent(QDropEvent* ev);

private:
    const int W = 256;      /**< 图像宽度*/
    const int H = 256;      /**< 图像高度*/
    QImage* m_image;    /**< 图像数据*/

    static unsigned int m_time;         /**< 时间变量，动画用*/
    int mouse_posX, mouse_posY;     /**< 鼠标位置*/


    QTime  temp_timer;          //测试用


    Scene *m_scene;

};

#endif // GRAPHICWIDGET_H
