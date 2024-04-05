#include <GL/glut.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    glViewport(0, 0, 300, 300);
    glClear(GL_COLOR_BUFFER_BIT); //화면지우기
    glColor3f(0.5, 0.5, 0.5);
    // glut: 픽셀개수(0~pixel)를(pixel = 300), gl: 좌표(0~1)로 변경 (원래 gl -1~1 이었는데 계산위해 변경)
    // glut를 300으로 나눠 0~1 이 되게함
    glBegin(GL_POLYGON); 
    glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0); //gl과 glut은 y방향 반대
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

void MyMouseMove(GLint X, GLint Y) { //드래그하면 호출됨
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
    glutMouseFunc(MyMouseClick); //클릭
    glutMotionFunc(MyMouseMove); //클릭상태로 이동
    glutMainLoop();
    return 0;
}
