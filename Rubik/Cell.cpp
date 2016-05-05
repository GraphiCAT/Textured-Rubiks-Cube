#include "Cell.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include "soil/SOIL.h"

GLuint Cell::texture = 0;
GLuint Cell::texture1 = 0;
GLuint Cell::texture2 = 0;
GLuint Cell::texture3 = 0;
GLuint Cell::texture4 = 0;
GLuint Cell::texture5 = 0;
GLuint Cell::texture6 = 0;


void Cell::initTexture() {
    glGenTextures(1, &Cell::texture);
    glBindTexture(GL_TEXTURE_2D,Cell::texture);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* image = SOIL_load_image("img_test.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);

    /* Texture 1-2 */
    glGenTextures(1, &Cell::texture1);
    glBindTexture(GL_TEXTURE_2D,Cell::texture1);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image1 = SOIL_load_image("blue.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);
    SOIL_free_image_data(image1);

    glGenTextures(1, &Cell::texture2);
    glBindTexture(GL_TEXTURE_2D,Cell::texture2);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image2 = SOIL_load_image("green.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
    SOIL_free_image_data(image2);

    glGenTextures(1, &Cell::texture3);
    glBindTexture(GL_TEXTURE_2D,Cell::texture3);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image3 = SOIL_load_image("orange.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);
    SOIL_free_image_data(image3);

    glGenTextures(1, &Cell::texture4);
    glBindTexture(GL_TEXTURE_2D,Cell::texture4);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image4 = SOIL_load_image("yellow.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image4);
    SOIL_free_image_data(image4);

    glGenTextures(1, &Cell::texture5);
    glBindTexture(GL_TEXTURE_2D,Cell::texture5);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image5 = SOIL_load_image("pink.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image5);
    SOIL_free_image_data(image5);

    glGenTextures(1, &Cell::texture6);
    glBindTexture(GL_TEXTURE_2D,Cell::texture6);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* image6 = SOIL_load_image("purple.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image6);
    SOIL_free_image_data(image6);
}

Cell::Cell(const Cell& c){
    color = c.color;
    location = c.location;
    normal = c.normal;
    textureSoil = c.textureSoil;
}

Cell::Cell(int _color, Point3D _location, Point3D _normal){
    color = _color;
    location = _location;
    normal = _normal;
}

Cell::~Cell(){
}

int Cell::getColor(){
    return color;
}

void Cell::setColor(int _color){
    color = _color;
}

Point3D Cell::getLocation(){
    return location;
}

void Cell::setLocation(Point3D _location){
    location = _location;
}

Point3D Cell::getNormal(){
    return normal;
}

void Cell::setNormal(Point3D _normal){
    normal = _normal;
}
void Cell::setColor(){
    if(color == RED){
        glColor3f(1.0f,0.0f,0.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture1);
    } else if(color == GREEN){
        glColor3f(0.0f,1.0f,0.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture2);
    } else if(color == WHITE){
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture3);
    } else if(color == BLUE){
        glColor3f(0.0f,0.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture4);
    } else if(color == ORANGE){
        glColor3f(1.0f,0.5f,0.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture5);
    } else if(color == YELLOW){
        glColor3f(1.0f,1.0f,0.0f);
        glBindTexture(GL_TEXTURE_2D, Cell::texture6);
    }
}

int Cell::getFace(){
    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);
    if (normal.isEquals(top)) {
        return 0;
    } else if (normal.isEquals(bottom)) {
        return 1;
    } else if (normal.isEquals(right)) {
        return 2;
    } else if (normal.isEquals(left)) {
        return 3;
    } else if (normal.isEquals(behind)) {
        return 4;
    } else if (normal.isEquals(infront)) {
        return 5;
    }
}


void Cell::drawCell() {
    float size = 0.9f;
    float blackspace = 1.0f;
    float x = location.getX()*2.25;
    float y = location.getY()*2.25;
    float z = location.getZ()*2.25;
    glBegin(GL_QUADS);		// Draw The Cube Using quads

    if (getFace() == 0) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y+blackspace, z-blackspace);	// Top Right Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace);	// Top Left Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace);	// Bottom Left Of The Quad (Top)
        glVertex3f(x+blackspace, y+blackspace, z+blackspace);	// Bottom Right Of The Quad (Top)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Top)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Top)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y+size, z+size);	// Bottom Right Of The Quad (Top)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y+size, z+size);	// Bottom Left Of The Quad (Top)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 1) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z+blackspace);	// Top Right Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace);	// Top Left Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(x+blackspace, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Bottom)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y-size, z+size);	// Top Left Of The Quad (Bottom)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y-size, z+size);	// Top Right Of The Quad (Bottom)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Bottom)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Bottom)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 2) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace-0.2, y+blackspace, z-blackspace);	// Top Right Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y+blackspace, z+blackspace);	// Top Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z+blackspace);	// Bottom Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Right)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+size, y+size, z+size);	// Top Left Of The Quad (Right)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Right)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Right)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+size, y-size, z+size);	// Bottom Left Of The Quad (Right)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 3) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x-blackspace+0.2, y+blackspace, z+blackspace);	// Top Right Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y+blackspace, z-blackspace);	// Top Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z+blackspace);	// Bottom Right Of The Quad (Left)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Left)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x-size, y+size, z+size);	// Top Right Of The Quad (Left)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x-size, y-size, z+size);	// Bottom Right Of The Quad (Left)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Left)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 4) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z-blackspace+0.2);	// Top Right Of The Quad (Back)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace+0.2);	// Top Left Of The Quad (Back)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Left Of The Quad (Back)
        glVertex3f(x+blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Right Of The Quad (Back)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+size, y+size, z-size); 	// Top Left Of The Quad (Back)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x-size, y+size, z-size); 	// Top Right Of The Quad (Back)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x-size, y-size, z-size);	// Bottom Right Of The Quad (Back)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+size, y-size, z-size);	// Bottom Left Of The Quad (Back)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 5) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y+blackspace, z+blackspace-0.2);	// Top Right Of The Quad (Front)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace-0.2);	// Top Left Of The Quad (Front)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Left Of The Quad (Front)
        glVertex3f(x+blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Right Of The Quad (Front)
        glEnd();

        setColor();
        glEnable( GL_TEXTURE_2D );
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z+size);	// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z+size);	// Top Right Of The Quad (Front)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z+size);	// Bottom Right Of The Quad (Front)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z+size);	// Bottom Left Of The Quad (Front)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}

void Cell::FreeTexture( GLuint texture )
{

  glDeleteTextures( 1, &texture );

}

