#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixMap("://Images/sleep.jpg");

    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setPixmap(pixMap);
}

Widget::~Widget()
{
    delete ui;
}

