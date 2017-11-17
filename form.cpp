#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include "bcalculator.h"
#include <QFileDialog>
#include <fstream>
#include <QDebug>
#include "form.h"
#include <QString>
#include <QDateTime>


//using namespace std ;


//PacketStream ps;

/*Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{

    ui->setupUi(this);
    //ui->textEdit->append(ALL);
}*/

Form::~Form()
{
    delete ui;
}

/*struct PPP
{
    unsigned int len;
    unsigned int nam;
    unsigned int t1;
    unsigned int t2;

};
vector<PPP> A(0);


void Form::analizator()
{
    QString fName = QFileDialog::getOpenFileName(0, "Open file","","PCAP files (*.cap)");

    qDebug() << fName;

    if ( fName == "" )
        return;
     QFile file(fName);

     if (!file.open(QIODevice::ReadOnly))
     {
             qDebug() << "error open file";
             return;
     }
     QTextStream stream(&file);
     QString buffer =stream.readAll();
     qDebug() << buffer;

     qDebug() << "Size = " << file.size();
     qDebug() << "Pos = " << file.pos();

    file.read((char *)&ps.fHeader, 24);

    qDebug() << ps.fHeader.snaplen << "   " << ps.fHeader.linktype;

     qDebug() << "Pos = " << file.pos();


    fstream F;
    F.open(fName.toLocal8Bit().data(),ios::in |ios::binary);
    int  cm=24;  //длина заголовка
    F.seekg(sizeof(char),ios::end);
    int conec=F.tellp();
    F.seekg(sizeof(char),ios::beg);
    F.seekg(sizeof(char)*cm);
    PcapHeader PK;
    A.clear();
    PPP OBRAZ;
    int i=1;
    while(cm<=conec)
    {
        F.read((char*)&PK,sizeof(PcapHeader));
        cm+=16;
        OBRAZ.len=PK.len;
        OBRAZ.nam=i;
        OBRAZ.t1=PK.t1;
        OBRAZ.t2=PK.t2;
        A.push_back(OBRAZ);
        i++;
        cm+=PK.len;
        F.seekg(sizeof(char)*cm);
       qDebug() <<"------------------------Namber packet :"<< OBRAZ.nam<< "------------------------"<<endl;
       qDebug() << "Len packet :" << OBRAZ.len<<endl;
       qDebug() << "time1"<< QDateTime::fromTime_t( OBRAZ.t1 ) ;
       qDebug() << "time2" << OBRAZ.t2<<endl;

       QString ALL="" ;

       ALL=QString::number(OBRAZ.nam);

    //  ui->textEdit->append(ALL);

    }






   Form *Analiz = new Form(this);
   Analiz->show();



}*/
