#include <stdio.h>
#include <gl/glut.h>
#include <math.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	//glVertex3f(-0.5, -0.5, 0.0);
	//glVertex3f(0.5, -0.5, 0.0);
	//glVertex3f(0.5, 0.5, 0.0);
	//glVertex3f(-0.5, 0.5, 0.0);
	double r = 0.5;

	for (int i = 0;i < 36;i++)
	{
		double angle = i * 3.141592 / 180 * 10; ////
		double x = r * cos(angle);
		double y = r * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}
int main(int a, char** pp) { // 강의교재와 freeglut가 다른 부분
	glutInit(&a, pp);     // 이 부분만 다르고 나머지 동일함
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
