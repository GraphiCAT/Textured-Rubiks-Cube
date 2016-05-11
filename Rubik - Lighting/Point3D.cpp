#include "Point3D.h"

Point3D::Point3D(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

Point3D::Point3D(const Point3D& p){
    x = p.x;
    y = p.y;
    z = p.z;
}

Point3D::~Point3D(){}

bool Point3D::isEquals(Point3D p){
    return (x == p.getX())&&(y == p.getY())&&(z == p.getZ());
}
