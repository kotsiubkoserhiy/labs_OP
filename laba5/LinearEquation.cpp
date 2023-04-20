#include "LinearEquation.h"
#include "TEquation.h"

LinearEquation::LinearEquation(double a, double b) : A(a), B(b) {}

//Функція для знаходження коренів рівняння
double* LinearEquation::FindRoots(int& count) const {
    if (A == 0) {
        count = 0;
        return nullptr;
    }
    else {
        double* roots = new double[1];
        roots[0] = -B / A;
        count = 1;
        return roots;
    }
}

// Функція для перевірки чи є задане значення x коренем рівняння
bool LinearEquation::IsRoot(double x) const {
    return A * x + B == 0;
}

// Функція для повернення рівняння у вигляді рядка
string LinearEquation::GetEquationString() const {
    ostringstream equation;
    equation << showpos << fixed << setprecision(2) << A << "x " << B << " = 0";
    return equation.str();
}