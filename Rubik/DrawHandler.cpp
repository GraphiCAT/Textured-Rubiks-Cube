#include "DrawHandler.h"
#include "Point3D.h"
#include "Cell.h"
#include "Cube.h"
#include "Cube5.h"

const int TRIANGLE = 0;
const int TRIANGLE_POINT = 1;
Cube rubiks;
Cube5 rubiks5;

#define CLOCKWISE 0
#define COUNTER_CLOCKWISE -1
#define TOP 1
#define BOTTOM 2
#define LEFT 3
#define RIGHT 4
#define BACK 5
#define FRONT 6
#define MIDDLEX 7
#define MIDDLEY 8
#define MIDDLEZ 9
#define ALLX 10
#define ALLY 11
#define ALLZ 12

#include <vector>
using namespace std;


int refreshMills = 15;        // refresh interval in milliseconds [NEW]
int iteration = 1;
float angle = 0.0f;
int direction = CLOCKWISE;

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glMatrixMode(GL_MODELVIEW);
   glTranslatef(0.0f, 0.0f, -20.0f);
   glRotatef(45.0f,1.0f,1.0f,0.0f);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}

void displayCube() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   rubiks.drawCube();
   glFlush();
}

void displayCube5() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
  rubiks5.drawCube();
  glFlush();
}

void keyPressed (unsigned char key, int x, int y) {
  Sleep(100);
  switch (key) {
    case 'b': rubiks.handleRotate(BACK,direction);
      break;
    case 'f': rubiks.handleRotate(FRONT,direction);
      break;
    case 'o': rubiks.handleRotate(BOTTOM,direction);
      break;
    case 't': rubiks.handleRotate(TOP,direction);
      break;
    case 'l': rubiks.handleRotate(LEFT,direction);
      break;
    case 'r': rubiks.handleRotate(RIGHT,direction);
      break;
    case 'x': rubiks.handleRotate(MIDDLEX,direction);
      break;
    case 'y': rubiks.handleRotate(MIDDLEY,direction);
      break;
    case 'z': rubiks.handleRotate(MIDDLEZ,direction);
      break;
    case 'c': toggleDirection();
      break;
    case 'X': rubiks.rotateAll(ALLX,direction);
      break;
    case 'Y': rubiks.rotateAll(ALLY,direction);
      break;
    case 'Z': rubiks.rotateAll(ALLZ,direction);
      break;
    case 's': rubiks.autoSolve();
      break;
    default:
      break;
  }
}

void keyPressed5 (unsigned char key, int x, int y) {
  Sleep(100);
  switch (key) {
    case 'b': rubiks5.handleRotate(BACK,direction);
      break;
    case 'f': rubiks5.handleRotate(FRONT,direction);
      break;
    case 'o': rubiks5.handleRotate(BOTTOM,direction);
      break;
    case 't': rubiks5.handleRotate(TOP,direction);
      break;
    case 'l': rubiks5.handleRotate(LEFT,direction);
      break;
    case 'r': rubiks5.handleRotate(RIGHT,direction);
      break;
    case 'x': rubiks5.handleRotate(MIDDLEX,direction);
      break;
    case 'y': rubiks5.handleRotate(MIDDLEY,direction);
      break;
    case 'z': rubiks5.handleRotate(MIDDLEZ,direction);
      break;
    case 'c': toggleDirection();
      break;
    case 'X': rubiks5.rotateAll(ALLX,direction);
      break;
    case 'Y': rubiks5.rotateAll(ALLY,direction);
      break;
    case 'Z': rubiks5.rotateAll(ALLZ,direction);
      break;
    default:
      break;
  }
}

void toggleDirection() {
  if (direction==CLOCKWISE)
    direction = COUNTER_CLOCKWISE;
  else
    direction = CLOCKWISE;
}


void mouse(int btn, int state, int x, int y)
  {
    if (state == GLUT_DOWN)
    {
      if (btn == GLUT_LEFT_BUTTON);

      else if (btn == GLUT_RIGHT_BUTTON);

  }
}

/* Called back when timer expired [NEW] */

void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

float red = 229.0/255.0;
float green = 0.0;
float blue = 81.0/255.0;

void triangle( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();

    if (red > 0) {
        red = red - (229.0/255.0)/iteration;
        green = green + (148.0/255.0)/iteration;
        blue = blue + (180.0/255.0)/iteration;
    } else {
        red = 229.0/255.0;
        green = 0;
        blue = 81.0/255.0;
    }
}


float red_point = 0.0/255.0;
float green_point = 166.0/255.0;
float blue_point  = 229.0/255.0;

void triangle_point( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red_point, green_point, blue_point);
    glBegin(GL_LINES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(a);
    glEnd();

    if (red_point < (175.0/255.0)) {
        red_point = red_point + (175.0/255.0)/iteration;
        green_point = green_point + (77.0/255.0)/iteration;
        blue_point = blue_point - (131.0/255.0)/iteration;
    } else {
        red_point = 0.0/255.0;
        green_point = 166.0/255.0;
        blue_point  = 229.0/255.0;
    }
}

// Draw our world
void display_1(void)
{
   displayCube();
}

void display_2(void)
{
   displayCube5();
}

// This is called when the window has been resized.
void reshape_2 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

// This is called when the window has been resized.
void reshape_3 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape_1(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void setIteration(int itr) {
    iteration = itr;
}

void printLogo() {
    char fr = 176;
    char fr_array[33];
    int i;
    for (i=0; i<33; i++) {
        fr_array[i] = fr;
    }
    fr_array[i] = 0;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << "  Welcome to GraphiCAT Rubik's!  " << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void printMenu() {

    std::cout << "Control" << std::endl;
    std::cout << "1: Start playing (3x3)" << std::endl;
    std::cout << "2: Start playing (5x5)" << std::endl;
    std::cout << "f: Rotate front" << std::endl;
    std::cout << "b: Rotate back" << std::endl;
    std::cout << "r: Rotate right" << std::endl;
    std::cout << "l: Rotate left" << std::endl;
    std::cout << "t: Rotate top" << std::endl;
    std::cout << "o: Rotate bottom" << std::endl;
    std::cout << "x: Rotate middle by x-axis" << std::endl;
    std::cout << "y: Rotate middle by y-axis" << std::endl;
    std::cout << "z: Rotate middle by z-axis" << std::endl;
    std::cout << "X: Rotate all by x-axis" << std::endl;
    std::cout << "Y: Rotate all by y-axis" << std::endl;
    std::cout << "Z: Middle all by z-axis" << std::endl;
    std::cout << "c: Toggle direction" << std::endl;

}

void printGoodbye() {
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "                         ====== Bye-bye! :'( ======                         " << std::endl;
}
