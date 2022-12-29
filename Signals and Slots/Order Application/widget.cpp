#include "widget.h"
#include "ui_widget.h"
#include <QCheckBox>
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QEventLoop>
#include <QPixmap>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QEventLoop loop;

    ui->progressBar->setTextVisible(false);
    ui->progressBar->setValue(0);

    connect(ui->checkBox, &QCheckBox::toggled, [=](bool a)
    {
        if(a && this->counter < 2)
        {
            this->counter++;
            this->text.append(ui->checkBox->text() + "\n");
        }
        else if(!a)
        {
            this->counter--;
            this->text.remove(ui->checkBox->text());
        }
        else
        {
           createMessageBox(ui->checkBox);
        }

        ui->textEdit->setText(text);

        qDebug() << this->counter;
    });

    connect(ui->checkBox_2, &QCheckBox::toggled, [=](bool a)
    {
        if(a && this->counter < 2)
        {
            this->counter++;
            this->text.append(ui->checkBox_2->text() + "\n");
        }
        else if(!a)
        {
            this->counter--;
            this->text.remove(ui->checkBox_2->text());
        }
        else
        {
            createMessageBox(ui->checkBox_2);
        }

        ui->textEdit->setText(text);

        qDebug() << this->counter;
    });

    connect(ui->checkBox_3, &QCheckBox::toggled, [=](bool a)
    {
        if(a && this->counter < 2)
        {
            this->counter++;
            this->text.append(ui->checkBox_3->text() + "\n");
        }
        else if(!a)
        {
            this->counter--;
            this->text.remove(ui->checkBox_3->text());
        }
        else
        {
            createMessageBox(ui->checkBox_3);
        }

        ui->textEdit->setText(text);

        qDebug() << this->counter;
    });

    connect(ui->checkBox_4, &QCheckBox::toggled, [=](bool a)
    {
        if(a && this->counter < 2)
        {
            this->counter++;
            this->text.append(ui->checkBox_4->text() + "\n");
        }
        else if(!a)
        {
            this->counter--;
            this->text.remove(ui->checkBox_4->text());
        }
        else
        {
            createMessageBox(ui->checkBox_4);
        }

        ui->textEdit->setText(text);

        qDebug() << this->counter;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createMessageBox(QCheckBox *checkboxes)
{
    QMessageBox messagebox;
    messagebox.setIcon(QMessageBox::Critical);
    messagebox.setWindowTitle("Hata");
    messagebox.setInformativeText("En fazla 2 malzeme seçebilirsiniz");
    messagebox.setStandardButtons(QMessageBox::Cancel);
    messagebox.exec();
    checkboxes->setChecked(false);
    this->counter++;
}

void Widget::on_pushButton_clicked()
{
    if(this->counter < 1){
        QMessageBox messagebox;
        messagebox.setIcon(QMessageBox::Critical);
        messagebox.setWindowTitle("Hata");
        messagebox.setInformativeText("En az 1 malzeme seçmeniz gerekmektedir.");
        messagebox.setStandardButtons(QMessageBox::Cancel);
        messagebox.exec();
    }
    else{
        QPixmap pixmap("C:/Users/Fatma/OneDrive/Masaüstü/Fatma/DERSLER-KODLAR/KODLAR/Qt5 GUI/Example_3/Hamburger.png");
        QMessageBox messagebox;
        messagebox.setIconPixmap(pixmap);
        messagebox.setWindowTitle("Sipariş alındı");
        messagebox.setInformativeText("Siparişiniz alındı. Bizi tercih ettiğiniz için teşekkür ederiz <3");
        messagebox.exec();
    }
}

