#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel *label = new QLabel(this);
    label->setText("Hello");

    QPalette palette1;
    palette1.setColor(QPalette::Normal, QPalette::Window, Qt::yellow);

    QFont labelFont("Helvetica", 23, QFont::DemiBold);
    label->setPalette(palette1);
    label->setFont(labelFont);
    label->setAutoFillBackground(true);   //This makes a highlighted sentences.
    label->move(350, 120);

    QIcon icon("C:/Users/Fatma/OneDrive/Masaüstü/Fatma/DERSLER-KODLAR/KODLAR/Qt5 GUI/Example_QWidget/click_foto.png");
    QFont buttonFont("Times", 13);
    QPushButton *pushbutton1 = new QPushButton("Click This", this);
    pushbutton1->setFont(buttonFont);
    pushbutton1->move(350, 220);
    pushbutton1->setIcon(icon);

    connect(pushbutton1, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonClicked()
{

    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setInformativeText("You clicked this Button");
    msg.exec();
}

