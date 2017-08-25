/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

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

class Ui_Search
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *class_ID_label;
    QLineEdit *class_ID_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *grade_label;
    QLineEdit *grade_lineEdit;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(400, 300);
        buttonBox = new QDialogButtonBox(Search);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Search);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 100, 190, 68));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        class_ID_label = new QLabel(widget);
        class_ID_label->setObjectName(QStringLiteral("class_ID_label"));

        horizontalLayout->addWidget(class_ID_label);

        class_ID_lineEdit = new QLineEdit(widget);
        class_ID_lineEdit->setObjectName(QStringLiteral("class_ID_lineEdit"));

        horizontalLayout->addWidget(class_ID_lineEdit);


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


        retranslateUi(Search);
        QObject::connect(buttonBox, SIGNAL(accepted()), Search, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Search, SLOT(reject()));

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Dialog", Q_NULLPTR));
        class_ID_label->setText(QApplication::translate("Search", "class_ID", Q_NULLPTR));
        grade_label->setText(QApplication::translate("Search", "grade", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
