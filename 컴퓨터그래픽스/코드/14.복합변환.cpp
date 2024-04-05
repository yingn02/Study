#include <GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW); // M
	glLoadIdentity(); // M = I

	//두 함수는 순서에 따라 결과가 다르다
	glTranslatef(0.6, 0.0, 0.0); // M = I * T = T
	glRotatef(45.0, 0.0, 0.0, 1.0); // M = T * R

	glutSolidCube(0.3); //T * R * P
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
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}