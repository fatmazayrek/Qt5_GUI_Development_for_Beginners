#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(const int &ID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->lineEdit->setText(QString::number(ID));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_upButton_clicked()
{
    emit UP();
}


void MyWidget::on_downButton_clicked()
{
    emit DOWN();
}

