#include <windows.h>
#include <gl/Gl.h>
#include "glut.h"
#include <iostream>
#include <fstream>

using namespace std;

int screenheight = 600;
int screenwidth = 800;
char* file = 0;

void drawPolyLineFile(char* fileName) {
	fstream inStream;
	inStream.open("dino.dat", ios::in);
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++) {
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void myDisplay()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //green
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile(file);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	// initialize window
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(0, 0);
	//glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	// create window
	glutCreateWindow("Rubber Rect Demo");

	// set the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 500);

	glMatrixMode(GL_MODELVIEW);
	// clear rendering surface
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background is black
	glViewport(0, 0, 500, 500);


	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return(0);

}