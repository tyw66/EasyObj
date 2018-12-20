#include "sample.h"
#include "transform.h"

Color sample(double x, double y, Scene *scene)
{
    //! 当前像素坐标变换
    double xPos, yPos;
    Util::scalePointXY(x,y,xPos,yPos,200,200);
    Util::movePointXY(xPos, yPos, xPos, yPos, 100, 100);


    ///遮挡检测
    return scene->m_mesh.sample(xPos, yPos);


}

