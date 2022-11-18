#include "Primitives.h"
#include "DrawingObject.h"
#include <glut.h>

line MassiveObj[26];
leaf F(T(), 1, 0.1, 0.6, 0);


void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
 
    F.print();
    //F.rotate(10);


    //рисуем координатную сетку
    for (int i = 0; i < 26; ++i) {
        MassiveObj[i].print();
    }

    

    glutSwapBuffers();
}

void timer(int = 0)
{
    display();
    glutTimerFunc(1000, timer, 0);
}

void glutStdStart(int argc, char** argv, int Xmin = -10, int Xmax = 10, int Ymin = -10, int Ymax = 10)
{  
    glutInit(&argc, argv);  // window init
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(630, 630);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Primitives");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
   // glEnable(GL_LINE_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(Xmin, Xmax, Ymin, Ymax, -1, 1);
    glutDisplayFunc(display);
    timer(0);
    glutMainLoop();
}

int main(int argc, char** argv) 
{

    // X axis
    MassiveObj[0] = line(T(-6, -6), T(6, -6), 1, 0.5, 0.5, 0.5);
    MassiveObj[1] = line(T(-6, -5), T(6, -5), 1, 0.5, 0.5, 0.5);
    MassiveObj[2] = line(T(-6, -4), T(6, -4), 1, 0.5, 0.5, 0.5);
    MassiveObj[3] = line(T(-6, -3), T(6, -3), 1, 0.5, 0.5, 0.5);
    MassiveObj[4] = line(T(-6, -2), T(6, -2), 1, 0.5, 0.5, 0.5);
    MassiveObj[5] = line(T(-6, -1), T(6, -1), 1, 0.5, 0.5, 0.5);
    MassiveObj[6] = line(T(-6, 0), T(6, 0), 1);
    MassiveObj[7] = line(T(-6, 1), T(6, 1), 1, 0.5, 0.5, 0.5);
    MassiveObj[8] = line(T(-6, 2), T(6, 2), 1, 0.5, 0.5, 0.5);
    MassiveObj[9] = line(T(-6, 3), T(6, 3), 1, 0.5, 0.5, 0.5);
    MassiveObj[10] = line(T(-6, 4), T(6, 4), 1, 0.5, 0.5, 0.5);
    MassiveObj[11] = line(T(-6, 5), T(6, 5), 1, 0.5, 0.5, 0.5);
    MassiveObj[12] = line(T(-6, 6), T(6, 6), 1, 0.5, 0.5, 0.5);

    // Y axis
    MassiveObj[13] = line(T(-6, -6), T(-6, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[14] = line(T(-5, -6), T(-5, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[15] = line(T(-4, -6), T(-4, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[16] = line(T(-3, -6), T(-3, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[17] = line(T(-2, -6), T(-2, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[18] = line(T(-1, -6), T(-1, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[19] = line(T(0, -6), T(0, 6), 1);
    MassiveObj[20] = line(T(1, -6), T(1, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[21] = line(T(2, -6), T(2, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[22] = line(T(3, -6), T(3, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[23] = line(T(4, -6), T(4, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[24] = line(T(5, -6), T(5, 6), 1, 0.5, 0.5, 0.5);
    MassiveObj[25] = line(T(6, -6), T(6, 6), 1, 0.5, 0.5, 0.5);

    F.moveBy(0.5, 0.2);
    
    glutStdStart(argc, argv, -6, 6, -6, 6);
};