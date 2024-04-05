#include <GL/glut.h>
GLfloat Delta = 0.0;

void MyDisplay() { //디스플레이 콜백함수
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.8);
        glVertex3f(-1.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, 0.5, 0.0);
        glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    //glFlush(); //single 버퍼링
    glutSwapBuffers(); //double 버퍼링
}

void MyIdle() {
    Delta = Delta + 0.001;
    glutPostRedisplay(); //그림다시 그려줘
}

int main(int argc, char** argv) {
    glutInit(&argc,argv); //GLUT 윈도우 함수
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //더블버퍼링, | GLUT_DOUBLE
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    //콜백함수가 없으면 아무일도 하지않고, 아무일도 하지 않으면 Idle 함수 ON
    glutIdleFunc(MyIdle); //컴퓨터가 아무일도 하지않으면 Idle 호출해줘
    glutMainLoop(); 
    return 0;
}
