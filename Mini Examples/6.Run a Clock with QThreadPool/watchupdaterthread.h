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
#include "thewatch.h"

class WatchUpdaterThread : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit WatchUpdaterThread(QObject *parent = nullptr);

    void run() override;

signals:
    void updateTimeFromThread(QString timetext);
};

#endif // WATCHUPDATERTHREAD_H
