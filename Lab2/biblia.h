#ifndef BIBLIA_H
#define BIBLIA_H
#include <cmath>

struct Point {
    double x, y;
};
struct Triangle {
    Point A, B, C;
    double area() const;
    bool contains(const Point &P) const;
};
double Ploshca(const Triangle &ABC);
double distance(const Point &A,const Point &B);
bool trule(const Triangle &ABC); //is there exiting triangle
bool trule_2(const Triangle &ABC); //is triangle VRODZHENIY or not
void TochkaVerrification(const Triangle &ABC, const Point &D);
void TochkaOnSegment(const Point &A, const Point &B, const Point &D);
int TochkaInPoint(const Triangle &ABC, const Point &D);
void furry();

#endif