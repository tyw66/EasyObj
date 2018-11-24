#ifndef CASE_H
#define CASE_H

#include <math.h>
#include "color.h"
#include "scene.h"

/**
 * @brief 参数图形。位置随鼠标移动,半径随时间变化
 * @param x 当前绘制的像素归一化位置
 * @param y
 * @param mx 鼠标归一化位置
 * @param my
 * @param time 时间，动画用
 * @return 该像素的颜色
 */
Color case000(double x, double y, double mx, double my, int time = 0);

/**
 * @brief 三维cube
 */
Color case001(double x, double y, double mx, double my, int time = 0);

/**
 * @brief OBJ
 */
Color case066(double x, double y, double mx, double my, Scene* scene);

#endif
