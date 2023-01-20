#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    ui->clientMessage->setInputMask("Hhhhhhhhhhhhhhhhhhhhhh");
//User should input the message in hex format.

    ui->clientMessage->setPlaceholderText("You have to input the message in hex format");

    connect(this, &MainWindow::newMessage, this, &MainWindow::showMessage);
    connect(client, &QTcpSocket::readyRead, this, &MainWindow::readClient);
    connect(client, &QTcpSocket::disconnected, this, &MainWindow::disConnected);

    client->connectToHost(QHostAddress::LocalHost, 1234);
//void QAbstractSocket::connectToHost(const QHostAddress &address, int port, QIODevice::OpenMode openMode = ReadWrite): Attempts to make a connection to address on port port.

//enum QHostAddress::LocalHost: The IPv4 localhost address. Equivalent to QHostAddress("127.0.0.1").

    if(client->waitForConnected())
//bool QTcpSocket::waitForConnected(): Waits until the socket is connected, up to msecs milliseconds. If the connection has been established, this function returns true; otherwise it returns false.
    {
        ui->statusbar->showMessage("Connected to Server");
    }

    else
    {
        QMessageBox::critical(this, "Client Error", QString("Not Connected"));
        exit(EXIT_FAILURE);
    }
}

MainWindow::~MainWindow()
{
    if(client->isOpen())
    {
        client->close();
    }

    delete ui;
}

void MainWindow::readClient()
{
    QByteArray byteArray;

    QDataStream socketStream(client);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> byteArray;

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1: Waiting for more data to come").arg(client->socketDescriptor());

        emit newMessage(message);

        return;
    }

    QString message = QString("Message from Server: %1").arg(QString::fromStdString(byteArray.toStdString()));

    emit newMessage(message);
}

void MainWindow::disConnected()
{
    client->deleteLater();
    client = nullptr;

    ui->statusbar->showMessage("Disconnected..");
}

void MainWindow::on_pushButton_clicked()
{
    if(client)
    {
        if(client->isOpen())
        {
            QString message = ui->clientMessage->text();

            QDataStream socketStream(client);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray byteArray = message.toUtf8();

            socketStream << byteArray;

            ui->clientMessage->clear();
        }
        else
        {
            QMessageBox::critical(this, "Client Error", "Socket does't seem to be opened");
        }
    }
    else
    {
        QMessageBox::critical(this, "Client Error", "Not connected");
    }
}

void MainWindow::showMessage(const QString &message)
{
    ui->textEdit->append(message);
}
