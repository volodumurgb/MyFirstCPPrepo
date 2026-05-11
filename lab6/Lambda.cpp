#include "Lambda.h"
#include <iostream>
#include <cmath>

/*Lambda::Lambda(double start_a, double start_b, double start_eps) {
    a = start_a;
    b = start_b;
    eps = start_eps;
}*/
Lambda::Lambda(){}
//enters a,b, eps
void Lambda::setIntervals(double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}
void Lambda::setTolerance(double vol_eps){
    eps = vol_eps;
}
//dyhotomia
void Lambda::Dyhotomia(){
    double loc_a = a; 
    double loc_b = b;

    auto f = [](double x) {
        return x - 1.0 / (3.0 - std::sin(3.6 * x));
    };
    
    if ((f(loc_a)*f(loc_b)) > 0){
        std::cout << "there is no solution of the equation on interval : (" << loc_a << ":"<< loc_b << ")" << std::endl;
        return;
    }
    int iterations = 0;
    while (std::abs(loc_a - loc_b) > eps && iterations < 100){
        iterations++;
        double c = (loc_a + loc_b) / 2;
        if ((f(loc_a)*f(c)) < 0){
            loc_b = c;
        }
        else {
            loc_a = c;
        }
    }
    double x = (loc_a + loc_b) / 2;
    if (iterations >= 100) {
        std::cout << "[Method Dyhotomia]Maximum iterations reached. Approximate solution: " << x << std::endl;
    } else {
        std::cout << "[Method Dyhotomia]Our solution is " << x << std::endl;
    }
}
//Newton
void Lambda::Newton(){
    auto f = [](double x) {
        return x - 1.0 / (3.0 - std::sin(3.6 * x));
    };
    auto df = [&](double x) {
        double dx = 1e-6;
        return (f(x + dx) - f(x)) / dx;
    };
    double x = (a + b) / 2;
    int iterations = 0;
    while (std::abs(f(x)) > eps && iterations < 100){
        iterations++;
        if (std::abs(df(x))<1e-9){
            std::cout << "derivative of a function is equal to 0, function stopped" << std::endl;
            std::cout << "[Method Newton]The last calculated solution was: " << x << std::endl;
            return;
        }
        x = x - f(x) / df(x);
    }
    if (iterations >= 100) {
        std::cout << "[Method Newton]Maximum iterations reached. Approximate solution: " << x << std::endl;
    } else {
        std::cout << "[Method Newton]Our solution is " << x << std::endl;
    }
}
//quadratic formula
void Lambda::quadratic(double a, double b, double c){
    std::cout << "Quadratic formula: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
    auto calcD =[]( double a, double b, double c) {
        return b * b - 4 * a * c;
    };
    double D = calcD(a, b, c);
    if (D < 0) {
        std::cout << "No real solutions" << std::endl;
    } else {
        double x1 = (-b + std::sqrt(D)) / (2 * a);
        double x2 = (-b - std::sqrt(D)) / (2 * a);
        std::cout << "Solutions: " << x1 << ", " << x2 << std::endl;
    }
}

Lambda::~Lambda(){
    std::cout << "class deleted" << std::endl;
}
void Kukuha() {
    Lambda *cls = new Lambda();
    double a, b, eps;
    std::cout << "Please enter Interval(type like \"0 0.8\"): ";
    std::cin >> a >> b;
    std::cout << "Please enter eps: ";
    std::cin >> eps;
    cls -> setIntervals(a, b);
    cls -> setTolerance(eps);
    cls -> Dyhotomia();
    cls -> Newton();
    double A, B, C;
    std::cout << "Please enter a, b, c for quadratic formula: ";
    std::cin >> A >> B >> C;
    std::cout << "Quadratic formula and solutions: " << std::endl;
    cls -> quadratic(A, B, C);
    delete cls;
}


