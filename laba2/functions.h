#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifndef LABA2_FUNCTIONS_H
#define LABA2_FUNCTIONS_H

using namespace std;

struct TBook {
    char phone_number[11];
    char start_time [6], end_time [6];
    int interval = 0;
    double cost = 0;
};

void createTellBook (string);
void outTellBook (string);
void readTellBook (string, vector <TBook>&);
void writeTellBook (string, vector <TBook>&);
void transformTellBook (string);
string getPhoneNumber();
void getCallTimes(string &start_time, string &end_time);
void getTimeParts(string time_str, int &hour, int &minute);
double calculateCallCost(int total_minutes, int start_hour, int start_minute, int end_hour, int end_minute);
#endif //LABA2_FUNCTIONS_H
