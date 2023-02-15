#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thewatch = new TheWatch();
    runnable = new WatchUpdaterThread(this);  //this eklediğinde widget kapandığında thread durur


    pool = QThreadPool::globalInstance();

    ui->verticalLayout->addWidget(thewatch);

    connect(runnable, SIGNAL(updateTimeFromThread(QString)), thewatch, SLOT(writeUpdatedTime(QString)));

    runnable->setAutoDelete(true);
    pool->start(runnable);
}

Widget::~Widget()
{
    delete ui;
//    runnable->exit();


    delete thewatch;
}

