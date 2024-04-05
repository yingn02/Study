#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "SVec.h"
float r = 0.3;
float t = 0;
float p[3] = { 0, 2, 0 };
float v[3] = { 0, 0, 0 };
float a[3] = { 0, -3, 0 };
void MyTimer(int notUsed)
{
	float time = 0.02;
	// Forward Euler Method
	for (int i = 0; i < 3; i++)
		v[i] = v[i] + a[i] * time;
	for (int i = 0; i < 3; i++)
		p[i] = p[i] + v[i] * time;

	if (p[1] < 0.0) {
		v[1] = fabs(v[1]);
		p[1] = 0.0;
	}
	t = t + 1;
	glutPostRedisplay();
	glutTimerFunc(20, MyTimer, 1);
}
void MyDisplay() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2, 1, 8, 0, 0, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.5, 0.2, -2.5);
	glVertex3f(1.5, 0.4, -1.5);
	glVertex3f(1.5, 0.1, 1.5);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 0, -2.5);
	glVertex3f(2.5, 0, -2.5);
	glVertex3f(2.5, 0, 2.5);
	glVertex3f(-2.5, 0, 2.5);
	glEnd();

	glTranslatef(p[0], p[1], p[2]);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(r, 10, 10);

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	//벡터의 대칭이동
	//SVec a(3, 4, 5, 0);
	//SVec b(-3, 2, 1, 0);
	//b.normalize();
	//SVec c = a.projection(b);
	//SVec d = a - c;
	//SVec e = c - d;
	//
	//printf("%f %f %f\n", e.m[0], e.m[1], e.m[2]);

	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);   //GL 상태변수 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 0.1, 100);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutTimerFunc(20, MyTimer, 1);
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}