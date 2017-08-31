#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include <QDialog>
#include <QLineEdit>
#include "donate.h"
namespace Ui {
class change_student;
}

class change_student : public QDialog
{
    Q_OBJECT

public:
    explicit change_student(QWidget *parent = 0);
    ~change_student();
    //get
    QString get_name();
    QString get_ID();
    QChar get_gender();
    int get_age();
    float get_money();
    //show old information
    void show_info(struct student_info* temp);
private:
    Ui::change_student *ui;
};

#endif // CHANGE_STUDENT_H
