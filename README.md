# Primitives 
2D graphic library based on openGL and Vector2D
-------
### Описание ###
Библиотека позволяет рисовать следующие примитивы: линии, круги, окружности, треугольники и четырехугольники. По сути она является небольшой оберткой над финкциями самого openGL, при этом позволяя хранить примитивы как объекты некоторого класса. Для примитивов реализованы методы, позволяющие менять тип их отрисовки. Например, можно вывести на экран не всю окружность, а какую-то ее часть, можно закрасить ее или сделать пунктирной. Исходная библиотека linal (откуда взят Vector2D): <https://github.com/Legokol/LinAl>.
### Пример кода ###

    #include "Primitives.h"
    #include <glut.h>

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
        glLoadIdentity(); // Сброс просмотра
        glOrtho(-5, 5, -5, 5, -1, 1);  //координатная сетка

        // это рисует координатную сетку из линий
        line L1(T(-5, 0), T(5, 0)); // T = Vector2D
        line L2(T(0, -5), T(0, 5));
        L1.print();
        L2.print();
        for (int i = -5; i < 5; ++i) {
            line L3(T(i, -0.1), T(i, 0.1));
            L3.print();
        }
        for (int i = -5; i < 5; ++i) {
            line L3(T(-0.1, i), T(0.1, i));
            L3.print();
        }
         
        rectangle P; //создаем и рисуем четырехуголник 
        P.setColor(1, 0, 0);
        P.moveLeft(2); P.moveUp(1);
        P.print(); 

        triangle Tr; //создаем и рисуем треугольник
        Tr.setColor(1, 1, 0);
        Tr.moveRight(2); Tr.moveUp(2);
        Tr.print();

        leaf F; F.setColor(0, 0.8, 0); //создаем и рисуем листик
        F.moveDown(2); F.moveRight(3);
        F.print();

        circle C; //создаем и рисуем окружность
        C.setColor(1, 1, 1);
        C.moveRight(-3); C.moveDown(3);
        C.print();

        glutSwapBuffers();
    }

    void timer(int = 0)
    {
        display();
        glutTimerFunc(1000, timer, 0);
    }

    int main(int argc, char** argv) {
      glutInit(&argc, argv);  // window init
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(480, 480);
      glutInitWindowPosition(0, 0);
      glutCreateWindow("Primitives");
      glClearColor(0.0, 0.0, 0.0, 1.0);
      glMatrixMode(GL_PROJECTION);
      glutDisplayFunc(display);
      timer(0);
      glutMainLoop();
      return 0;
    };
### Результат работы ###
![image](https://user-images.githubusercontent.com/61201241/202005071-3ab5a77d-fc2d-4181-bd04-aa54271366b8.png)
