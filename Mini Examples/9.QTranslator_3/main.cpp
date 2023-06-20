#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QObject>
#include <QDebug>
#include <QInputDialog>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
