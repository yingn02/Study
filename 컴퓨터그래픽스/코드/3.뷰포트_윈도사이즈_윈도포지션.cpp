#include <GL/glut.h>

void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	glViewport(0, 0, 600, 400); ////네모의 위치 시작점, 그리는 공간의 크기(강제변경), 좌하단이 (0,0): GL, 이것을 안쓰면 기본적으로 꽉채움
	glColor3f(1.0, 1.0, 1.0); ////도형의 색 정하기
	glBegin(GL_POLYGON);                //입력 기본요소 정의
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600); ////창의 크기를 (가로, 세로)로 설정
	glutInitWindowPosition(100, 200); ////결과창이 뜨는 좌표, 좌상단이 (0,0): GLUT
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0); ////GL 상태변수 설정, 특정색으로 지우기
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}