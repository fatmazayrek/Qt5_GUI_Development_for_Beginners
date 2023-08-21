#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStyleFactory>
#include <QDebug>
#include <QTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);

    setMaximumSize(400, 400);

    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_write_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Kaydet");

    if(filename.isEmpty())
    {
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}


void MainWindow::on_read_clicked()
{
    QString fileContent;
    idx = 1;

    QString filename = QFileDialog::getOpenFileName(this, "Open File");

    ui->lineEdit->setText(filename);

    if(filename.isEmpty())
    {
        return;
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();

        fileContent.append(line);

        QStringList strlist = line.split(";");

        numberlist.append(strlist.at(0));
        datalist.append(strlist.at(1));
    }

    ui->textEdit->setText(fileContent);

    file.close();
}


void MainWindow::on_select_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File");

    if(filename.isEmpty())
    {
        return;
    }

    ui->lineEdit->setText(filename);
}


void MainWindow::on_copy_clicked()
{
    QString srcText = ui->lineEdit->text();

    QString dstText = ui->lineEdit_2->text();

    if(srcText.isEmpty() | dstText.isEmpty())
    {
        return;
    }

    QFile file(srcText);

    if(file.copy(dstText))
    {
        qDebug() << "Success";
    }
    else
    {
        qDebug() << "Fail";
    }
}

void MainWindow::timerSlot()
{
    if(idx < numberlist.size())
    {
        double fark = numberlist[idx].toDouble() - numberlist[idx - 1].toDouble();

        qDebug() << QTime::currentTime() << datalist.at(idx - 1) << fark * 1000;

        timer->start(static_cast<int>(fark * 1000.0));

        idx ++;
    }
    else
    {
        on_startButton_clicked();
    }
}


void MainWindow::on_startButton_clicked()
{
    idx = 1;
    timer->start(1000);
}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

