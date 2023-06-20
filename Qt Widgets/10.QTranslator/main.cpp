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

    QTranslator t;

    QStringList languages;
    languages << "Türkçe" << "İngilizce";

    QInputDialog dialog;
    dialog.setFixedSize(300, 300);
    QString lang = dialog.getItem(NULL, "Dil Seçiniz", "Language", languages);

    if(lang == "İngilizce")
    {
        t.load(":/almanca.qm");
    }

    if(lang != "Türkçe")
    {
        a.installTranslator(&t);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
