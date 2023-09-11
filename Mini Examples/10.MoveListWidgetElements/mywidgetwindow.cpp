#include "mywidgetwindow.h"
#include "ui_mywidgetwindow.h"

#include <QDebug>

MyWidgetWindow::MyWidgetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidgetWindow)
{
    ui->setupUi(this);

    // ::::::::::Görselleme::::::::::
    ui->listWidget->setSpacing(30);


    // ::::::::::Başlangıç Widget'ı Ekle:::::::::::
    QListWidgetItem *listItem = new QListWidgetItem();

    MyWidget *widget = new MyWidget(0, this);

    listItem->setSizeHint(widget->sizeHint()); // Optional: set the item's size hint based on your widget

    ui->listWidget->addItem(listItem);
    ui->listWidget->setItemWidget(listItem, widget);
    ui->listWidget->setSortingEnabled(true);

    connect(widget, &MyWidget::UP, this, &MyWidgetWindow::UP);
    connect(widget, &MyWidget::DOWN, this, &MyWidgetWindow::DOWN);

    // ::::::::Başlangıç Atamalarını Yap:::::::
    isFirst = true;
    count = 1;
}

MyWidgetWindow::~MyWidgetWindow()
{
    delete ui;
}

// ::::::::::::::Public Slots:::::::::::::
void MyWidgetWindow::UP()
{
    moveUP();
}

void MyWidgetWindow::DOWN()
{
    moveDOWN();
}

// :::::::::::::::::Private Slots:::::::::::::
void MyWidgetWindow::on_addButton_clicked()
{
    QListWidgetItem *listItem = new QListWidgetItem();

    MyWidget *widget = new MyWidget(count, this);

    listItem->setSizeHint(widget->sizeHint()); // Optional: set the item's size hint based on your widget

    ui->listWidget->addItem(listItem);
    ui->listWidget->setItemWidget(listItem, widget);

    connect(widget, &MyWidget::UP, this, &MyWidgetWindow::UP);
    connect(widget, &MyWidget::DOWN, this, &MyWidgetWindow::DOWN);
    count++;
}


void MyWidgetWindow::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();

    delete item;
}

void MyWidgetWindow::moveUP()
{
    int currIndex = ui->listWidget->currentRow();

    if(currIndex > 0)
    {
        QListWidgetItem *currentItem = ui->listWidget->item(currIndex);

        QListWidgetItem *listItem = new QListWidgetItem();

        MyWidget *widget = dynamic_cast<MyWidget*>(ui->listWidget->itemWidget(ui->listWidget->item(currIndex)));

        listItem->setSizeHint(widget->sizeHint()); // Optional: set the item's size hint based on your widget

        ui->listWidget->insertItem(currIndex-1, listItem);
        ui->listWidget->setItemWidget(listItem, widget);

        ui->listWidget->setCurrentItem(listItem);

        delete currentItem;
    }
}

void MyWidgetWindow::moveDOWN()
{
    int currIndex = ui->listWidget->currentRow();

    if(currIndex < ui->listWidget->count()-1)
    {
        QListWidgetItem *current = ui->listWidget->currentItem();
        int currIndex = ui->listWidget->row(current);

        QListWidgetItem *next = ui->listWidget->item(ui->listWidget->row(current) + 1);
        int nextIndex = ui->listWidget->row(next);

        QListWidgetItem *temp = ui->listWidget->item(nextIndex);

        QListWidgetItem *listItem = new QListWidgetItem();

        MyWidget *widget = dynamic_cast<MyWidget*>(ui->listWidget->itemWidget(ui->listWidget->item(nextIndex)));

        listItem->setSizeHint(widget->sizeHint()); // Optional: set the item's size hint based on your widget

        ui->listWidget->insertItem(currIndex, listItem);
        ui->listWidget->setItemWidget(listItem, widget);

        ui->listWidget->insertItem(nextIndex, current);

        delete temp;
    }
}

