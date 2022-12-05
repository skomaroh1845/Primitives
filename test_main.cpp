#include "Primitives.h"
#include "DrawingObject.h"
#include "glutStd.cpp"
#include <glut.h>


DrawingObject** ppM;
DrawingObject** initGrill(double Xmin = -10, double Xmax = 10, double stepX = 1, double Ymin = -10, double Ymax = 10, double stepY = 1);

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
 
    //рисуем координатную сетку
    for (int i = 0; ppM[i] != nullptr; ++i) ppM[i]->print(); 

    glutSwapBuffers();  // Bring printed image from buffer to screen
}

void timer(int = 0)  // time ticks
{
    display();
    glutTimerFunc(1000, timer, 0);  
}

int main(int argc, char** argv) 
{
    ppM = initGrill();  // return pointer on massive of grill lines 

    glutStdStart(display, timer, argc, argv, 600, 600);
};


DrawingObject** initGrill(double Xmin, double Xmax, double stepX, double Ymin, double Ymax, double stepY) {
    
    int nX = (Xmax - Xmin) / stepX + 1;  // number of lines
    int nY = (Ymax - Ymin) / stepY + 1;

    line* Lines = new line[nX + nY];

    // X axis
    for (int i = 0; i < nX; ++i) {
        if (i == trunc(nX / 2)) 
            Lines[i] = line(T(Xmin, Ymin + i * stepY), T(Xmax, Ymin + i * stepY), 1);
        else 
            Lines[i] = line(T(Xmin, Ymin + i * stepY), T(Xmax, Ymin + i * stepY), 1, 0.4, 0.4, 0.4);
    }
    // Y axis
    for (int i = 0; i < nY; ++i) {
        if (i == trunc(nY / 2)) 
            Lines[nX + i] = line(T(Xmin + i * stepX, Ymin), T(Xmin + i * stepX, Ymax), 1);
        else 
            Lines[nX + i] = line(T(Xmin + i * stepX, Ymin), T(Xmin + i * stepX, Ymax), 1, 0.4, 0.4, 0.4);
    }

    DrawingObject** pLines = new DrawingObject*[nX + nY + 1];

    for (int i = 0; i < nX + nY; ++i) {
        pLines[i] = (Lines + i);
    }
    pLines[nX + nY] = nullptr;

    return pLines;
}