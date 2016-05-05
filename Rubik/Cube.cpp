#include "Cube.h"
#include <windows.h>  // for MS Windows

#include <iostream>
#include <vector>
#include <algorithm>

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

using namespace std;

bool Cube::solve = false;

Cube::Cube() {
    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);

    //BOTTOM SURFACE
    surface[0] = Cell(WHITE, Point3D(-1,-1.9,-1), top);
    surface[1] = Cell(WHITE, Point3D(0,-1.9,-1), top);
    surface[2] = Cell(WHITE, Point3D(1,-1.9,-1), top);
    surface[3] = Cell(WHITE, Point3D(-1,-1.9,0), top);
    surface[4] = Cell(WHITE, Point3D(0,-1.9,0), top);
    surface[5] = Cell(WHITE, Point3D(1,-1.9,0), top);
    surface[6] = Cell(WHITE, Point3D(-1,-1.9,1), top);
    surface[7] = Cell(WHITE, Point3D(0,-1.9,1), top);
    surface[8] = Cell(WHITE, Point3D(1,-1.9,1), top);


    //TOP SURFACE
    surface[9] = Cell(YELLOW, Point3D(-1,1.9,-1), bottom);
    surface[10] = Cell(YELLOW, Point3D(0,1.9,-1), bottom);
    surface[11] = Cell(YELLOW, Point3D(1,1.9,-1), bottom);
    surface[12] = Cell(YELLOW, Point3D(-1,1.9,0), bottom);
    surface[13] = Cell(YELLOW, Point3D(0,1.9,0), bottom);
    surface[14] = Cell(YELLOW, Point3D(1,1.9,0), bottom);
    surface[15] = Cell(YELLOW, Point3D(-1,1.9,1), bottom);
    surface[16] = Cell(YELLOW, Point3D(0,1.9,1), bottom);
    surface[17] = Cell(YELLOW, Point3D(1,1.9,1), bottom);

    //LEFT SURFACE
    surface[18] = Cell(RED, Point3D(-1.1,-1,-1), left);
    surface[19] = Cell(RED, Point3D(-1.1,0,-1), left);
    surface[20] = Cell(RED, Point3D(-1.1,1,-1), left);
    surface[21] = Cell(RED, Point3D(-1.1,-1,0), left);
    surface[22] = Cell(RED, Point3D(-1.1,0,0), left);
    surface[23] = Cell(RED, Point3D(-1.1,1,0), left);
    surface[24] = Cell(RED, Point3D(-1.1,-1,1), left);
    surface[25] = Cell(RED, Point3D(-1.1,0,1), left);
    surface[26] = Cell(RED, Point3D(-1.1,1,1), left);

    //RIGHT SURFACE
    surface[27] = Cell(ORANGE, Point3D(1.1,-1,-1), right);
    surface[28] = Cell(ORANGE, Point3D(1.1,0,-1), right);
    surface[29] = Cell(ORANGE, Point3D(1.1,1,-1), right);
    surface[30] = Cell(ORANGE, Point3D(1.1,-1,0), right);
    surface[31] = Cell(ORANGE, Point3D(1.1,0,0), right);
    surface[32] = Cell(ORANGE, Point3D(1.1,1,0), right);
    surface[33] = Cell(ORANGE, Point3D(1.1,-1,1), right);
    surface[34] = Cell(ORANGE, Point3D(1.1,0,1), right);
    surface[35] = Cell(ORANGE, Point3D(1.1,1,1), right);

    //BACK SURFACE
    surface[36] = Cell(BLUE, Point3D(-1,-1,-1.1), behind);
    surface[37] = Cell(BLUE, Point3D(0,-1,-1.1), behind);
    surface[38] = Cell(BLUE, Point3D(1,-1,-1.1), behind);
    surface[39] = Cell(BLUE, Point3D(-1,0,-1.1), behind);
    surface[40] = Cell(BLUE, Point3D(0,0,-1.1), behind);
    surface[41] = Cell(BLUE, Point3D(1,0,-1.1), behind);
    surface[42] = Cell(BLUE, Point3D(-1,1,-1.1), behind);
    surface[43] = Cell(BLUE, Point3D(0,1,-1.1), behind);
    surface[44] = Cell(BLUE, Point3D(1,1,-1.1), behind);

    //FRONT SURFACE
    surface[45] = Cell(GREEN, Point3D(-1,-1,1.1), infront);
    surface[46] = Cell(GREEN, Point3D(0,-1,1.1), infront);
    surface[47] = Cell(GREEN, Point3D(1,-1,1.1), infront);
    surface[48] = Cell(GREEN, Point3D(-1,0,1.1), infront);
    surface[49] = Cell(GREEN, Point3D(0,0,1.1), infront);
    surface[50] = Cell(GREEN, Point3D(1,0,1.1), infront);
    surface[51] = Cell(GREEN, Point3D(-1,1,1.1), infront);
    surface[52] = Cell(GREEN, Point3D(0,1,1.1), infront);
    surface[53] = Cell(GREEN, Point3D(1,1,1.1), infront);

}

Cube::Cube(const Cube& c){

}

Cube::~Cube(){
}

Cell* Cube::getSurface() {
    return surface;
}

void Cube::setSurface(Cell _surface[64]){
}

void Cube::drawCube(){
    for (int i = 0; i < 54; i++) {
        surface[i].drawCell();
    }
}

void Cube::rotateAll(int axis, int direction) {
  float degrees_per_frame = 5.0f;
  int frames = 45.0f/degrees_per_frame;

  if (direction==COUNTER_CLOCKWISE) {
    for (int i=0;i<=frames;i++) {
      rotateByAxis(degrees_per_frame,axis);
      Sleep(100);
    }
  } else {
    for (int i=0;i<=frames;i++) {
      rotateByAxis(-degrees_per_frame,axis);
      Sleep(100);
    }
  }
}

void Cube::rotateByAxis(GLfloat angle, int axis) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

  switch (axis) {
    case ALLX:
      glRotatef(angle,1.0f,0.0f,0.0f);
      break;
    case ALLY:
      glRotatef(angle,0.0f,1.0f,0.0f);
      break;
    case ALLZ:
      glRotatef(angle,0.0f,0.0f,1.0f);
      break;
    default:
      break;
  }
  drawCube();

  glutSwapBuffers();
}

void Cube::handleRotate(int face, int direction) {
  if (!solve) {
    faceHistory.push_back(face);
    directionHistory.push_back(direction);
  }

  float degrees_per_frame = 10.0f;
  int frames = 90.0f/degrees_per_frame;
  GLfloat angleCube = 0.0f;
  vector<int> rotate = getRotationVector(face);
  vector<int> sides(rotate.begin(),rotate.begin()+12);
  if (direction==COUNTER_CLOCKWISE) {
    for (int i=0;i<=frames;i++) {
      rotateSlice(angleCube,rotate,getRotationAxis(face));
      angleCube += degrees_per_frame;
      Sleep(100);
    }
    swapColors(sides,3);
    if (rotate.size()>12) {
        vector<int> flat(rotate.begin()+12,rotate.begin()+20);
        swapColors(flat,2);
    }
  } else {
    for (int i=0;i<=frames;i++) {
      rotateSlice(angleCube,getRotationVector(face),getRotationAxis(face));
      angleCube -= degrees_per_frame;
      Sleep(100);
    }
    swapColors(sides,-3);
    if (rotate.size()>12) {
        vector<int> flat(rotate.begin()+12,rotate.begin()+20);
        swapColors(flat,-2);
    }
  }
}

void Cube::autoSolve() {
  solve = true;
  int moves = faceHistory.size();
  for (int i=0;i<moves;i++) {
    if (directionHistory.back()==CLOCKWISE) {
      handleRotate(faceHistory.back(),COUNTER_CLOCKWISE);
    }
    else {
      handleRotate(faceHistory.back(),CLOCKWISE);
    }
    faceHistory.pop_back();
    directionHistory.pop_back();
  }
  solve=false;
}

vector<int> Cube::getRotationVector(int face) {
  switch (face) {
    case BOTTOM: {
      int arr[] = {24,21,18,36,37,38,27,30,33,47,46,45,0,1,2,5,8,7,6,3,4}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case TOP: {
      int arr[] = {26,23,20,42,43,44,29,32,35,53,52,51,9,10,11,14,17,16,15,12,13}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case RIGHT: {
      int arr[] = {8,5,2,38,41,44,11,14,17,53,50,47,27,28,29,32,35,34,33,30,31}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case LEFT: {
      int arr[] = {6,3,0,36,39,42,9,12,15,51,48,45,18,19,20,23,26,25,24,21,22}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case BACK: {
      int arr[] = {18,19,20,9,10,11,29,28,27,2,1,0,42,43,44,41,38,37,36,39,40}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case FRONT: {
      int arr[] = {24,25,26,15,16,17,35,34,33,8,7,6,51,52,53,50,47,46,45,48,49}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEY: {
      int arr[] = {50,49,48,25,22,19,39,40,41,28,31,34}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEX: {
      int arr[] = {7,4,1,37,40,43,10,13,16,52,49,46}; // clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    case MIDDLEZ: {
      int arr[] = {5,4,3,21,22,23,12,13,14,32,31,30}; //clockwise
      return vector<int>(arr, arr + sizeof(arr) / sizeof(arr[0]));
      } break;
    default:
      break;
  }
  return vector<int>();
}

Point3D Cube::getRotationAxis(int face) {
  switch (face) {
    case BOTTOM:
    case TOP:
    case MIDDLEY:
      return Point3D(0.0,1.0,0.0);
      break;
    case RIGHT:
    case LEFT:
    case MIDDLEX:
      return Point3D(-1.0,0.0,0.0);
      break;
    case BACK:
    case FRONT:
    case MIDDLEZ:
      return Point3D(0.0,0.0,1.0);
      break;
    default:
      break;
  }
  return Point3D();
}

void Cube::rotateSlice(GLfloat angle, vector<int> rotate, Point3D axis) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glPushMatrix();

    //Draw cube unrotated
    for (int i = 0; i < 54; i++) {
        if(std::find(rotate.begin(), rotate.end(), i) == rotate.end()) {
            surface[i].drawCell();
        }
    }

    glPopMatrix();

    glPushMatrix();
    //Rotate around axis
    glRotatef(angle,(GLfloat)axis.getX(),(GLfloat)axis.getY(),(GLfloat)axis.getZ());

    //Draw rotated
    for (int i = 0; i < rotate.size(); i++) {
        surface[rotate.at(i)].drawCell();
    }

    glPopMatrix();

    glutSwapBuffers();
}

void Cube::swapColors(vector<int> array, int jump) {
  vector<int> colors;

  //copy colors to temp vector
  for (int i=0;i<array.size();i++) {
    colors.push_back(surface[array.at(i)].getColor());
  }

  //swap colors from vector
  for (int i=0;i<array.size();i++) {
    surface[array.at(i)].setColor(colors.at((i+array.size()+jump)%array.size()));
  }
}
