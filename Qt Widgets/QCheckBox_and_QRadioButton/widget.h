#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:

private:
    Ui::Widget *ui;
    int counter = 0;
    QList<QCheckBox*> checkbox_set;

private slots:
    void checkCheckBox(bool checked);
    void on_pushButton_clicked();
};
#endif // WIDGET_H
