#include <iostream>
#include <bitset>
#include <sstream>
#ifndef LABA4_NUMERAL8_H
#define LABA4_NUMERAL8_H
using namespace std;
class Numeral8 {
private:
    int value;

public:
    Numeral8();
    Numeral8(string v);
    Numeral8(int v);

    string get_value();
    void set_value(string v);
    void from_decimal(int decimal);

    Numeral8 &operator++();
    Numeral8 &operator+=(int v);
    Numeral8 operator+(const Numeral8 &other);

    int to_decimal();
    string to_octal_string();
};
#endif //LABA4_NUMERAL8_H