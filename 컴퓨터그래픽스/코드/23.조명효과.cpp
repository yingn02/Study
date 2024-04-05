#include <GL/glut.h>

void InitLight() {
	GLfloat MyLightPosition[] = { 1.0, 0.0, 0.0, 1.0 }; // 10, 0, 0, 1 //���� �־����� �������� ���� ����
	GLfloat MyLightDirection[] = { 3.0, 4.0, 3.0, 0.0 }; //L // 30, 40, 30, 0 //������ ������ ������, �־����ٰ� �޶���������
	GLfloat MySpotDirection[] = { -1.0, 0.0, 0.0, 0.0 };
	GLfloat MySpotAngle = 40; // 10
	glEnable(GL_LIGHTING); ////����ȿ�� Ȱ��ȭ
	glEnable(GL_LIGHT0);
	int mode = 1;
	switch (mode) {
	case 1:	// ���⼺ ����
		glLightfv(GL_LIGHT0, GL_POSITION, MyLightDirection); //���� ��İ���� �ȴ�
		break;
	case 2: // ��ġ�� ����
		glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);
		break;
	case 3: // ���� ����
		glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, MySpotDirection);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, MySpotAngle);
		break;
	}
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);    //��������
}
void InitMaterial() {
	GLfloat mAmbient[] = { 0.3, 0.3, 0.3, 1 };
	GLfloat mDiffuse[] = { 0.8, 0.8, 0.8, 1 };
	GLfloat mSpecular[] = { 0.1, 0.1, 0.1, 1 };
	GLfloat power = 25;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, power);
	glEnable(GL_NORMALIZE);
}
void MyDisplay() {                      //���÷��� �ݹ��Լ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       //GL ���º��� ����
	glShadeModel(GL_SMOOTH); // GL_FLAT, ������ ������ ������ ĥ��
	glColor3f(1, 0, 0);////������ Ȱ��ȭ�Ǹ�, ����ڰ� �ο��� glColor�� ���õ�
	//glutSolidTeapot(0.5);
	glutSolidSphere(0.5, 20, 20);
	// ���⼺ ����, MyLightDirection 8,4,1
	//glBegin(GL_TRIANGLES);
	//	glNormal3f(0.0, 0.0, 1.0);
	//	glVertex3f(0.0, 0.0, 1.0);
	//
	//	glNormal3f(0.0, 1.0, 0.0);
	//	glVertex3f(0.0, 1.0, 0.0);
	//
	//	glNormal3f(1.0, 0.0, 0.0);
	//	glVertex3f(1.0, 0.0, 0.0);
	//glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT ������ �Լ�
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Sample Drawing");

	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0, 1.0, 1.0, 1.0);   //GL ���º��� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);    //������ȯ

	InitLight();
	InitMaterial();
	glutDisplayFunc(MyDisplay);         //GLUT �ݹ��Լ� ���
	glutMainLoop();                     //�̺�Ʈ ���� ����
	return 0;
}
