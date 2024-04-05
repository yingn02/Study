#include <GL/glut.h>

//��Ģ���ƴ����� ���Ǵ»��: ������Է��� ���� -> ����(����)���� ���� -> �׸��׸���
int c = 0;
float move = 0;
float gy = 0;

float cArr[4][3] = { //�̷��͵� �� �� �־��
    {0,0,0}, //��
    {1,0,0}, //��
    {1,0.5,0}, //��
    {1,1,0}, //��
};

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (c == 1)//
        glColor3f(1.0, 0.0, 0.0);
    else
        glColor3f(0.5, 0.5, 0.5);

    //glColor3f(cArr[c][0], cArr[c][1], cArr[c][2]); //�̷��͵� �� �� �־��

    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + move, -0.5 + gy, 0.0);
    glVertex3f(0.5 + move, -0.5 + gy, 0.0);
    glVertex3f(0.5 + move, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + move, 0.5 + gy, 0.0);
    glEnd();
    glFlush();
}

//Ű���尡 ������ '������' ���ŵ����� �ʴ´�
// 3���� �Ķ���Ͱ� �̸� ��ӵǾ��ִ�, ��? Ű���尡���������� ���콺 ��ǥ�� �˾ƾ��ؼ�!
void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //X,Y: Ű���尡 ���� ���� ���콺����
    switch (KeyPressed) {
    case 'a':
        c = 1;
        glutPostRedisplay(); //�׸��� �ٽ� �׸��� �̺�Ʈ�� �߻� -> Mydisplay()
        break;
    case 'b':
        c = 0;
        glutPostRedisplay(); //�׸��� �ٽ� �׸��� �̺�Ʈ�� �߻� -> Mydisplay()
        break;
    case 'c':
        if (X < 100 && Y < 100) {
            move += 0.1;
            glutPostRedisplay(); //�׸��� �ٽ� �׸��� �̺�Ʈ�� �߻� -> Mydisplay()
            break;
        }

    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:                //'esc' Ű�� �ƽ�Ű �ڵ� ��
        exit(0); break;
    }
}

void MySpecial(int KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case GLUT_KEY_UP: //UP
        gy += 0.1;
        glutPostRedisplay();
        break;
    }
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
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);//Ű���尡 ������ �������� �Լ��� ȣ������
    glutSpecialFunc(MySpecial); //Ű���尡 ������ �������� �Լ��� ȣ������ (ȭ��ǥ�� Ư�� Ű�� ���)
    glutMainLoop();
    return 0;
}
