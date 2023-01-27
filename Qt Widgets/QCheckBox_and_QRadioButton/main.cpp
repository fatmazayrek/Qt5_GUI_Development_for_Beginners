#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("QCheckBox and QRadioButton Example");
    w.show();
    return a.exec();
}
