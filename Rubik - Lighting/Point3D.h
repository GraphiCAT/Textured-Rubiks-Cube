#ifndef Point3D_H
#define Point3D_H

class Point3D
{
    public:
        Point3D(){};
        Point3D(float _x, float _y, float _z);
        Point3D(const Point3D& p);
        ~Point3D();

        float getX(){return x;};
        float getY(){return y;};
        float getZ(){return z;};

        // Setter
        void setX(float _x) {x = _x; };
        void setY(float _y) {y = _y; };
        void setZ(float _z) {z = _z; };

        bool isEquals(Point3D p);


    private:
        float x;
        float y;
        float z;

};
#endif // Point3D_H
