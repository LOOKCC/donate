/********************************************************************************
** Form generated from reading UI file 'insert_class.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_CLASS_H
#define UI_INSERT_CLASS_H

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

class Ui_insert_class
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *class_NO_label;
    QLineEdit *class_NO_lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *grade_label;
    QLineEdit *grade_lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *person_nmber_label;
    QLineEdit *person_number_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *college_nane_label;
    QLineEdit *college_name_lineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *counselor_label;
    QLineEdit *counselor_lineEdit;

    void setupUi(QDialog *insert_class)
    {
        if (insert_class->objectName().isEmpty())
            insert_class->setObjectName(QStringLiteral("insert_class"));
        insert_class->resize(400, 300);
        buttonBox = new QDialogButtonBox(insert_class);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(insert_class);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 240, 176));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        class_NO_label = new QLabel(layoutWidget);
        class_NO_label->setObjectName(QStringLiteral("class_NO_label"));

        horizontalLayout_6->addWidget(class_NO_label);

        class_NO_lineEdit = new QLineEdit(layoutWidget);
        class_NO_lineEdit->setObjectName(QStringLiteral("class_NO_lineEdit"));

        horizontalLayout_6->addWidget(class_NO_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        grade_label = new QLabel(layoutWidget);
        grade_label->setObjectName(QStringLiteral("grade_label"));

        horizontalLayout_7->addWidget(grade_label);

        grade_lineEdit = new QLineEdit(layoutWidget);
        grade_lineEdit->setObjectName(QStringLiteral("grade_lineEdit"));

        horizontalLayout_7->addWidget(grade_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        person_nmber_label = new QLabel(layoutWidget);
        person_nmber_label->setObjectName(QStringLiteral("person_nmber_label"));

        horizontalLayout_8->addWidget(person_nmber_label);

        person_number_lineEdit = new QLineEdit(layoutWidget);
        person_number_lineEdit->setObjectName(QStringLiteral("person_number_lineEdit"));

        horizontalLayout_8->addWidget(person_number_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        college_nane_label = new QLabel(layoutWidget);
        college_nane_label->setObjectName(QStringLiteral("college_nane_label"));

        horizontalLayout_9->addWidget(college_nane_label);

        college_name_lineEdit = new QLineEdit(layoutWidget);
        college_name_lineEdit->setObjectName(QStringLiteral("college_name_lineEdit"));

        horizontalLayout_9->addWidget(college_name_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        counselor_label = new QLabel(layoutWidget);
        counselor_label->setObjectName(QStringLiteral("counselor_label"));

        horizontalLayout_10->addWidget(counselor_label);

        counselor_lineEdit = new QLineEdit(layoutWidget);
        counselor_lineEdit->setObjectName(QStringLiteral("counselor_lineEdit"));

        horizontalLayout_10->addWidget(counselor_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_10);


        retranslateUi(insert_class);
        QObject::connect(buttonBox, SIGNAL(accepted()), insert_class, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), insert_class, SLOT(reject()));

        QMetaObject::connectSlotsByName(insert_class);
    } // setupUi

    void retranslateUi(QDialog *insert_class)
    {
        insert_class->setWindowTitle(QApplication::translate("insert_class", "Dialog", Q_NULLPTR));
        class_NO_label->setText(QApplication::translate("insert_class", "class_NO", Q_NULLPTR));
        grade_label->setText(QApplication::translate("insert_class", "grade", Q_NULLPTR));
        person_nmber_label->setText(QApplication::translate("insert_class", "person_number", Q_NULLPTR));
        college_nane_label->setText(QApplication::translate("insert_class", "college_name", Q_NULLPTR));
        counselor_label->setText(QApplication::translate("insert_class", "counselor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class insert_class: public Ui_insert_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_CLASS_H
