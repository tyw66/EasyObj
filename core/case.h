#ifndef CASE_H
#define CASE_H

#include "color.h"
#include "scene.h"

/**
 * @brief 三维cube
 * @param x 当前绘制的像素归一化位置
 * @param y
 * @param scene 场景
 * @return 该像素的颜色
 */

Color caseCube(double x, double y, Scene *scene);

/**
 * @brief OBJ
 */
Color caseObj(double x, double y, double mx, double my, Scene* scene);

#endif
