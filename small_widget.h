#ifndef SMALL_WIDGET_H
#define SMALL_WIDGET_H

#include <main.h>

class Small_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Small_widget(QWidget *parent = nullptr, QString arr = "");
    QHBoxLayout *labelLineEditLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *btnLayout;

    QLabel *label;
    QLabel *tip;
    QPushButton *btn;
    QLineEdit *line;


signals:

public slots:
};

#endif // SMALL_WIDGET_H
