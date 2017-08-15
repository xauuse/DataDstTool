#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include "qexcel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    long totalCount=0;
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    void setCellAttributes(QExcel mCell, int row, int column, int fontSize);

private slots:
    void getExcelSlot();
    void connectCRSQLSlot();
    void connectXHSQLSlot();
    void searchDataSlot();
};

#endif // MAINWINDOW_H
