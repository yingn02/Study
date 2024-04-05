#include <GL/glut.h>

static int SpinAngle = 0;

void InitLight() {
	GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 };     //조명 특성
	GLfloat light0_diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat material_ambient[] = { 0.4, 0.4, 0.4, 1.0 };  //물체 특성
	GLfloat material_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_SMOOTH);    //구로 셰이딩
	glEnable(GL_DEPTH_TEST);    //깊이 버퍼 활성화
	glEnable(GL_LIGHTING);      //조명 활성화
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}

void MyDisplay() {
	GLfloat LightPosition[] = { 0.0, 0.0, 1.5, 1.0 }; // 1_1. 위치를 원점(0,0,0)으로 바꾸고, 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	//glTranslatef(0.0, 0.0, -5.0); // LooAt 대신 사용. 물체를 적당히 멀리 배치함
	glPushMatrix();
	glRotatef(SpinAngle, 1.0, 0.0, 0.0);
	// 1_2. 아래 두 문장을 서로 교환하면(조명의 위치가 변경되므로) 동일한 효과를 얻는다.
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glTranslatef(0.0, 0.0, 1.5);

	// 가상적인 조명을 표시하므로, 조명자체에 조명효과를 주면 곤란함
	glDisable(GL_LIGHTING);
	glColor3f(0.9, 0.9, 0.9);
	glutWireSphere(0.06, 10, 10);	// 조명그리기
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glutSolidSphere(1.0, 100, 100);
	glPopMatrix();
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void MyMouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			SpinAngle = (SpinAngle + 15) % 360;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("openGL Sample Drawing");
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);
	glutMainLoop();
	return 0;
}