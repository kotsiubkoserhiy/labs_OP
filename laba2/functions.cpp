#include "functions.h"

using namespace std;

// Функція для створення телефонної книги, запис у файл
void createTellBook (string namefile){
    TBook temp;
    ofstream createFile (namefile, ios::out | ios::binary);
    int n;
    cout << "Введіть кількість записів: "; cin >>n;
    for (int i = 1; i<=n ; i++){
        cout<<i<<" запиc: "<<endl;
        string  t = getPhoneNumber().c_str();
        strcpy(temp.phone_number, t.c_str());
        string ts, te;
        getCallTimes(ts,te);
        strcpy(temp.start_time, ts.c_str());
        strcpy(temp.end_time, te.c_str());
        createFile.write((char*) &temp, sizeof (temp));
    }
    createFile.close();
}

// Функція для виведення інформації з файла на екран
void outTellBook (string namefile){
    TBook temp;
    ifstream inFile (namefile, ios::in | ios::binary);
    cout << "Номер\t\tГодини розмови\tТривалість\tВартість\n";
    while (inFile.read((char*) &temp, sizeof (temp))){
        cout << temp.phone_number << "\t"<< temp.start_time<<" - "<< temp.end_time<<"\t"<<temp.interval<<"\t\t\t"<<temp.cost<<'\n';
    }
    inFile.close();
}

// Функція для зчитування створеної телефонної книги у вектор
void readTellBook (string namefile, vector <TBook> &tbook){
    TBook temp;
    ifstream inFile (namefile, ios:: binary);
    while (inFile.read((char*) &temp, sizeof (temp))){
        tbook.push_back(temp);
    }
    inFile.close();
}

// Функція для запису створеної телефонної книги у вектор
void writeTellBook (string namefile, vector <TBook> &tbook){
    ofstream writeFile (namefile, ios::binary);
    for (auto temp : tbook){
        writeFile.write((char*) &temp, sizeof (temp));
    }

    writeFile.close();
}

// Функція для введення номера телефонна з перевіркою
string getPhoneNumber() {
    string phone_number;
    cout << "Введіть номер телефону (10 Numbers): ";
    cin >> phone_number;
    // Перевірка на правильний формат номера телефону (10 цифр)
    while (phone_number.length() != 10 || !all_of(phone_number.begin(), phone_number.end(), ::isdigit)) {
        cout << "Некоректний формат номера телефону! Введіть 10 цифр: ";
        cin >> phone_number;
    }
    return phone_number;
}

// Функція для запиту часу початку та кінця переговорів
void getCallTimes(string &start_time, string &end_time) { // введення часу розмови з перевіркою
    cout << "Введіть початок переговорів (ГГ:ХХ): ";
    cin >> start_time;
    // Перевірка на правильний формат часу (ГГ:ХХ)
    while (start_time.length() != 5 || !isdigit(start_time[0]) || !isdigit(start_time[1]) || start_time[2] != ':' || !isdigit(start_time[3]) || !isdigit(start_time[4])) {
        cout << "Некоректний формат часу! Введіть ГГ:ХХ: ";
        cin >> start_time;
    }

    cout << "Введіть кінець переговорів (ГГ:ХХ): ";
    cin >> end_time;
    // Перевірка на правильний формат часу (ГГ:ХХ)
    while (end_time.length() != 5 || !isdigit(end_time[0]) || !isdigit(end_time[1]) || end_time[2] != ':' || !isdigit(end_time[3]) || !isdigit(end_time[4])) {
        cout << "Некоректний формат часу! Введіть ГГ:ХХ: ";
        cin >> end_time;
    }
}

// Функція для розбиття часу на години та хвилини
void getTimeParts(string time_str, int &hour, int &minute) { // розбиття часу на години та хвилини
    hour = stoi(time_str.substr(0, 2));
    minute = stoi(time_str.substr(3, 2));
}

// Функція для обчислення вартості дзвінка на основі тривалості та часу доби
double calculateCallCost(int total_minutes, int start_hour, int start_minute, int end_hour, int end_minute) {
    double cost = 0.0;
    if (start_hour >= 9 && end_hour < 20) {
        // Розмова вдень
        cost = total_minutes * 1.5;
    } else if (start_hour >= 20 || end_hour < 9) {
        // Розмова вночі
        cost = total_minutes * 0.9;
    } else if (start_hour < 9 && end_hour >= 9 && end_hour < 20) {
        // Розмова починається вночі, а закінчується вдень
        int day_minutes = (end_hour - 9) * 60 + end_minute;
        int night_minutes = total_minutes - day_minutes;
        cost = day_minutes * 1.5 + night_minutes * 0.9;
    } else if (start_hour <20 && end_hour >= 20 && start_hour < 9) {
        // Розмова починається вдень, а закінчується вночі
        int night_minutes = (24 - start_hour) * 60 - start_minute;
        int day_minutes = total_minutes - night_minutes;
        cost = day_minutes * 1.5 + night_minutes * 0.9;
    } else {
        // Розмова охоплює дві періоди (день та ніч)
        int day_minutes = (20 - start_hour) * 60 - start_minute;
        int night_minutes = total_minutes - day_minutes;
        cost = day_minutes * 1.5 + night_minutes * 0.9;
    }
    return cost;
}

// Функція для обробки телефонної книги згідно із завданням
void transformTellBook (string namefile){
    vector <TBook> telbook;
    readTellBook(namefile,telbook);
    int i=0;
    int start_hour, start_minute, end_hour, end_minute;
    cout<<"Тривалість розмов:\n";
    cout << "Номер\t\tГодини розмови\tТривалість\n";
    while(i<telbook.size()){
        string start_time = telbook[i].start_time;
        getTimeParts(start_time, start_hour, start_minute);
        string end_time = telbook[i].end_time;
        getTimeParts(end_time, end_hour, end_minute);
        int total_minutes = (end_hour - start_hour) * 60 + (end_minute - start_minute);
        telbook[i].interval = total_minutes;

        cout << telbook[i].phone_number << "\t" << telbook[i].start_time<<" - "<<telbook[i].end_time<<"\t"<<telbook[i].interval<<"хв\n";

        // якщо тривалість розмови менше 3 хв, то вилучаємо розмову з тел книги
        if (total_minutes <3) {telbook.erase(telbook.begin()+i); continue;}

        telbook[i].cost = calculateCallCost(total_minutes,start_hour,start_minute,end_hour,end_minute);
        i++;
    }

    writeTellBook(namefile, telbook);
}