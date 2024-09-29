#include "insert_widget.h"

insert_widget::insert_widget(QWidget *parent) : QWidget(parent)
{
    // 添加提示标签
    tipLabel = new QLabel("请添加图书");
    label1 = new QLabel("书名：");
    label2 = new QLabel("数量：");
    label3 = new QLabel("价格：");
    lineEdit1 = new QLineEdit();
    lineEdit2 = new QLineEdit();
    lineEdit3 = new QLineEdit();
    btn = new QPushButton("确定");

    // 设置标签和编辑框的样式表
    tipLabel->setMinimumHeight(200);
    label1->setStyleSheet("font-size: 20px;");
    label2->setStyleSheet("font-size: 20px;");
    label3->setStyleSheet("font-size: 20px;");
    lineEdit1->setStyleSheet("font-size: 30px;");
    lineEdit2->setStyleSheet("font-size: 30px;");
    lineEdit3->setStyleSheet("font-size: 30px;");
    btn->setStyleSheet("max-width: 100px; max-height: 60px;");


    formLayout = new QFormLayout;
    formLayout->addRow(tipLabel);
    formLayout->addRow(label1, lineEdit1);
    formLayout->addRow(label2, lineEdit2);
    formLayout->addRow(label3, lineEdit3);

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btn);

    mLayout = new QVBoxLayout;
    mLayout->addLayout(formLayout);
    mLayout->addLayout(buttonLayout);

    this->setLayout(mLayout);
    this->hide();
}
