#include <GL/glut.h>
GLboolean IsSphere = true; //���� �׸����ΰ�

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5);
    //Wire ��� Solid�� �Լ��̸� �ٲٸ� ������ �������� ���̵�
    if (IsSphere)
        //���̾�� �� �� (������, �浵, ����)
        glutWireSphere(0.5, 15, 30); 
    else
        //���̾�� �� �䷯�� (���� ����, ���� ũ��, �浵, ����)
        glutWireTorus(0.1, 0.3, 40, 20); 
    glFlush();
}

//����ڰ� ������ �޴��� �̿��ϱ�
void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = true; //���� �׸����ΰ�
    else if (entryID == 2)
        IsSphere = false; //���� �׸����ΰ�
    else if (entryID == 3)
        exit(0);
    glutPostRedisplay(); //�׸��� �ٽ� �׸��ÿ�
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Example Drawing");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    //�޴� ����� ����ϱ�
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //�޴��� ������ �Լ�ȣ�� ���
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); //���ݱ��� ���� �޴��� �����ʿ� �ٿ���
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
