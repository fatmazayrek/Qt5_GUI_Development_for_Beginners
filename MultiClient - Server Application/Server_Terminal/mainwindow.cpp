#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);   //new QTcpServer();
//Server can only read message from client.

    ui->serverMessage->setReadOnly(true);

    if(server->listen(QHostAddress::Any, 1234))
    {
        connect(server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
        connect(this, &MainWindow::newMessage, this, &MainWindow::showMessage);

        ui->statusbar->showMessage("Server is listening");
        ui->serverTextEdit->setText("Users have to input messages in hex format!!");
    }
}

MainWindow::~MainWindow()
{
    foreach (QTcpSocket *client, clients_set)
    {
        client->close();
        client->deleteLater();
    }

    server->close();
    server->deleteLater();

    delete ui;
}

void MainWindow::newConnection()
{
    while(server->hasPendingConnections())
    {
        appendClient(server->nextPendingConnection());
    }
}

void MainWindow::appendClient(QTcpSocket *client)
{
    clients_set.insert(client);
    connect(client, &QTcpSocket::readyRead, this, &MainWindow::readClient);
    connect(client, &QTcpSocket::disconnected, this, &MainWindow::disConnected);

    ui->comboBox->addItem(QString::number(client->socketDescriptor()));

    showMessage(QString("Client with socket: %1 has entered the room").arg(client->socketDescriptor()));
}

void MainWindow::readClient()
{
    QTcpSocket *client = reinterpret_cast<QTcpSocket*>(sender());
//Qobject *Qobject::sender(): Returns a pointer to the object that sent the signal, if called in a slot activated by a signal; otherwise it returns nullptr. The pointer is valid only during the execution of the slot that calls this function from this object's thread context.

    QByteArray byteArray;

    QDataStream socketStream(client);
//QDataStream::QDataStrem(QIODevice *d): Constructs a data stream that uses the I/O device d
    socketStream.setVersion(QDataStream::Qt_5_15);
//void QDataStream::setVersion(int a): Sets the version number of the data serialization format to v, a value of the Version enum. You don't have to set a version if you are using the current version of Qt, but it is recommended.
    socketStream.startTransaction();
    socketStream >> byteArray;
//QDataStream &QDataStream::operator>>(): Reads data.

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 : Waiting for more data to come..").arg(client->socketDescriptor());

        emit newMessage(message);

        return;
    }

    QString message = QString("Incoming message from %1: %2").arg(client->socketDescriptor()).arg(QString::fromStdString(byteArray.toStdString()));

    replaceMessage(byteArray);

    emit newMessage(message);
}

void MainWindow::showMessage(const QString &message)
{
    ui->serverTextEdit->append(message);
}

void MainWindow::disConnected()
{
    QTcpSocket *client = reinterpret_cast<QTcpSocket*>(sender());

    QSet<QTcpSocket*>::iterator it = clients_set.find(client);

    if(it != clients_set.end())
    {
        showMessage(QString(" A Client has left the room"));

        clients_set.remove(*it);
    }

    refCombobox();

    client->deleteLater();
}

void MainWindow::on_pushButton_clicked()
{
    QString receiver = ui->comboBox->currentText();

    if(receiver == "All")
    {
        foreach(QTcpSocket *client, clients_set)
        {
            sendMessage(client);
        }
    }
    else
    {
        foreach(QTcpSocket *client, clients_set)
        {
            if(client->socketDescriptor() == receiver.toLongLong())
            {
                sendMessage(client);

                break;
            }
        }
    }

    ui->serverMessage->setReadOnly(false);
    ui->serverMessage->clear();
    ui->serverMessage->setReadOnly(true);
}

void MainWindow::sendMessage(QTcpSocket *client)
{
    if(client)
    {
        if(client->isOpen())
        {
            QString messagepref;
            messagepref = "%1 : Outgoing replaced message from server: ";

            messagepref = messagepref.arg(client->socketDescriptor());
            QString message = ui->serverMessage->text();
            messagepref.append(message);

            showMessage(messagepref);

            QDataStream socketStream(client);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray byteArray = message.toUtf8();

            socketStream << byteArray;
//QDataStream operator<<(): Writes data i to socket.
        }
        else
        {
            QMessageBox::critical(this, "Server Error", "Socket doesn't seem to be opened");
        }
    }
    else
    {
        QMessageBox::critical(this, "Server Error", "Not connected");
    }
}

void MainWindow::refCombobox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("All");

    foreach(QTcpSocket *client, clients_set)
    {
        ui->comboBox->addItem(QString::number(client->socketDescriptor()));
    }
}

void MainWindow::replaceMessage(QByteArray &byteArray)
{
    ui->serverMessage->setReadOnly(false);

    int size = byteArray.size();

    QByteArray temp;
    QByteArray lastByte = byteArray.mid(size-2, 2);
    QByteArray lastSecByte = byteArray.mid(size-4, 2);

    temp = lastByte;

    byteArray = byteArray.replace(lastByte,lastSecByte);
    byteArray = byteArray.replace(size-4, 2, temp);

    ui->serverMessage->setText(QString::fromStdString(byteArray.toStdString()));
    ui->serverMessage->setReadOnly(true);
}

