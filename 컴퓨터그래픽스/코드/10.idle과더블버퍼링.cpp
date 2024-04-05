#include <GL/glut.h>
GLfloat Delta = 0.0;

void MyDisplay() { //���÷��� �ݹ��Լ�
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.8);
        glVertex3f(-1.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, 0.5, 0.0);
        glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    //glFlush(); //single ���۸�
    glutSwapBuffers(); //double ���۸�
}

void MyIdle() {
    Delta = Delta + 0.001;
    glutPostRedisplay(); //�׸��ٽ� �׷���
}

int main(int argc, char** argv) {
    glutInit(&argc,argv); //GLUT ������ �Լ�
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //������۸�, | GLUT_DOUBLE
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    //�ݹ��Լ��� ������ �ƹ��ϵ� �����ʰ�, �ƹ��ϵ� ���� ������ Idle �Լ� ON
    glutIdleFunc(MyIdle); //��ǻ�Ͱ� �ƹ��ϵ� ���������� Idle ȣ������
    glutMainLoop(); 
    return 0;
}
