#include <GL/glut.h>
GLboolean IsSphere = true; //공을 그릴것인가

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.0, 0.5);
    //Wire 대신 Solid로 함수이름 바꾸면 선들이 가득차서 면이됨
    if (IsSphere)
        //와이어로 된 구 (반지름, 경도, 위도)
        glutWireSphere(0.5, 15, 30); 
    else
        //와이어로 된 토러스 (도넛 굵기, 도넛 크기, 경도, 위도)
        glutWireTorus(0.1, 0.3, 40, 20); 
    glFlush();
}

//사용자가 선택한 메뉴를 이용하기
void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = true; //공을 그릴것인가
    else if (entryID == 2)
        IsSphere = false; //공을 그릴것인가
    else if (entryID == 3)
        exit(0);
    glutPostRedisplay(); //그림을 다시 그리시오
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

    //메뉴 만들어 등록하기
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //메뉴가 눌리면 함수호출 약속
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); //지금까지 만든 메뉴를 오른쪽에 붙여라
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
