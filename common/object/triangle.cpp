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

    z_index =  fabs((vva.z + vvb.z + vvc.z)/3 - d);

    Vec3 pva, pvb, pvc;

    pva.x = vva.x * d / vva.z;
    pva.y = vva.y * d / vva.z;
    pva.z = d;

    pvb.x = vvb.x * d / vvb.z;
    pvb.y = vvb.y * d / vvb.z;
    pvb.z = d;

    pvc.x = vvc.x * d / vvc.z;
    pvc.y = vvc.y * d / vvc.z;
    pvc.z = d;

    return  Triangle(pva, pvb, pvc, color_fill);
}

void Triangle::rotate(double xAngle, double yAngle, double zAngle)
{
    va.rotateXAxis(xAngle);
    va.rotateYAxis(yAngle);
    va.rotateZAxis(zAngle);

    vb.rotateXAxis(xAngle);
    vb.rotateYAxis(yAngle);
    vb.rotateZAxis(zAngle);

    vc.rotateXAxis(xAngle);
    vc.rotateYAxis(yAngle);
    vc.rotateZAxis(zAngle);
}
