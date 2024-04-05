#include <GL/glut.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    glViewport(0, 0, 600, 600);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES); //그림판을 만들어보자
    ////무조건300이 아니라 뷰포트에 맞춘것
    glVertex3f(TopLeftX / 600.0, (600 - TopLeftY) / 600.0, 0.0);
    //glVertex3f(TopLeftX / 600.0, (600 - BottomRightY) / 600.0, 0.0);
    glVertex3f(BottomRightX / 600.0, (600 - BottomRightY) / 600.0, 0.0);
    //glVertex3f(BottomRightX / 600.0, (600 - TopLeftY) / 600.0, 0.0);
    glEnd();
    glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //어느쪽버튼인가, 눌려져있는가, 마우스좌표
    // 왼쪽 버튼 눌린 순간, 마우스좌표를 전역에 저장하자
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        //TopLeftX = X;
        //TopLeftY = Y;
        BottomRightX = TopLeftX = X;
        BottomRightY = TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    //현재 좌표를 전역에 저장하고 다시 그려달라고 요청
    //BottomRightX = X;
    //BottomRightY = Y;
    TopLeftX = BottomRightX; //직전의 좌표를 저장해두며 따라가게하는것
    TopLeftY = BottomRightY;

    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    //여기도 600
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(MyDisplay);
    //클릭이 있을때
    glutMouseFunc(MyMouseClick);
    //드래그 있을때
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}
