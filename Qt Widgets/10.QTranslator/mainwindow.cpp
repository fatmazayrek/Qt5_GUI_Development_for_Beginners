#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyleFactory>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    setDefault();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDefault()
{
    ui->isimLabel->setText(tr("İsim"));
    ui->isim->setPlaceholderText(tr("İsim Giriniz "));
    ui->soyisim->setPlaceholderText(tr("Soyisim giriniz"));
    ui->soyisimLabel->setText(tr("soyisim"));
    ui->numara->setPlaceholderText(tr("Numara giriniz"));
    ui->numaraLabel->setText(tr("Numara"));
    ui->yazdirButton->setText(tr("Yazdır"));
}


void MainWindow::on_yazdirButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText(tr("<-İletişim Bilgileri->"));
    msgBox.setInformativeText(tr("İsim: %1 \nSoyisim: %2 \nNumara: %3").arg(ui->isim->text()).arg(ui->soyisim->text()).arg(ui->numara->text()));
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setMinimumSize(200, 100);
    int ret = msgBox.exec();
}


void MainWindow::on_selectDil_clicked()
{

}
