/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *crSqlAction;
    QAction *xhSQLAction;
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *iccidEdit;
    QPushButton *searchButton;
    QPushButton *outputButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *printEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(450, 346);
        crSqlAction = new QAction(MainWindow);
        crSqlAction->setObjectName(QStringLiteral("crSqlAction"));
        xhSQLAction = new QAction(MainWindow);
        xhSQLAction->setObjectName(QStringLiteral("xhSQLAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 41, 21));
        iccidEdit = new QLineEdit(centralWidget);
        iccidEdit->setObjectName(QStringLiteral("iccidEdit"));
        iccidEdit->setGeometry(QRect(110, 30, 161, 21));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(290, 30, 75, 23));
        outputButton = new QPushButton(centralWidget);
        outputButton->setObjectName(QStringLiteral("outputButton"));
        outputButton->setGeometry(QRect(170, 230, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 70, 321, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        printEdit = new QTextEdit(layoutWidget);
        printEdit->setObjectName(QStringLiteral("printEdit"));
        printEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(printEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(crSqlAction);
        menu->addAction(xhSQLAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        crSqlAction->setText(QApplication::translate("MainWindow", "\346\275\256\346\266\246(&F)", 0));
        xhSQLAction->setText(QApplication::translate("MainWindow", "\346\200\273\351\203\250(&G)", 0));
        label->setText(QApplication::translate("MainWindow", "\345\267\245\345\215\225\345\217\267\357\274\232", 0));
        searchButton->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", 0));
        outputButton->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", 0));
        label_2->setText(QApplication::translate("MainWindow", "Log:", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
