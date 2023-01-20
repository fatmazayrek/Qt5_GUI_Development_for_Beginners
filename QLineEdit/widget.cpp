#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFont f("Gill Sans", 10, QFont::Decorative);

    QLabel *firstName = new QLabel(this);
    firstName->setText("FirstName");
    firstName->move(10, 10);
    firstName->setMinimumSize(70, 50);
    firstName->setFont(f);

    QLineEdit *firstLine = new QLineEdit(this);
    firstLine->setPlaceholderText("Enter your Name");
    firstLine->move(100, 10);
    firstLine->setMinimumSize(200, 50);

    //1.Method ---->
    connect(firstLine, &QLineEdit::textChanged, this, &Widget::toHigherCase);

    QLabel *lastName = new QLabel(this);
    lastName->setText("LastName");
    lastName->move(10, 80);
    lastName->setMinimumSize(70, 50);
    lastName->setFont(f);

    QLineEdit *lastLine = new QLineEdit(this);
    lastLine->setPlaceholderText("Enter your lastName");
    lastLine->move(100, 80);
    lastLine->setMinimumSize(200, 50);

    //2.Method --->
    connect(lastLine, &QLineEdit::textChanged, [=](QString text)
    {
        lastLine->setText(text.toUpper());
    });

    QLabel *city = new QLabel(this);
    city->setText("City");
    city->move(10, 150);
    city->setMinimumSize(70, 50);
    city->setFont(f);

    QLineEdit *cityLine = new QLineEdit(this);
    cityLine->setPlaceholderText("Enter your City");
    cityLine->move(100, 150);
    cityLine->setMinimumSize(200, 50);

    QPushButton *button = new QPushButton("Add Information", this);
    button->move(160, 240);

    connect(button, &QPushButton::clicked, [=](){
        if(!firstLine->text().isEmpty() && !lastLine->text().isEmpty() && !cityLine->text().isEmpty())
        {
            qDebug() << QString("FirstName: %1").arg(firstLine->text());
            qDebug() << QString("LastName: %1").arg(lastLine->text());
            qDebug() << QString("City: %1").arg(cityLine->text());
        }

        else
        {
            QMessageBox::critical(this, "Error", "You should fill all Line", QMessageBox::Cancel | QMessageBox::Ok);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::toHigherCase(const QString &text)
{
    QLineEdit *lineEdit = reinterpret_cast<QLineEdit*>(sender());

    lineEdit->setText(text.toUpper());
}

