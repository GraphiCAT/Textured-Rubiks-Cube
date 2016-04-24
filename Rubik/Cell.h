#ifndef Cell_H
#define Cell_H

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "Point3D.h"
#include <vector>
#define RED 0
#define GREEN 1
#define WHITE 2
#define BLUE 3
#define ORANGE 4
#define YELLOW 5


class Cell
{
    public :
        Cell(){};
        Cell(int _color, Point3D _location, Point3D _normal, std::vector<GLuint> _texture);
        Cell(const Cell& c);
        ~Cell();
        int getColor();
        void setColor(int _color);
        Point3D getLocation();
        void setLocation(Point3D _location);
        Point3D getNormal();
        void setNormal(Point3D _normal);
        void drawCell();
        void setColor();
        void setTexture();
        int getFace();


    private :
        int color;
        Point3D location;
        Point3D normal;
        std::vector<GLuint> texture;
};

#endif // Cell_H
