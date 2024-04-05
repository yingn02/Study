#include <GL/glut.h>

void MyDisplay() {                      //디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW); //지금부터 행렬 조작을 할건데, gl내부의 model행렬 에 반영해라
	glLoadIdentity(); //현재 행렬을 단위행렬로 초기화
	glTranslatef(0.6, 0.0, 0.0); //d가 0인데 0.6만큼 이동했다 //x,y,z 이동에 대한 행렬 생성하고 이를 현재행렬에 반영하라
	glRotatef(45.0, 0.0, 0.0, 1.0); //z축으로 45도 회전

	//복합변환의 예: glTranslatef 와 glRotatef 둘 다 적용

	float d = 0.0;

	glBegin(GL_POLYGON);                //입력 기본요소 정의
	glVertex3f(-0.5 + d, -0.5, 0.0);
	glVertex3f(0.5 + d, -0.5, 0.0);
	glVertex3f(0.5 + d, 0.5, 0.0);
	glVertex3f(-0.5 + d, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0);   //GL 상태변수 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}