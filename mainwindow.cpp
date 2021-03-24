#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->masmenos, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->porciento, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->sumar, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->restar, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->dividir, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->multiplicar, SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ui->sumar->setCheckable(true);
    ui->restar->setCheckable(true);
    ui->dividir->setCheckable(true);
    ui->multiplicar->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if ((ui->sumar->isChecked() || ui->restar->isChecked() || ui->dividir->isChecked() || ui->multiplicar->isChecked()) &&) {
        labelNumber = button->text().toDouble();
    } else {
        labelNumber = (ui->label->text() + button->text()).toDouble();
    }

    newLabel = QString::number(labelNumber, 'g', 15);

    ui->label->setText(newLabel);

}


void MainWindow::on_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g', 15);
        ui->label->setText(newLabel);
    }

    if (button->text() == "%") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_clear_released()
{

}

void MainWindow::on_igual_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if (ui->sumar->isChecked()) {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->sumar->setChecked(false);
    } else if (ui->restar->isChecked()) {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->restar->setChecked(false);
    } else if (ui->dividir->isChecked()) {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->dividir->setChecked(false);
    } else if (ui->multiplicar->isChecked()) {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->multiplicar->setChecked(false);
    }

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}
