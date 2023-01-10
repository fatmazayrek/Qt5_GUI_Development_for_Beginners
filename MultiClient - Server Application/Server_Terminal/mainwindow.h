#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QSet>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPushButton>
#include <QInputDialog>

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
    void newMessage(QString);

private slots:
    void newConnection();
    void appendClient(QTcpSocket *client);

    void readClient();
    void disConnected();

    void showMessage(const QString &message);
    void sendMessage(QTcpSocket *client);

    void on_pushButton_clicked();

    void refCombobox();
    void replaceMessage(QByteArray &byteArray);

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QSet<QTcpSocket*> clients_set;
};
#endif // MAINWINDOW_H
