#include <iostream>
#include "func.h"
#include <windows.h>


int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Dot d;
    Circle c1;
    Circle c2;
    Square s1;
    Square s2;
    
    std::cout << "TОЧКА" << std::endl;
    readDot(d);
    printDot(d);
    std::cout << "==============================" << std::endl;

    std::cout << "КРУГ" << std::endl;
    readCircle(c1);
    printCircle(c1);
    lengthCircle(c1);
    squareCircle(c1);
    std::cout << "==============================" << std::endl;

    std::cout << "КВАДРАТ" << std::endl;
    readSquare(s1);
    printSquare(s1);
    perimetrSquare(s1);
    squareSquare(s1);
    std::cout << "==============================" << std::endl;

    std::cout << "ПРИНАДЛЕЖНОСТЬ ТОЧКИ ФИГУРЕ" << std::endl;
    readDot(d);
    readCircle(c1);
    Dot_in_Circle(d, c1);
    std::cout << "--------" << std::endl;
    
    readDot(d);
    readSquare(s1);
    Dot_in_Square(d, s1);
    std::cout << "==============================" << std::endl;

    std::cout << "НАХОЖДЕНИЕ ТОЧКИ НА КОНТУРЕ" << std::endl;
    readDot(d);
    readCircle(c1);
    Dot_on_border_Circle(d, c1);
    std::cout << "--------" << std::endl;

    readDot(d);
    readSquare(s1);
    Dot_on_Square_Border(d, s1);
    std::cout << "==============================" << std::endl;

    std::cout << "ПЕРЕСЕЧЕНИЕ ФИГУР" << std::endl;
    readCircle(c1);
    readCircle(c2);
    intersection_circles(c1, c2);
    std::cout << "--------" << std::endl;

    readSquare(s1);
    readSquare(s2);
    intersection_squares(s1, s2);
    std::cout << "--------" << std::endl;

    readCircle(c1);
    readSquare(s1);
    intersectCircleSquare(c1, s1);
    std::cout << "==============================" << std::endl;

    std::cout << "ПРИНАДЛЕЖНОСТЬ ФИГУРЫ" << std::endl;
    readCircle(c1);
    readCircle(c2);
    Circle_in_Circle(c1, c1);
    std::cout << "--------" << std::endl;

    readSquare(s1);
    readSquare(s2);
    Square_in_Square(s1, s2);
    std::cout << "--------" << std::endl;

    readSquare(s1);
    readCircle(c1);
    Square_in_Circle(s1, c1);
    std::cout << "--------" << std::endl;

    readCircle(c1);
    readSquare(s1);
    Circle_in_Square(s1, c1);

    return 0;
}
