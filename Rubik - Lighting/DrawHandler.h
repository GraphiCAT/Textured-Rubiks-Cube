#ifndef DrawHandler_H
#define DrawHandler_H
#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

typedef GLfloat point2[2];

/* Initialize OpenGL Graphics */
void initGL();
void init();
void displayCube();
void displayCube5();
void triangle( point2 a, point2 b, point2 c);
void triangle_point( point2 a, point2 b, point2 c);
void divide_triangle(point2 a, point2 b, point2 c,int m, int type);
void displaySierpinskiTriangle(int n, int type);
void display_1(void);
void display_2(void);
void display_3(void);
void reshape_1(GLsizei width, GLsizei height);
void reshape_2 (int w, int h);
void reshape_3 (int w, int h);
void setIteration(int itr);
void keyPressed(unsigned char key, int x, int y);
void keyPressed5(unsigned char key, int x, int y);
void mouse(int btn, int state, int x, int y);
void toggleDirection();

void printLogo();
void printMenu();
void printGoodbye();

void timer(int value);


#endif // DrawHandler_H
