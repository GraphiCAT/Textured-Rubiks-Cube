/*
 * main.cpp: 3D Shapes
 */
#include <cstdlib>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "DrawHandler.h"
#include "Cell.h"
#include <iostream>

/* Global variables */
char title[] = "Rubix";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
int window_1, window_2;

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   char choice = -1;
   glutInit(&argc, argv);

   while (choice != '0') {
       system("CLS");
       printLogo();
       printMenu();
       std::cout << std::endl;
       std::cout << "Input: ";
       std::cin >> choice;

       glutInitWindowSize(800, 600);
       glutInitWindowPosition(50, 50);
       window_1 = glutCreateWindow (argv[0]);
       glutSetWindowTitle(title);

       Cell::initTexture();

       if (choice == '1') { // cube
           glutDisplayFunc(display_1);
           glutReshapeFunc(reshape_1);
           glutKeyboardFunc(keyPressed);
           glutMouseFunc(mouse);
           initGL();
           glutMainLoop();
       } else if (choice == '2') { // cube
           glutDisplayFunc(display_2);
           glutReshapeFunc(reshape_1);
           glutKeyboardFunc(keyPressed5);
           glutMouseFunc(mouse);
           initGL();
           glutMainLoop();
       }
   }
   printGoodbye();
   return 0;
}
