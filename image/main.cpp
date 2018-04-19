
#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

#include "imageloader.h"

using namespace std;
#define ROWS 1.0
#define COLUMNS 1.0

GLuint _textureId;
GLuint _textureId1;
int zomX=100,zomY=175;

float getx(int x)
{
    return float(x)/450;
}
float gety(int y)
{
    return float(y)/350;
}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//glPushMatrix();

	//glTranslatef(0.0, 0.0, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glEnd();

//glPopMatrix();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix();
//glEnable(GL_TEXTURE_2D);
//glNormal3f(0.0f, 0.0f, 1.0f);
glLineWidth(7.0f);
glTranslatef(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
      glVertex3f(getx(0), gety(175), 0.0);
      glVertex3f(getx(512), gety(175), 0.0);
    glEnd();
glPopMatrix();
	glutSwapBuffers();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}
void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLfloat)w,(GLfloat)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void initialize() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	//gluPerspective(45.0, 1.00, 1.0, 200.0);
	//Image* image = loadBMP("text.bmp");
	Image* image = loadBMP("C:\\Users\\ASUS\\OneDrive\\6th Sem\\Graphics\\Arif\\final\\project\\image\\bin\\Debug\\pyramid.bmp");
	//_textureId = loadTexture(image);
	_textureId = loadTexture(image);
	delete image;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 700);

	glutCreateWindow("Textures");
	initialize();
	//lightSetting();
	glutDisplayFunc(drawScene);
	//gluOrtho2D(0, 900, 0, 700);
    glutReshapeFunc(reshape_callback);
	glutMainLoop();
	return 0;
}









