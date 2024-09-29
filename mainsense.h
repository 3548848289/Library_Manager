#ifndef MAINSENSE_H
#define MAINSENSE_H
#include"main.h"
#include"book.h"
#include"small_widget.h"
#include"insert_widget.h"
#include"databases.h"
class MainSense : public QWidget
{
    Q_OBJECT

public:
    MainSense(QWidget *parent = 0);
    ~MainSense();
private:

    void init_rs();
    void init_ls();
    void insert_book();
    void drop_book();
    void find_book();
    void borrow_book();
    void return_book();


    QHBoxLayout * mainLayout;
    QVBoxLayout * rightLayout;
    QVBoxLayout * leftLayout;
    QFrame * frame_right;
    QFrame * frame_left;
    QLabel * label;
    QVector<QPushButton*> btn_vector;
    QVector<book*> book_vector;



    int judge;
    insert_widget * widget_insert;
    Small_widget * widget_drop;
    Small_widget * widget_return;
    Small_widget * widget_borrow;
    Small_widget * widget_find;

    databases * db;


};

#endif // MAINSENSE_H
