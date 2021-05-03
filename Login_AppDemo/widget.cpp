#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(username=="Test"&&password=="Test")
    {
        QMessageBox::information(this,"Login","Username and Password is correct");
        hide();
        info=new InfoDialog(this);
        info->show();
       // ui->statusbar->showMessage("Username and Password is correct");

    }
    else
    {
         QMessageBox::warning(this,"Login","Username and Password is incorrect");
    }
}
