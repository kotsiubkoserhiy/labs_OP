#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H
#include "TEquation.h"

class QuadraticEquation : public TEquation {
public:
    QuadraticEquation(double a, double b, double c);

    double* FindRoots(int& count) const override;
    bool IsRoot(double x) const override;
    string GetEquationString() const override;

private:
    double A;
    double B;
    double C;
};

#endif // QUADRATICEQUATION_H
