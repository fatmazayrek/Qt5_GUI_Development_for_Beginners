#ifndef THEWATCH_H
#define THEWATCH_H

#include <QWidget>
#include <QThread>

#include <QLabel>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>
#include <QDateTime>

class TheWatch : public QWidget
{
    Q_OBJECT

public:
    explicit TheWatch(QWidget *parent = nullptr);

signals:
    void timeUpdated(QString timeText);

public slots:
    void writeUpdatedTime(QString timeText);

private:
    QLabel *label;
};

#endif // THEWATCH_H
