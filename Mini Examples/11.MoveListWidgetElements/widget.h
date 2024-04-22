#ifndef WIDGET_H
#define WIDGET_H

// ::::::::::::Inner Classes::::::::::
#include "mywidgetwindow.h"

// ::::::::::::Qt Libs:::::::::::::
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_nextButton_clicked();
    void on_previousButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
