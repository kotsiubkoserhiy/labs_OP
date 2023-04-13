#include "Numeral8.h"

Numeral8::Numeral8() {
    value = 0;
}

Numeral8::Numeral8(string v) {
    value = stoi(v);

}

Numeral8::Numeral8(int v) {
    value = v;
}

string Numeral8::get_value() {
    stringstream str;
    // конвертування значення у вказаний формат (oct - конвертація до вісімкового числа)
    str << oct << value;
    return str.str();
}

void Numeral8::set_value(string v) {
    value = stoi(v, nullptr, 8);
    // nullptr - вказівник на функцію, яка визначає базу числа
}

void Numeral8::from_decimal(int decimal) {
    value = decimal;
}

Numeral8& Numeral8:: operator++() {
    value++;
    return *this;
}

Numeral8& Numeral8:: operator+=(int v) {
    value += v;
    stringstream str1;
    str1<<oct<<value;
    value = stoi(str1.str(), nullptr,8);
    return *this;
}

Numeral8 Numeral8::operator+(const Numeral8& other) {
    return Numeral8(value + other.value);
}

int Numeral8::to_decimal() {
    return value;
}

string Numeral8::to_octal_string() {
    bitset<32> bits(value);
    // Створення об'єкту бітового поля фіксованого розміру в 32 біти
    string binary_string = bits.to_string();
    binary_string.erase(0, binary_string.find_first_not_of('0'));
    // Видалення початкових нулів з двійкового рядка
    int addition = (3 - binary_string.length() % 3) % 3;
    // Доповнення двійкового рядка нулями на початку,аби довжина була кратною 3
    binary_string = std::string(addition, '0') + binary_string;
    // Перетворення двійкового рядка у вісімковий
    string octal_string;
    for (int i = 0; i < binary_string.length(); i += 3) {
        string part_digit = binary_string.substr(i, 3);
        int octal_digit = stoi(part_digit, nullptr, 2);
        octal_string += to_string(octal_digit);
    }
    return octal_string;
}