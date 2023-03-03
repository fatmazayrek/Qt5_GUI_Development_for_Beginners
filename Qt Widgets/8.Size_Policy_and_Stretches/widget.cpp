#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setKeyboardTracking(true);
    ui->doubleSpinBox->setAccelerated(true);
    ui->doubleSpinBox->setMaximum(10.00);
    ui->doubleSpinBox->setSingleStep(0.1);
    ui->doubleSpinBox->setSpecialValueText(tr("Please set value"));     //If you want some text in the SpinBox then you must use this function

    ui->horizontalSlider->setTickPosition(QSlider::TicksAbove);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(10);
    ui->horizontalSlider->setSingleStep(100);

    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        ui->horizontalSlider->setValue(ui->doubleSpinBox->value());
    });

    ui->dial->setNotchesVisible(true);
    ui->dial->setWrapping(false);
    ui->dial->setMaximum(10);
    ui->dial->setMinimum(0);
    ui->dial->setSingleStep(100);
    ui->dial->setSliderPosition(0);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->dial, &QDial::setValue);
}

Widget::~Widget()
{
    delete ui;
}

