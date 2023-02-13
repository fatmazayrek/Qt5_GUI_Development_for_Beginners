#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    thewatch = new TheWatch();
    thread = new WatchUpdaterThread(this);

//    QVBoxLayout *vlayout;
//    vlayout->addWidget(thewatch);
//    setLayout(vlayout);

    ui->verticalLayout->addWidget(thewatch);

    connect(thread, SIGNAL(updateTimeFromThread(QString)), thewatch, SLOT(writeUpdatedTime(QString)) );

    thread->start();
}

Widget::~Widget()
{
    delete ui;

    thread->exit();

    delete thread;
    delete thewatch;
}

