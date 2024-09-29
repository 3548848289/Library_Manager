#include "small_widget.h"

Small_widget::Small_widget(QWidget *parent, QString arr) : QWidget(parent)
{

    tip = new QLabel(arr, this);
    tip->setMaximumHeight(200);  // 设置最大高度为20像素
    label = new QLabel("书名", this);
    line = new QLineEdit(this);
    btn = new QPushButton("确定", this);
    btn->setStyleSheet("min-width: 100px; min-height: 40px;");
    label->setStyleSheet("font-size: 20px;");
    line->setStyleSheet("font-size: 30px;");

    // 创建水平布局管理器，放置 label 和 line
    labelLineEditLayout = new QHBoxLayout;
    labelLineEditLayout->addWidget(label);
    labelLineEditLayout->addWidget(line);

    // 创建垂直布局管理器，放置 tip 和 labelLineEditLayout
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tip);
    mainLayout->addLayout(labelLineEditLayout);

    // 创建水平布局管理器，放置 btn 在右下角
    btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);  // 添加伸缩量，将 btn 推到右边
    btnLayout->addWidget(btn);
    mainLayout->addLayout(btnLayout);

    this->setLayout(mainLayout);
    this->hide();


}
