#ifndef CLASS_H
#define CLASS_H

class HospoduDaiSul{
    public:
    /*HospoduDaiSul(double start_a, double start_b, double start_eps);*/
        HospoduDaiSul(void);
        ~HospoduDaiSul(void);
        void setIntervals(double vol_a, double vol_b);
        void setTolerance(double eps);
        //methods
        void Dyhotomia();
        void Newton();

    private:
        double a;
        double b;
        double eps;
        double f(double x);
        double df(double x);
};

void Pomolumosi();

#endif