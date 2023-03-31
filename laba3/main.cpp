#include <iostream>
#include "Abonent.h"
#include "functions.h"

int main() {
    int num;
    cout << "Enter numbers abonents -> ";
    cin >> num;
    cin.ignore();

    vector <Abonent> abonents (num);
    abonents = createValues(num);
    cout << "----List of subscribers----" << endl;
    for (int i=0; i<num; i++){
        cout<< i << " subscribers" << endl;
        cout << " Name: " << abonents[i].getName() << endl;
        cout << " Address: " << abonents[i].getAddress() << endl;
        cout << " Phone: " << abonents[i].getPhoneNumber() << endl;
    }

    Abonent maxSumAbonent = abonents[0];
    for (int i = 0; i < num; i++) {
        if (abonents[i].sumDigits() > maxSumAbonent.sumDigits()) {
            maxSumAbonent = abonents[i];
        }
    }
    cout << "----Result----" << endl;
    cout << "The subscriber with the largest sum of digits in the phone number: " << maxSumAbonent.getName() << endl;
    cout << "Phone number: " << maxSumAbonent.getPhoneNumber() << endl;
    cout << "Sum of numbers: " << maxSumAbonent.sumDigits() << endl;

    return 0;
}
