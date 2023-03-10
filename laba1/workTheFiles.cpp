//
// Created by mac user on 09.03.2023.
//

#include "workTheFiles.h"
//--------createFile--------
void createFile(char path[]){
    cout << "Creating a file with filePointer: " << endl;
    FILE *writeFile;
    if ((writeFile = fopen(path, "w"))==NULL){
        cout << "Cannot open file" << endl;
        exit(0);
    }
    char str[81];  // масив символів рядка
    cout << "Enter multiple lines (Enter empty string to stop): " << endl;
    do{
        gets(str); // вводимо з клавіатури рядок
        // записуємо у файл
        fputs(str,writeFile);
        fputs("\n",writeFile);
    }while (strlen(str) > 0); // якщо введено не порожній рядок
    fclose(writeFile);
}

void createFile(string path){
    cout << "Creating a file with fileStream: " << endl;
    fstream outFile(path, ios::out);
    if (!outFile){
        cout << "Cannot open file" << endl;
        exit(0);
    }
    string line = ""; //допоміжна змінна
    cout<< "Enter a string of text (Enter empty string to stop): "<< endl;
    do{
        getline(cin, line);
        outFile << line << endl;
    }while (line.size() > 0);
    outFile.close();
}

//--------readFile--------
void readFile(char path[]){
    FILE *readFile;
    if ((readFile = fopen(path, "r"))==NULL){
        cout << "Cannot open file" << endl;
        exit(0);
    }
    char str[81]; //допоміжна змінна
    //читаємо дані поки не кінець файла
    while(fgets(str,81, readFile)){
        cout << str;
    }
    fclose(readFile);
}

void readFile(string path){
    fstream inFile(path, ios::in);
    if (!inFile){
        cout<<"Cannot open file" << endl;
        exit(0);
    }
    string line; //допоміжна змінна
    //читаємо дані поки не кінець файла
    while (!inFile.eof()){
        getline(inFile,line);
        cout << line << endl;
    }
    inFile.close();
}

//--------addFile--------
void addFile(char path[], int len, int p){
    FILE *aFile;
    if ((aFile = fopen(path, "a+"))==NULL){
        cout << "Cannot open file" << endl;
        exit(0);
    }
    // записуємо у файл
    fprintf(aFile, "Length - %d; sequence number - %d", len-1, p);
    fclose(aFile);
}

void addFile(string path, int len, int p){
    fstream aFile(path,ios::app);
    if (!aFile){
        cout<<"Cannot open file" << endl;
        exit(0);
    }
    aFile << "Length - " << len-1 << "; sequence number - " << p << endl;
    aFile.close();
}

//------writeFile-------
void writeFile(char path[], char* data){
    FILE *wFile;
    if ((wFile = fopen(path, "w"))==NULL){
        cout << "Cannot open file" << endl;
        exit(0);
    }
    // записуємо у файл
    fputs(data, wFile);
    fclose(wFile);
}

void writeFile(string path, string data){
    fstream wFile(path,ios::out);
    if (!wFile){
        cout<<"Cannot open file" << endl;
        exit(0);
    }
    wFile << data;
    wFile.close();
}