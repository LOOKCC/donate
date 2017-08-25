/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionf;
    QAction *action_New;
    QAction *action_Save;
    QAction *action_Open;
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *changeButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sortsButton;
    QPushButton *sortdButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *moreButton;
    QPushButton *ratioButton;
    QPushButton *searchButton;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(818, 672);
        actionf = new QAction(MainWindow);
        actionf->setObjectName(QStringLiteral("actionf"));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 511, 611));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(510, 0, 301, 351));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 380, 254, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        insertButton = new QPushButton(layoutWidget);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout->addWidget(insertButton);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        changeButton = new QPushButton(layoutWidget);
        changeButton->setObjectName(QStringLiteral("changeButton"));

        horizontalLayout->addWidget(changeButton);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(550, 490, 198, 104));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sortsButton = new QPushButton(widget);
        sortsButton->setObjectName(QStringLiteral("sortsButton"));

        horizontalLayout_2->addWidget(sortsButton);

        sortdButton = new QPushButton(widget);
        sortdButton->setObjectName(QStringLiteral("sortdButton"));

        horizontalLayout_2->addWidget(sortdButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        moreButton = new QPushButton(widget);
        moreButton->setObjectName(QStringLiteral("moreButton"));

        horizontalLayout_3->addWidget(moreButton);

        ratioButton = new QPushButton(widget);
        ratioButton->setObjectName(QStringLiteral("ratioButton"));

        horizontalLayout_3->addWidget(ratioButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        searchButton = new QPushButton(widget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        verticalLayout_2->addWidget(searchButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 818, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionf->setText(QApplication::translate("MainWindow", "f", Q_NULLPTR));
        action_New->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        insertButton->setText(QApplication::translate("MainWindow", "Insert", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        changeButton->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
        sortsButton->setText(QApplication::translate("MainWindow", "Sort_student", Q_NULLPTR));
        sortdButton->setText(QApplication::translate("MainWindow", "Sort_donate", Q_NULLPTR));
        moreButton->setText(QApplication::translate("MainWindow", ">200", Q_NULLPTR));
        ratioButton->setText(QApplication::translate("MainWindow", "Ratio", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
