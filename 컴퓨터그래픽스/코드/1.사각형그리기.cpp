#include <stdio.h>
#include <gl/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
int main(int a, char** pp) { // 강의교재와 freeglut가 다른 부분
	glutInit(&a, pp);     // 이 부분만 다르고 나머지 동일함
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(MyDisplay); ////콜백함수를 등록하는 명령, 화면을 그릴 일이생기면 내가만든 함수 호출약속, 현재 약속만 수행
	glutMainLoop(); //5장9p의 do while문 같은 것, 그려야하는 이벤트들이 발생할지 기다려서, 이벤트마다 약속대로 수행
	return 0;
}
