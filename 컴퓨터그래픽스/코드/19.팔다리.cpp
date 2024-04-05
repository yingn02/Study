//���� �ڷ� ���̸� �ȵȴ�
//0 ~ +90 -> -1 ~ 1 *45 +45

#include <GL/glut.h>
#include <math.h>

float h = 0.25;
float a = 0.001f;
float t = 0;
GLUquadricObj* cyl;

void MyIdle()
{
	t = t + 1.0f;
	if (h <= 0.1) a = +0.0001f;
	if (h >= 0.6) a = -0.0001f;
	h = h + a;
	glutPostRedisplay();
}

void MyDisplay() {
	cyl = gluNewQuadric();
	gluQuadricDrawStyle(cyl, GLU_LINE);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(5, 0.3, 5);
	glutWireCube(0.3);
	glPopMatrix();

	//glPushMatrix();
	//glColor3f(0.0, 0.0, 1.0);
	//glTranslatef(0, h, 0);
	//glutWireSphere(0.1, 20, 20);
	//glPopMatrix();

	 //1. ����
	glPushMatrix();
	glRotatef(-90, 1, 0, 0); // -90
	// Cynliner�� +z�������� �������.
	gluCylinder(cyl, 0.1, 0.1, 0.5, 20, 5); //����� �׸���

	// 2. ��1
	glPushMatrix();
	glTranslatef(0.15, 0.0, 0.5);
	glutWireSphere(0.05, 20, 20);
	glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);
	glPopMatrix();

	// 3. ��2
	glPushMatrix();
	glTranslatef(-0.15, 0.0, 0.5);
	glutWireSphere(0.05, 20, 20);
	glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);
	glPopMatrix();

	// 4. �ٸ�1
	glPushMatrix();
	glTranslatef(0.10, 0.0, -0.01);
	glutWireSphere(0.05, 20, 20);
	glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);
	glPopMatrix();

	// 4. �ٸ�2
	glPushMatrix();
	glTranslatef(-0.10, 0.0, -0.01);
	glutWireSphere(0.05, 20, 20);
	glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
	gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);
	glPopMatrix();

	glPopMatrix(); // ���� ��

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

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-2.0, 0.6, 4, 0, 0, 0, 0, 1, 0);

	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}