#ifndef INSERT_STUDENT_H
#define INSERT_STUDENT_H

#include <QDialog>
#include <QLineEdit>
namespace Ui {
class insert_student;
}

class insert_student : public QDialog
{
    Q_OBJECT

public:
    explicit insert_student(QWidget *parent = 0);
    ~insert_student();
    //get
    QString get_name();
    QString get_ID();
    QChar get_gender();
    int get_age();
    float get_money();
    //clear lineedit
    void Clear();
private:
    Ui::insert_student *ui;
};

#endif // INSERT_STUDENT_H
