#include <iostream>
#include <stdlib.h>

#include "case.h"

#include "scene.h"

#include "object/mesh.h"

#include "transform.h"


Color caseCube(double x, double y, Scene *scene)
{
    //! 当前像素坐标变换
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,200,200);
    Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);




    ///遮挡检测
    return scene->m_mesh.sample(xPos, yPos);


}

Color caseObj(double x, double y, double mx, double my, Scene *scene)
{
//    //! 背景色
//    Color c(64,64,64);

//    //! 当前像素坐标变换
//    double xPos, yPos;
//    Util::scalePointXY(x,y,xPos,yPos,200,200);
//    Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);

//    //! 鼠标位置坐标变换
//    double xMouse, yMouse;
//    Util::scalePointXY(mx,my,xMouse,yMouse,180,180);
//    Util::movePointXY(xMouse, yMouse, xMouse, yMouse, 90, 90);


//    ///旋转
//    scene->m_mesh.rotate(-yMouse,xMouse,0);


//    ///投影变换
//    double d = 100;//投影面 坐标
//    Vec3 eye(0,0,100);
//    return scene->m_mesh.sample(xPos, yPos);
}
