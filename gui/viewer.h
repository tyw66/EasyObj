#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTime>
#include <QMouseEvent>
#include <QPainter>

#include "../core/sample.h"
#include "../core/scene.h"



/**
 * @brief 基于Qt的图形显示控件
 */
class Viewer : public QWidget
{
    Q_OBJECT

    /**
     * @brief 交互模式
     */
    enum INTER_STATUS{
        FREE = 0,
        ROTATE = 1,
        PAN = 2
    };

public:
    /**
     * @brief 构造函数
     * @param parent
     */
    explicit Viewer(QWidget *parent = 0);

    /**
     * @brief 渲染图像
     * @param x 鼠标位置X
     * @param y 鼠标位置y
     * @param x0 鼠标上一位置X
     * @param y0 鼠标上一位置y
     * @param whl_del 滚轮位置变动
     */
    void renderImg(int x, int y, int x0, int y0, double whl_del);

protected:
    /**
     * @brief 处理重绘事件
     * @param ev
     */
    void paintEvent(QPaintEvent* ev );
    /**
     * @brief 处理拖拽事件
     * @param ev
     */
    void dragEnterEvent(QDragEnterEvent* ev);
    /**
     * @brief 处理放下事件
     * @param ev
     */
    void dropEvent(QDropEvent* ev);
    /**
     * @brief 处理鼠标移动事件
     * @param ev
     */
    void mouseMoveEvent(QMouseEvent* ev);
    /**
     * @brief 处理鼠标按下事件
     * @param ev
     */
    void mousePressEvent(QMouseEvent* ev);
    /**
     * @brief 处理鼠标释放事件
     * @param ev
     */
    void mouseReleaseEvent(QMouseEvent* ev);
    /**
     * @brief 处理鼠标滚轮事件
     * @param ev
     */
    void wheelEvent(QWheelEvent* ev);

private:
    const int W = 256;      /**< 图像宽度*/
    const int H = 256;      /**< 图像高度*/
    QImage* m_image;        /**< 图像数据*/
    Scene *m_scene;         /**< 场景数据 */

    INTER_STATUS m_status;          /**< 交互模式 */
    int mouse_curX, mouse_curY;     /**< 鼠标当前位置*/
    int mouse_posX, mouse_posY;     /**< 鼠标上一位置*/
    double wheel_delta;

    QTime  fps_timer;                   /**< 测试用 */
    static unsigned int m_time;         /**< 时间变量，动画用*/



};

#endif // GRAPHICWIDGET_H
