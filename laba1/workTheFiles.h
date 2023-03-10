//
// Created by mac user on 09.03.2023.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#ifndef LABA1_WORKTHEFILES_H
#define LABA1_WORKTHEFILES_H
//--------createFile--------
void createFile(char path[]);
void createFile(string path);
//--------readFile--------
void readFile(char path[]);
void readFile(string path);
//--------addFile--------
void addFile(char path[], int len, int p);
void addFile(string path, int len, int p);
//--------writeFile------
void writeFile(char path[], char*);
void writeFile(string path, string data);
#endif //LABA1_WORKTHEFILES_H
