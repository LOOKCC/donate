/********************************************************************************
** Form generated from reading UI file 'insert.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_H
#define UI_INSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_insert
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *insert)
    {
        if (insert->objectName().isEmpty())
            insert->setObjectName(QStringLiteral("insert"));
        insert->resize(400, 300);
        buttonBox = new QDialogButtonBox(insert);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(insert);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 63, 20));
        lineEdit = new QLineEdit(insert);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 30, 113, 28));

        retranslateUi(insert);
        QObject::connect(buttonBox, SIGNAL(accepted()), insert, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), insert, SLOT(reject()));

        QMetaObject::connectSlotsByName(insert);
    } // setupUi

    void retranslateUi(QDialog *insert)
    {
        insert->setWindowTitle(QApplication::translate("insert", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("insert", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class insert: public Ui_insert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_H
