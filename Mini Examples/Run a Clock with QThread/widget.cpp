#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thewatch = new TheWatch();
    thread = new WatchUpdaterThread(this);

    ui->verticalLayout->addWidget(thewatch);

    connect(thread, SIGNAL(updateTimeFromThread(QString)), thewatch, SLOT(writeUpdatedTime(QString)) );

    thread->start();
}

Widget::~Widget()
{
    delete ui;
    delete thewatch;

    thread->quit();
    thread->wait(1000);

    if (!thread->isFinished()) {
        thread->terminate();
    }


}



