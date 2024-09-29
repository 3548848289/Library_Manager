#include "mainsense.h"

MainSense::MainSense(QWidget *parent) : QWidget(parent)
{
    db = new databases();

    this->resize(1200,800);
    this->judge = 0;


    mainLayout = new QHBoxLayout(this);

    init_ls();
    init_rs();

    mainLayout->addWidget(frame_left, 4);
    mainLayout->addWidget(frame_right, 1);


    widget_insert = new insert_widget();
    leftLayout->addWidget(widget_insert);

    widget_return = new Small_widget(nullptr, "请输入你归换的图书名称");
    leftLayout->addWidget(widget_return);

    widget_drop = new Small_widget(nullptr, "请输入你删除的图书名称");
    leftLayout->addWidget(widget_drop);

    widget_find = new Small_widget(nullptr, "请输入你寻找的图书名称");
    leftLayout->addWidget(widget_find);

    widget_borrow = new Small_widget(nullptr, "请输入你借入的图书名称");
    leftLayout->addWidget(widget_borrow);



    // 定义一个函数指针数组，存储对应的成员函数指针
    typedef void (MainSense::*MemberFunctionPointer)();
    MemberFunctionPointer functions[]
            = {&MainSense::insert_book, &MainSense::drop_book, &MainSense::find_book,
               &MainSense::borrow_book, &MainSense::return_book};
    for (int i = 0; i < 5; ++i) {
        connect(btn_vector[i], &QPushButton::clicked, [=]() {
            (this->*functions[i])();  // 调用成员函数指针
            frame_right->setEnabled(false);
        });
    }

    connect(btn_vector[5], &QPushButton::clicked, [=](){
        this->close();
        frame_right->setEnabled(false);
    });

}


void MainSense::init_ls()
{
    leftLayout = new QVBoxLayout(this);
    frame_left = new QFrame(this);
    frame_left->setLayout(leftLayout);
    frame_left->setStyleSheet("QFrame {border: 2px solid blue; border-radius: 5px; padding: 10px;}");

}

void MainSense::init_rs()
{
    rightLayout = new QVBoxLayout(this);
    frame_right = new QFrame(this);
    frame_right->setStyleSheet("QFrame {border: 2px solid blue;}");
    QStringList arr;
    arr << "添加图书" <<" 删除图书" <<"查询图书" << "借阅图书" << "归还图书" << "退出系统";
    btn_vector.resize(6); // 设置btn_vector的大小为5
    for(int i = 0; i < 6; i++)
    {
        btn_vector[i] = new QPushButton;
        btn_vector[i]->setFixedSize(100, 50);
        btn_vector[i]->setText(arr[i]);
        rightLayout->addWidget(btn_vector[i]);
    }

    frame_right->setLayout(rightLayout);

}

void MainSense::insert_book()
{
    widget_insert->show();
    QObject::connect(widget_insert->btn, &QPushButton::clicked, [=]() {
        book_vector.push_back(new book);
        int i =  book_vector.size() - 1;
        book_vector[i]->book_name = widget_insert->lineEdit1->text();
        book_vector[i]->book_size = book_vector[i]->book_much
                                  = (widget_insert->lineEdit2->text()).toInt();
        book_vector[i]->book_price = (widget_insert->lineEdit3->text()).toFloat();
        book_vector[i]->book_status = true;
        db->insert(*book_vector[i]);
        widget_insert->hide();
        frame_right->setEnabled(true);
    });
}

void MainSense::drop_book()
{
    widget_drop->show();
    QObject::connect(widget_drop->btn, &QPushButton::clicked, [=]() {
        QString bookNameToDelete = widget_drop->line->text();
        for (auto it = book_vector.begin(); it != book_vector.end(); ++it) {
            if ((*it)->book_name == bookNameToDelete)
            {
                delete *it;
                book_vector.erase(it);
                widget_drop->tip->setText("书本成功删除");
                widget_drop->hide();
                frame_right->setEnabled(true);
                break;
            }
        }

    });


}

void MainSense::find_book()
{    

    widget_find->show(); // 显示借书界面
    bool judge1 = false;
    QObject::connect(widget_find->btn, &QPushButton::clicked, [&]() {
        QString bookTofind = widget_find->line->text();
        for (book* b : book_vector)
        {
            if (b->book_name == bookTofind)
            {
                int much = b->book_much;
                QString name = b->book_name;
                bool status = b->book_status;
                double price = b->book_price;
                bookTofind += "找到该书\n书名: " + name + " 数量: " + QString::number(much)
                             + " 价格: " + QString::number(price)
                             + " 状态: " + (status ? "在库" : "借出") + "\n";
                widget_find->tip->setText(bookTofind);
                judge1 = true;
                break;
            }
        }
        if(!judge1)
            widget_find->tip->setText("未找到该书籍或该书籍不可归换");
        QTimer::singleShot(2000, [=]() {
                       widget_find->hide();
                       frame_right->setEnabled(true);
                   });
    });
}


void MainSense::borrow_book()
{
    widget_borrow->show();
    bool judge1 = false;
    QObject::connect(widget_borrow->btn, &QPushButton::clicked, [&]() {
        QString bookToBorrow = widget_borrow->line->text();
        for (book* b : book_vector)
        {
            if (b->book_name == bookToBorrow && b->book_much != 0)
            {
                b->book_much--;
                widget_return->tip->setText("借书成功");
                judge1 = true;
                break;
            }
            else if(b->book_much == 0)
            {
                b->book_status = false;
            }
        }
        if(!judge1)
            widget_borrow->tip->setText("未找到该书籍或该书籍不可借出");
        QTimer::singleShot(2000, [=]() {
                       widget_borrow->hide();
                       frame_right->setEnabled(true);
                   });
    });
}

void MainSense::return_book()
{
    widget_return->show();
    bool judge1 = false;
    QObject::connect(widget_return->btn, &QPushButton::clicked, [&]() {
        QString bookToreturn = widget_return->line->text();
        for (book* b : book_vector)
        {
            if (b->book_name == bookToreturn && b->book_size > b->book_much)
            {
                b->book_much++;
                widget_return->tip->setText("还书成功");
                judge1 = true;
                break;
            }
        }
        if(!judge1)
            widget_borrow->tip->setText("未找到该书籍或该书籍不可归还");
        QTimer::singleShot(2000, [=]() {
                       widget_return->hide();
                       frame_right->setEnabled(true);
        });
    });
}





MainSense::~MainSense()
{

}


