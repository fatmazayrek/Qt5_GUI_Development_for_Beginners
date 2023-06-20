#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setdef();

    isEnglish = false;

    connect(ui->pushButton, &QPushButton::clicked, [=](bool click)
    {
        isEnglish = !isEnglish;
    });

    translator.load(":/language.qm");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(!isEnglish)
    {
        qApp->installTranslator(&translator);

        ui->pushButton->setText("Translate Turkish");

        ui->lineEdit->setPlaceholderText(tr("Hello"));
    }
    else
    {
        qApp->removeTranslator(&translator);

        ui->pushButton->setText("İngilizce çevir");

        ui->lineEdit->setPlaceholderText(tr("Merhaba"));

        translator.load(":/language.qm");
    }
}

void MainWindow::setdef()
{
    ui->lineEdit->setPlaceholderText(tr("Merhaba"));
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

