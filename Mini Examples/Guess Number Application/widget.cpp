#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(0));
    guessNumber = rand() % 10 + 1;

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QMessageBox messageBox;
    bool ok;
    numberInput = ui->NumberEdit->text().toInt(&ok);
    ui->messageLabel->clear();

    try{
        if(!ok){
            throw numberInput;
        }

        else{
            if(numberInput > guessNumber){
                ui->messageLabel->setText(ui->messageLabel->text().append(" NO!! greater than actual number:(("));
            }

            else if(numberInput == guessNumber){
                ui->messageLabel->setText(ui->messageLabel->text().append("YES!! Right Guess:))"));
            this->close();
            }

            else{
                 ui->messageLabel->setText(ui->messageLabel->text().append(" NO!! less than actual number:(("));
            }
        }
    }

    catch(int a){
        messageBox.setIcon(QMessageBox::Critical);
        messageBox.setWindowTitle("Error");
        messageBox.setText("You must input the integer value!!");
        messageBox.setInformativeText("Click Cancel Button for EXIT or Click Reset Button for RETRY:)");
        messageBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Reset);
        int ret = messageBox.exec();

        if(ret == QMessageBox::Reset){
            ui->NumberEdit->clear();
        }
    }
}

