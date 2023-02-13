#ifndef WATCHUPDATERTHREAD_H
#define WATCHUPDATERTHREAD_H

#include <QWidget>
#include <QThread>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>
#include <QDateTime>
#include <QRunnable>
#include <QThreadPool>

class WatchUpdaterThread : public QThread, public QObject
{
    Q_OBJECT

public:
    explicit WatchUpdaterThread(QObject *parent = nullptr);
    void run();

signals:
    void updateTimeFromThread(QString timetext);
};

#endif // WATCHUPDATERTHREAD_H
