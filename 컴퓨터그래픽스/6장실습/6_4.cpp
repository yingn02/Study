#include <GL/glut.h>
int angle = 0;
int mode = 1;
void MyIdle()
{
	angle++;
	glutPostRedisplay();
}
void MyKeyboard(unsigned char ch, int x, int y) {
	if (ch == 'q') exit(0);
	if (ch == '1') mode = 1;
	if (ch == '2') mode = 2;
	if (ch == '3') mode = 3;
	glutPostRedisplay();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (mode) {
	case 1: // ��ü ���� ������ ���
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(0.6 - 0.15, 0.4 - 0.15, 0.0);	// 3. ȸ�� �߽��� ���ϴ� ������ �̵�
		glRotatef(angle*0.05f, 0.0, 0.0, 1.0); // 2. ȸ��
		glTranslatef(0.15, 0.15, 0.0);	// 1. ȸ�� �߽��� �������� �̵�
		break;
	case 2: // ��ǥ�� ���� ����
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0.6, 0.4, 0.0);	// 1. ��ǥ�踦 �̵� 
		glTranslatef((-0.15), (-0.15), 0.0);	// 2. ȸ�� �߽��� ��ü ��ǥ�� ������ �ǵ��� �߰� �̵�
		glRotatef(angle*0.05f, 0.0, 0.0, 1.0); // 3. �Ǻ� �̵����� ȸ��
		glTranslatef(0.15, 0.15, 0.0);	// 4. ȸ������� ����ġ(��ǥ�谡 �̹� ȸ���Ǿ� �����Ƿ�, ���ϴ��� ȸ�� ���� ��ġ�� ������)
		break;
	case 3: // ��ü ���� ������ ���(���ϴ��� ������ǥ�� 0.45, 0.25���� �̿�)
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef((0.6 - 0.15), (0.4 - 0.15), 0.0);	// 4. �Ǻ�ȸ�� 3�ܰ�, �� �ڸ��� ����
		glRotatef(angle*0.05f, 0.0, 0.0, 1.0);	// 3. �Ǻ�ȸ�� 2�ܰ�, ���� ȸ��
		glTranslatef(-(0.6 - 0.15), -(0.4 - 0.15), 0.0); // 2. �Ǻ�ȸ�� 1�ܰ�, �Ǻ��� ������
		glTranslatef(0.6, 0.4, 0.0); // 1. �����δ�.
		break;
	}
	glutSolidCube(0.3);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutIdleFunc(MyIdle);

	glutMainLoop();
	return 0;
}