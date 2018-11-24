#ifndef MESH_H
#define MESH_H

#include <vector>
#include "triangle.h"

/**
 * @brief 三角网格类
 * @note 拥有一系列三角形对象，同时自己也是Object3D对象
 */
class Mesh : public Object3D
{
public:
    Mesh();

    /**
     * @brief add
     * @param tr
     */
    void add(const Triangle& tr){
        m_data.push_back(tr);
    }

    /**
     * @brief isContain
     * @param x
     * @param y
     * @return
     */
    bool isContain(double x, double y);

    /**
     * @brief 旋转
     * @param xAngle 旋转角度
     * @param yAngle
     * @param zAngle
     */
    void rotate(double xAngle, double yAngle, double zAngle);

    /**
     * @brief 投影
     * @param eye 观测位置
     * @param 投影面 坐标
     */
//    void project(const Vec3& eye, double d);

    /**
     * @brief 获取颜色
     * @param x 像素坐标
     * @param y
     * @param eye 摄像机位置
     * @param d 投影平面坐标
     * @return
     */
    Color sample(double x, double y, const Vec3 &eye, double d);

    /**
     * @brief 方便函数，生成一个立方体
     */
    void makeCube();
    /**
     * @brief clear
     */
    void clear();


private:
    std::vector<Triangle> m_data; /**< 三角形集合数据*/

    std::vector<Triangle> m_buffer; /**< 缓存*/

};

#endif // MESH_H
