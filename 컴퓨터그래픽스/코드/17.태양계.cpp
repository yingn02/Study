#include <GL/glut.h>
static int Day = 0, Time = 0;

//문제; 마젠타 색 금성 만들기

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);

	//태양그리기
	glutWireSphere(0.15, 20, 16);

	//금성 그리기
	glPushMatrix();
		glRotatef((GLfloat)Day * 2.0, 0.0, 1.0, 0.0);
		glTranslatef(0.4, 0.0, 0.0);
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
		glColor3f(1, 0, 1);
		glutWireSphere(0.08, 10, 8);
	glPopMatrix();

	//지구그리기
	glPushMatrix(); //최상단 복사해서 쌓는다
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
		glTranslatef(0.6, 0.0, 0.0);
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
		glColor3f(0.5, 0.6, 0.7);
		glutWireSphere(0.08, 10, 8);

		//달 그리기
		glPushMatrix();
			glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
			glTranslatef(0.15, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();

		//달 그리기
		glPushMatrix();
			glRotatef((GLfloat)Time * 0.5, 0.0, 1.0, 0.0);
			glTranslatef(0.25, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();

	glPopMatrix();

	//만약 여기에 달 넣으면 태양중심으로 돈다

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