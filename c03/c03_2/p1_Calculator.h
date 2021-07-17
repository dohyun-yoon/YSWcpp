#ifndef __CALC__
#define __CALC__

class Calculator{
    private:
        int addCount;
        int subCount;
        int mulCount;
        int divCount;
    
    public:
        void Init();
        void ShowOpCount();
        double Add(double x, double y);
        double Sub(double x, double y);
        double Mul(double x, double y);
        double Div(double x, double y);
};

#endif