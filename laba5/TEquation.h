#ifndef TEQUATION_H
#define TEQUATION_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

class TEquation {
public:
    virtual double* FindRoots(int& count) const = 0;
    virtual bool IsRoot(double x) const = 0;
    virtual string GetEquationString() const = 0;
    virtual ~TEquation() {}
};

#endif // TEQUATION_H
