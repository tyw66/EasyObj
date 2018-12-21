#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object3d.h"

class Triangle : public Object3D
{
public:
    Vec3 va, vb, vc; /**< 顶点坐标*/
    Vec3 na, nb, nc; /**< 法向量*/
    double z_index; /**< */

    /**
     * @brief 默认构造函数
     */
    Triangle(){}

    /**
     * @brief 构造函数
     * @param v1
     * @param v2
     * @param v3
     * @param z
     * @param c
     */
    Triangle(const Vec3& v1, const Vec3& v2, const Vec3& v3, const Color& c);

    /**
     * @brief isContain
     * @param x
     * @param y
     * @return
     */
    bool isContain(double x, double y);

    /**
     * @brief projectTo2D
     * @param eye
     * @param d
     * @return
     */
    Triangle projectTo2D(Vec3 eye, double d);

    /**
     * @brief rotate
     * @param xAngle
     * @param yAngle
     * @param zAngle
     */
    void rotate(double xRad, double yRad, double zRad);
};

#endif // TRIANGLE_H
