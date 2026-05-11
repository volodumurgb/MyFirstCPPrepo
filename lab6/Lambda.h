#ifndef LAMBDA_H
#define LAMBDA_H
class Lambda
{
    public:
    /*Lambda(double start_a, double start_b, double start_eps);*/
        Lambda(void);
        ~Lambda(void);
        void setIntervals(double vol_a, double vol_b);
        void setTolerance(double eps);
        //methods
        void Dyhotomia();
        void Newton();
        void quadratic(double a, double b, double c);

    private:
        double a;
        double b;
        double eps;
};

void Kukuha();

#endif // LAMBDA_H