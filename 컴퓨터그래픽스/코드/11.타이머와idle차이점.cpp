#include <GL/glut.h>
GLfloat Delta = 0.0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.8);
        glVertex3f(-1.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, 0.5, 0.0);
        glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyTimer(int Value) {
    Delta = Delta + 0.001;
    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1); //타이머는 참고로 1회용임
    //idle: 컴퓨터 성능 좋으면 빠름, 자원소모량 많음, 시간제어하려면 프로그래머가 직접 시간 계산
    //timer: 균일한 속도, 큰 시간 간격이라면 자원절약, 시간제어를 타이머함수에게 맡김

}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    //40ms의 시간이 지난 후, 내가만든 함수 호출, 1은 그냥 변수
    glutTimerFunc(40, MyTimer, 1); 
    glutMainLoop();
    return 0;
}
