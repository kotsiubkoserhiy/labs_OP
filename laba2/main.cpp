#include "functions.h"

using namespace std;

int main() {
    string namefile;
    cout <<"Введіть імʼя файла: "; cin >> namefile;
    createTellBook(namefile);
    cout << "Телефонна книга: " << endl;
    outTellBook(namefile);
    transformTellBook(namefile);
    cout <<"Оброблена телефонна книга: " <<endl;
    outTellBook(namefile);
    return 0;
}
