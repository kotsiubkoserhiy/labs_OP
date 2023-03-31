#ifndef TEST3_ABONENT_H
#define TEST3_ABONENT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Abonent {
private:
    string name;
    string address;
    string phoneNumber;
    bool isPhoneNumberValid(string);

public:
    Abonent();
    Abonent(string, string, string);

    string getName();
    string getAddress();
    string getPhoneNumber();

    void setName(string);
    void setAddress(string);
    void setAbonentPhoneNumber(string);

    int sumDigits();
};
#endif //TEST3_ABONENT_H
