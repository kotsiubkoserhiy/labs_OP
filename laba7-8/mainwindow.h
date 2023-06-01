#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "realnumbersfile.h"
#include <QApplication>
#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QPalette>


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void inputValuesButtonClicked();
    void processButtonClicked();
    void clearDataButtonClicked();

private:
    QLineEdit *inputCountLineEdit;
    QLineEdit *minValueLineEdit;
    QLineEdit *maxValueLineEdit;
    QLineEdit *factorLineEdit;
    QPlainTextEdit *outputTextEdit;

    RealNumbersFile inputFileObj;

    void setupUI();
};

#endif // MAINWINDOW_H
