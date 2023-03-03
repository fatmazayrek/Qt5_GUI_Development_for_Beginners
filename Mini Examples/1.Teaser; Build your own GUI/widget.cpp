#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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
    qDebug() << "Submitting Datas: " << endl << "Name: " << ui->nameEdit->text() << endl << "Surname: " << ui->surnameEdit->text() << endl;

    static QString text;
    text.append("Datas are Submitting:\n");
    text.append(ui->nameEdit->text());
    text.append(' ' + ui->surnameEdit->text() + '\n');
    ui->messageBox->setPlainText(text);

}

