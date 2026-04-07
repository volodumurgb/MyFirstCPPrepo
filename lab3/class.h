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
        double f(double x);
        double df(double x);

    private:
        double a;
        double b;
        double eps;
};

void Pomolumosi();

#endif