#include "biblia.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double distance(Point &A, Point &B) {
    double X = abs(A.x - B.x);
    double Y = abs(A.y - B.y);
    return sqrt(X*X + Y*Y);
};

double Ploshca(Point &A, Point &B, Point &C) {
    double p = (distance(A, B)+distance(B, C)+distance(C, A))/2;
    return sqrt(p*(p-distance(A, B))*(p-distance(B, C))*(p-distance(C, A)));
};

bool trule(Point &A, Point &B, Point &C) { //is there exiting triangle
    if (distance(A, B)+distance(B, C) <= distance(C, A)
     || distance(A, C)+distance(B, C) <= distance(B, A)
     || distance(A, B)+distance(A, C) <= distance(C, B))
        return 0;
    else return 1;
};
bool trule_2(Point &A, Point &B, Point &C) { //is triangle VRODZHENIY or not
    double eps = 1e-9;
    if (fabs(distance(A, B)+distance(B, C) - distance(C, A)) < eps
     || fabs(distance(A, C)+distance(B, C) - distance(B, A)) < eps
     || fabs(distance(A, B)+distance(A, C) - distance(C, B)) < eps)
        return 1;
    else return 0;
};

bool TochkaInPloshca(Point &A, Point &B, Point &C, Point &D) {
    if (Ploshca(A, B, C) == Ploshca(A, B, D)+Ploshca(B, C, D)+Ploshca(C, A, D))
        return 1;
    else return 0;
};

int TochkaInPoint(Point &A, Point &B, Point &C, Point &D) {
    if (A.x == D.x && A.y == D.y) {
        std::cout << "The point is \033[36mA\033[0m" << std::endl;
        return 1;
    } else if (B.x == D.x && B.y == D.y) {
        std::cout << "The point is \033[36mB\033[0m" << std::endl;
        return 1;
    } else if (C.x == D.x && C.y == D.y) {
        std::cout << "The point is \033[36mC\033[0m" << std::endl;
        return 1;
    } else {
        std::cout << "The point \033[35mis not\033[0m any of the vertex of the triangle :(" << std::endl;
    }
    return 0;

};

void TochkaOnSegment(Point &A, Point &B, Point &D) {
    if ((std::min(A.x, B.x) <= D.x && std::max(A.x, B.x) >= D.x) 
    && (std::min(A.y, B.y) <= D.y && std::max(A.y, B.y) >= D.y)) {
        std::cout << "Futhermore, that point in a \033[33msegment\033[0m" << std::endl;
    }
};

void TochkaVerrification(Point &A, Point &B, Point &C, Point &D) {
    if (TochkaInPoint(A, B, C, D)) {
        return;
    } else {
    if ( (D.x -A.x)*(B.y - A.y) - (D.y - A.y)*(B.x - A.x) == 0 ) {
            std::cout << "The point is \033[32mon the line AB\033[0m" << std::endl;
            TochkaOnSegment(A, B, D);
        } else if ( (D.x -B.x)*(C.y - B.y) - (D.y - B.y)*(C.x - B.x) == 0 ) {
            std::cout << "The point is \033[32mon the line BC\033[0m" << std::endl;
            TochkaOnSegment(B, C, D);
        } else if ( (D.x -C.x)*(A.y - C.y) - (D.y - C.y)*(A.x - C.x) == 0 ) {
            std::cout << "The point is \033[32mon the line CA\033[0m" << std::endl;
            TochkaOnSegment(C, A, D);
        } else {
            std::cout << "The point is \033[32mnot\033[0m on any of the lines" << std::endl;
        }
    }
};

void furry() {
    int n;
    Point A, B, C;
    bool valid_triangle = false;
    while (!valid_triangle) {  
        std::cout << "Please enter the coordinates of point \033[38;5;212mA\033[0m: " << std::endl;
        std::cin >> A.x >> A.y;
        std::cout << "Please enter the coordinates of point \033[38;5;212mB\033[0m: " << std::endl;
        std::cin >> B.x >> B.y;
        std::cout << "Please enter the coordinates of point \033[38;5;212mC\033[0m: " << std::endl;
        std::cin >> C.x >> C.y;
        if (trule(A, B, C)) {
            if (trule_2(A, B, C)) {
                std::cout << "The triangle is degenerate (points are collinear)" << std::endl;
                std::cout << "Please enter \033[31mvalid\033[0m points that form a proper triangle" << std::endl;
            } else {
                std::cout << "The area of the triangle is: " << Ploshca(A, B, C) << std::endl;
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
        if (TochkaInPloshca(A, B, C, D)) {
            std::cout << "The point \e[38;5;88mis in\033[0m the area of the triangle" << std::endl;
        } else {
            std::cout << "The point \e[38;5;129mis not in\033[0m the area of the triangle" << std::endl;
        }
        TochkaVerrification(A, B, C, D);
    };
    
};