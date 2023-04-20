#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H
#include "TEquation.h"

class LinearEquation : public TEquation {
public:
    LinearEquation(double a, double b);

    double* FindRoots(int& count) const override;
    bool IsRoot(double x) const override;
    string GetEquationString() const override;

private:
    double A;
    double B;
};

#endif // LINEAREQUATION_H
