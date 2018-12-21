#include "triangle.h"

Triangle::Triangle(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3, const Color &c)
{
    va = v1; vb = v2; vc = v3;
    xPos = (v1.x+v2.x+v3.y)/3;
    yPos = (v1.y+v2.y+v3.y)/3;
    color_fill = c;
}

bool Triangle::isContain(double x, double y)
{
    //叉乘判断法
    Vec3 p(x,y,0);
    Vec3 pa = va - p;
    Vec3 pb = vb - p;
    Vec3 pc = vc - p;

    pa.z=0;
    pb.z=0;
    pc.z=0;

    Vec3 t1 = crossProduct(pa, pb);
    Vec3 t2 = crossProduct(pb, pc);
    Vec3 t3 = crossProduct(pc, pa);

    //如果t1 t2 t3同向，则点在三角形内
    double f1 = t1 * t2;
    double f2 = t1 * t3;

    return f1>0 && f2 >0;
}

Triangle Triangle::projectTo2D(Vec3 eye, double d)
{
    Vec3 vva, vvb, vvc;//va在眼坐标下的坐标
    vva = -eye + va;
    vvb = -eye + vb;
    vvc = -eye + vc;

    double z_ind =  fabs((vva.z + vvb.z + vvc.z)/3 - d);

    Vec3 pva, pvb, pvc;

    double f = d / vva.z;
    pva.x = vva.x * f;
    pva.y = vva.y * f;
    pva.z = d;

    f = d / vvb.z;
    pvb.x = vvb.x * f;
    pvb.y = vvb.y * f;
    pvb.z = d;

    f = d / vvc.z;
    pvc.x = vvc.x * f;
    pvc.y = vvc.y * f;
    pvc.z = d;



    Triangle projTr(pva, pvb, pvc, color_fill);
    projTr.z_index = z_ind;
    return projTr;
}

void Triangle::rotate(double xRad, double yRad, double zRad)
{
    va.rotateXAxis(xRad);
    va.rotateYAxis(yRad);
    va.rotateZAxis(zRad);

    vb.rotateXAxis(xRad);
    vb.rotateYAxis(yRad);
    vb.rotateZAxis(zRad);

    vc.rotateXAxis(xRad);
    vc.rotateYAxis(yRad);
    vc.rotateZAxis(zRad);
}
