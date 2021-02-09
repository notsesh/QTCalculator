#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sign,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_petcent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_split,SIGNAL(clicked()),this,SLOT(math_operations()));


    ui->pushButton_split->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton*)sender();

   double all_numbers;
   QString new_label;

   if (ui->display->text().contains(".") && button->text() == "0" ) {
       new_label = ui->display->text() + button->text();
   } else {
       all_numbers = (ui->display->text() + button ->text()).toDouble();
       new_label = QString::number(all_numbers, 'g', 15);
   }


   ui->display->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
     if(!(ui->display->text().contains('.')))
     ui->display->setText(ui->display->text() + ".");
}

void MainWindow::operations()
{
   QPushButton *button = (QPushButton*)sender();
   double all_numbers;
   QString new_label;

   if(button->text() == "+/-") {
   all_numbers = (ui->display->text()).toDouble();
   all_numbers = all_numbers * -1;
   new_label = QString::number(all_numbers, 'g', 15);

   ui->display->setText(new_label);
   } else if(button->text() == "%") {
       all_numbers = (ui->display->text()).toDouble();
       all_numbers = all_numbers * 0.01;
       new_label = QString::number(all_numbers, 'g', 15);

       ui->display->setText(new_label);
    }

}


void MainWindow::math_operations()
{


    QPushButton *button = (QPushButton*)sender();

    num_first = ui->display->text().toDouble();
    ui->display->setText("");

    button->setChecked(true);
}


void MainWindow::on_button_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_split->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    ui->display->setText("0");
}

void MainWindow::on_pushButton_equally_clicked()
{

    double LabelNumber, num_second;
    QString new_label;

    num_second = ui->display->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {

        LabelNumber = num_first + num_second;
        new_label = QString::number(LabelNumber, 'g', 15);
        ui->display->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_minus->isChecked()) {

        LabelNumber = num_first - num_second;
        new_label = QString::number(LabelNumber, 'g', 15);
        ui->display->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    } else if (ui->pushButton_split->isChecked()) {

        if (num_second == 0) {

            ui->display->setText("Error");

        }

        else {

        LabelNumber = num_first / num_second;
        new_label = QString::number(LabelNumber, 'g', 15);
        ui->display->setText(new_label);
        ui->pushButton_split->setChecked(false);
        }
    } else if (ui->pushButton_multiply->isChecked()) {

        LabelNumber = num_first * num_second;
        new_label = QString::number(LabelNumber, 'g', 15);
        ui->display->setText(new_label);
        ui->pushButton_multiply->setChecked(false);

    }
}
