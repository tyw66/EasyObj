#include "scene.h"
#include "transform.h"
#include<QDebug>

Scene::Scene()
{
}

void Scene::update(double x, double y)
{
    qDebug() << y;
    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    Util::scalePointXY(x,y,xMouse,yMouse,180,180);
    Util::movePointXY(xMouse, yMouse, xMouse, yMouse, 90, 90);

    qDebug()<< yMouse;

    ///旋转
    m_mesh.rotate(-yMouse,0,0);


    ///投影变换
    double d = 80;//投影面 坐标
    Vec3 eye(0,50,100);
    m_mesh.project(eye,d);
}
