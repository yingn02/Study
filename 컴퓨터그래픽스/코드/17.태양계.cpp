#include <GL/glut.h>
static int Day = 0, Time = 0;

//����; ����Ÿ �� �ݼ� �����

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);

	//�¾�׸���
	glutWireSphere(0.15, 20, 16);

	//�ݼ� �׸���
	glPushMatrix();
		glRotatef((GLfloat)Day * 2.0, 0.0, 1.0, 0.0);
		glTranslatef(0.4, 0.0, 0.0);
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
		glColor3f(1, 0, 1);
		glutWireSphere(0.08, 10, 8);
	glPopMatrix();

	//�����׸���
	glPushMatrix(); //�ֻ�� �����ؼ� �״´�
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
		glTranslatef(0.6, 0.0, 0.0);
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
		glColor3f(0.5, 0.6, 0.7);
		glutWireSphere(0.08, 10, 8);

		//�� �׸���
		glPushMatrix();
			glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
			glTranslatef(0.15, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();

		//�� �׸���
		glPushMatrix();
			glRotatef((GLfloat)Time * 0.5, 0.0, 1.0, 0.0);
			glTranslatef(0.25, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();

	glPopMatrix();

	//���� ���⿡ �� ������ �¾��߽����� ����

	glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':
		Day = (Day + 10) % 360;
		glutPostRedisplay();
		break;
	case 't':
		Time = (Time + 5) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void MyTimer(int v) {
	Day++; Time++;
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutTimerFunc(40, MyTimer, 1);
	glutMainLoop();
	return 0;
}