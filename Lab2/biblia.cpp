#include "biblia.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double distance(const Point &A, const Point &B) { //hypot is calculating hypotinuze: (x^2 + y^2)^0.5
    return std::hypot(A.x - B.x, A.y - B.y);
}

double Triangle::area() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); //if triangle have an area it`s not VRODZHENUI
}

bool Triangle::isValid() const {
    return area() > 1e-9; 
}

bool Triangle::contains(const Point &D) const {
    double S_main = area();
    double S_sum = Triangle{A, B, D}.area() + Triangle{A, C, D}.area() + Triangle{B, C, D}.area();
    return std::fabs(S_main - S_sum) < 1e-9;
}

void Triangle::verifyPointLocation(const Point &D) const {
    double eps = 1e-9;

    if (distance(A, D) < eps) { std::cout << "The point is \033[36mA\033[0m\n"; return; } //guessing if the point is our vertex
    if (distance(B, D) < eps) { std::cout << "The point is \033[36mB\033[0m\n"; return; }
    if (distance(C, D) < eps) { std::cout << "The point is \033[36mC\033[0m\n"; return; }

    auto isOnSegment = [&](const Point& p1, const Point& p2, const std::string& name) { //if the point is on segment(vector *)
        if (std::fabs((D.x - p1.x) * (p2.y - p1.y) - (D.y - p1.y) * (p2.x - p1.x)) < eps) {
            if (D.x >= std::min(p1.x, p2.x) && D.x <= std::max(p1.x, p2.x) &&
                D.y >= std::min(p1.y, p2.y) && D.y <= std::max(p1.y, p2.y)) {
                std::cout << "The point is \033[32mon the segment " << name << "\033[0m\n";
                return true;
            }
        }
        return false;
    };
    if (isOnSegment(A, B, "AB")) return;
    if (isOnSegment(B, C, "BC")) return;
    if (isOnSegment(C, A, "CA")) return;
    std::cout << "The point \033[35mis not\033[0m any of the vertex or edges :(\n";
}

void furry() {
    Triangle ABC;
    
    while (true) {  
        std::cout << "Enter coordinates for \033[38;5;212mA\033[0m (x y): "; std::cin >> ABC.A.x >> ABC.A.y;
        std::cout << "Enter coordinates for \033[38;5;212mB\033[0m (x y): "; std::cin >> ABC.B.x >> ABC.B.y;
        std::cout << "Enter coordinates for \033[38;5;212mC\033[0m (x y): "; std::cin >> ABC.C.x >> ABC.C.y;
        
        if (ABC.isValid()) {
            std::cout << "The area of the triangle is: " << ABC.area() << std::endl;
            break; //if our triangle doesn`t exist the code will loop
        } 
        std::cout << "\033[31mInvalid or VRODZHENIY triangle. Please try again. If you want, i don`t care [AS]\033[0m\n"; //silly continue if triangle is invalid
        std::cout << "Continue or not?(type 1 if yes, 0 if not(program will reatart))";
        bool k;
        std::cin >> k;
        if (k == 1) {
            break;
        };
    }

    int n;
    std::cout << "Enter the \033[35mnumber of points\033[0m to check: ";
    std::cin >> n;
    
    for (int j = 0; j < n; j++) {
        Point D;
        std::cout << "\nEnter coordinates for point \033[38;5;212mD\033[0m: ";
        std::cin >> D.x >> D.y;
        
        if (ABC.contains(D)) { //if point D is in triangle
            std::cout << "The point \033[38;5;88mis inside\033[0m the triangle.\n";
        } else {
            std::cout << "The point \033[38;5;129mis outside\033[0m the triangle.\n";
        }
        
        ABC.verifyPointLocation(D); //other verifications
    }
}   