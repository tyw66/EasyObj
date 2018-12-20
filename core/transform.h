#ifndef UTIL_H
#define UTIL_H

#include "vec.h"
#include <math.h>

namespace Util {

/**
 * @brief 平移坐标点
 * @param x0
 * @param y0
 * @param x1
 * @param y1
 * @param xDist
 * @param yDist
 */
void movePointXY(double x0, double y0, double &x1, double &y1,double xDist, double yDist){
    x1 = x0 - xDist;
    y1 = y0 - yDist;
}

/**
 * @brief 当前像素点映射到坐标轴上,xy直角坐标系
 * @param x0 变换前X : 0-1
 * @param y0
 * @param x1 变换后X
 * @param y1
 */
void scalePointXY(double x0, double y0, double &x1, double &y1,double xFactor, double yFactor){
    x1 = x0 * xFactor;
    y1 = y0 * yFactor;
}
/**
 * @brief 旋转坐标点
 * @param x0
 * @param y0
 * @param x1
 * @param y1
 * @param angle 旋转角度
 */
void rotatePointXY(double x0, double y0, double& x1, double& y1, double angle, double rxCenter, double ryCenter){

    double a = PI * angle / 180;
    //    x1 = (x0 - rxCenter) *cos(a) + (y0 - ryCenter) *sin(a);
    //    y1 = -(x0 - rxCenter) *sin(a) + (y0 - ryCenter) * cos(a);

    movePointXY(x0,y0,x1,y1,rxCenter,ryCenter);
    x1 = x0 *cos(a) + y0 *sin(a);
    y1 = -x0 *sin(a) + y0 * cos(a);
    movePointXY(x1,y1,x1,y1,-rxCenter,-ryCenter);

}

/**
 * @brief 当前像素点映射到坐标轴上，极坐标系
 * Detail. 定义坐标系
 * @param x0 变换前X: 0-1
 * @param y0
 * @param r 变换后
 * @param theta
 * @return
 */
void transPointRTheta(double x, double y, double& r, double& theta){
    //    double x1,y1;
    //    scalePointXY(x,y,x1,y1);

    //    theta = atan(y1/x1);
    //    double r_ = sqrt(x1*x1+y1*y1);
    //    r = r_*200.0;//映射
}

//void rotatePointXYZ(Vec3 x0,Vec3 y0,Vec3 z0,Vec3& x1,Vec3& y1,Vec3& z1, double angle);

}
#endif // UTIL_H
