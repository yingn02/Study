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
int main(int a, char** pp) { // ���Ǳ���� freeglut�� �ٸ� �κ�
	glutInit(&a, pp);     // �� �κи� �ٸ��� ������ ������
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
