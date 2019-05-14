#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "BigNumbers.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    std::vector<int> lhsVector;
    std::vector<int> rhsVector;
    std::string lhs = ui->lhsText->toPlainText().toLocal8Bit().constData();
    std::string rhs = ui->rhsText->toPlainText().toLocal8Bit().constData();

    //Build vectors for lhs and rhs
    for (char& c: lhs) {
        lhsVector.push_back(c - 48);
    }
    for (char& c: rhs) {
        rhsVector.push_back(c - 48);
    }

    BigNumbers::BigNumber lhsB(lhsVector);
    BigNumbers::BigNumber rhsB(rhsVector);

    BigNumbers::BigNumber resB;
    resB = lhsB + rhsB;

    std::string result;
    result = resB.toString();

    ui->label->setText(QString::fromStdString(result));

}

void MainWindow::on_subButton_clicked()
{
    std::vector<int> lhsVector;
    std::vector<int> rhsVector;
    std::string lhs = ui->lhsText->toPlainText().toLocal8Bit().constData();
    std::string rhs = ui->rhsText->toPlainText().toLocal8Bit().constData();

    //Build vectors for lhs and rhs
    for (char& c: lhs) {
        lhsVector.push_back(c - 48);
    }
    for (char& c: rhs) {
        rhsVector.push_back(c - 48);
    }

    BigNumbers::BigNumber lhsB(lhsVector);
    BigNumbers::BigNumber rhsB(rhsVector);

    BigNumbers::BigNumber resB;
    resB = lhsB - rhsB;

    std::string result;
    result = resB.toString();

    ui->label->setText(QString::fromStdString(result));
}

void MainWindow::on_multButton_clicked()
{
    std::vector<int> lhsVector;
    std::vector<int> rhsVector;
    std::string lhs = ui->lhsText->toPlainText().toLocal8Bit().constData();
    std::string rhs = ui->rhsText->toPlainText().toLocal8Bit().constData();

    //Build vectors for lhs and rhs
    for (char& c: lhs) {
        lhsVector.push_back(c - 48);
    }
    for (char& c: rhs) {
        rhsVector.push_back(c - 48);
    }

    BigNumbers::BigNumber lhsB(lhsVector);
    BigNumbers::BigNumber rhsB(rhsVector);

    BigNumbers::BigNumber resB;
    resB = lhsB * rhsB;

    std::string result;
    result = resB.toString();

    ui->label->setText(QString::fromStdString(result));
}
