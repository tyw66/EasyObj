#include "scene.h"

void movePointXY(double x0, double y0, double &x1, double &y1,double xDist, double yDist){
    x1 = x0 - xDist;
    y1 = y0 - yDist;
}

void scalePointXY(double x0, double y0, double &x1, double &y1,double xFactor, double yFactor){
    x1 = x0 * xFactor;
    y1 = y0 * yFactor;
}

Scene::Scene()
{

}

void Scene::update(double x, double y)
{
    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    scalePointXY(x,y,xMouse,yMouse,180,180);
    movePointXY(xMouse, yMouse, xMouse, yMouse, 90, 90);


    ///旋转
    m_mesh.rotate(-yMouse,-xMouse,0);


    ///投影变换
    double d = 80;//投影面 坐标
    Vec3 eye(0,50,100);
    m_mesh.project(eye,d);
}
