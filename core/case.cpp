#include <iostream>
#include <stdlib.h>

#include "case.h"

#include "scene.h"

#include "object/object2d.h"
#include "object/circle.h"
#include "object/mesh.h"

#include "math/transform.h"

Color case000(double x, double y, double mx, double my, int time)
{
    Color color(250, 211, 94);    //背景填充

    //当前像素点坐标转换
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,200,200);

    //圆心坐标转换
    double xCenter,yCenter;
    Util::scalePointXY(mx,my,xCenter,yCenter,200,200);

    //圆
    double r = 30 + 10*sin(time/2);//半径随时间变化
    Circle circle(xCenter, yCenter, 0, Color(255,0,0), r);
    if(circle.isContain(xPos, yPos)){
        return circle.color_fill;
    }

    return color;
}



Color case001(double x, double y, double mx, double my, int time)
{
    //! 背景色
    Color c(64,64,64);

    //! 当前像素坐标变换
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,200,200);
    Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);

    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    Util::scalePointXY(mx,my,xMouse,yMouse,180,180);
    Util::movePointXY(xMouse, yMouse, xMouse, yMouse, 90, 90);

    //! 画立方体
    Mesh mesh;
    mesh.makeCube();

    ///旋转
    mesh.rotate(-yMouse,xMouse,0);


    ///投影变换
    double d = 100;//投影面 坐标
    Vec3 eye(0,0,100);
    return mesh.sample(xPos, yPos,eye,d);


}

Color case066(double x, double y, double mx, double my, Scene *scene)
{
    //! 背景色
    Color c(64,64,64);

    //! 当前像素坐标变换
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,200,200);
    Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);

    //! 鼠标位置坐标变换
    double xMouse, yMouse;
    Util::scalePointXY(mx,my,xMouse,yMouse,180,180);
    Util::movePointXY(xMouse, yMouse, xMouse, yMouse, 90, 90);


    ///旋转
    scene->m_mesh.rotate(-yMouse,xMouse,0);


    ///投影变换
    double d = 100;//投影面 坐标
    Vec3 eye(0,0,100);
    return scene->m_mesh.sample(xPos, yPos,eye,d);
}
