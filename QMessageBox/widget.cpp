#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    *addOrCancel = 0;

    QIcon icon("C:/Users/Fatma/OneDrive/Masaüstü/Fatma/DERSLER-KODLAR/KODLAR/Qt5 GUI/QMessageBox_Example/buttonImage.png");

    QFont f1("Trebuchet MS", 11, QFont::Cursive);

    QPushButton *button1 = new QPushButton("Click this", this);
    button1->move(360, 260);
    button1->setMinimumHeight(55);
    button1->setMinimumWidth(58);
    button1->setFont(f1);
    button1->setIcon(icon);

    //connect signal of button with slot
    connect(button1, &QPushButton::clicked, this, &Widget::on_pushButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonClicked()
{
    QPixmap pixmap("C:/Users/Fatma/OneDrive/Masaüstü/Fatma/DERSLER-KODLAR/KODLAR/Qt5 GUI/QMessageBox_Example/enter.png");

    QMessageBox msg;
    msg.setMinimumSize(300, 200);
    msg.setWindowTitle("MessageBox");
    msg.setInformativeText("If you want to enter a name, click <b>Add</b>. If you don't want it, click <b>Cancel<\b>.");
    msg.setIconPixmap(pixmap);

    QPushButton *add = msg.addButton(tr("Add"), QMessageBox::ActionRole);
    QPushButton *cancel = msg.addButton(tr("Cancel"), QMessageBox::YesRole);

    msg.setDefaultButton(cancel);
    msg.exec();

    if(msg.clickedButton() == add)
    {
        qDebug() << "You Clicked Add Button";
    }

    else if(msg.clickedButton() == cancel)
    {
        qDebug() << "You clicked Cancel Button";
    }

    else
    {
        qDebug() << "You didn't click any button";
    }
}

