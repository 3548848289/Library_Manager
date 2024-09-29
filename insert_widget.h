#ifndef INSERT_WIDGET_H
#define INSERT_WIDGET_H

#include <main.h>

class insert_widget : public QWidget
{
    Q_OBJECT
public:
    explicit insert_widget(QWidget *parent = nullptr);
    QLabel *tipLabel;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QPushButton *btn;
    QFormLayout *formLayout;
    QVBoxLayout *mLayout;
    QWidget *inputWidget;
    QHBoxLayout *buttonLayout;
signals:

public slots:
};

#endif // INSERT_WIDGET_H
