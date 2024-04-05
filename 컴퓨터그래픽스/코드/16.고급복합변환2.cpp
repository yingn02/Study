#include <GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	glColor3f(1.0, 0.0, 0.0);

	//점 기준으로 회전이 먼저, 이후 평행이동, 행렬과 코드의 순서는 반대라는거임 그냥

	glMatrixMode(GL_MODELVIEW); //앞으로 다루는 행렬함수는 modelview 변수에 조작해줘
	glLoadIdentity(); //그 행렬을 단위행렬로 초기화해줘

	//순서바꾸면 결과가 다른 이유를 말하시오
	glTranslatef(0.6, 0.0, 0.0); //그 행렬에 평행이동 행렬 만들어서 '곱해줘'
	glRotatef(45.0, 0.0, 0.0, 1.0); //그 행렬애 회전이동 행렬 만들어서 '곱해줘', 회전중심은 원점, 축은 z
	//회전이동 2차원까지만 암기

	glutSolidCube(0.3); //그 행렬에 곱하면서, 육면체 그려줘
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