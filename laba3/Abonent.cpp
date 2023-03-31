#include "Abonent.h"

//конструктори
Abonent::Abonent() {
    this->name = "";
    this->address = "";
    this->phoneNumber ="";
}

Abonent::Abonent(string name, string address, string phoneNumber) {
    setName(name);
    setAddress(address);
    setAbonentPhoneNumber(phoneNumber);
}

//геттери для одержання інформації
string Abonent::getName() {
    return this->name;
}

string Abonent::getAddress() {
    return this->address;
}

string Abonent::getPhoneNumber() {
    return this->phoneNumber;
}

//сетери для запису інформації
void Abonent::setName(string name) {
    if (name.length()>0){
        this->name = name;
    }
    else{
        this->name = "";
    }

}

void Abonent::setAddress(string address) {
    if (address.length()>0){
        this->address = address;
    }
    else{
        this->address = "";
    }
}

void Abonent::setAbonentPhoneNumber(string phoneNumber) {
    if (this->isPhoneNumberValid(phoneNumber)) {
        this->phoneNumber = phoneNumber;
    } else {
        this->phoneNumber = "";
    }
}

// публічні методи класу Абонент
bool Abonent::isPhoneNumberValid(string phoneNumber) {
    // Перевірка на те, щоб номер телефону складався з 10 цифр
    if (phoneNumber.length() != 10) {
        return false;
    }
    // Перевірка на те, щоб всі символи номеру телефону були цифрами
    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int Abonent::sumDigits() {
    int sum = 0;
    for (char c: this->phoneNumber) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}
