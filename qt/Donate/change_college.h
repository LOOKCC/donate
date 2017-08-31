#ifndef CHANGE_COLLEGE_H
#define CHANGE_COLLEGE_H

#include <QDialog>
#include <QLineEdit>
#include "donate.h"

namespace Ui {
class change_college;
}

class change_college : public QDialog
{
    Q_OBJECT

public:
    explicit change_college(QWidget *parent = 0);
    //get
    QString get_college_name();
    QString get_person_name();
    QString get_phone_number();
    ~change_college();
    //show old information
    void show_info(struct college_info* temp);

private:
    Ui::change_college *ui;
};

#endif // CHANGE_COLLEGE_H
