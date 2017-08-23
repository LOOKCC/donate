/********************************************************************************
** Form generated from reading UI file 'change_student.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_STUDENT_H
#define UI_CHANGE_STUDENT_H

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

class Ui_change_student
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ID_label;
    QLineEdit *ID_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *gender_label;
    QLineEdit *gender_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *age_label;
    QLineEdit *age_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *money_label;
    QLineEdit *monet_lineEdit;

    void setupUi(QDialog *change_student)
    {
        if (change_student->objectName().isEmpty())
            change_student->setObjectName(QStringLiteral("change_student"));
        change_student->resize(400, 300);
        buttonBox = new QDialogButtonBox(change_student);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(change_student);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 240, 176));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        name_label = new QLabel(layoutWidget);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout->addWidget(name_label);

        name_lineEdit = new QLineEdit(layoutWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout->addWidget(name_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ID_label = new QLabel(layoutWidget);
        ID_label->setObjectName(QStringLiteral("ID_label"));

        horizontalLayout_2->addWidget(ID_label);

        ID_lineEdit = new QLineEdit(layoutWidget);
        ID_lineEdit->setObjectName(QStringLiteral("ID_lineEdit"));

        horizontalLayout_2->addWidget(ID_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gender_label = new QLabel(layoutWidget);
        gender_label->setObjectName(QStringLiteral("gender_label"));

        horizontalLayout_3->addWidget(gender_label);

        gender_lineEdit = new QLineEdit(layoutWidget);
        gender_lineEdit->setObjectName(QStringLiteral("gender_lineEdit"));

        horizontalLayout_3->addWidget(gender_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        age_label = new QLabel(layoutWidget);
        age_label->setObjectName(QStringLiteral("age_label"));

        horizontalLayout_4->addWidget(age_label);

        age_lineEdit = new QLineEdit(layoutWidget);
        age_lineEdit->setObjectName(QStringLiteral("age_lineEdit"));

        horizontalLayout_4->addWidget(age_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        money_label = new QLabel(layoutWidget);
        money_label->setObjectName(QStringLiteral("money_label"));

        horizontalLayout_5->addWidget(money_label);

        monet_lineEdit = new QLineEdit(layoutWidget);
        monet_lineEdit->setObjectName(QStringLiteral("monet_lineEdit"));

        horizontalLayout_5->addWidget(monet_lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(change_student);
        QObject::connect(buttonBox, SIGNAL(accepted()), change_student, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), change_student, SLOT(reject()));

        QMetaObject::connectSlotsByName(change_student);
    } // setupUi

    void retranslateUi(QDialog *change_student)
    {
        change_student->setWindowTitle(QApplication::translate("change_student", "Dialog", Q_NULLPTR));
        name_label->setText(QApplication::translate("change_student", "name", Q_NULLPTR));
        ID_label->setText(QApplication::translate("change_student", "ID", Q_NULLPTR));
        gender_label->setText(QApplication::translate("change_student", "gender", Q_NULLPTR));
        age_label->setText(QApplication::translate("change_student", "age", Q_NULLPTR));
        money_label->setText(QApplication::translate("change_student", "money", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class change_student: public Ui_change_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_STUDENT_H
