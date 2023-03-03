#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(server->listen(QHostAddress::Any, 3456)){
        qDebug() << "Succesful:)";
    }
    else{
        qDebug() << "Failed";
    }
}

void MainWindow::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("Hello my Friend:)");

    socket->flush();
    socket->waitForBytesWritten(30000);

    socket->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

