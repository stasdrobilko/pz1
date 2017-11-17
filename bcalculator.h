#ifndef BCALCULATOR_H
#define BCALCULATOR_H

#include <QMainWindow>

namespace Ui {
class BCalculator;
}

class BCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit BCalculator(QWidget *parent = 0);
    ~BCalculator();

    double  num;
    QString function;
    bool flag;
    double pi;
    double e;

private:
    Ui::BCalculator *ui;

public slots:
    void push_0();
    void push_1();
    void push_2();
    void push_3();
    void push_4();
    void push_5();
    void push_6();
    void push_7();
    void push_8();
    void push_9();

    void push_CLEAR();
    void push_DEL();
    void push_POINT();

    void push_EQV();
    void push_PLUS();
    void push_MINUS();
    void push_MULTI();
    void push_DIV();
    void push_PLMIN();
    void push_PERCENT();
    void push_SIN();
    void push_COS();
    void push_TAG();
    void push_LOG10();
    void push_LN();
    void push_PI();
    void push_E();
    void push_FACTORIAL();
    void push_SQRT();
    void push_num_Y();


};

#endif // BCALCULATOR_H
