#include "biblia.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double distance(const Point &A, const Point &B) {
    double X = std::fabs(A.x - B.x);
    double Y = std::fabs(A.y - B.y);
    return std::sqrt(X*X + Y*Y);
};

double Ploshca(const Triangle &ABC) {
    double p = (distance(ABC.A, ABC.B)+distance(ABC.B, ABC.C)+distance(ABC.C, ABC.A))/2;
    return sqrt(p*(p-distance(ABC.A, ABC.B))*(p-distance(ABC.B, ABC.C))*(p-distance(ABC.C, ABC.A)));
};

double Triangle::area() const {
    return Ploshca(*this);
};

bool Triangle::contains(const Point &D) const {
    Triangle t1 = {A, B, D};
    Triangle t2 = {A, C, D};
    Triangle t3 = {B, C, D};
    
    double S_main = area();
    double S_sum = t1.area() + t2.area() + t3.area();
    
    return std::fabs(S_main - S_sum) < 1e-9;
};

bool trule(const Triangle &ABC) { //is there exiting triangle
    if (distance(ABC.A, ABC.B)+distance(ABC.B, ABC.C) <= distance(ABC.C, ABC.A)
     || distance(ABC.A, ABC.C)+distance(ABC.B, ABC.C) <= distance(ABC.B, ABC.A)
     || distance(ABC.A, ABC.B)+distance(ABC.A, ABC.C) <= distance(ABC.C, ABC.B))
        return false;
    else return true;
};
bool trule_2(const Triangle &ABC) { //is triangle VRODZHENIY or not
    double eps = 1e-9;
    if (fabs(distance(ABC.A, ABC.B)+distance(ABC.B, ABC.C) - distance(ABC.C, ABC.A)) < eps
     || fabs(distance(ABC.A, ABC.C)+distance(ABC.B, ABC.C) - distance(ABC.B, ABC.A)) < eps
     || fabs(distance(ABC.A, ABC.B)+distance(ABC.A, ABC.C) - distance(ABC.C, ABC.B)) < eps)
        return 1;
    else return 0;
};

int TochkaInPoint(const Triangle &ABC, const Point &D) { //is our pount equal to vertex of triangle
    if (ABC.A.x == D.x && ABC.A.y == D.y) {
        std::cout << "The point is \033[36mA\033[0m" << std::endl;
        return 1;
    } else if (ABC.B.x == D.x && ABC.B.y == D.y) {
        std::cout << "The point is \033[36mB\033[0m" << std::endl;
        return 1;
    } else if (ABC.C.x == D.x && ABC.C.y == D.y) {
        std::cout << "The point is \033[36mC\033[0m" << std::endl;
        return 1;
    } else {
        std::cout << "The point \033[35mis not\033[0m any of the vertex of the triangle :(" << std::endl;
    }
    return 0;

};

void TochkaOnSegment(const Point &A, const Point &B, const Point &D) {
    if ((std::min(A.x, B.x) <= D.x && std::max(A.x, B.x) >= D.x) 
    && (std::min(A.y, B.y) <= D.y && std::max(A.y, B.y) >= D.y)) {
        std::cout << "Futhermore, that point in a \033[33msegment\033[0m" << std::endl;
    }
};

void TochkaVerrification(const Triangle &ABC, const Point &D) { //all "verification" to the point
    if (TochkaInPoint(ABC, D)) {
        return;
    } else {
    if ( std::fabs((D.x -ABC.A.x)*(ABC.B.y - ABC.A.y) - (D.y - ABC.A.y)*(ABC.B.x - ABC.A.x)) < 1e-9 ) {
            std::cout << "The point is \033[32mon the line AB\033[0m" << std::endl;
            TochkaOnSegment(ABC.A, ABC.B, D);
        } else if ( std::fabs((D.x -ABC.B.x)*(ABC.C.y - ABC.B.y) - (D.y - ABC.B.y)*(ABC.C.x - ABC.B.x)) < 1e-9 ) {
            std::cout << "The point is \033[32mon the line BC\033[0m" << std::endl;
            TochkaOnSegment(ABC.B, ABC.C, D);
        } else if ( std::fabs((D.x -ABC.C.x)*(ABC.A.y - ABC.C.y) - (D.y - ABC.C.y)*(ABC.A.x - ABC.C.x)) < 1e-9 ) {
            std::cout << "The point is \033[32mon the line CA\033[0m" << std::endl;
            TochkaOnSegment(ABC.C, ABC.A, D);
        } else {
            std::cout << "The point is \033[32mnot\033[0m on any of the lines" << std::endl;
        }
    }
};

void furry() { //main function
    int n;
    Point A, B, C;
    Triangle ABC;
    bool valid_triangle = false;
    while (!valid_triangle) {  
        std::cout << "Please enter the coordinates of point \033[38;5;212mA\033[0m: " << std::endl;
        std::cin >> ABC.A.x >> ABC.A.y;
        std::cout << "Please enter the coordinates of point \033[38;5;212mB\033[0m: " << std::endl;
        std::cin >> ABC.B.x >> ABC.B.y;
        std::cout << "Please enter the coordinates of point \033[38;5;212mC\033[0m: " << std::endl;
        std::cin >> ABC.C.x >> ABC.C.y;
        if (trule(ABC)) {
            if (trule_2(ABC)) {
                std::cout << "The triangle is degenerate (points are collinear)" << std::endl;
                std::cout << "Please enter \033[31mvalid\033[0m points that form a proper triangle" << std::endl;
            } else {
                std::cout << "The area of the triangle is: " << ABC.area() << std::endl;
                valid_triangle = true;
            }
        } else {
            std::cout << "There is NO triangle with these points" << std::endl;
            std::cout << "Please enter \033[31mvalid\033[0m Points" << std::endl;
        }
    };
    std::cout << "Please enter the \033[35mnumber of points\033[0m, that need to be checked: " << std::endl; //try it
    std::cin >> n;
    for (int j = 0; j < n; j++) {
        Point D;
        std::cout << "Please enter the coordinates of point \033[38;5;212mD\033[0m: " << std::endl;
        std::cin >> D.x >> D.y;
        if (ABC.contains(D)) {
            std::cout << "The point \033[38;5;88mis in\033[0m the area of the triangle" << std::endl;
        } else {
            std::cout << "The point \033[38;5;129mis not in\033[0m the area of the triangle" << std::endl;
        }
        TochkaVerrification(ABC, D);
    };
    
};