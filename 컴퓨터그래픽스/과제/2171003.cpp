#include <GL/glut.h>
#include <math.h>

float a = 0.001f;
float t = 0;
GLUquadricObj* cyl;
GLint cx, cy, mx, my;
float gx = 0, gy = 0, gz = 0; //��� Ű �Է�

void MyTimer(int Value) {
	t = t + 1.0f;

	glutPostRedisplay();
	glutTimerFunc(1, MyTimer, 1);
}

void MyDisplay() {
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.6, 0.1, 0.1);

	 //����(��)
	glPushMatrix();
		glScalef(1, 1, 1);
		glutSolidCube(0.35);

		//�Ӹ�
		glPushMatrix();
			glTranslatef(0, 0.15, 0.15);
			glutSolidCube(0.25);

			//��
			glPushMatrix();
				glTranslatef(0, -0.08, 0.15);
				glutSolidCube(0.1);
			glPopMatrix();

			//��
			glPushMatrix();
				glTranslatef(0.08, 0.12, -0.08);
				glRotatef(-90, 1, 0, 0);
				glutSolidCone(0.05,0.1,10,1);
			glPopMatrix();

			//��2
			glPushMatrix();
				glTranslatef(-0.08, 0.12, -0.08);
				glRotatef(-90, 1, 0, 0);
				glutSolidCone(0.05, 0.1, 10, 1);
			glPopMatrix();

		glPopMatrix();

		// �ٸ�1
		glPushMatrix();
			glTranslatef(0.12, -0.12, 0.1);
			glutWireSphere(0.07, 20, 20);
			glRotatef(sin(t * 0.001) * 15 + 60, 1, 0, 0);
			gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

			glPushMatrix();
				glTranslatef(0, 0, 0.1);
				glutWireSphere(0.07, 20, 20);
				glRotatef(sin(t * 0.001) * 5 + 15, 1, 0, 0);
				gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

				//��1
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// �ٸ�2
		glPushMatrix();
			glTranslatef(-0.12, -0.12, 0.1);
			glutWireSphere(0.07, 20, 20);
			glRotatef(-sin(t * 0.001) * 15 + 60, 1, 0, 0);
			gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

			glPushMatrix();
				glTranslatef(0, 0, 0.1);
				glutWireSphere(0.07, 20, 20);
				glRotatef(-sin(t * 0.001) * 5 + 15, 1, 0, 0);
				gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

				//��2
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix(); 

///////////////////////////////////////////////////////////////////////////////////////////////////////

	//����(��)
	glPushMatrix();
		glTranslatef(0, 0, -0.35);
		glutSolidCube(0.35);

		// �ٸ�3
		glPushMatrix();
			glTranslatef(0.10, -0.12, -0.1);
			glutWireSphere(0.07, 20, 20);
			glRotatef(-sin(t * 0.001) * 15 + 100, 1, 0, 0);
			gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

			glPushMatrix();
				glTranslatef(0, 0, 0.1);
				glutWireSphere(0.07, 20, 20);
				glRotatef(-sin(t * 0.001) * 15 + 15, 1, 0, 0);
				gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

				//��3
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// �ٸ�4
		glPushMatrix();
			glTranslatef(-0.10, -0.12, -0.1);
			glutWireSphere(0.07, 20, 20);
			glRotatef(sin(t * 0.001) * 15 + 100, 1, 0, 0);
			gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

			glPushMatrix();
				glTranslatef(0, 0, 0.1);
				glutWireSphere(0.07, 20, 20);
				glRotatef(sin(t * 0.001) * 15 + 15, 1, 0, 0);
				gluCylinder(cyl, 0.07, 0.07, 0.15, 20, 20);

				//��4
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// ����
		glPushMatrix();
			glTranslatef(0, 0.35, -0.35);
			glRotatef(45, 1, 0, 0);
			gluCylinder(cyl, 0.03, 0.03, 0.3, 20, 20);
		glPopMatrix();

	glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////////////////

	//��� ��ü
	glPushMatrix();
		glColor3f(0, 1, 1);
		glTranslatef(gx, gy, gz); //��� �̵��� �ٽ�

		//����
		for (float i = 2.2; i <= 2.5; i += 0.1) {
			for (float j = 0.0; j <= 0.4; j+=0.1) {
				glPushMatrix();
					glTranslatef(j, 1, i);
					glutSolidCube(0.1);
				glPopMatrix();
			}
		}


		glColor3f(0, 0, 1);
		//����1
		glPushMatrix();
			glTranslatef(0, 1.1, 2.2);
			glRotatef(t+0.001, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.2);
			glRotatef(t+0.001 + 90, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.2);
			glRotatef(t + 0.001 + 180, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.2);
			glRotatef(t + 0.001 + 270, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����2
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.2);
			glRotatef(t + 0.001, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.2);
			glRotatef(t + 0.001 + 90, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.2);
			glRotatef(t + 0.001 + 180, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.2);
			glRotatef(t + 0.001 + 270, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����3
		glPushMatrix();
			glTranslatef(0, 1.1, 2.5);
			glRotatef(t + 0.001, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.5);
			glRotatef(t + 0.001 + 90, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.5);
			glRotatef(t + 0.001 + 180, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.5);
			glRotatef(t + 0.001 + 270, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 90, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 180, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//����4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 270, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//�ٸ�
		glPushMatrix();
			glTranslatef(0, 1.1, 2.2);
			glRotatef(90, 1, 0, 0);
			gluCylinder(cyl, 0.01, 0.01, 0.2, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.2);
			glRotatef(90, 1, 0, 0);
			gluCylinder(cyl, 0.01, 0.01, 0.2, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.1, 2.5);
			glRotatef(90, 1, 0, 0);
			gluCylinder(cyl, 0.01, 0.01, 0.2, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(90, 1, 0, 0);
			gluCylinder(cyl, 0.01, 0.01, 0.2, 20, 20);
		glPopMatrix();

		//�ٸ�2
		glPushMatrix();
			glTranslatef(0, 0.9, 2.15);
			gluCylinder(cyl, 0.01, 0.01, 0.4, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.3, 0.9, 2.15);
			gluCylinder(cyl, 0.01, 0.01, 0.4, 20, 20);
		glPopMatrix();

	glPopMatrix();

	glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		cx = X;
		cy = Y;
	}
}

void MyMouseMove(GLint X, GLint Y) { //�巡���ϸ� ȣ���
	mx = X;
	my = Y;

	float xAngle = 0.0f; // x�� ȸ��
	float yAngle = 0.0f; // y�� ȸ��

	float dx = mx - cx; //newx-oldx
	float dy = my - cy; //newy-oldy

	xAngle += dx * 0.1f; // x�� ��ȭ��
	yAngle += dy * 0.1f; // y�� ��ȭ��

	glLoadIdentity();
	gluLookAt(-15, 1, 1, 0, 1, 1, 0, 1, 0);
	glRotatef(xAngle, 0.0f, 1.0f, 0.0f); // y�� ȸ��
	glRotatef(yAngle, 1.0f, 0.0f, 0.0f); // x�� ȸ��

	glutPostRedisplay();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'w':
	case 'W':
		gz += 0.01;
		glutPostRedisplay();
		break;
	case 'a':
	case 'A':
		gx += 0.01;
		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		gz -= 0.01;
		glutPostRedisplay();
		break;

	case 'd':
	case 'D':
		gx -= 0.01;
		glutPostRedisplay(); 
		break;

	}
}

void MySpecial(int KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case GLUT_KEY_UP: //up
		gy += 0.01;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN: //down
		gy -= 0.01;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(15, 1.5, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-15, 1, 1, 0, 1, 1, 0, 1, 0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouseClick); //Ŭ��
	glutMotionFunc(MyMouseMove); //Ŭ�����·� �̵�
	glutTimerFunc(1, MyTimer, 1);
	glutMainLoop();
	return 0;
}