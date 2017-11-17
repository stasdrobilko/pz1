#include "bcalculator.h"
#include "ui_bcalculator.h"
#include <iostream>
#include <math.h>

BCalculator::BCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BCalculator)
{
    ui->setupUi(this);
    num=0;
    flag = true;

    ui->setupUi(this);
    connect(ui->push_0, SIGNAL(clicked()),this,SLOT(push_0()));
    connect(ui->push_1, SIGNAL(clicked()),this,SLOT(push_1()));
    connect(ui->push_2, SIGNAL(clicked()),this,SLOT(push_2()));
    connect(ui->push_3, SIGNAL(clicked()),this,SLOT(push_3()));
    connect(ui->push_4, SIGNAL(clicked()),this,SLOT(push_4()));
    connect(ui->push_5, SIGNAL(clicked()),this,SLOT(push_5()));
    connect(ui->push_6, SIGNAL(clicked()),this,SLOT(push_6()));
    connect(ui->push_7, SIGNAL(clicked()),this,SLOT(push_7()));
    connect(ui->push_8, SIGNAL(clicked()),this,SLOT(push_8()));
    connect(ui->push_9, SIGNAL(clicked()),this,SLOT(push_9()));
    connect(ui->push_CLEAR, SIGNAL(clicked()),this,SLOT(push_CLEAR()));
    connect(ui->push_DEL, SIGNAL(clicked()),this,SLOT(push_DEL()));
    connect(ui->push_POINT, SIGNAL(clicked()),this,SLOT(push_POINT()));
    connect(ui->push_EQV, SIGNAL(clicked()),this,SLOT(push_EQV()));
    connect(ui->push_PLUS, SIGNAL(clicked()),this,SLOT(push_PLUS()));
    connect(ui->push_MINUS, SIGNAL(clicked()),this,SLOT(push_MINUS()));
    connect(ui->push_MULTI, SIGNAL(clicked()),this,SLOT(push_MULTI()));
    connect(ui->push_DIV, SIGNAL(clicked()),this,SLOT(push_DIV()));
    connect(ui->push_PLMIN, SIGNAL(clicked()),this,SLOT(push_PLMIN()));
    connect(ui->push_PERCENT, SIGNAL(clicked()),this,SLOT(push_PERCENT()));
    connect(ui->push_SQRT, SIGNAL(clicked()),this,SLOT(push_SQRT()));
    connect(ui->push_num_Y, SIGNAL(clicked()),this,SLOT(push_num_Y()));
}

BCalculator::~BCalculator()
{
    delete ui;
}

void BCalculator::push_0()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"0");
    flag = false;
}

void BCalculator::push_1()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"1");
    flag = false;
}

void BCalculator::push_2()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"2");
    flag = false;
}

void BCalculator::push_3()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"3");
    flag = false;
}

void BCalculator::push_4()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"4");
    flag = false;
}

void BCalculator::push_5()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"5");
    flag = false;
}

void BCalculator::push_6()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"6");
    flag = false;
}

void BCalculator::push_7()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"7");
    flag = false;
}

void BCalculator::push_8()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"8");
    flag = false;
}

void BCalculator::push_9()
{
    if(flag)
        ui->result->setText("");
    ui->result->setText(ui->result->text()+"9");
    flag = false;
}

void BCalculator::push_CLEAR()
{
    ui->result->setText("");
    function = "0";
    num = 0;
}

void BCalculator::push_DEL()
{
    if (ui->result->text().size() == 1)
        ui->result->setText("0");
    else
        ui->result->setText(ui->result->text().left(ui->result->text().size()-1));
}

void BCalculator::push_POINT()
{
    if(flag)
        ui->result->setText("0");
    ui->result->setText(ui->result->text()+".");
    flag = false;
}

void BCalculator::push_EQV()
{
    double temp, second;
    second = ui->result->text().toDouble();
    if(function != "")
    {
        if (function== "+")
            temp = num + second;
        if (function== "-")
            temp = num - second;
        if (function== "*")
            temp = num * second;
        if (function== "/")
            temp = num / second;
        if (function== "num^Y")
            temp=pow(num,second);
        if (function== "%")
            temp=(num*second)/100;
        ui->result->setText(QString::number(temp));
    }
    flag = true;
}

void BCalculator::push_PLUS()
{
    function="+";
    num= ui->result->text().toDouble();
    flag = true;
}

void BCalculator::push_MINUS()
{
    function="-";
    num= ui->result->text().toDouble();
    flag = true;
}

void BCalculator::push_MULTI()
{
    function="*";
    num= ui->result->text().toDouble();
    flag = true;
}

void BCalculator::push_DIV()
{
    function="/";
    num= ui->result->text().toDouble();
    flag = true;
}

void BCalculator::push_PLMIN()
{
    if (ui->result->text().toDouble() > 0 )
        ui->result->setText(QString::number(-ui->result->text().toDouble()));
    else
        ui->result->setText(QString::number(ui->result->text().toDouble()));
}

void BCalculator::push_PERCENT()
{
    function="%";
    num = ui->result->text().toDouble();
    flag = true;
}

void BCalculator::push_SIN()
{
    double rad,fi;
    fi=ui->result->text().toDouble();
    rad=fi*pi/180;
    ui->result->setText(QString::number(sin(rad)));
}

void BCalculator::push_COS()
{
    double rad,fi;
    fi=ui->result->text().toDouble();
    rad=fi*pi/180;
    ui->result->setText(QString::number(cos(rad)));
}

void BCalculator::push_TAG()
{
    double rad,fi;
    fi=ui->result->text().toDouble();
    rad=fi*pi/180;
    ui->result->setText(QString::number(tan(rad)));
}

void BCalculator::push_LOG10()
{
    num= ui->result->text().toDouble();
    ui->result->setText(QString::number(log10(num)));
}

void BCalculator::push_LN()
{
    num= ui->result->text().toDouble();
    ui->result->setText(QString::number(log(num)));
}

void BCalculator::push_PI()
{
    pi = 3.14159;
    ui->result->setText(QString::number(pi));
}

void BCalculator::push_E()
{
    e = 2.71828;
    ui->result->setText(QString::number(e));
}

void BCalculator::push_FACTORIAL()
{
    int tmp = 1;
    num= ui->result->text().toInt();
    for(int i=1; i<=num ; i++)
        tmp = tmp * i;
    ui->result->setText(QString::number(tmp));
}

void BCalculator::push_SQRT()
{
    num= ui->result->text().toDouble();
    ui->result->setText(QString::number(sqrt(num)));
}

void BCalculator::push_num_Y()
{
    function="num^Y";
    num = ui->result->text().toDouble();
    flag = true;

}
