#ifndef INSERT_CLASS_H
#define INSERT_CLASS_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class insert_class;
}

class insert_class : public QDialog
{
    Q_OBJECT

public:
    explicit insert_class(QWidget *parent = 0);
    ~insert_class();
    QString get_class_ID();
    int get_grade();
    int get_person_number();
    QString get_college_name();
    QString get_counselor();

private:
    Ui::insert_class *ui;
};

#endif // INSERT_CLASS_H
