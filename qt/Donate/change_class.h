#ifndef CHANGE_CLASS_H
#define CHANGE_CLASS_H

#include <QDialog>
#include <QLineEdit>
#include "donate.h"

namespace Ui {
class change_class;
}

class change_class : public QDialog
{
    Q_OBJECT

public:
    explicit change_class(QWidget *parent = 0);
    ~change_class();
    //get
    QString get_class_ID();
    int get_grade();
    int get_person_number();
    QString get_college_name();
    QString get_counselor();
    //show old information
    void show_info(struct class_info* temp);

private:
    Ui::change_class *ui;
};

#endif // CHANGE_CLASS_H
