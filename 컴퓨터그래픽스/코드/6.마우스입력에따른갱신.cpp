#include <GL/glut.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    glViewport(0, 0, 300, 300);
    glClear(GL_COLOR_BUFFER_BIT); //ȭ�������
    glColor3f(0.5, 0.5, 0.5);
    // glut: �ȼ�����(0~pixel)��(pixel = 300), gl: ��ǥ(0~1)�� ���� (���� gl -1~1 �̾��µ� ������� ����)
    // glut�� 300���� ���� 0~1 �� �ǰ���
    glBegin(GL_POLYGON); 
    glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0); //gl�� glut�� y���� �ݴ�
    glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
    glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
    glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0.0);
    glEnd();
    glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y) { //�巡���ϸ� ȣ���
    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick); //Ŭ��
    glutMotionFunc(MyMouseMove); //Ŭ�����·� �̵�
    glutMainLoop();
    return 0;
}
