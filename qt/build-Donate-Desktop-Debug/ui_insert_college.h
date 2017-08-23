/********************************************************************************
** Form generated from reading UI file 'insert_college.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_COLLEGE_H
#define UI_INSERT_COLLEGE_H

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

class Ui_insert_college
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *college_name_label;
    QLineEdit *college_name_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *person_name_label;
    QLineEdit *peraon_name_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *phone_number_label;
    QLineEdit *phone_number_lineEdit;

    void setupUi(QDialog *insert_college)
    {
        if (insert_college->objectName().isEmpty())
            insert_college->setObjectName(QStringLiteral("insert_college"));
        insert_college->resize(400, 300);
        buttonBox = new QDialogButtonBox(insert_college);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(insert_college);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 240, 176));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        college_name_label = new QLabel(layoutWidget);
        college_name_label->setObjectName(QStringLiteral("college_name_label"));

        horizontalLayout->addWidget(college_name_label);

        college_name_lineEdit = new QLineEdit(layoutWidget);
        college_name_lineEdit->setObjectName(QStringLiteral("college_name_lineEdit"));

        horizontalLayout->addWidget(college_name_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        person_name_label = new QLabel(layoutWidget);
        person_name_label->setObjectName(QStringLiteral("person_name_label"));

        horizontalLayout_2->addWidget(person_name_label);

        peraon_name_lineEdit = new QLineEdit(layoutWidget);
        peraon_name_lineEdit->setObjectName(QStringLiteral("peraon_name_lineEdit"));

        horizontalLayout_2->addWidget(peraon_name_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        phone_number_label = new QLabel(layoutWidget);
        phone_number_label->setObjectName(QStringLiteral("phone_number_label"));

        horizontalLayout_3->addWidget(phone_number_label);

        phone_number_lineEdit = new QLineEdit(layoutWidget);
        phone_number_lineEdit->setObjectName(QStringLiteral("phone_number_lineEdit"));

        horizontalLayout_3->addWidget(phone_number_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(insert_college);
        QObject::connect(buttonBox, SIGNAL(accepted()), insert_college, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), insert_college, SLOT(reject()));

        QMetaObject::connectSlotsByName(insert_college);
    } // setupUi

    void retranslateUi(QDialog *insert_college)
    {
        insert_college->setWindowTitle(QApplication::translate("insert_college", "Dialog", Q_NULLPTR));
        college_name_label->setText(QApplication::translate("insert_college", "college_name", Q_NULLPTR));
        person_name_label->setText(QApplication::translate("insert_college", "person_name", Q_NULLPTR));
        phone_number_label->setText(QApplication::translate("insert_college", "phone_number", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class insert_college: public Ui_insert_college {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_COLLEGE_H
