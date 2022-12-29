#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int counter = 0;
    QString text = "";


private:
    Ui::Widget *ui;
    void createMessageBox(QCheckBox *checkboxes);


private slots:
    void on_pushButton_clicked();
};
#endif // WIDGET_H
