#ifndef CASE_H
#define CASE_H

#include "color.h"
#include "scene.h"

/**
 * @brief 取样
 * @param x 当前绘制的像素归一化位置
 * @param y
 * @param scene 场景
 * @return 该像素的颜色
 */

Color sample(double x, double y, Scene *scene);



#endif
