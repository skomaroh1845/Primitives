#include "Primitives.h"
#include <glut.h>

triangle Tr(T(), 0.5, 0, 0.7, 0.1);

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
    glLoadIdentity(); // Сброс просмотра
    glOrtho(-5, 5, -5, 5, -1, 1);  //координатная сетка
 
    Tr.print();
    Tr.rotate(10);
    

    glutSwapBuffers();
}

void timer(int = 0)
{
    display();
    glutTimerFunc(1000, timer, 0);
}

void glutStdStart(int argc, char** argv) 
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
}

int main(int argc, char** argv) {
    glutStdStart(argc, argv);
    Tr.moveTo(2, -1);
    Tr.changeSizeAlongAxis(1, 2);
    glutDisplayFunc(display);
    timer(0);
    glutMainLoop();
};