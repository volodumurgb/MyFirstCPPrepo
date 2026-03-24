#ifndef BIBLIA_H
#define BIBLIA_H

struct Point {
    double x, y;
};
struct Triangle{
    Point A, B, C;
};
double distance(Point &A, Point &B);
bool trule(Triangle &ABC); //is there exiting triangle
bool trule_2(Triangle &ABC); //is triangle VRODZHENIY or not
double Ploshca(Triangle &ABC);
double Ploshca(Point A, Point B, Point C);
bool TochkaInPloshca(Triangle &ABC, Point &D);
void TochkaVerrification(Triangle &ABC, Point &D);
void TochkaOnSegment(Point &A, Point &B, Point &D);
int TochkaInPoint(Triangle &ABC, Point &D);
void furry();

#endif