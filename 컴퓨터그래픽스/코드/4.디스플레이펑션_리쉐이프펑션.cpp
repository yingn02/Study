#include <GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);       //�÷����ۿ� �ʱ�ȭ ���� ����
	glColor3f(0.5, 0.5, 0.5); //��ü�� ȸ��
	glBegin(GL_POLYGON);                //�ٰ����� �׸��ڴ� (�簢��)
	//vertex : ������, ����
	glVertex3f(-0.5, -0.5, 0.0);    //���ϴ� ��ǥ
	glVertex3f(0.5, -0.5, 0.0);     //���ϴ� ��ǥ
	glVertex3f(0.5, 0.5, 0.0);      //���� ��ǥ
	glVertex3f(-0.5, 0.5, 0.0);     //�»�� ��ǥ
	glEnd();
	glFlush(); //������� �ԷµǾ��ִ� ��� �������� ��ɾ ��������
}
void MyReshape(int NewWidth, int NewHeight) { ////���� �� ���󵵵�, NewWidth, NewHeight�� �����ΰ�? ���ιٲ� â�� ũ���Դϴ�.
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);               //GLUT ������ �Լ�
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);   //�ʱ�ȭ ���� ���, ������� �����
	glutDisplayFunc(MyDisplay); ////ȭ���� �׸� ���̻���� �������� �Լ� ȣ����
	glutReshapeFunc(MyReshape); ////(�ٽ�) âũ�� ����Ǹ� �������� �Լ� ȣ����
	glutMainLoop();
	return 0;
}
