#include <GL/glut.h>

//법칙은아니지만 통용되는상식: 사용자입력이 오면 -> 전역(상태)변수 변경 -> 그림그리기
int c = 0;
float move = 0;
float gy = 0;

float cArr[4][3] = { //이런것도 쓸 수 있어요
    {0,0,0}, //검
    {1,0,0}, //빨
    {1,0.5,0}, //주
    {1,1,0}, //노
};

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (c == 1)//
        glColor3f(1.0, 0.0, 0.0);
    else
        glColor3f(0.5, 0.5, 0.5);

    //glColor3f(cArr[c][0], cArr[c][1], cArr[c][2]); //이런것도 쓸 수 있어요

    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + move, -0.5 + gy, 0.0);
    glVertex3f(0.5 + move, -0.5 + gy, 0.0);
    glVertex3f(0.5 + move, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + move, 0.5 + gy, 0.0);
    glEnd();
    glFlush();
}

//키보드가 눌려도 '저절로' 갱신되지는 않는다
// 3개의 파라미터가 미리 약속되어있다, 왜? 키보드가눌렸을때의 마우스 좌표를 알아야해서!
void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //X,Y: 키보드가 눌릴 때의 마우스좌쵸
    switch (KeyPressed) {
    case 'a':
        c = 1;
        glutPostRedisplay(); //그림을 다시 그리는 이벤트를 발생 -> Mydisplay()
        break;
    case 'b':
        c = 0;
        glutPostRedisplay(); //그림을 다시 그리는 이벤트를 발생 -> Mydisplay()
        break;
    case 'c':
        if (X < 100 && Y < 100) {
            move += 0.1;
            glutPostRedisplay(); //그림을 다시 그리는 이벤트를 발생 -> Mydisplay()
            break;
        }

    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:                //'esc' 키의 아스키 코드 값
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
    glutKeyboardFunc(MyKeyboard);//키보드가 눌리면 내가만든 함수를 호출해줘
    glutSpecialFunc(MySpecial); //키보드가 눌리면 내가만든 함수를 호출해줘 (화살표등 특수 키의 경우)
    glutMainLoop();
    return 0;
}
