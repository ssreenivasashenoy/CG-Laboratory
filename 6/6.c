#include <stdio.h>
#include <GL/glut.h>
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6, 6, -6, 6, -12, 12);
	glMatrixMode(GL_MODELVIEW);
}
void wall()
{
	glPushMatrix();
	glTranslatef(-2, 2, 0);
	glScalef(0.05, 2, 2);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 0.05, 2);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2, -2);
	glScalef(2, 2, 0.05);
	glutSolidCube(2);
	glPopMatrix();
}
void table()
{
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(1, 0.05, 1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, 0.2, 0.8);
	glScalef(0.1, 0.25, 0.1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 0.2, 0.8);
	glScalef(0.1, 0.25, 0.1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 0.2, -0.8);
	glScalef(0.1, 0.25, 0.1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, 0.2, -0.8);
	glScalef(0.1, 0.25, 0.1);
	glutSolidCube(2);
	glPopMatrix();
}
void tea()
{
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glutSolidTeapot(0.5);
	glPopMatrix();
}
void display(void)
{
	float amb[] = {1, 1, 0, 1};
	float pos[] = {4, 8, 4, 0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	gluLookAt(4, 1, 4, 1, 0, 1, 0, 1, 0);
	wall();
	table();
	tea();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Teapot");
	init();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glutMainLoop();
}