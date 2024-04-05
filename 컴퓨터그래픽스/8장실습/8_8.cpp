#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include "SVec.h"
float r = 0.3f;	// 공반지름
float p[3] = { 1, 2, -1 };	// 초기 위치
float v[3] = { 0, 0, 0 };	// 초기 속도
float a[3] = { 0, -3, 0 };	// 초기 가속도

// 삼각형의 세 점
SVec p1(-2.0, 0.2, -2.0, 1);
SVec p2(1.5, 0.3, -1.5, 1);
SVec p3(1.5, 0.1, 1.5, 1);

void MyTimer(int notUsed)
{
	SVec t1 = p2 - p1;
	SVec t2 = p3 - p1;
	SVec N = t1.cross(t2);

	float time = 0.02f;
	// Forward Euler Method
	for (int i = 0; i < 3; i++)
		v[i] = v[i] + a[i] * time;
	for (int i = 0; i < 3; i++)
		p[i] = p[i] + v[i] * time;

	SVec P(p[0], p[1], p[2], 1);
	float dist = P.distance2plane(N, p1);
	//printf("(%f %f %f %f)\t", p[0], p[1], p[2], dist);
	if (dist < r) { // hit
		SVec V(v[0], v[1], v[2], 1);
		SVec newV = V.reflection(N);
		v[0] = newV.m[0];
		v[1] = newV.m[1];
		v[2] = newV.m[2];
	}

	//if (p[1] < 0.0) {
	//	v[1] = fabs(v[1]);
	//	p[1] = 0.0;
	//}
	glutPostRedisplay();
	glutTimerFunc(20, MyTimer, 1);
}
void MyDisplay() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 2, 8, // 1,9,8
		0, 0, 0,
		0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.6, 0.2, 0.6);
	glBegin(GL_TRIANGLES);
	glVertex3fv(p1.m);
	glVertex3fv(p2.m);
	glVertex3fv(p3.m);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 0, -2.5);
	glVertex3f(2.5, 0, -2.5);
	glVertex3f(2.5, 0, 2.5);
	glVertex3f(-2.5, 0, 2.5);
	glEnd();

	glTranslatef(p[0], p[1], p[2]);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(r, 10, 10);

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	//벡터의 대칭이동
	//SVec a(3, 4, 5, 0);
	//SVec b(-3, 2, 1, 0);
	//b.normalize();
	//SVec c = a.projection(b);
	//SVec d = a - c;
	//SVec e = c - d;
	//
	//printf("%f %f %f\n", e.m[0], e.m[1], e.m[2]);

	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);   //GL 상태변수 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 0.1, 100);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutTimerFunc(20, MyTimer, 1);
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}