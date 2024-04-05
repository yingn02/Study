#include <GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	glColor3f(1.0, 0.0, 0.0);

	//�� �������� ȸ���� ����, ���� �����̵�, ��İ� �ڵ��� ������ �ݴ��°��� �׳�

	glMatrixMode(GL_MODELVIEW); //������ �ٷ�� ����Լ��� modelview ������ ��������
	glLoadIdentity(); //�� ����� ������ķ� �ʱ�ȭ����

	//�����ٲٸ� ����� �ٸ� ������ ���Ͻÿ�
	glTranslatef(0.6, 0.0, 0.0); //�� ��Ŀ� �����̵� ��� ���� '������'
	glRotatef(45.0, 0.0, 0.0, 1.0); //�� ��ľ� ȸ���̵� ��� ���� '������', ȸ���߽��� ����, ���� z
	//ȸ���̵� 2���������� �ϱ�

	glutSolidCube(0.3); //�� ��Ŀ� ���ϸ鼭, ����ü �׷���
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