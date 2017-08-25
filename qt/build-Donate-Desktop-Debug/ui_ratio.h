/********************************************************************************
** Form generated from reading UI file 'ratio.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATIO_H
#define UI_RATIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ratio
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ratio)
    {
        if (ratio->objectName().isEmpty())
            ratio->setObjectName(QStringLiteral("ratio"));
        ratio->resize(400, 300);
        buttonBox = new QDialogButtonBox(ratio);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(ratio);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 50, 256, 192));

        retranslateUi(ratio);
        QObject::connect(buttonBox, SIGNAL(accepted()), ratio, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ratio, SLOT(reject()));

        QMetaObject::connectSlotsByName(ratio);
    } // setupUi

    void retranslateUi(QDialog *ratio)
    {
        ratio->setWindowTitle(QApplication::translate("ratio", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ratio: public Ui_ratio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATIO_H
