#include "Primitives.h"
#include <glut.h>

line L;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // ������� ������
    glLoadIdentity(); // ����� ���������
    glOrtho(-5, 5, -5, 5, -1, 1);  //������������ �����
 
    L.print();
    L.rotate(10);

    glutSwapBuffers();
}

void timer(int = 0)
{
    display();
    glutTimerFunc(1000, timer, 0);
}

void glutStdStart(int argc, char** argv) // you must have display func "display(void)" and timer func "timer(int = 0)"
{  
    glutInit(&argc, argv);  // window init
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Primitives");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glutDisplayFunc(display);
    timer(0);
}

int main(int argc, char** argv) {
    glutStdStart(argc, argv);
    L.moveBy(0, 2);
    glutMainLoop();
};