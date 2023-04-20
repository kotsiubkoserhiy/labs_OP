#include "TEquation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"

int main() {
    srand(time(nullptr)); // ініціалізація генератора випадкових чисел

    // Створюємо та обчислюємо p лінійних рівнянь
    const int p = 5;
    double sumLinearRoots = 0;
    for (int i = 0; i < p; i++) {
        double a = rand() % 10 - 5;
        double b = rand() % 10 - 5;
        LinearEquation eq(a, b);
        int count;
        double* roots = eq.FindRoots(count);
        cout << "Linear equation " << i + 1 << ": " << eq.GetEquationString() << endl;
        if (roots != nullptr) {
            cout << "Roots:";
            for (int j = 0; j < count; j++) {
                cout << " " << roots[j];
                sumLinearRoots += roots[j];
            }
            cout << endl;
            delete[] roots;
        }
        else {
            cout << "No roots" << endl;
        }
    }
    cout << "Sum of roots of " << p << " linear equations: " << sumLinearRoots << endl;

    // Створюємо та обчислюємо t квадратних рівнянь
    const int t = 5;
    double sumQuadraticRoots = 0;
    for (int i = 0; i < t; i++) {
        double a = rand() % 10 - 5;
        double b = rand() % 10 - 5;
        double c = rand() % 10 - 5;
        QuadraticEquation eq(a, b, c);
        int count;
        double* roots = eq.FindRoots(count);
        cout << "Quadratic equation " << i + 1 << ": " << eq.GetEquationString() << endl;
        if (roots != nullptr) {
            cout << "Roots:";
            for (int j = 0; j < count; j++) {
                cout << " " << roots[j];
                sumQuadraticRoots += roots[j];
            }
            cout << endl;
            delete[] roots;
        }
        else {
            cout << "No roots" << endl;
        }
    }
    cout << "Sum of roots of " << t << " quadratic equations: " << sumQuadraticRoots << endl;
    return 0;
}
