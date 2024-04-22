#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(const int &ID, QWidget *parent = nullptr);
    ~MyWidget();

signals:
    void UP();
    void DOWN();

private slots:
    void on_upButton_clicked();
    void on_downButton_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
