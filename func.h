#include "structs.h"

double distance(double x1, double y1, double x2, double y2);

void readDot(Dot &d);
void printDot(const Dot &d);

void readCircle(Circle &c);
void printCircle(const Circle &c);
void lengthCircle(const Circle &c);
void squareCircle(const Circle &c);

void readSquare(Square &s);
void printSquare(const Square &s);
void perimetrSquare(const Square &s);
void squareSquare(const Square &s);

void Dot_in_Circle(const Dot &d, const Circle &c);
void Dot_in_Square(const Dot &d, const Square &s);

void Dot_on_border_Circle(const Dot &d, const Circle &c);
void Dot_on_Square_Border(const Dot &d, const Square &s);

void intersection_circles(const Circle &c1, const Circle &c2);
void intersection_squares(const Square &s1, const Square &s2);
void intersectCircleSquare(const Circle &c, const Square &s);

void Circle_in_Circle(const Circle &c1, const Circle &c2);
void Square_in_Square(const Square &s1, const Square &s2);
void Square_in_Circle(const Square &s, const Circle &c);
void Circle_in_Square(const Square &s, const Circle &c);
