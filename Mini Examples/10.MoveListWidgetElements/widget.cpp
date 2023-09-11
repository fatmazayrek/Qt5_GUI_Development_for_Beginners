#include "widget.h"
#include "ui_widget.h"

// ::::::::::::Qt Libs::::::::::::::
#include <QStyleFactory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // ::::::Add Widget::::::
    MyWidgetWindow *myWindow = new MyWidgetWindow(this);
    ui->stackedWidget->insertWidget(1, myWindow);

    ui->stackedWidget->setCurrentIndex(0);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_previousButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

