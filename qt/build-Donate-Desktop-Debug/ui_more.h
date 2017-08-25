/********************************************************************************
** Form generated from reading UI file 'more.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORE_H
#define UI_MORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_more
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *more)
    {
        if (more->objectName().isEmpty())
            more->setObjectName(QStringLiteral("more"));
        more->resize(400, 300);
        buttonBox = new QDialogButtonBox(more);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(more);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 40, 256, 192));

        retranslateUi(more);
        QObject::connect(buttonBox, SIGNAL(accepted()), more, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), more, SLOT(reject()));

        QMetaObject::connectSlotsByName(more);
    } // setupUi

    void retranslateUi(QDialog *more)
    {
        more->setWindowTitle(QApplication::translate("more", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class more: public Ui_more {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_H
