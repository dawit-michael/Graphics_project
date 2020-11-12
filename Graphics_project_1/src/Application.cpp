#include <windows.h>
#include <iostream>
#include <cstdio>
#include<conio.h>
#include <string>
#include <cstdlib>
#include<GL/gl.h>
#include <GL/glut.h>

#define KEY_ESC 27
using namespace std;


/*

Hilcoe School Of computer Science and Technology

Name: Dawit Michael Asefa
DRB1702
Section A
Id:-IL1425





*/


int window, returnmenu, returnsubmenu, returnsubmenucolor1, returnsubmenucolor2, returnsubmenucolor3, returnsubmenucolor4, returnsubmenucolor5, returnsubmenucolor6, returnsubmenucolor7, returnsubmenucolor8, value = 0;
string shape;

void printtext(int x, int y, string String);
int xTeapot = 220;
int yTeapot = 400;
int WindowHeight = 490;
int WindowWidth = 720;
int slices = 50, stacks = 50;
double rotate_x = 0.0;
double rotate_y = 0.0;
bool autorotate = true;

bool showControls = false;

float grow_shrink = 0.01f;
float resize_f = 0.01f;

float shape_size = 0.5f ;

float xrot = 100.0f;
float yrot = -100.0f;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;

const double cellSize = 0.1f;
void menu(int n) {
	if (n == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	else
	{
		value = n;
	}
	glutPostRedisplay();
}
void createMenu(void) {

	//Teapot
	returnsubmenucolor1 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 11);
	glutAddMenuEntry("Grey", 12);


	//
	returnsubmenucolor2 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 21);
	glutAddMenuEntry("Grey", 22);


	//Torus
	returnsubmenucolor3 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 31);
	glutAddMenuEntry("Grey", 32);


	//Point
	/*
	returnsubmenucolor5 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 46);
	glutAddMenuEntry("Grey", 47);*/



	returnmenu = glutCreateMenu(menu); //function to call menu function and return value
	glutAddMenuEntry("Home", 1);
	glutAddMenuEntry("Tile One 2D", 46);
	glutAddMenuEntry("Tile Two 2D", 56);
	/*
	glutAddMenuEntry("Square", 61);
	glutAddSubMenu("Sphere", returnsubmenucolor2);
	glutAddSubMenu("Teapot", returnsubmenucolor1);
	glutAddSubMenu("Donut Shape", returnsubmenucolor3);

	glutAddMenuEntry("Cone", 41);*/
	glutAddMenuEntry("Tile three 3D", 51);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void rotater() {
	if (autorotate) {
		double t = glutGet(GLUT_ELAPSED_TIME) / 1900.0;
		double a = t * 60;
		glRotated(a, 1.0, 0.0, 1.0);
		glRotated(a, 0.0, 1.0, 0.0);
		glRotated(a, 0.0, 0.0, 1.0);
	}

}
void keyRotate() {
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
}



void printtext(int x, int y, string String) {

	//(x,y) is from the bottom left of the window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2i(x, y);
	for (int i = 0; i < String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
	}
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void displayHome() {

	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glColor3d(1.0, 0.0, 0.0);
	glTranslated(0.0, 0.65, 0.0);
	rotater();
	glutWireCone(0.3, 0.4, 3, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 0.0, 0.0);
	glTranslated(0.0, -0.65, 0.0);
	rotater();
	glutSolidCube(0.3);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	glTranslatef(1.0, 0, 0);

	char string[64];
	glColor3d(1.0, 1.0, 1.0);
	sprintf_s(string, "HiLCoE School Of Computer Science and Technology");
	printtext(150, 300, string);
	glColor3d(0.0, 1.4, 1.0);
	sprintf_s(string, "Developed By:");
	printtext(300, 270, string);
	sprintf_s(string, "---- Dawit Michael ----");
	printtext(256, 250, string);
	glColor3d(0.0, 1.4, 1.0);
	sprintf_s(string, "---- DRB 1702 ----");
	printtext(270, 240, string);
	glColor3d(0.0, 1.4, 1.0);
	sprintf_s(string, "---- ID IL1425----");
	printtext(270, 230, string);
	glColor3d(1.0, 0.0, 1.0);
	sprintf_s(string, "Please Right Click anywhere");
	printtext(250, 210, string);
	sprintf_s(string, "to show your child");
	printtext(290, 190, string);
	sprintf_s(string, "a shape from the list.");
	printtext(280, 170, string);
	glPopMatrix();


}

//this fuction draws a rectangle with backward "\" facing diagonal
void makeRectangelTypeOne(double x_cordinate, double y_cordinate, double color1[3], double color2[3]) {


	glBegin(GL_TRIANGLES);
	glColor3f(color1[0], color1[1], color1[2]);
	glVertex2f(x_cordinate, y_cordinate);
	glVertex2f(x_cordinate + cellSize, y_cordinate);
	glVertex2f(x_cordinate + cellSize, y_cordinate - cellSize);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(color2[0], color2[1], color2[2]);
	glVertex2f(x_cordinate, y_cordinate);
	glVertex2f(x_cordinate, y_cordinate - cellSize);
	glVertex2f(x_cordinate + cellSize, y_cordinate - cellSize);
	glEnd();
}

//this fuction draws a rectangle with forward "/" facing diagonal
void makeRectangelTypeTwo(double x_cordinate, double y_cordinate, double color1[3], double color2[3]) {
	glBegin(GL_TRIANGLES);
	glColor3f(color1[0], color1[1], color1[2]);
	glVertex2f(x_cordinate, y_cordinate);
	glVertex2f(x_cordinate, y_cordinate - cellSize);
	glVertex2f(x_cordinate + cellSize, y_cordinate);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(color2[0], color2[1], color2[2]);
	glVertex2f(x_cordinate + cellSize, y_cordinate - cellSize);
	glVertex2f(x_cordinate, y_cordinate - cellSize);
	glVertex2f(x_cordinate + cellSize, y_cordinate);
	glEnd();
}

//draws tile one
void DrawTileOne() {
	double x_cordinate = -0.8f;
	double y_cordinate = 0.8f;

	double colorLightGreen[3] = { 0.76, 0.82, 0.72 };
	double colorDarkGreen[3] = { 0.44, 0.52, 0.4 };
	double colorDarkBrown[3] = { 0.35, 0.32, 0.27 };
	double colorLightBrown[3] = { 0.92, 0.86, 0.74 };

	
		for (int row = 1; row <= 4; row++)
		{
			for (int col = 1; col <= 4; col++)
			{

				//row one

				if (row == 1 && col == 1) {

					makeRectangelTypeOne(x_cordinate, y_cordinate, colorLightGreen, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + cellSize, y_cordinate, colorDarkBrown, colorLightBrown); // go right
					makeRectangelTypeTwo(x_cordinate, y_cordinate - cellSize, colorDarkGreen, colorLightGreen); //go back left and down
					makeRectangelTypeOne(x_cordinate + cellSize, y_cordinate - cellSize, colorLightBrown, colorDarkBrown); //go right

				}
				else if (row == 1 && col == 2)
				{
					makeRectangelTypeOne(x_cordinate + 2 * cellSize, y_cordinate, colorDarkGreen, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 3 * cellSize, y_cordinate, colorDarkGreen, colorLightGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 2 * cellSize, y_cordinate - cellSize, colorLightBrown, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 3 * cellSize, y_cordinate - cellSize, colorLightGreen, colorDarkGreen); // gor right
				}
				else if (row == 1 && col == 3) {
					makeRectangelTypeOne(x_cordinate + 4 * cellSize, y_cordinate, colorDarkGreen, colorLightGreen); //left
					makeRectangelTypeTwo(x_cordinate + 5 * cellSize, y_cordinate, colorDarkGreen, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 4 * cellSize, y_cordinate - cellSize, colorLightGreen, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 5 * cellSize, y_cordinate - cellSize, colorLightBrown, colorDarkGreen); // gor right
				}
				else if (row == 1 && col == 4) {

					makeRectangelTypeOne(x_cordinate + 6 * cellSize, y_cordinate, colorDarkBrown, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 7 * cellSize, y_cordinate, colorLightGreen, colorDarkGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 6 * cellSize, y_cordinate - cellSize, colorLightBrown, colorDarkBrown); // go back left and down
					makeRectangelTypeOne(x_cordinate + 7 * cellSize, y_cordinate - cellSize, colorDarkGreen, colorLightGreen);

				}



				// row two


				else if (row == 2 && col == 1) {

					makeRectangelTypeOne(x_cordinate, y_cordinate - 2 * cellSize, colorDarkBrown, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + cellSize, y_cordinate - 2 * cellSize, colorLightBrown, colorDarkGreen); // go right
					makeRectangelTypeTwo(x_cordinate, y_cordinate - 3 * cellSize, colorLightBrown, colorDarkGreen); //go back left and down
					makeRectangelTypeOne(x_cordinate + cellSize, y_cordinate - 3 * cellSize, colorDarkGreen, colorDarkGreen); //go right

				}
				else if (row == 2 && col == 2)
				{
					makeRectangelTypeOne(x_cordinate + 2 * cellSize, y_cordinate - 2 * cellSize, colorDarkGreen, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + 3 * cellSize, y_cordinate - 2 * cellSize, colorDarkGreen, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 2 * cellSize, y_cordinate - 3 * cellSize, colorDarkGreen, colorLightBrown); // go back left and down
					makeRectangelTypeOne(x_cordinate + 3 * cellSize, y_cordinate - 3 * cellSize, colorLightBrown, colorDarkBrown); // gor right

				}
				else if (row == 2 && col == 3) {
					makeRectangelTypeOne(x_cordinate + 4 * cellSize, y_cordinate - 2 * cellSize, colorDarkGreen, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 5 * cellSize, y_cordinate - 2 * cellSize, colorDarkGreen, colorDarkGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 4 * cellSize, y_cordinate - 3 * cellSize, colorLightBrown, colorDarkBrown); // go back left and down
					makeRectangelTypeOne(x_cordinate + 5 * cellSize, y_cordinate - 3 * cellSize, colorDarkGreen, colorLightBrown); // gor right

				}
				else if (row == 2 && col == 4) {

					makeRectangelTypeOne(x_cordinate + 6 * cellSize, y_cordinate - 2 * cellSize, colorLightBrown, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + 7 * cellSize, y_cordinate - 2 * cellSize, colorDarkBrown, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 6 * cellSize, y_cordinate - 3 * cellSize, colorDarkGreen, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 7 * cellSize, y_cordinate - 3 * cellSize, colorLightBrown, colorDarkGreen);

				}

				//// row three

				else if (row == 3 && col == 1) {

					makeRectangelTypeOne(x_cordinate, y_cordinate - 4 * cellSize, colorDarkGreen, colorLightGreen); //left
					makeRectangelTypeTwo(x_cordinate + cellSize, y_cordinate - 4 * cellSize, colorDarkGreen, colorLightBrown); // go right
					makeRectangelTypeTwo(x_cordinate, y_cordinate - 5 * cellSize, colorLightGreen, colorDarkGreen); //go back left and down
					makeRectangelTypeOne(x_cordinate + cellSize, y_cordinate - 5 * cellSize, colorLightBrown, colorDarkGreen); //go right

				}
				else if (row == 3 && col == 2)
				{
					makeRectangelTypeOne(x_cordinate + 2 * cellSize, y_cordinate - 4 * cellSize, colorDarkBrown, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 3 * cellSize, y_cordinate - 4 * cellSize, colorLightGreen, colorDarkGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 2 * cellSize, y_cordinate - 5 * cellSize, colorLightBrown, colorDarkBrown); // go back left and down
					makeRectangelTypeOne(x_cordinate + 3 * cellSize, y_cordinate - 5 * cellSize, colorDarkGreen, colorLightGreen); // gor right

				}
				else if (row == 3 && col == 3) {
					makeRectangelTypeOne(x_cordinate + 4 * cellSize, y_cordinate - 4 * cellSize, colorLightGreen, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + 5 * cellSize, y_cordinate - 4 * cellSize, colorDarkBrown, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 4 * cellSize, y_cordinate - 5 * cellSize, colorDarkGreen, colorLightGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 5 * cellSize, y_cordinate - 5 * cellSize, colorLightBrown, colorDarkBrown); // gor right


				}
				else if (row == 3 && col == 4) {

					makeRectangelTypeOne(x_cordinate + 6 * cellSize, y_cordinate - 4 * cellSize, colorDarkGreen, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 7 * cellSize, y_cordinate - 4 * cellSize, colorDarkGreen, colorLightGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 6 * cellSize, y_cordinate - 5 * cellSize, colorLightBrown, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 7 * cellSize, y_cordinate - 5 * cellSize, colorLightGreen, colorDarkGreen); //go right

				}

				//// row four

				else if (row == 4 && col == 1) {

					makeRectangelTypeOne(x_cordinate, y_cordinate - 6 * cellSize, colorDarkGreen, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + cellSize, y_cordinate - 6 * cellSize, colorDarkGreen, colorDarkGreen); // go right
					makeRectangelTypeTwo(x_cordinate, y_cordinate - 7 * cellSize, colorLightBrown, colorDarkBrown); //go back left and down
					makeRectangelTypeOne(x_cordinate + cellSize, y_cordinate - 7 * cellSize, colorDarkGreen, colorLightBrown); //go right
				}
				else if (row == 4 && col == 2)
				{
					makeRectangelTypeOne(x_cordinate + 2 * cellSize, y_cordinate - 6 * cellSize, colorLightBrown, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + 3 * cellSize, y_cordinate - 6 * cellSize, colorDarkBrown, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 2 * cellSize, y_cordinate - 7 * cellSize, colorDarkGreen, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 3 * cellSize, y_cordinate - 7 * cellSize, colorLightBrown, colorDarkGreen); // gor right


				}
				else if (row == 4 && col == 3) {
					makeRectangelTypeOne(x_cordinate + 4 * cellSize, y_cordinate - 6 * cellSize, colorDarkBrown, colorLightBrown); //left
					makeRectangelTypeTwo(x_cordinate + 5 * cellSize, y_cordinate - 6 * cellSize, colorLightBrown, colorDarkGreen); //go right
					makeRectangelTypeTwo(x_cordinate + 4 * cellSize, y_cordinate - 7 * cellSize, colorLightBrown, colorDarkGreen); // go back left and down
					makeRectangelTypeOne(x_cordinate + 5 * cellSize, y_cordinate - 7 * cellSize, colorDarkGreen, colorDarkGreen); // gor right



				}
				else if (row == 4 && col == 4) {

					makeRectangelTypeOne(x_cordinate + 6 * cellSize, y_cordinate - 6 * cellSize, colorDarkGreen, colorDarkGreen); //left
					makeRectangelTypeTwo(x_cordinate + 7 * cellSize, y_cordinate - 6 * cellSize, colorDarkGreen, colorLightBrown); //go right
					makeRectangelTypeTwo(x_cordinate + 6 * cellSize, y_cordinate - 7 * cellSize, colorDarkGreen, colorLightBrown); // go back left and down
					makeRectangelTypeOne(x_cordinate + 7 * cellSize, y_cordinate - 7 * cellSize, colorLightBrown, colorDarkBrown); //go right

				}

			}
		}
	
}

//draws tile tile two
void DrawTileTwo() {

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, 0.65f);
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-0.75f, 0.85f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.95686f, 0.937f, 0.92f);
	glVertex2f(-0.75f, 0.85f);
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-0.5f, 0.65f);
	glVertex2f(-0.5f, 1.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.5f, 1.0f);
	glVertex2f(-0.5f, 0.65f);
	glVertex2f(-0.25f, 0.5f);
	glVertex2f(-0.25f, 0.85f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.95686f, 0.937f, 0.92f);
	glVertex2f(-0.25f, 0.85f);
	glVertex2f(-0.25f, 0.5f);
	glVertex2f(0.0f, 0.65f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

	///second raw
	glBegin(GL_QUADS);
	glColor3f(0.95686f, 0.937f, 0.92f);
	glVertex2f(-1.0f, 0.35f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.75f, 0.15f);
	glVertex2f(-0.75f, 0.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-0.75f, 0.15f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, 0.35f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95686f, 0.937f, 0.92f);
	glVertex2f(-0.5f, 0.35f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.25f, 0.15f);
	glVertex2f(-0.25f, 0.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.25f, 0.5f);
	glVertex2f(-0.25f, 0.15f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.35f);
	glEnd();


}

void threeD_drawPoly() {


	glBegin(GL_POLYGON);
	//rectangle top left
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0504f, -1.0f);
	glVertex3f(0.875f, 0.0504f, -1.0f);
	glVertex3f(0.5f, 0.0504f, -0.625f);
	glVertex3f(0.625f, 0.0504f, -0.5f);
	glVertex3f(1.0f, 0.0504f, -0.875f);




	glEnd();

	glBegin(GL_POLYGON);
	//rectangle top right

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0504f, 0.0f);
	glVertex3f(0.875f, 0.0504f, 0.0f);

	glVertex3f(0.5f, 0.0504f, -0.375f);
	glVertex3f(0.625f, 0.0504f, -0.5f);

	glVertex3f(1.0f, 0.0504f, -0.125f);
	glEnd();

	glBegin(GL_POLYGON);
	//rectangle bottom left

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0504f, -1.0f);
	glVertex3f(0.0f, 0.0504f, -0.875f);

	glVertex3f(0.375f, 0.0504f, -0.5f);
	glVertex3f(0.5f, 0.0504f, -0.625f);

	glVertex3f(0.125f, 0.0504f, -1.0f);
	glEnd();

	glBegin(GL_POLYGON);
	//rectangle bottom left

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0504f, 0.0f);
	glVertex3f(0.125f, 0.0504f, 0.0f);

	glVertex3f(0.5f, 0.0504f, -0.375f);
	glVertex3f(0.375f, 0.0504f, -0.5f);

	glVertex3f(0.0f, 0.0504f, -0.125f);
	glEnd();


}

void threeD_drawMiniTriangles() {
	//left
	glBegin(GL_TRIANGLES);
	glColor3f(0.655f, 0.655f, 0.66f);
	glVertex3f(0.65f, 0.0502f, -1.0f);
	glVertex3f(0.5f, 0.0502f, -0.8f);
	glVertex3f(0.35f, 0.0502f, -1.0f);
	glEnd();

	//left white
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.55f, 0.0503f, -1.0f);
	glVertex3f(0.5f, 0.0503f, -0.95f);
	glVertex3f(0.45f, 0.0503f, -1.0f);
	glEnd();


	//right
	glBegin(GL_TRIANGLES);
	glColor3f(0.655f, 0.655f, 0.66f);
	glVertex3f(0.65f, 0.0502f, -0.0f);
	glVertex3f(0.5f, 0.0502f, -0.2f);
	glVertex3f(0.35f, 0.0502f, -0.0f);
	glEnd();

	//right white
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.55f, 0.0503f, -0.0f);
	glVertex3f(0.5f, 0.0503f, -0.05f);
	glVertex3f(0.45f, 0.0503f, -0.0f);
	glEnd();

	//top
	glBegin(GL_TRIANGLES);
	glColor3f(0.655f, 0.655f, 0.66f);
	glVertex3f(1.0f, 0.0502f, -0.65f);
	glVertex3f(0.8f, 0.0502f, -0.5f);
	glVertex3f(1.0f, 0.0502f, -0.35f);
	glEnd();

	//top white
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0503f, -0.55f);
	glVertex3f(0.95f, 0.0503f, -0.5f);
	glVertex3f(1.0f, 0.0503f, -0.45f);
	glEnd();

	//bottom
	glBegin(GL_TRIANGLES);
	glColor3f(0.655f, 0.655f, 0.66f);
	glVertex3f(0.0f, 0.0502f, -0.65f);
	glVertex3f(0.2f, 0.0502f, -0.5f);
	glVertex3f(0.0f, 0.0502f, -0.35f);
	glEnd();

	//bottom white
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0503f, -0.55f);
	glVertex3f(0.05f, 0.0503f, -0.5f);
	glVertex3f(0.0f, 0.0503f, -0.45f);
	glEnd();
}

void DrawTilethree() {

	glBegin(GL_QUADS);
	// bottom square
	glColor3f(0.655f, 0.655f, 0.66f);
	glVertex3f(0.95f, 0.05f, -0.5f);
	glVertex3f(0.5f, 0.05f, -0.95f);
	glVertex3f(0.05f, 0.05f, -0.5f);
	glVertex3f(0.5f, 0.05f, -0.05f);

	// top square
	glColor3f(0.369f, 0.416f, 0.470f);
	glVertex3f(0.8f, 0.0501f, -0.5f);
	glVertex3f(0.5f, 0.0501f, -0.8f);
	glVertex3f(0.2f, 0.0501f, -0.5f);
	glVertex3f(0.5f, 0.0501f, -0.2f);
	glEnd();
	threeD_drawMiniTriangles();
	threeD_drawPoly();

}

void idle(void) {
	glutPostRedisplay();
}


///holds controls defined on keyboard() to display keys to press to transform the object
void mySpecialFunction()
{

	char string[64];
	sprintf_s(string, "___________________________________________");
	printtext(220, 400, string);
	sprintf_s(string, "press [w] or [W] to move up ");
	printtext(220, 390, string);
	sprintf_s(string, "press [s] or [S] to move down ");
	printtext(220, 380, string);
	sprintf_s(string, "press [a] or [A] to move left ");
	printtext(220, 370, string);
	sprintf_s(string, "press [d] or [D] to move right ");
	printtext(220, 360, string);
	sprintf_s(string, "press [z] or [Z] to scale up ");
	printtext(220, 350, string);
	sprintf_s(string, "press [x] or [X] to scale down ");
	printtext(220, 340, string);

}

//a function to draw a cube for later on tile will be printed on it
void DrawCube() {
	// Top face (y = 1.0f)  (background)
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.049f, -1.0f);
	glVertex3f(-1.0f, 0.0495f, -1.0f);
	glVertex3f(-1.0f, 0.049f, 1.0f);
	glVertex3f(1.0f, 0.049f, 1.0f);

	// Bottom face (y = -1.0f)
	glColor3f(0.24f, 0.24f, 0.26f);
	glVertex3f(1.0f, -0.049f, 1.0f);
	glVertex3f(-1.0f, -0.049f, 1.0f);
	glVertex3f(-1.0f, -0.049f, -1.0f);
	glVertex3f(1.0f, -0.049f, -1.0f);

	// Front face  (z = 1.0f)
	glColor3f(0.24f, 0.24f, 0.26f);
	glVertex3f(1.0, 0.049f, 1.0f);
	glVertex3f(-1.0f, 0.049f, 1.0f);
	glVertex3f(-1.0f, -0.049f, 1.0f);
	glVertex3f(1.0f, -0.049f, 1.0f);

	// Back face (z = -1.0f)
	glColor3f(0.24f, 0.24f, 0.26f);
	glVertex3f(1.0f, -0.049f, -1.0f);
	glVertex3f(-1.0f, -0.049f, -1.0f);
	glVertex3f(-1.0f, 0.049f, -1.0f);
	glVertex3f(1.0f, 0.049f, -1.0f);

	// Left face (x = -1.0f)
	glColor3f(0.24f, 0.24f, 0.26f);
	glVertex3f(-1.0f, 0.049f, 1.0f);
	glVertex3f(-1.0f, 0.049f, -1.0f);
	glVertex3f(-1.0f, -0.049f, -1.0f);
	glVertex3f(-1.0f, -0.049f, 1.0f);

	// Right face (x = 1.0f)
	glColor3f(0.24f, 0.24f, 0.26f);
	glVertex3f(1.0f, 0.049f, -1.0f);
	glVertex3f(1.0f, 0.049f, 1.0f);
	glVertex3f(1.0f, -0.049f, 1.0f);
	glVertex3f(1.0f, -0.049f, -1.0f);
	glEnd();
}

void Draw(void) {


	
	glPushMatrix();

	glTranslatef(tra_x, tra_y, tra_z);

	

	displayHome();

	if (value == 1)
	{
		displayHome();
	}

	/*
		Draw the 2d floor tile one shape
	*/
	else if (value == 46) {
		glPushMatrix();

		
		glTranslatef(tra_x, tra_y, tra_z);//translate on the object in the desired direction

		glScalef(shape_size + (grow_shrink / 20), shape_size + (grow_shrink / 20), 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		char string[128];
		glColor3d(1.0, 0.0, 0.0);
		sprintf_s(string, "This is a First Tile 2d floor Design");
		printtext(200, 430, string);
		glColor3d(1.0, 1.0, 1.0);
		
		sprintf_s(string, "Press [y] or [Y]  to show Controls & [h] or [H]  to hide Controls");
		printtext(100, 410, string);

		//shows controls on the screen
		if (showControls) {
			mySpecialFunction();
		}

		glLineWidth(5);
		glPointSize(0);

		//here are colors for the tile

		double colorLightGreen[3] = { 0.76, 0.82, 0.72 };
		double colorDarkGreen[3] = { 0.44, 0.52, 0.4 };
		double colorDarkBrown[3] = { 0.35, 0.32, 0.27 };
		double colorLightBrown[3] = { 0.92, 0.86, 0.74 };


		glScalef(0.5, 0.5, 0);

		//create quadrants 
		///creates quadrant as its orignal position which is left top  (quadrant II)
		DrawTileOne();
		

		///creates quadrant translated from orignal position to bottom which is left bottom  (quadrant III)
		glTranslatef(0.0f, -0.8f, 0.0f);
		DrawTileOne();

		///creates quadrant translated from orignal position to bottom & right which is right bottom  (quadrant IV)
		glTranslatef(0.8f, 0.0f, 0.0f);
		DrawTileOne();

		///creates quadrant translated from orignal position to right which is right top  (quadrant I)
		glTranslatef(0.0f, 0.8f, 0.0f);
		DrawTileOne();



		glPopMatrix();
	}
	/*
		Draw the 2d floor deisgn two
	*/
	else if (value == 56) {
		glPushMatrix();
		glTranslatef(tra_x, tra_y, tra_z);//translate on the object in the desired direction

		glScalef(shape_size + (grow_shrink/20), shape_size + (grow_shrink/20), 0.0);
		glColor3d(1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslated(0.0, -0.5, 0.0);

		glEnable(GL_DEPTH_TEST);
		char string[128];
		sprintf_s(string, "This is a Triangle.");
		printtext(220, 430, string);

		sprintf_s(string, "Press [y] or [Y]  to show Controls & [h] or [H]  to hide Controls");
		printtext(100, 410, string);
		glLineWidth(2);
		glPointSize(0);
		


		//shows controls on the screen
		if (showControls) {
			mySpecialFunction();
		}

		glTranslatef(0, 0.5, 0);

		//create quadrants 
		///creates quadrant as its orignal position which is left top  (quadrant II)
		DrawTileTwo();

		///creates quadrant translated from orignal position to bottom which is left bottom  (quadrant III)
		glTranslatef(0.0f, -1.0f, 0.0f);
		DrawTileTwo();

		///creates quadrant translated from orignal position to bottom & right which is right bottom  (quadrant IV)
		glTranslatef(1.0f, 0.0f, 0.0f);
		DrawTileTwo();

		///creates quadrant translated from orignal position to right which is right top  (quadrant I)
		glTranslatef(0.0f, 1.0f, 0.0f);
		DrawTileTwo();

		///white-ish background
		glTranslatef(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		glColor3f(0.607f, 0.607f, 0.607f);   // White 
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(1.0f, -1.0f);
		glVertex2f(1.0f, 1.0f);
		glEnd();
		glPopMatrix();

	}
	/*
		Draw the 3d shape floor design three
	*/
	else if (value == 51) {
		glPushMatrix();
		glTranslatef(tra_x, tra_y, tra_z);//translate on the object in the desired direction

		
		glColor3d(1.0, 1.0, 1.0);
		keyRotate();
		//rotater();
		glScalef(shape_size + (grow_shrink / 20), shape_size + (grow_shrink / 20), shape_size + (grow_shrink / 20));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		char string[128];

		sprintf_s(string, "This is a 3d Floor Design.");
		printtext(220, 440, string);
		sprintf_s(string, "Press [y] or [Y]  to show Controls & [h] or [H]  to hide Controls");
		printtext(100, 430, string);

		//shows controls on the screen
		if (showControls) {
			mySpecialFunction();
			sprintf_s(string, "press [right-arrow] to rotate right ");
			printtext(220, 330, string);
			sprintf_s(string, "press [left-arrow] to rotate left ");
			printtext(220, 320, string);
			sprintf_s(string, "press [up-arrow] to rotate up ");
			printtext(220, 310, string);
			sprintf_s(string, "press [down-arrow] to rotate down ");
			printtext(220, 300, string);
		}

		glScalef(0.5, 0.5, 0.5);

		glBegin(GL_QUADS);
		// Begin drawing the color cube with 6 quads
		DrawCube();
		  // End of drawing color-cube

		DrawTilethree();

		glTranslatef(0.0f, 0.0f, 1.0f);
		DrawTilethree();

		glTranslatef(-1.0f, 0.0f, 0.0f);
		DrawTilethree();

		glTranslatef(0.0f, 0.0f, -1.0f);
		DrawTilethree();
		glPopMatrix();
	}
	
	glFlush();
}
void reshape(int w, int h) {

	glutReshapeWindow(800, 800);
	
}



//handles keyboard inputs from the user
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(1);
		break;



	case 'w':
	case 'W':
		tra_y += 0.01f;
		break;
	case 's':
	case 'S':
		tra_y -= 0.01f;
		break;
	case 'a':
	case 'A':
		tra_x -= 0.01f;
		break;
	case 'd':
	case 'D':
		tra_x += 0.01f;
		break;
	case 'u':
	case 'U':
		xrot += 1.0f;
		yrot += 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	case 'y':
	case 'Y':
		showControls = true;
		break;

	case 'h':
	case 'H':
		showControls = false;
		break;
	case 'Z':
	case 'z':
		grow_shrink--;
		break;
	case 'X':
	case 'x':
		grow_shrink++;

		break;

	}


	glutPostRedisplay();
}

void keyup(byte key, int x, int y) {
	if (key == ' ')
		autorotate = !autorotate;
}
void KeyboardFunctions(int key, int x, int y) {
	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	//  Request display update
	glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 7.0f, 1.0f, 1.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Graphics Assignment - Dawit Michael Asefa  section (A) - ID IL1425");
	createMenu();
	glClearColor(0.0, 0.0, 0.0, 0.5);
	glutSpecialFunc(KeyboardFunctions);
	glutKeyboardFunc(keyup);

	glutReshapeFunc(reshape);


	glutKeyboardFunc(keyboard);
	//glutkey

	glutDisplayFunc(Draw);

	glutIdleFunc(idle);


	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_SHADE_MODEL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glutMainLoop();
	return 1;
}
