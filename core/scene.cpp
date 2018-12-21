#include "scene.h"
#include "transform.h"
#include<QDebug>

Scene::Scene()
{
    m_projD = 90;
}

void Scene::update(double x, double y, double x0, double y0, double whl_delta)
{
    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    double xMouse0, yMouse0;
    Util::scalePointXY(x,y,xMouse,yMouse,2*PI,2*PI);
    Util::scalePointXY(x0,y0,xMouse0,yMouse0,2*PI,2*PI);


    ///旋转
    m_mesh.rotate(-(yMouse - yMouse0),(xMouse - xMouse0),0);


    ///投影变换
    m_projD += whl_delta;
    if(m_projD < 0) m_projD = 0; //注释掉这一句会有神奇效果

    Vec3 eye(0,0,80);
    m_mesh.project(eye,m_projD);
}
