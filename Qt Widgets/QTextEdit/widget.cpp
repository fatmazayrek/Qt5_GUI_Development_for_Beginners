#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    workUi();
}

Widget::~Widget()
{
}

void Widget::workUi()
{
    QFont f("Optima", 10, QFont::Bold);

    QLabel *label = new QLabel("This is my text", this);
    label->setMinimumSize(250, 20);
    label->setFont(f);
    label->move(220, 25);

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->move(70, 55);
    textEdit->setMinimumSize(500, 300);
    textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    textEdit->setFontFamily("Times New Roman");
    textEdit->setFontPointSize(10);

    QPushButton *copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(70, 30);
    copyButton->move(70, 365);

    //Copy text in the QTextEdit when Copy button is clicked --->
    connect(copyButton, &QPushButton::clicked, [=]()
    {
        textEdit->selectAll();
        textEdit->copy();
        label->setText("Text was copied");
    });

    QPushButton *cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(70, 30);
    cutButton->move(150, 365);

    //Cut text in the QTextEdit when Cut button is clicked ---->
    connect(cutButton, &QPushButton::clicked, [label, textEdit]()
    {
        textEdit->selectAll();
        textEdit->cut();
        label->setText("Text was cut");
    });

    QPushButton *pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(70, 30);
    pasteButton->move(230, 365);

    //Paste text copied in the QTextEdit when Paste button is clicked ----->
    connect(pasteButton, &QPushButton::clicked, [=]()
    {
        textEdit->paste();
        label->setText("Text was pasted");
    });

    QPushButton *undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(70, 30);
    undoButton->move(310, 365);

    //Undoes the last operation ---->
    connect(undoButton, &QPushButton::clicked, [=]()
    {
        textEdit->undo();
        label->setText("Undoes the last operation");
    });

    QPushButton *redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(70, 30);
    redoButton->move(390, 365);

    //Redoes the last operation ---->
    connect(redoButton, &QPushButton::clicked, [=]()
    {
        textEdit->redo();
        label->setText("Redoes the last operation");
    });
}



