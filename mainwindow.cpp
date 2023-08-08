#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button1_clicked()
{
    numberClicked(1.0);
}


void MainWindow::on_button2_clicked()
{
    numberClicked(2.0);
}


void MainWindow::on_button3_clicked()
{
    numberClicked(3.0);
}


void MainWindow::on_button4_clicked()
{
    numberClicked(4.0);
}


void MainWindow::on_button5_clicked()
{
    numberClicked(5.0);
}


void MainWindow::on_button6_clicked()
{
    numberClicked(6.0);
}


void MainWindow::on_button7_clicked()
{
    numberClicked(7.0);
}


void MainWindow::on_button8_clicked()
{
    numberClicked(8.0);
}


void MainWindow::on_button9_clicked()
{
    numberClicked(9.0);
}


void MainWindow::on_button0_clicked()
{
    numberClicked(0.0);
}


void MainWindow::on_buttonDot_clicked()
{
    if (_countSignesAfterDot == 0) {
        _countSignesAfterDot++;
        ui->lcdOperand->display(QString::number(_operand) + ".0");
    }

}


void MainWindow::on_buttonSign_clicked()
{

}


void MainWindow::on_buttonPlus_clicked()
{

}


void MainWindow::on_buttonMenos_clicked()
{

}


void MainWindow::on_buttonMultiply_clicked()
{

}


void MainWindow::on_buttonDivide_clicked()
{

}


void MainWindow::on_buttonEqual_clicked()
{

}


void MainWindow::on_buttonBackspace_clicked()
{
    if (_countSignesAfterDot > 0) {
        _countSignesAfterDot--;
    } else {
        _operand = _operand / 10;
    }
    updateLcdOperand();
}


void MainWindow::on_buttonClear_clicked()
{
    _operand = 0;
    _countSignesAfterDot = 0;
    updateLcdOperand();
}

void MainWindow::updateLcdOperand()
{
    ui->lcdOperand->display(_operand);
}

void MainWindow::numberClicked(double num)
{
    if (_countSignesAfterDot > 0) {
        for (int i = 0; i < _countSignesAfterDot; i++) {
            num = num / 10;
        }
        _operand = _operand + num;
        _countSignesAfterDot++;
    }
    else {
        _operand = _operand * 10 + num;
    }

    updateLcdOperand();
}

