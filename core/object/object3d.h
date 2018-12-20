#ifndef OBJECT_H
#define OBJECT_H

#include <math.h>
#include "../color.h"
#include "../vec.h"

#define PI 3.1415926

/**
 * @brief 所有3D几何体的基类
 */
class Object3D
{
public:
    //! 图形位置
    double xPos, yPos,zPos;

    //! 漫射颜色
    Color color_fill;

    //! 构造函数
    Object3D(){}
    Object3D(double x, double y, double z):xPos(x),yPos(y),zPos(z){}
    Object3D(double x, double y, double z, Color color):xPos(x),yPos(y),zPos(z),color_fill(color){}

    //! 一个点是否在几何体内部
    virtual bool isContain(double x, double y) = 0;

    //! 一个点到该几何体的带符号距离场
    virtual double getSDF(double x, double y, double z){
        return sqrt(x * x + y * y + z * z);
    }

};

#endif // OBJECT_H
