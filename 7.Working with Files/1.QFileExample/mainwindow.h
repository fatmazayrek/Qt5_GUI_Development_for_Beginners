#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStringList>

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
    void on_write_clicked();

    void on_read_clicked();

    void on_select_clicked();

    void on_copy_clicked();

    void timerSlot();

    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;

    QStringList numberlist;
    QStringList datalist;
    int idx;
};
#endif // MAINWINDOW_H
