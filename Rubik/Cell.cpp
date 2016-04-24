#include "Cell.h"
#include <windows.h>  // for MS Windows
#include "soil/SOIL.h"
#include <vector>


Cell::Cell(const Cell& c){
    color = c.color;
    location = c.location;
    normal = c.normal;
}

Cell::Cell(int _color, Point3D _location, Point3D _normal, std::vector<GLuint> _texture){
    color = _color;
    location = _location;
    normal = _normal;
    texture = _texture;
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
    } else if(color == GREEN){
        glColor3f(0.0f,1.0f,0.0f);
    } else if(color == WHITE){
        glColor3f(1.0f,1.0f,1.0f);
    } else if(color == BLUE){
        glColor3f(0.0f,0.0f,1.0f);
    } else if(color == ORANGE){
        glColor3f(1.0f,0.5f,0.0f);
    } else if(color == YELLOW){
        glColor3f(1.0f,1.0f,0.0f);
    }
}

void Cell::setTexture(){
    if(color == RED){
      glBindTexture(GL_TEXTURE_2D,texture.at(RED));
    } else if(color == GREEN){
      glBindTexture(GL_TEXTURE_2D,texture.at(GREEN));
    } else if(color == WHITE){
      glBindTexture(GL_TEXTURE_2D,texture.at(WHITE));
    } else if(color == BLUE){
      glBindTexture(GL_TEXTURE_2D,texture.at(BLUE));
    } else if(color == ORANGE){
      glBindTexture(GL_TEXTURE_2D,texture.at(ORANGE));
    } else if(color == YELLOW){
      glBindTexture(GL_TEXTURE_2D,texture.at(YELLOW));
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

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Top)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Top)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x-size, y+size, z+size);	// Bottom Left Of The Quad (Top)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x+size, y+size, z+size);	// Bottom Right Of The Quad (Top)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 1) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z+blackspace);	// Top Right Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace);	// Top Left Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(x+blackspace, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Bottom)
        glEnd();

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x+size, y-size, z+size);	// Top Right Of The Quad (Bottom)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x-size, y-size, z+size);	// Top Left Of The Quad (Bottom)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Bottom)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Bottom)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 2) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace-0.2, y+blackspace, z-blackspace);	// Top Right Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y+blackspace, z+blackspace);	// Top Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z+blackspace);	// Bottom Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Right)
        glEnd();

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Right)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x+size, y+size, z+size);	// Top Left Of The Quad (Right)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x+size, y-size, z+size);	// Bottom Left Of The Quad (Right)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Right)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 3) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x-blackspace+0.2, y+blackspace, z+blackspace);	// Top Right Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y+blackspace, z-blackspace);	// Top Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z+blackspace);	// Bottom Right Of The Quad (Left)
        glEnd();

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x-size, y+size, z+size);	// Top Right Of The Quad (Left)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Left)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Left)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x-size, y-size, z+size);	// Bottom Right Of The Quad (Left)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 4) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z-blackspace+0.2);	// Top Right Of The Quad (Back)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace+0.2);	// Top Left Of The Quad (Back)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Left Of The Quad (Back)
        glVertex3f(x+blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Right Of The Quad (Back)
        glEnd();

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x+size, y-size, z-size);	// Top Right Of The Quad (Back)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x-size, y-size, z-size);	// Top Left Of The Quad (Back)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x-size, y+size, z-size);	// Bottom Left Of The Quad (Back)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x+size, y+size, z-size);	// Bottom Right Of The Quad (Back)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 5) {
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y+blackspace, z+blackspace-0.2);	// Top Right Of The Quad (Front)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace-0.2);	// Top Left Of The Quad (Front)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Left Of The Quad (Front)
        glVertex3f(x+blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Right Of The Quad (Front)
        glEnd();

        setTexture();
        glEnable (GL_TEXTURE_2D);
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f (1.0f,1.0f);
        glVertex3f(x+size, y+size, z+size);	// Top Right Of The Quad (Front)
        glTexCoord2f (0.0f,1.0f);
        glVertex3f(x-size, y+size, z+size);	// Top Left Of The Quad (Front)
        glTexCoord2f (0.0f,0.0f);
        glVertex3f(x-size, y-size, z+size);	// Bottom Left Of The Quad (Front)
        glTexCoord2f (1.0f,0.0f);
        glVertex3f(x+size, y-size, z+size);	// Bottom Right Of The Quad (Front)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glEnd();
}
