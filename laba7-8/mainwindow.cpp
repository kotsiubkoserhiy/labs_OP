#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent), inputFileObj("input.bin")
{
    setupUI();

    // Set color for the program
    QPalette palette;
    palette.setColor(QPalette::Base, Qt::white);
    palette.setColor(QPalette::Text, Qt::black);
    setPalette(palette);

    // Змінити колір кнопок
    palette.setColor(QPalette::Button, QColor(255, 0, 0));

    // Змінити колір фону
    palette.setColor(QPalette::Window, QColor(155, 100, 200));

    // Змінити колір тексту
    palette.setColor(QPalette::WindowText, QColor(0, 0, 0));

    // Встановити палітру для головного вікна
    setPalette(palette);
}


void MainWindow::setupUI()
{
    setWindowTitle("Real Numbers Processor");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QFormLayout *formLayout = new QFormLayout();

    QLabel *inputCountLabel = new QLabel("Enter the number of values:");
    inputCountLineEdit = new QLineEdit();
    formLayout->addRow(inputCountLabel, inputCountLineEdit);

    QPushButton *inputValuesButton = new QPushButton("Enter the values for input file");
    formLayout->addWidget(inputValuesButton);
    connect(inputValuesButton, &QPushButton::clicked, this, &MainWindow::inputValuesButtonClicked);

    QLabel *minValueLabel = new QLabel("Enter the minimum value:");
    minValueLineEdit = new QLineEdit();
    formLayout->addRow(minValueLabel, minValueLineEdit);

    QLabel *maxValueLabel = new QLabel("Enter the maximum value:");
    maxValueLineEdit = new QLineEdit();
    formLayout->addRow(maxValueLabel, maxValueLineEdit);

    QLabel *factorLabel = new QLabel("Enter the factor:");
    factorLineEdit = new QLineEdit();
    formLayout->addRow(factorLabel, factorLineEdit);

    QPushButton *processButton = new QPushButton("Process");
    formLayout->addWidget(processButton);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::processButtonClicked);

    QPushButton *clearDataButton = new QPushButton("Clear Data");
    formLayout->addWidget(clearDataButton);
    connect(clearDataButton, &QPushButton::clicked, this, &MainWindow::clearDataButtonClicked);

    mainLayout->addLayout(formLayout);

    outputTextEdit = new QPlainTextEdit();
    outputTextEdit->setReadOnly(true);
    mainLayout->addWidget(outputTextEdit);
}

void MainWindow::inputValuesButtonClicked()
{
    bool ok;
    int inputCount = inputCountLineEdit->text().toInt(&ok);
    if (ok) {
        double inputValues[MAX_NUMBERS];
        for (int i = 0; i < inputCount; i++) {
            bool ok;
            QString value = QInputDialog::getText(this, "Input", "Enter value #" + QString::number(i + 1), QLineEdit::Normal, "", &ok);
            if (ok && !value.isEmpty()) {
                inputValues[i] = value.toDouble();
            } else {
                QMessageBox::critical(this, "Error", "Invalid input.");
                return;
            }
        }

        try {
            inputFileObj.writeToFile(inputValues, inputCount);
        } catch (const exception& e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
            return;
        }

        QMessageBox::information(this, "Success", "Input file created successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Invalid input count.");
    }
}

void MainWindow::processButtonClicked()
{
    double minValue = minValueLineEdit->text().toDouble();
    double maxValue = maxValueLineEdit->text().toDouble();
    int factor = factorLineEdit->text().toInt();

    string outputFilename = "output.bin";
    try {
        inputFileObj.readFromFile();
        inputFileObj.writeProcessedFile(outputFilename, minValue, maxValue, factor);
        inputFileObj.readProcessedFile(outputFilename, outputTextEdit);
        QMessageBox::information(this, "Success", "Processing completed successfully.");
    } catch (const exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
        return;
    }
}

void MainWindow::clearDataButtonClicked()
{
    inputCountLineEdit->clear();
    minValueLineEdit->clear();
    maxValueLineEdit->clear();
    factorLineEdit->clear();
    outputTextEdit->clear();
    inputFileObj.clearData();
}

