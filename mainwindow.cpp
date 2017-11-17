#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "bcalculator.h"
#include <QFileDialog>
#include <fstream>
#include <QDebug>
#include "form.h"
#include <QString>
#include <QDateTime>




using namespace std ;


PacketStream ps;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAnalizator, SIGNAL(triggered()), this, SLOT(analizator()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionCalic_triggered()
{
    BCalculator *cal =new  BCalculator(this);
    cal->show();
}
struct PPP
{
    unsigned int len;
    unsigned int nam;
    unsigned int t1;
    unsigned int t2;

};
vector<PPP> A(0);



void MainWindow::analizator()
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
    F.seekg(sizeof(char),ios::end);//переход в конец пакета
    int conec=F.tellp();//Последний элемент файла
    F.seekg(sizeof(char),ios::beg);//in start
    F.seekg(sizeof(char)*cm);//in zagolovok
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
       qDebug() <<"№"<< OBRAZ.nam<< "------------------------"<<endl;
       qDebug() << "Packet len :" << OBRAZ.len<<endl;
       qDebug() << "time1"<< QDateTime::fromTime_t( OBRAZ.t1 ) ;
       qDebug() << "time2" << OBRAZ.t2<<endl;

       QString ALL="" ;

       ALL=QString::number(OBRAZ.nam);
      ui->textEdit->append("------------------------Number packet : " + ALL + "-------------------------------");
       ALL=QString::number(OBRAZ.len);
      ui->textEdit->append("Len packet : " + ALL + "");

       ALL=(QDateTime::fromTime_t(OBRAZ.t1)).toString();

      ui->textEdit->append( "Time 1 : "  + ALL + "");
       ALL=QString::number(OBRAZ.t2);
      ui->textEdit->append( "Time 2 : "  + ALL + "");

    }






 //  Form *Analiz = new Form(this);
 //  Analiz->show();





   }

