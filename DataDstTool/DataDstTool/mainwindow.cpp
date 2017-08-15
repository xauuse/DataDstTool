#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QThread>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QThread thread;
//    this->moveToThread(&thread);
    connect(ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(searchDataSlot()));
    connect(ui->crSqlAction,SIGNAL(triggered(bool)),this,SLOT(connectCRSQLSlot()));
    connect(ui->xhSQLAction,SIGNAL(triggered(bool)),this,SLOT(connectXHSQLSlot()));
    connect(ui->outputButton,SIGNAL(clicked(bool)),this,SLOT(getExcelSlot()));
//    thread.start();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::setCellAttributes(QExcel mCell, int row, int column, int fontSize)
{
    mCell.setCellFontSize(row,column,fontSize);
    mCell.setRowHeight(row,26.25);
    mCell.setCellTextCenter(row,column);
}

void MainWindow::getExcelSlot()
{
    QString path = QFileDialog::getOpenFileName(this, tr("search execl"),
                                                "/home",
                                                tr("EXCEL (*.xlsx *.xls)"));
    QExcel cell(path);
    cell.selectSheet("Sheet1"); //创建Excel对象，并选择工作表

    QSqlQuery query;

    QString serQuery="select * from xh_order_list where xh_order_number='";
    QString iccidQuery=ui->iccidEdit->text();
    serQuery += iccidQuery +"'";
    query.exec(serQuery);
    int rid ;
    while(query.next())
    {
        rid =query.value(0).toInt();
        QString str=query.value(3).toString();
    }
    QString filListQey="select * from xh_datatool_record where rid="+QString::number(rid,10);
    query.exec(filListQey);
    QString fileadress;
    int j=0;
    while (query.next())
    {

        QString filename=query.value(7).toString();  //文件名
        int fileCount =query.value(8).toInt();  //表中数量

        qDebug()<<filename;
        if(filename.contains("remake",Qt::CaseSensitive))   //判断是否是remake的补码文件
        {
       //     fileadress=filename;

        }else {
            fileadress=filename.left(filename.length()-4);
            cell.setCellString(6+j,1,fileadress);  //在Excel表中插入文件名
            cell.setCellFontSize(6+j,1,9);
            cell.setRowHeight(6+j,26);
            cell.setCellTextCenter(6+j,1);
            cell.setCellFontStyle(6+j,1,"Times New Roman");
            cell.setCellLineStyle(6+j,1);

            cell.setCellString(6+j,2,QString::number(fileCount)); //在Excel表中插入数量
            totalCount += fileCount;
             ui->printEdit->append(QString::number(fileCount));
             ui->printEdit->append(QString::number(totalCount));
            QSqlQuery mQuery;
            QString selectQey="select * from `"+fileadress+"`";
            qDebug()<<selectQey;

            mQuery.exec(selectQey);
            vector<QString> m_iccidV;
            while(mQuery.next())
            {

                QString ICCID=mQuery.value(1).toString();
                m_iccidV.push_back(ICCID);
            }
            if(m_iccidV.empty()){
                qDebug()<<"无数据....";
            }
            else {

                QString firstID=m_iccidV[0].left(20);
                qDebug()<<"第一条ICCID："<<firstID;
                cell.setCellString(6+j,3,firstID); //在Excel表中插入首条ICCID


                QString lastID=m_iccidV[m_iccidV.size()-1].left(20);
                qDebug()<<"最后一条ICCID： "<<lastID;
                cell.setCellString(6+j,4,lastID); //在Excel表中插入末条ICCID

                m_iccidV.clear();

            }
            j++;

        }


    }

    QString orderCount="下单数量(Qty): ";
    orderCount  += QString::number(totalCount);
    cell.setCellString(3,6,orderCount);


    cell.save();
    ui->printEdit->append("数据输出成功!");

    }


//连接潮润数据库
void MainWindow::connectCRSQLSlot()
{
    db.setHostName("192.168.100.115");
    db.setUserName("xhsmart");
    db.setPassword("xhsmart2011");
    db.setPort(3308);
    db.setDatabaseName("xh_data_hq");
    if(db.open())
    {
       ui->printEdit->setText("潮润数据库连接成功！");
    }
    else
    {
        ui->printEdit->setText("潮润数据库连接失败！");
    }
}

//连接总部数据库
void MainWindow::connectXHSQLSlot()
{
    //192.168.100.113","xhsmart","xhsmart2011","xh_data_server",3308
    db.setHostName("192.168.100.113");
    db.setUserName("xhsmart");
    db.setPassword("xhsmart2011");
    db.setPort(3308);
    db.setDatabaseName("xh_data_server");
    if(db.open())
    {
       ui->printEdit->setText("星汉数据库连接成功！");
    }
    else
    {
        ui->printEdit->setText("星汉数据库连接失败！");
    }

}

//查找
void MainWindow::searchDataSlot()
{
    QSqlQuery query;
    QString serQuery="select * from xh_order_list where xh_order_number='";
    QString iccidQuery=ui->iccidEdit->text();
    serQuery += iccidQuery +"'";
    query.exec(serQuery);
    int rid ;
    while(query.next())
    {
        rid =query.value(0).toInt();
        QString str=query.value(3).toString();
    }
    QString filListQey="select * from xh_datatool_record where rid="+QString::number(rid,10);
    query.exec(filListQey);
    QString fileadress;

    while (query.next()) {
        QString filename=query.value(7).toString();
        qDebug()<<filename;
        if(filename.contains("remake",Qt::CaseSensitive))
        {
            fileadress=filename;
             ui->printEdit->append(fileadress);
        }else {
            fileadress=filename.left(filename.length()-4);
            ui->printEdit->append(fileadress);
        }
    }
}


