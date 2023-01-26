#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("Click these buttons for test");

    //QHBoxLayout Example ----->
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->addWidget(ui->pushButton_1);
    layout->addWidget(ui->pushButton_2);
    layout->addWidget(ui->pushButton_3);
    layout->addWidget(ui->pushButton_4);

    QHBoxLayout *layout_1 = new QHBoxLayout();
    layout_1->addWidget(ui->label);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addLayout(layout_1);
    vlayout->addLayout(layout);
    vlayout->addStretch();

    connect(ui->pushButton_1, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_1->text()).append(" was clicked"));
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_2->text()).append(" was clicked"));
    });

    connect(ui->pushButton_3, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_3->text()).append(" was clicked"));
    });

    connect(ui->pushButton_4, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_4->text()).append(" was clicked"));
    });
}

Widget::~Widget()
{
    delete ui;
}

