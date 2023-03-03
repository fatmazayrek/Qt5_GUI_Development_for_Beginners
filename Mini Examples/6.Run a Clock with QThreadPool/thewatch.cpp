#include "thewatch.h"

TheWatch::TheWatch(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);

    label = new QLabel(QString("00:00:00"));

    QString strFont = "font: 75 108pt 'Comic Sans MS',";

    label->setStyleSheet(strFont);
    label->setAlignment(Qt::AlignCenter);
    label->setMargin(0); // to stretch the widget

    qDebug() << "TheWatch Constructor, Thread ID: " << QThread::currentThread();

    layout->addWidget(label);
}

void TheWatch::writeUpdatedTime(QString timeText)
{
    label->setText(timeText);
}
