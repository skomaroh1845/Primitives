#include "Primitives.h"
#include "DrawingObject.h"
#include <glut.h>

leaf F(T(), 1, 0.1, 0.6, 0);
DrawingObject** ppM;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
 
    F.print();
    //F.rotate(10);


    //рисуем координатную сетку
    for (int i = 0; i < 26; ++i) {
        ppM[i]->print();
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
    line MassiveObj[26];
    DrawingObject* pM[26];

    // XY axes
    for (int i = 0; i < 13; ++i) {
        if (i == 6) {
            MassiveObj[i] = line(T(-6, i-6), T(6, i-6), 1);
            MassiveObj[i+13] = line(T(i-6, -6), T(i-6, 6), 1);
            continue;
        }
        MassiveObj[i] = line(T(-6, i-6), T(6, i-6), 1, 0.5, 0.5, 0.5);
        MassiveObj[i+13] = line(T(i-6, -6), T(i-6, 6), 1, 0.5, 0.5, 0.5);
    }

    for (int i = 0; i < 26; ++i) {
        pM[i] = (MassiveObj + i);
    }
    ppM = pM;

    F.moveBy(0.5, 0.2);

    glutStdStart(argc, argv, -6, 6, -6, 6);

};