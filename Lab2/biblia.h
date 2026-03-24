#ifndef BIBLIA_H
#define BIBLIA_H

struct Point {
    double x, y;
};
double distance(Point &A, Point &B);
bool trule(Point &A, Point &B, Point &C); //is there exiting triangle
bool trule_2(Point &A, Point &B, Point &C); //is triangle VRODZHENIY or not
double Ploshca(Point &A, Point &B, Point &C);
bool TochkaInPloshca(Point &A, Point &B, Point &C, Point &D);
void TochkaVerrification(Point &A, Point &B, Point &C, Point &D);
void TochkaOnSegment(Point &A, Point &B, Point &D);
int TochkaInPoint(Point &A, Point &B, Point &C, Point &D);
void furry();

#endif