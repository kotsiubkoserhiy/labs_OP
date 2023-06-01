#include "realnumbersfile.h"

RealNumbersFile::RealNumbersFile(const string& filename) : filename(filename) {}

// Метод для запису масиву значень у файл
void RealNumbersFile::writeToFile(double* values, int count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Cannot open file: " + filename);
    }

    file.write(reinterpret_cast<char*>(values), count * sizeof(double));
    if (file.fail()) {
        throw std::runtime_error("Error writing to file: " + filename);
    }

    file.close();
}

// Метод для зчитування значень з файлу у масив
void RealNumbersFile::readFromFile() {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    int count = fileSize / sizeof(double);
    if (count > MAX_NUMBERS) {
        throw std::runtime_error("File contains too many numbers.");
    }

    numbersCount = 0;
    while (numbersCount < count && file.read(reinterpret_cast<char*>(&numbers[numbersCount]), sizeof(double))) {
        numbersCount++;
    }

    file.close();
}

// Метод для запису оброблених значень у вихідний файл
void RealNumbersFile::writeProcessedFile(const string& outputFilename, double minValue, double maxValue, int factor) {
    ofstream outputFile(outputFilename, ios::binary);
    if (!outputFile) {
        throw runtime_error("Cannot open output file: " + outputFilename);
    }

    for (int i = 0; i < numbersCount; i++) {
        double number = numbers[i];

        if (number >= minValue && number <= maxValue) {
            double result = number * factor;

            if (result < number && result / factor != number) {
                throw overflow_error("Overflow occurred.");
            } else if (result > number && result / factor != number) {
                throw underflow_error("Underflow occurred.");
            }

            outputFile.write(reinterpret_cast<char*>(&result), sizeof(double));
            if (outputFile.fail()) {
                throw runtime_error("Error writing to file: " + outputFilename);
            }
        }
    }

    outputFile.close();
}

// Метод для зчитування оброблених значень з вихідного файлу та їх виведення
void RealNumbersFile::readProcessedFile(const string& outputFilename, QPlainTextEdit* outputTextEdit) {
    ifstream file(outputFilename, ios::binary);
    if (!file) {
        throw runtime_error("Cannot open output file: " + outputFilename);
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    int count = fileSize / sizeof(double);
    if (count > MAX_NUMBERS) {
        throw runtime_error("Output file contains too many numbers.");
    }

    outputTextEdit->clear();
    outputTextEdit->appendPlainText("Output file content:");
    for (int i = 0; i < count; i++) {
        double number;
        if (file.read(reinterpret_cast<char*>(&number), sizeof(double))) {
            outputTextEdit->appendPlainText(QString::number(number));
        } else {
            throw runtime_error("Error reading from output file: " + outputFilename);
        }
    }

    file.close();
}

// Метод для очищення даних
void RealNumbersFile::clearData() {
    numbersCount = 0;
}
