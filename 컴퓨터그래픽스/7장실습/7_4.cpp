#include <GL/glut.h>
#include <math.h>
#include "Camera.h"

Camera cam;

float h = 0.25;
float a = 0.01f; // 초기 속도
float t = 0;

void MyTimer(int n)
{
	t = t + 1;
	if (h <= 0.25) a = +0.01f; // 속도 증가
	if (h >= 0.75) a = -0.01f; // 속도 감소
	h = h + a; // 위치 이동
	glutTimerFunc(40, MyTimer, 1);
	glutPostRedisplay();

}
void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed) {
	case 'w':
		cam.pitch(-0.5);
		break;
	case 's':
		cam.pitch(+0.5);
		break;
	case 'a':
		cam.yaw(-0.5);
		break;
	case 'd':
		cam.yaw(+0.5);
		break;
	case 'q':
		cam.roll(-0.5);
		break;
	case 'e':
		cam.roll(+0.5);
		break;


	case 'i':
		cam.slide(0, 0.1f, 0);
		break;
	case 'k':
		cam.slide(0, -0.1f, 0);
		break;

	case 'j':
		cam.slide(-0.1f, 0, 0);
		break;

	case 'l':
		cam.slide(0.1f, 0, 0);
		break;

	case '[':
		cam.slide(0, 0, 0.1f);
		break;

	case ']':
		cam.slide(0, 0, -0.1f);
		break;

	}
	glutPostRedisplay();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(5, 0.3f, 5);
	glutWireCube(0.3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0, h, 0);
	glutWireSphere(0.2, 20, 20);
	glPopMatrix();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(20, 1, 0.1, 1000);

	// gluLookAt을 대신하는 클래스 구현
	cam.set(0, 3, 4, 0, 0, 0, 0, 1, 0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}