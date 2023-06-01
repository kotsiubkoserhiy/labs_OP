#ifndef REALNUMBERSFILE_H
#define REALNUMBERSFILE_H
#include <fstream>
#include <iostream>
#include  <stdexcept>
#include <QPlainTextEdit>

using namespace std;

const int MAX_NUMBERS = 1000;

class RealNumbersFile {
public:
    RealNumbersFile(const std::string& filename);

    void writeToFile(double* values, int count);

    void readFromFile();

    void writeProcessedFile(const string& outputFilename, double minValue, double maxValue, int factor);

    void readProcessedFile(const string& outputFilename, QPlainTextEdit* outputTextEdit);

    void clearData();


private:
    string filename;
    double numbers[MAX_NUMBERS];
    int numbersCount = 0;
};

#endif
