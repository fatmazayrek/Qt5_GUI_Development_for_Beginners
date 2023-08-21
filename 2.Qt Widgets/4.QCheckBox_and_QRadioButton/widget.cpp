#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup *buttonIngredients = new QButtonGroup();

    buttonIngredients->setExclusive(false);
    buttonIngredients->addButton(ui->domates);
    buttonIngredients->addButton(ui->marul);
    buttonIngredients->addButton(ui->jalapeno);
    buttonIngredients->addButton(ui->limon);
    buttonIngredients->addButton(ui->maydonoz);
    buttonIngredients->addButton(ui->misir);
    buttonIngredients->addButton(ui->nane);
    buttonIngredients->addButton(ui->tursu);

    foreach(QAbstractButton *comb, buttonIngredients->buttons())
    {
        QCheckBox *check = reinterpret_cast<QCheckBox*>(comb);

        checkbox_set.append(check);

        connect(check, &QCheckBox::toggled, this, &Widget::checkCheckBox);
    }

    QButtonGroup *buttongroup = new QButtonGroup(this);
    buttongroup->addButton(ui->nareksisi);
    buttongroup->addButton(ui->acisos);
    buttongroup->addButton(ui->cokacisos);
    buttongroup->addButton(ui->burgersos);
    buttongroup->setExclusive(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkCheckBox(bool checked)
{
    QCheckBox *checkbox = reinterpret_cast<QCheckBox*>(sender());

    if(this->counter < 4)
    {
        if(checked)
        {
            this->counter++;

            qDebug() << this->counter;
        }
        else
        {
            this->counter--;

            qDebug() << this->counter;
        }
    }
    else
    {
        checkbox->setChecked(false);

        foreach(QCheckBox *check, checkbox_set)
        {
            if(!check->isChecked())
            {
                check->setEnabled(false);
            }
        }
    }
}


void Widget::on_pushButton_clicked()
{
    QPixmap pixmap("://images/gift.png");

    QMessageBox msg;
    msg.setIconPixmap(pixmap);
    msg.setInformativeText("Siparişiniz alındı. Bizi tercih ettiğiniz için teşekkürler:)");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();

}

