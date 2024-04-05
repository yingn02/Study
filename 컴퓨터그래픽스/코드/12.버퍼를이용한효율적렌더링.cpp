#include <GL/glut.h>
GLfloat MyVertices[8][3] = { //육면체를 위한 점 8개
	{ -0.25, -0.25, 0.25 },
	{ -0.25, 0.25, 0.25 },
	{ 0.25, 0.25, 0.25 },
	{ 0.25, -0.25, 0.25 },
	{ -0.25, -0.25, -0.25 },
	{ -0.25, 0.25, -0.25 },
	{ 0.25, 0.25, -0.25 },
	{ 0.25, -0.25, -0.25 }
};
GLfloat MyColors[8][3] = { //육면체를 위한 색 8가지
	{ 0.2, 0.2, 0.2 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};
GLubyte MyVertexList[24] = { //육면체를 위한 사각형 6개의 인덱스
	0, 3, 2, 1,
	2, 3, 7, 6,
	0, 4, 7, 3,
	1, 2, 6, 5,
	4, 5, 6, 7,
	0, 1, 5, 4
};

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW); // 깊이검사(8장)를 하지 않고, front face사용
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY); //컬러에 대해 배열을 쓸거다 선언
	glEnableClientState(GL_VERTEX_ARRAY);//정점에 대해 배열을 쓸거다 선언
	glColorPointer(3, GL_FLOAT, 0, MyColors);//아래와 같은 의미
	glVertexPointer(3, GL_FLOAT, 0, MyVertices); //정점들이 있는 포인터 지정 size는 xyz 3개
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(30.0, 1.0, 1.0, 1.0);

	//glDrawElements: 요소를 그려라, GL_POLYGON 으로 그려라
	//&MyVertexList[4 * i] 이걸 이용해 그려라(시작점?) count 4는 4개를 묶어서 그리란뜻
	for (GLint i = 0; i < 6; i++)
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
//만약 사면체를 그린다면?