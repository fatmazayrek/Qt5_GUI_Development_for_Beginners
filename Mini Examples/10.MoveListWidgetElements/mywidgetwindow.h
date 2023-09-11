#ifndef MYWIDGETWINDOW_H
#define MYWIDGETWINDOW_H

// ::::::::::Inner Classes:::::::::
#include "mywidget.h"

// ::::::::::Qt Libs::::::::
#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class MyWidgetWindow;
}

class MyWidgetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidgetWindow(QWidget *parent = nullptr);
    ~MyWidgetWindow();

public slots:
    void UP();
    void DOWN();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MyWidgetWindow *ui;

    bool isFirst;
    int count;

private:
    void moveUP();
    void moveDOWN();
};

#endif // MYWIDGETWINDOW_H
