#include "watchupdaterthread.h"

WatchUpdaterThread::WatchUpdaterThread(QObject *parent)
    : QThread{parent}, QObject(parent)
{

}

void WatchUpdaterThread::run()
{
    while(true)
    {
        emit updateTimeFromThread(QDateTime::currentDateTime().toString("hh:mm:ss"));
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss");
        QThread::sleep(1);
    }
}
