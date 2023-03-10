#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFont>
#include <QDebug>
#include <QDateTime>
#include "thewatch.h"
#include "watchupdaterthread.h"
#include <QThreadPool>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    TheWatch *thewatch;
    WatchUpdaterThread *thread;
};
#endif // WIDGET_H
