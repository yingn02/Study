#include <GL/glut.h>
#include <math.h>

float a = 0.001f;
float t = 0;
GLUquadricObj* cyl;
GLint cx, cy, mx, my;
float gx = 0, gy = 0, gz = 0; //드론 키 입력

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

	 //몸통(앞)
	glPushMatrix();
		glScalef(1, 1, 1);
		glutSolidCube(0.35);

		//머리
		glPushMatrix();
			glTranslatef(0, 0.15, 0.15);
			glutSolidCube(0.25);

			//입
			glPushMatrix();
				glTranslatef(0, -0.08, 0.15);
				glutSolidCube(0.1);
			glPopMatrix();

			//귀
			glPushMatrix();
				glTranslatef(0.08, 0.12, -0.08);
				glRotatef(-90, 1, 0, 0);
				glutSolidCone(0.05,0.1,10,1);
			glPopMatrix();

			//귀2
			glPushMatrix();
				glTranslatef(-0.08, 0.12, -0.08);
				glRotatef(-90, 1, 0, 0);
				glutSolidCone(0.05, 0.1, 10, 1);
			glPopMatrix();

		glPopMatrix();

		// 다리1
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

				//발1
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// 다리2
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

				//발2
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

	//몸통(뒤)
	glPushMatrix();
		glTranslatef(0, 0, -0.35);
		glutSolidCube(0.35);

		// 다리3
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

				//발3
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// 다리4
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

				//발4
				glPushMatrix();
					glTranslatef(0, 0, 0.1);
					glutWireSphere(0.05, 20, 20);
					glRotatef(-sin(t * 0.001) * 30 - 70, 1, 0, 0);
					gluCylinder(cyl, 0.05, 0.05, 0.15, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// 꼬리
		glPushMatrix();
			glTranslatef(0, 0.35, -0.35);
			glRotatef(45, 1, 0, 0);
			gluCylinder(cyl, 0.03, 0.03, 0.3, 20, 20);
		glPopMatrix();

	glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////////////////

	//드론 본체
	glPushMatrix();
		glColor3f(0, 1, 1);
		glTranslatef(gx, gy, gz); //드론 이동의 핵심

		//몸통
		for (float i = 2.2; i <= 2.5; i += 0.1) {
			for (float j = 0.0; j <= 0.4; j+=0.1) {
				glPushMatrix();
					glTranslatef(j, 1, i);
					glutSolidCube(0.1);
				glPopMatrix();
			}
		}


		glColor3f(0, 0, 1);
		//모터1
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

		//모터2
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

		//모터3
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

		//모터4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//모터4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 90, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//모터4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 180, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//모터4
		glPushMatrix();
			glTranslatef(0.3, 1.1, 2.5);
			glRotatef(t + 0.001 + 270, 0, 1, 0);
			glutWireSphere(0.01, 20, 20);
			gluCylinder(cyl, 0.01, 0.01, 0.1, 20, 20);
		glPopMatrix();

		//다리
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

		//다리2
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

void MyMouseMove(GLint X, GLint Y) { //드래그하면 호출됨
	mx = X;
	my = Y;

	float xAngle = 0.0f; // x축 회전
	float yAngle = 0.0f; // y축 회전

	float dx = mx - cx; //newx-oldx
	float dy = my - cy; //newy-oldy

	xAngle += dx * 0.1f; // x축 변화값
	yAngle += dy * 0.1f; // y축 변화값

	glLoadIdentity();
	gluLookAt(-15, 1, 1, 0, 1, 1, 0, 1, 0);
	glRotatef(xAngle, 0.0f, 1.0f, 0.0f); // y축 회전
	glRotatef(yAngle, 1.0f, 0.0f, 0.0f); // x축 회전

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
	glutMouseFunc(MyMouseClick); //클릭
	glutMotionFunc(MyMouseMove); //클릭상태로 이동
	glutTimerFunc(1, MyTimer, 1);
	glutMainLoop();
	return 0;
}