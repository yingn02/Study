#include <GL/glut.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    glViewport(0, 0, 600, 600);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES); //�׸����� ������
    ////������300�� �ƴ϶� ����Ʈ�� �����
    glVertex3f(TopLeftX / 600.0, (600 - TopLeftY) / 600.0, 0.0);
    //glVertex3f(TopLeftX / 600.0, (600 - BottomRightY) / 600.0, 0.0);
    glVertex3f(BottomRightX / 600.0, (600 - BottomRightY) / 600.0, 0.0);
    //glVertex3f(BottomRightX / 600.0, (600 - TopLeftY) / 600.0, 0.0);
    glEnd();
    glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //����ʹ�ư�ΰ�, �������ִ°�, ���콺��ǥ
    // ���� ��ư ���� ����, ���콺��ǥ�� ������ ��������
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        //TopLeftX = X;
        //TopLeftY = Y;
        BottomRightX = TopLeftX = X;
        BottomRightY = TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    //���� ��ǥ�� ������ �����ϰ� �ٽ� �׷��޶�� ��û
    //BottomRightX = X;
    //BottomRightY = Y;
    TopLeftX = BottomRightX; //������ ��ǥ�� �����صθ� ���󰡰��ϴ°�
    TopLeftY = BottomRightY;

    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    //���⵵ 600
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(MyDisplay);
    //Ŭ���� ������
    glutMouseFunc(MyMouseClick);
    //�巡�� ������
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}
