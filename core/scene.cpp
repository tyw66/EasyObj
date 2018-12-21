#include "scene.h"
#include "transform.h"
#include<QDebug>

Scene::Scene()
{
}

void Scene::update(double x, double y, double x0, double y0)
{
    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    double xMouse0, yMouse0;
    Util::scalePointXY(x,y,xMouse,yMouse,2*PI,2*PI);
    Util::scalePointXY(x0,y0,xMouse0,yMouse0,2*PI,2*PI);


    ///旋转
    m_mesh.rotate(-(yMouse - yMouse0),(xMouse - xMouse0),0);


    ///投影变换
    double d = 90;//投影面 坐标
    Vec3 eye(0,0,100);
    m_mesh.project(eye,d);
}
