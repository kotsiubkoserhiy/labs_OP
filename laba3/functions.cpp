#include "functions.h"

//функції для роботи
string AbonentName (){
    string name;
    cout << "Enter name abonent -> " ;
    getline(cin,name);
    return name;
}

string AbonentAddress (){
    string address;
    cout << "Enter adress abonent -> " ;
    getline(cin, address);
    return address;
}

string AbonentPhoneNumber(){
    string phoneNumber;
    cout << "Enter num tel abonenta (10 numbers) -> " ;
    cin >> phoneNumber;
    cin.ignore();
    return phoneNumber;
}

vector<Abonent> createValues(int n) {
    vector <Abonent> array(n);
    for (int i = 0; i < n; i++) {
        //Enter name
        do {
            array[i].setName(AbonentName());
        } while (array[i].getName() == "");
        //Enter address
        do {
            array[i].setAddress(AbonentAddress());
        } while (array[i].getAddress() == "");
        //Enter phone
        do {
            array[i].setAbonentPhoneNumber(AbonentPhoneNumber());
        } while (array[i].getPhoneNumber() == "");
    }
    return array;
}