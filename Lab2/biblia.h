#ifndef BIBLIA_H
#define BIBLIA_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
   
    double area() const;                               
    bool isValid() const;                              // VRoDZHENUI
    bool contains(const Point &D) const;               // Point in triangle
    void verifyPointLocation(const Point &D) const;    // all about the point D
};

double distance(const Point &A, const Point &B);
void furry();                                          // main function, i like the name

#endif