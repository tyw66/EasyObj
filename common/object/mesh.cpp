#include "mesh.h"

Mesh::Mesh()
{

}

bool Mesh::isContain(double x, double y)
{


}

void Mesh::rotate(double xAngle, double yAngle, double zAngle)
{
    for(int i = 0; i < m_data.size(); ++i){
        m_data[i].rotate(xAngle, yAngle, zAngle);
    }
}


Color Mesh::sample(double x, double y, const Vec3 &eye, double d)
{
    Color c;
    double index = 10e9;
    for(int i = 0; i < m_data.size(); ++i){
        Triangle projTr = m_data[i].projectTo2D(eye,d);
        if(projTr.isContain(x,y)){
            if(projTr.z_index < index){
                c = projTr.color_fill;
                index = projTr.z_index;
            }
        }
    }
    return c;

    /*
    //遍历三角形，记下哪些三角形包含这个像素点
    m_buffer.clear();
    for(int i = 0; i < m_data.size(); ++i){
        Triangle tr = m_data[i].projectTo2D(eye,d);
        if(tr.isContain(x,y)){
            m_buffer.push_back(tr);
        }
    }
    //计算这些三角形中谁离摄像机最近
    for(int i = 0; i < m_buffer.size(); ++i){

    }
    //返回这个三角形的颜色值

    */

}

void Mesh::makeCube()
{
    Vec3 vt1(-30, -30, 30);
    Vec3 vt2(30, -30, 30);
    Vec3 vt3(30, -30, -30);
    Vec3 vt4(-30, -30, -30);
    Vec3 vt5(-30, 30, 30);
    Vec3 vt6(30, 30, 30);
    Vec3 vt7(30, 30, -30);
    Vec3 vt8(-30, 30, -30);

    Triangle triangle1(vt1,vt2,vt3,Color(255,125,0));
    Triangle triangle2(vt1,vt3,vt4,Color(125,125,0));

    Triangle triangle3(vt2,vt3,vt6,Color(0,255,0));
    Triangle triangle4(vt3,vt6,vt7,Color(255,0,255));

    Triangle triangle5(vt1,vt2,vt5,Color(0,0,255));
    Triangle triangle6(vt2,vt5,vt6,Color(255,0,0));

    Triangle triangle7(vt5,vt6,vt7,Color(255,125,255));
    Triangle triangle8(vt5,vt7,vt8,Color(125,0,0));

    Triangle triangle9(vt3,vt4,vt8,Color(255,125,0));
    Triangle triangle10(vt3,vt7,vt8,Color(125,0,255));

    Triangle triangle11(vt1,vt4,vt8,Color(255,255,125));
    Triangle triangle12(vt1,vt5,vt8,Color(125,125,255));

    m_data.push_back(triangle1);
    m_data.push_back(triangle2);
    m_data.push_back(triangle3);
    m_data.push_back(triangle4);
    m_data.push_back(triangle5);
    m_data.push_back(triangle6);
    m_data.push_back(triangle7);
    m_data.push_back(triangle8);
    m_data.push_back(triangle9);
    m_data.push_back(triangle10);
    m_data.push_back(triangle11);
    m_data.push_back(triangle12);
}

void Mesh::clear()
{
    m_data.clear();
}
