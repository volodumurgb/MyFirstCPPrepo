#include "class.h"
#include <iostream>
#include <cmath>

/*HospoduDaiSul::HospoduDaiSul(double start_a, double start_b, double start_eps) {
    a = start_a;
    b = start_b;
    eps = start_eps;
}*/
HospoduDaiSul::HospoduDaiSul(){}
//enters a,b, eps
void HospoduDaiSul::setIntervals(double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}
void HospoduDaiSul::setTolerance(double vol_eps){
    eps = vol_eps;
}
//calculating functions
double HospoduDaiSul::f(double x){
    double f = x - 1 / (3 - sin(3.6 * x));
    return f;
}
double HospoduDaiSul::df(double x){
    double dx = 1e-6;
    double df = (f(x+dx)-f(x)/dx);
    return df;
}
//dyhotomia
void HospoduDaiSul::Dyhotomia(){
    if ((f(a)*f(b)) > 0){
        std::cout << "there is no solution of the equation on interval : (" << a << ":"<< b << ")" << std::endl;
        return;
    }
    while (std::abs(a - b) > eps){
        double c = (a + b) / 2;
        if ((f(a)*f(c)) < 0){
            b = c;
        }
        else {
            a = c;
        }
    }
    double x = (a + b) / 2;
    std::cout << "[Method Dyhotomia]Our solution is " << x << std::endl;
}
//Newton
void HospoduDaiSul::Newton(){
    double x = (a + b) / 2;
    while (std::abs(f(x)) > eps){
        if (std::abs(df(x))<1e-9){
            std::cout << "derivative of a function is equal to 0, function stopped" << std::endl;
            std::cout << "[Method Newton]The last calculated solution was: " << x << std::endl;
            return;
        }
        x = x - f(x) / df(x);
    }
    std::cout << "[Method Newton]Our solution is " << x << std::endl;
}
HospoduDaiSul::~HospoduDaiSul(){
    std::cout << "class deleted" << std::endl;
}
void Pomolumosi() {
    HospoduDaiSul *cls = new HospoduDaiSul();
    double a, b, eps;
    std::cout << "Please enter Interval(type like \"0 0.8\"): ";
    std::cin >> a >> b;
    std::cout << "Please enter eps: ";
    std::cin >> eps;
    cls -> setIntervals(a, b);
    cls -> setTolerance(eps);
    cls -> Dyhotomia();
    cls -> Newton();
    delete cls;
}



