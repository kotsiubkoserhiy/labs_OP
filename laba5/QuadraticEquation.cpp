#include "QuadraticEquation.h"
#include "LinearEquation.h"
#include "TEquation.h"

QuadraticEquation::QuadraticEquation(double a, double b, double c) : A(a), B(b), C(c) {}

//Функція для знаходження коренів рівняння
double* QuadraticEquation::FindRoots(int& count) const {
    if (A == 0) {
        return LinearEquation(B, C).FindRoots(count);
    }
    else {
        double D = B * B - 4 * A * C;
        if (D < 0) {
            count = 0;
            return nullptr;
        }
        else if (D == 0) {
            double* roots = new double[1];
            roots[0] = -B / (2 * A);
            count = 1;
            return roots;
        }
        else {
            double* roots = new double[2];
            roots[0] = (-B + sqrt(D)) / (2 * A);
            roots[1] = (-B - sqrt(D)) / (2 * A);
            count = 2;
            return roots;
        }
    }
}

// Функція для перевірки чи є задане значення x коренем рівняння
bool QuadraticEquation::IsRoot(double x) const {
    return A * x * x + B * x + C == 0;
}

// Функція для повернення рівняння у вигляді рядка
string QuadraticEquation::GetEquationString() const {
    stringstream ss;
    ss << fixed << setprecision(2) << A << "x^2 + "
    <<fixed << setprecision(2) << B << "x + "
    <<fixed << setprecision(2) << C << " = 0";
    return ss.str();
}

