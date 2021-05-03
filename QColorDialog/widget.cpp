#include "widget.h"
#include "ui_widget.h"
#include<QColorDialog>
#include<QDebug>
#include<QColor>
#include<QPalette>
#include<QFontDialog>
#include<QFont>
#include<QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_TextColorpushButton_clicked()
{
    QPalette palette =ui->label->palette();
    QColor color=palette.color(QPalette::WindowText);
    QColor chosencolor=QColorDialog::getColor(color,this,"choose text color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::WindowText,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a valid color";
    }
    else
    {
        qDebug()<<"User chosen invalid color";
    }
}


void Widget::on_FontpushButton_clicked()
{
    bool ok;
      QFont font=QFontDialog::getFont(&ok,QFont("Times New Roman",10),this);
      if(ok)
      {
          ui->label->setFont(font);
      }
      else
      {
   QMessageBox::information(this,"Message","user didn't chose font");
      }
}

void Widget::on_BackgroundColorpushButton_clicked()
{
    QPalette palette =ui->label->palette();
       QColor color=palette.color(QPalette::Window);
       QColor chosencolor=QColorDialog::getColor(color,this,"choose text color");
       if(chosencolor.isValid())
       {
           palette.setColor(QPalette::Window,chosencolor);
           ui->label->setPalette(palette);
           qDebug()<<"User chosen a valid color";
       }
       else
       {
           qDebug()<<"User chosen invalid color";
       }
}
