#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFont f("Monospace", 15, QFont::Decorative);

    ui->label->setFont(f);
    ui->label->setText("Hello");

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(ui->label);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(ui->pushButton, 0, 0);
    gridLayout->addWidget(ui->pushButton_2, 0 , 1);
    gridLayout->addWidget(ui->pushButton_3, 0, 2);
    gridLayout->addWidget(ui->pushButton_4, 1, 0);
    gridLayout->addWidget(ui->pushButton_5, 1, 1);
    gridLayout->addWidget(ui->pushButton_6, 1, 2);
    gridLayout->addWidget(ui->pushButton_7, 2, 0);
    gridLayout->addWidget(ui->pushButton_8, 2, 1);
    gridLayout->addWidget(ui->pushButton_9, 2, 2);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addLayout(gridLayout);
    hlayout->addLayout(vlayout);

    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton->text()).append(" was clicked"));
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

    connect(ui->pushButton_5, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_5->text()).append(" was clicked"));
    });

    connect(ui->pushButton_6, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_6->text()).append(" was clicked"));
    });

    connect(ui->pushButton_7, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_7->text()).append(" was clicked"));
    });

    connect(ui->pushButton_8, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_8->text()).append(" was clicked"));
    });

    connect(ui->pushButton_9, &QPushButton::clicked, [=]()
    {
        ui->label->setText(QString(ui->pushButton_9->text()).append(" was clicked"));
    });

    setLayout(hlayout);

}

Widget::~Widget()
{
    delete ui;
}

