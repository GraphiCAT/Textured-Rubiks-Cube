#ifndef Cube5_H
#define Cube5_H

#include "Point3D.h"
#include "Cell.h"
#include <vector>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

class Cube5
{
    public :
        Cube5();
        Cube5(const Cube5& c);
        ~Cube5();
        Cell* getSurface();
        void setSurface(Cell _surface[150]);
        void drawCube();
        void handleRotate(int face, int direction);
        void rotateAll(int axis, int direction);
        void swapColors(std::vector<int> array, int jump);


    private :
        void rotateSlice(GLfloat angle,std::vector<int> rotate, Point3D axis);
        std::vector<int> getRotationVector(int face);
        Point3D getRotationAxis(int face);
        void rotateByAxis(GLfloat angle, int axis);
        Cell surface[150];

};

#endif // Cube_H

