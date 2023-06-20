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

signals:
    void sendDil(QString language);
private slots:
    void on_yazdirButton_clicked();

    void on_selectDil_clicked();

private:
    Ui::MainWindow *ui;

    QTranslator t;

private:
    void setDefault();

};
#endif // MAINWINDOW_H
