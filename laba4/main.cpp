#include "Numeral8.h"

int main() {
    string input;
    cout << "Введіть перше вісімкове число: ";
    cin >> input;
    Numeral8 N1(input);
    cout << "Значення першого числа: " << N1.get_value() << endl;
    ++N1;
    cout << "Значення першого числа ++: " << N1.get_value() << endl;

    int value;
    cout << "Введіть друге вісімкове число: ";
    cin >> value;
    Numeral8 N2(value);
    cout<< "Значення другого числа: " << N2.get_value() << endl;
    cout << "Введіть ціле число, яке потрібно додати до другого вісімкового числа: ";
    int add;
    cin>>add;
    N2+=add;
    cout << "Значення другого числа +=add: " << N2.get_value() << endl;
    Numeral8 N3;
    N3= N1 + N2;

    cout << "Значення першого числа: " << N1.get_value() << endl;
    cout << "Значення другого числа: " << N2.get_value() << endl;
    cout << "Значення третього числа:  " << N3.get_value() << endl;

    string octal_string = N3.to_octal_string();
    cout << "Третє число у вісімковому форматі: " << octal_string << endl;

    int decimal = N3.to_decimal();
    cout << "Третє число у десятковому форматі: " << decimal << endl;

    return 0;
}