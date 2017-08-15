#ifndef MTHREAD_H
#define MTHREAD_H
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include "qexcel.h"
#include "mainwindow.h"

class mThread
{
public:
    mThread();
private slots:
    void getExcelSlot();
};

#endif // MTHREAD_H
