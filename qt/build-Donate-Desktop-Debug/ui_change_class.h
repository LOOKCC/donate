/********************************************************************************
** Form generated from reading UI file 'change_class.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_CLASS_H
#define UI_CHANGE_CLASS_H

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

class Ui_change_class
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *class_NO_label;
    QLineEdit *class_NO_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *grade_label;
    QLineEdit *grade_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *person_number_label;
    QLineEdit *person_numberlineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *college_name_label;
    QLineEdit *college_name_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *counselor_label;
    QLineEdit *counselor_lineEdit;

    void setupUi(QDialog *change_class)
    {
        if (change_class->objectName().isEmpty())
            change_class->setObjectName(QStringLiteral("change_class"));
        change_class->resize(400, 300);
        buttonBox = new QDialogButtonBox(change_class);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(change_class);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 50, 240, 176));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        class_NO_label = new QLabel(widget);
        class_NO_label->setObjectName(QStringLiteral("class_NO_label"));

        horizontalLayout->addWidget(class_NO_label);

        class_NO_lineEdit = new QLineEdit(widget);
        class_NO_lineEdit->setObjectName(QStringLiteral("class_NO_lineEdit"));

        horizontalLayout->addWidget(class_NO_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        grade_label = new QLabel(widget);
        grade_label->setObjectName(QStringLiteral("grade_label"));

        horizontalLayout_2->addWidget(grade_label);

        grade_lineEdit = new QLineEdit(widget);
        grade_lineEdit->setObjectName(QStringLiteral("grade_lineEdit"));

        horizontalLayout_2->addWidget(grade_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        person_number_label = new QLabel(widget);
        person_number_label->setObjectName(QStringLiteral("person_number_label"));

        horizontalLayout_3->addWidget(person_number_label);

        person_numberlineEdit = new QLineEdit(widget);
        person_numberlineEdit->setObjectName(QStringLiteral("person_numberlineEdit"));

        horizontalLayout_3->addWidget(person_numberlineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        college_name_label = new QLabel(widget);
        college_name_label->setObjectName(QStringLiteral("college_name_label"));

        horizontalLayout_4->addWidget(college_name_label);

        college_name_lineEdit = new QLineEdit(widget);
        college_name_lineEdit->setObjectName(QStringLiteral("college_name_lineEdit"));

        horizontalLayout_4->addWidget(college_name_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        counselor_label = new QLabel(widget);
        counselor_label->setObjectName(QStringLiteral("counselor_label"));

        horizontalLayout_5->addWidget(counselor_label);

        counselor_lineEdit = new QLineEdit(widget);
        counselor_lineEdit->setObjectName(QStringLiteral("counselor_lineEdit"));

        horizontalLayout_5->addWidget(counselor_lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox->raise();
        class_NO_label->raise();
        class_NO_lineEdit->raise();
        grade_label->raise();
        person_number_label->raise();
        college_name_label->raise();
        counselor_label->raise();
        counselor_lineEdit->raise();
        college_name_lineEdit->raise();
        grade_lineEdit->raise();
        person_numberlineEdit->raise();
        college_name_label->raise();
        counselor_label->raise();
        person_number_label->raise();
        grade_label->raise();
        class_NO_label->raise();
        class_NO_lineEdit->raise();
        counselor_lineEdit->raise();
        college_name_lineEdit->raise();
        grade_lineEdit->raise();
        person_numberlineEdit->raise();
        grade_lineEdit->raise();

        retranslateUi(change_class);
        QObject::connect(buttonBox, SIGNAL(accepted()), change_class, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), change_class, SLOT(reject()));

        QMetaObject::connectSlotsByName(change_class);
    } // setupUi

    void retranslateUi(QDialog *change_class)
    {
        change_class->setWindowTitle(QApplication::translate("change_class", "Dialog", Q_NULLPTR));
        class_NO_label->setText(QApplication::translate("change_class", "class_NO", Q_NULLPTR));
        grade_label->setText(QApplication::translate("change_class", "grade", Q_NULLPTR));
        person_number_label->setText(QApplication::translate("change_class", "person_number", Q_NULLPTR));
        college_name_label->setText(QApplication::translate("change_class", "college_name", Q_NULLPTR));
        counselor_label->setText(QApplication::translate("change_class", "counselor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class change_class: public Ui_change_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_CLASS_H
