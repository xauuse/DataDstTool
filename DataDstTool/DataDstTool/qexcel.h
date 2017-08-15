#ifndef QEXCEL_H
#define QEXCEL_H
#include <QString>
#include <QVariant>

class QAxObject;

class QExcel : public QObject
{
public:
    QExcel(QString xlsFilePath, QObject *parent = 0);
    ~QExcel();

public:
    QAxObject * getWorkBooks();
    QAxObject * getWorkBook();
    QAxObject * getWorkSheets();
    QAxObject * getWorkSheet();

public:
    /**************************************************************************/
    /* 工作表                                                                 */
    /**************************************************************************/
    void selectSheet(const QString& sheetName);
    //sheetIndex 起始于 1
    void selectSheet(int sheetIndex);  //选择工作表
    void deleteSheet(const QString& sheetName); //删除工作表
    void deleteSheet(int sheetIndex);
    void insertSheet(QString sheetName);        //插入工作表
    int getSheetsCount();           //获得工作表数量
    //在 selectSheet() 之后才可调用
    QString getSheetName();             //获得工作表名字
    QString getSheetName(int sheetIndex);

    /**************************************************************************/
    /* 单元格                                                                 */
    /**************************************************************************/
    void setCellString(int row, int column, const QString& value);  //设置单元格的值
    //cell 例如 "A7"
    void setCellString(const QString& cell, const QString& value);
    //range 例如 "A5:C7"
    void mergeCells(const QString& range); //合并单元格
    void mergeCells(int topLeftRow, int topLeftColumn, int bottomRightRow, int bottomRightColumn);
    QVariant getCellValue(int row, int column);
    void clearCell(int row, int column);  //清除数值
    void clearCell(const QString& cell);

    /**************************************************************************/
    /* 布局格式                                                               */
    /**************************************************************************/
    void getUsedRange(int *topLeftRow, int *topLeftColumn, int *bottomRightRow, int *bottomRightColumn);
    //设置列宽
    void setColumnWidth(int column, int width);
    void setRowHeight(int row, int height);
    //设置单元格文字居中
    void setCellTextCenter(int row, int column);
    void setCellTextCenter(const QString& cell);
    //设置单元格文字自动折行
    void setCellTextWrap(int row, int column, bool isWrap);
    void setCellTextWrap(const QString& cell, bool isWrap);
    //设置一行自适应行高
    void setAutoFitRow(int row);
    //合并一列中相同连续的单元格
    void mergeSerialSameCellsInAColumn(int column, int topRow);
     //获取一张工作表已用行数
    int getUsedRowsCount();
    //设置粗体
    void setCellFontBold(int row, int column, bool isBold);
    void setCellFontBold(const QString& cell, bool isBold);
    //设置文字大小
    void setCellFontSize(int row, int column, int size);
    void setCellFontSize(const QString& cell, int size);
    //设置字体样式
    void setCellFontStyle(int row,int cloum,const QString& fontStyle);
    //设置边线框
    void setCellLineStyle(int row, int column);
    /**************************************************************************/
    /* 文件                                                                   */
    /**************************************************************************/
    void save();
    void close();

private:
    QAxObject * excel;
    QAxObject * workBooks;
    QAxObject * workBook;
    QAxObject * sheets;
    QAxObject * sheet;
};

#endif
