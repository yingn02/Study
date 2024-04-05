#include <GL/glut.h>

void MyDisplay() {                      //���÷��� �ݹ��Լ�
	glClear(GL_COLOR_BUFFER_BIT);       //GL ���º��� ����
	glViewport(0, 0, 600, 400); ////�׸��� ��ġ ������, �׸��� ������ ũ��(��������), ���ϴ��� (0,0): GL, �̰��� �Ⱦ��� �⺻������ ��ä��
	glColor3f(1.0, 1.0, 1.0); ////������ �� ���ϱ�
	glBegin(GL_POLYGON);                //�Է� �⺻��� ����
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT ������ �Լ�
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600); ////â�� ũ�⸦ (����, ����)�� ����
	glutInitWindowPosition(100, 200); ////���â�� �ߴ� ��ǥ, �»���� (0,0): GLUT
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0); ////GL ���º��� ����, Ư�������� �����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT �ݹ��Լ� ���
	glutMainLoop();                     //�̺�Ʈ ���� ����
	return 0;
}