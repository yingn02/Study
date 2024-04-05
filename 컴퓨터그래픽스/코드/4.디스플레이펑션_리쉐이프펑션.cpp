#include <GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);       //컬러버퍼에 초기화 색을 가함
	glColor3f(0.5, 0.5, 0.5); //물체는 회색
	glBegin(GL_POLYGON);                //다각형을 그리겠다 (사각형)
	//vertex : 꼭짓점, 정점
	glVertex3f(-0.5, -0.5, 0.0);    //좌하단 좌표
	glVertex3f(0.5, -0.5, 0.0);     //좌하단 좌표
	glVertex3f(0.5, 0.5, 0.0);      //우상단 좌표
	glVertex3f(-0.5, 0.5, 0.0);     //좌상단 좌표
	glEnd();
	glFlush(); //현재까지 입력되어있는 모든 오픈지엘 명령어를 실행해줘
}
void MyReshape(int NewWidth, int NewHeight) { ////아직 잘 몰라도됨, NewWidth, NewHeight가 무엇인가? 새로바뀐 창의 크기입니다.
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);   //초기화 색은 백색, 흰색으로 지운다
	glutDisplayFunc(MyDisplay); ////화면을 그릴 일이생기면 내가만든 함수 호출약속
	glutReshapeFunc(MyReshape); ////(핵심) 창크기 변경되면 내가만든 함수 호출약속
	glutMainLoop();
	return 0;
}
