#include <iostream>
#include <cmath>
#include "func.h"

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx - dy*dy);
}

void readDot(Dot &d) {
    std::cout << "Введите координаты точки (x, y): ";
    std::cin >> d.cord_x >> d.cord_y;
}

void printDot(const Dot &d) {
    std::cout << "Точка: " << "(" << d.cord_x << ", " << d.cord_y << ")" << std::endl;
}

void readCircle(Circle &c) {
    std::cout << "Введите координаты центра круга (x, y): ";
    std::cin >> c.Center_circle.cord_x >> c.Center_circle.cord_y;
    std::cout << "Радиус круга: ";
    std::cin >> c.radius;
}

void printCircle(const Circle &c) {
    std::cout << "Центр круга: " << "(" << c.Center_circle.cord_x << ", " << c.Center_circle.cord_y << ")" << std::endl;
    std::cout << "Радиус круга: " << c.radius << std::endl;
}

void lengthCircle(const Circle &c) {
    std::cout << "Длина круга = " << 2 * M_PI * c.radius << std::endl;
}

void squareCircle(const Circle &c) {
    std::cout << "Площадь круга = " << M_PI * c.radius * c.radius << std::endl;
}

void readSquare(Square &s) {
    std::cout << "Введите координаты левого верхнего угла квадрата (x, y): ";
    std::cin >> s.Corner_left_upper.cord_x >> s.Corner_left_upper.cord_y;
    std::cout << "Введите длину стороны квадрата: ";
    std::cin >> s.side;
}

void printSquare(const Square &s) {
    std::cout << "Координаты левого верхнего угла квадрата: (" << s.Corner_left_upper.cord_x  << ", " << s.Corner_left_upper.cord_y << ")" << std::endl;
    std::cout << "Длина стороны квадрата = " << s.side << std::endl;
}

void perimetrSquare(const Square &s) {
    std::cout << "Периметр квадрата = " << s.side * 4 << std::endl;
}

void squareSquare(const Square &s) {
    std::cout << "Площадь квадрата = " << s.side * s.side << std::endl;
}

void Dot_in_Circle(const Dot &d, const Circle &c) {
    if(distance(d.cord_x, d.cord_y, c.Center_circle.cord_x, c.Center_circle.cord_y) < c.radius) { 
        std::cout << "Точка принадлежит кругу" << std::endl;
    }
    else {
        std::cout << "Точка не принадлежит кругу" << std::endl;
    }
}

void Dot_in_Square(const Dot &d, const Square &s) {
    if((s.Corner_left_upper.cord_x < d.cord_x < (s.Corner_left_upper.cord_x + s.side)) && ((s.Corner_left_upper.cord_y - s.side) < d.cord_y < s.Corner_left_upper.cord_y)) {
        std::cout << "Точка принадлежит квадрату" << std::endl;
    }
    else {
        std::cout << "Точка не принадлежит квадрату" << std::endl;
    }
}

void Dot_on_border_Circle(const Dot &d, const Circle &c) {
    if(distance(d.cord_x, d.cord_y, c.Center_circle.cord_x, c.Center_circle.cord_y) == c.radius) {
        std::cout << "Точка лежит на границе круга" << std::endl;
    }
    else {
        std::cout << "Точка не лежит на границе круга" << std::endl;
    }
}

void Dot_on_Square_Border(const Dot &d, const Square &s) {
    double left   = s.Corner_left_upper.cord_x;
    double right  = s.Corner_left_upper.cord_x + s.side;
    double top    = s.Corner_left_upper.cord_y;
    double bottom = s.Corner_left_upper.cord_y - s.side;

    bool onBorder = false;

    if ((d.cord_x == left || d.cord_x == right) && (d.cord_y >= bottom && d.cord_y <= top)) {
        onBorder = true;
    }

    else if ((d.cord_y == top || d.cord_y == bottom) && (d.cord_x >= left && d.cord_x <= right)) {
        onBorder = true;
    }

    if (onBorder)
        std::cout << "Точка лежит на границе квадрата" << std::endl;
    else
        std::cout << "Точка не лежит на границе квадрата" << std::endl;
}

void intersection_circles(const Circle &c1, const Circle &c2) {
    if( (distance(c1.Center_circle.cord_x, c1.Center_circle.cord_y, c2.Center_circle.cord_x, c2.Center_circle.cord_y)) <= (c1.radius + c2.radius)) {
        std::cout << "Два круга пересекаются" << std::endl;
    }
    else {
        std::cout << "Два круга не пересекаются" << std::endl;
    }
}


void intersection_squares(const Square &s1, const Square &s2) {
    if((s1.Corner_left_upper.cord_x + s1.side < s2.Corner_left_upper.cord_x) || (s2.Corner_left_upper.cord_x + s2.side < s1.Corner_left_upper.cord_x) || (s1.Corner_left_upper.cord_y - s1.side > s2.Corner_left_upper.cord_y) || (s2.Corner_left_upper.cord_y - s2.side > s1.Corner_left_upper.cord_y)) {
        std::cout << "Квадраты не пересекаются" << std::endl;
    }
    else {
        std::cout << "Квадраты пересекаются" << std::endl;
    }
}


void intersectCircleSquare(const Circle &c, const Square &s) {
    double left   = s.Corner_left_upper.cord_x;
    double right  = s.Corner_left_upper.cord_x + s.side;
    double top    = s.Corner_left_upper.cord_y;
    double bottom = s.Corner_left_upper.cord_y + s.side;

    bool cx_inside = (c.Center_circle.cord_x >= left) && (c.Center_circle.cord_x <= right);
    bool cy_inside = (c.Center_circle.cord_y >= bottom) && (c.Center_circle.cord_y <= top);

    bool intersects = false;

    if (cx_inside && cy_inside) {
        double d_left   = c.Center_circle.cord_x - left;
        double d_right  = right - c.Center_circle.cord_x;
        double d_top    = top - c.Center_circle.cord_y;
        double d_bottom = c.Center_circle.cord_y - bottom;

        // вместо std::min:
        double min_edge = d_left;
        if (d_right < min_edge)  min_edge = d_right;
        if (d_top < min_edge)    min_edge = d_top;
        if (d_bottom < min_edge) min_edge = d_bottom;

        intersects = (c.radius >= min_edge);
    } else {
        double dx = 0.0;
        if (c.Center_circle.cord_x < left) dx = left - c.Center_circle.cord_x;
        else if (c.Center_circle.cord_x > right) dx = c.Center_circle.cord_x - right;

        double dy = 0.0;
        if (c.Center_circle.cord_y < bottom) dy = bottom - c.Center_circle.cord_y;
        else if (c.Center_circle.cord_y > top) dy = c.Center_circle.cord_y - top;

        double dist = std::sqrt(dx*dx + dy*dy);
        intersects = (dist <= c.radius);
    }

    if (intersects)
        std::cout << "Круг и квадрат пересекаются" << std::endl;
    else
        std::cout << "Круг и квадрат не пересекаются" << std::endl;
}

void Circle_in_Circle(const Circle &c1, const Circle &c2) {
    if( (distance(c1.Center_circle.cord_x, c1.Center_circle.cord_y, c2.Center_circle.cord_x, c2.Center_circle.cord_y) + c1.radius) < c2.radius) {
        std::cout << "Первый круг принадлежит второму" << std::endl;
    }
    else {
        std::cout << "Первый круг не принадлежит второму" << std::endl;
    }
}


void Square_in_Square(const Square &s1, const Square &s2) {
    double a_left = s1.Corner_left_upper.cord_x;
    double a_right = s1.Corner_left_upper.cord_x + s1.side;
    double a_top = s1.Corner_left_upper.cord_y;
    double a_bottom = s1.Corner_left_upper.cord_y - s1.side;

    double b_left = s2.Corner_left_upper.cord_x;
    double b_right = s2.Corner_left_upper.cord_x + s2.side;
    double b_top = s2.Corner_left_upper.cord_y;
    double b_bottom = s2.Corner_left_upper.cord_y - s2.side;

    if((a_left > b_left) && (a_right < b_right) && (a_bottom > b_bottom) && (a_top < b_top)) {
        std::cout << "Первый квадрат принадлежит второму" << std::endl;
    }
    else {
        std::cout << "Первый квадрат не принадлежит второму" << std::endl;
    }
}


void Square_in_Circle(const Square &s, const Circle &c) {
    double left = s.Corner_left_upper.cord_x;
    double right = s.Corner_left_upper.cord_x + s.side;
    double top = s.Corner_left_upper.cord_y;
    double bottom = s.Corner_left_upper.cord_y - s.side;

    bool inside = true;
    double dx, dy;

    dx = left - c.Center_circle.cord_x;  dy = top - c.Center_circle.cord_y;
    if (!(dx*dx + dy*dy < c.radius * c.radius)) {
        inside = false;
    }
    dx = right - c.Center_circle.cord_x; dy = top - c.Center_circle.cord_y;
    if (!(dx*dx + dy*dy < c.radius * c.radius)) {
        inside = false;
    }
    dx = left - c.Center_circle.cord_x;  dy = bottom - c.Center_circle.cord_y;
    if (!(dx*dx + dy*dy < c.radius * c.radius)) {
        inside = false;
    }
    dx = right - c.Center_circle.cord_x; dy = bottom - c.Center_circle.cord_y;
    if (!(dx*dx + dy*dy < c.radius * c.radius)) {
        inside = false;
    }
    if (inside)
        std::cout << "Квадрат полностью принадлежит кругу" << std::endl;
    else
        std::cout << "Квадрат не принадлежит кругу" << std::endl;
}


void Circle_in_Square(const Square &s, const Circle &c) {
    double left = s.Corner_left_upper.cord_x;
    double right = s.Corner_left_upper.cord_x + s.side;
    double top = s.Corner_left_upper.cord_y;
    double bottom = s.Corner_left_upper.cord_y - s.side;

    bool inside = true;

    if (c.Center_circle.cord_x - c.radius < left)   inside = false;
    if (c.Center_circle.cord_x + c.radius > right)  inside = false; 
    if (c.Center_circle.cord_y + c.radius > top)    inside = false; 
    if (c.Center_circle.cord_y - c.radius < bottom) inside = false; 

    if (inside)
        std::cout << "Круг полностью входит в квадрат" << std::endl;
    else
        std::cout << "Круг не входит в квадрат" << std::endl;
}
