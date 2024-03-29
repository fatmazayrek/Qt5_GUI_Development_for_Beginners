#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_yazdirButton_clicked();

    void on_selectDil_clicked();

    void on_selectDil_2_clicked();

private:
    Ui::MainWindow *ui;

    QTranslator t;

private:
    QTranslator translator;

    void setDefault();


    // QWidget interface
protected:
    void changeEvent(QEvent *event);
};
#endif // MAINWINDOW_H
