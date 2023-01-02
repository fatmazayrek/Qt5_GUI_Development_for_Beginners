#include "mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QPushButton>
#include <QApplication>
#include <QAction>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *pushButton1 = new QPushButton("Click me", this);
    pushButton1->move(250, 250);

    //Create QAction menus --->
    QAction *quitAction = new QAction("Quit", this);
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    QAction *readMessage = new QAction("Read Message");
    connect(readMessage, SIGNAL(triggered(bool)), this, SLOT(openWindow()));

    //Adding shortcut --->
    QAction *copy = new QAction("Copy");
    copy->setShortcut(Qt::Key_Enter);

    QAction *cut = new QAction("Cut");
    copy->setShortcut(Qt::Key_A);

    //Create MenuBar ---->
    QMenu *file = menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Tools");
    QMenu *help = menuBar()->addMenu("Help");

    //Adding action into the MenuBar ---->
    file->addAction(quitAction);
    file->addAction(copy);
    file->addAction(cut);
    help->addAction(readMessage);

    statusBar()->showMessage("Uploading files", 4570);

}

MainWindow::~MainWindow()
{
}

void MainWindow::openWindow()
{
    QMessageBox msg;
    msg.setIcon(QMessageBox::Warning);
    msg.setInformativeText("Button Test:)");
    msg.setWindowTitle("Check Button");
    msg.exec();
}

