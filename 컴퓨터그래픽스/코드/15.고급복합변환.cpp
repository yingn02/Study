#include <GL/glut.h>

float r = 0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// 피봇(특별한 기준점 중심) 회전
	glTranslatef(-0.15, -0.15, -0.15); // 3 (0,0,0) -> (-0.15,-0.15,-0.15)
	glRotatef(r, 0.0, 0.0, 1.0); // 2
	glTranslatef(-0.15, -0.15, -0.15); // 1 (-0.15,-0.15,-0.15) -> (0,0,0)

	glutSolidCube(0.3);
	glFlush();
}

void MyIdle() {
	r += 3.0;
	glutPostRedisplay();
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
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutIdleFunc(MyIdle);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}