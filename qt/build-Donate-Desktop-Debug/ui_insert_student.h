/********************************************************************************
** Form generated from reading UI file 'insert_student.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_STUDENT_H
#define UI_INSERT_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insert_student
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *name_label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ID_label;
    QLineEdit *ID_lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *gender_label;
    QLineEdit *gender_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *age_label;
    QLineEdit *age_lineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *money_label;
    QLineEdit *money_lineEdit;

    void setupUi(QDialog *insert_student)
    {
        if (insert_student->objectName().isEmpty())
            insert_student->setObjectName(QStringLiteral("insert_student"));
        insert_student->resize(400, 300);
        buttonBox = new QDialogButtonBox(insert_student);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(insert_student);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 240, 176));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        name_label = new QLabel(layoutWidget);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout_6->addWidget(name_label);

        name_lineEdit = new QLineEdit(layoutWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout_6->addWidget(name_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ID_label = new QLabel(layoutWidget);
        ID_label->setObjectName(QStringLiteral("ID_label"));

        horizontalLayout_7->addWidget(ID_label);

        ID_lineEdit = new QLineEdit(layoutWidget);
        ID_lineEdit->setObjectName(QStringLiteral("ID_lineEdit"));

        horizontalLayout_7->addWidget(ID_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        gender_label = new QLabel(layoutWidget);
        gender_label->setObjectName(QStringLiteral("gender_label"));

        horizontalLayout_8->addWidget(gender_label);

        gender_lineEdit = new QLineEdit(layoutWidget);
        gender_lineEdit->setObjectName(QStringLiteral("gender_lineEdit"));

        horizontalLayout_8->addWidget(gender_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        age_label = new QLabel(layoutWidget);
        age_label->setObjectName(QStringLiteral("age_label"));

        horizontalLayout_9->addWidget(age_label);

        age_lineEdit = new QLineEdit(layoutWidget);
        age_lineEdit->setObjectName(QStringLiteral("age_lineEdit"));

        horizontalLayout_9->addWidget(age_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        money_label = new QLabel(layoutWidget);
        money_label->setObjectName(QStringLiteral("money_label"));

        horizontalLayout_10->addWidget(money_label);

        money_lineEdit = new QLineEdit(layoutWidget);
        money_lineEdit->setObjectName(QStringLiteral("money_lineEdit"));

        horizontalLayout_10->addWidget(money_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_10);


        retranslateUi(insert_student);
        QObject::connect(buttonBox, SIGNAL(accepted()), insert_student, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), insert_student, SLOT(reject()));

        QMetaObject::connectSlotsByName(insert_student);
    } // setupUi

    void retranslateUi(QDialog *insert_student)
    {
        insert_student->setWindowTitle(QApplication::translate("insert_student", "Dialog", Q_NULLPTR));
        name_label->setText(QApplication::translate("insert_student", "name", Q_NULLPTR));
        ID_label->setText(QApplication::translate("insert_student", "ID", Q_NULLPTR));
        gender_label->setText(QApplication::translate("insert_student", "gender", Q_NULLPTR));
        age_label->setText(QApplication::translate("insert_student", "age", Q_NULLPTR));
        money_label->setText(QApplication::translate("insert_student", "money", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class insert_student: public Ui_insert_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_STUDENT_H
