#ifndef INSERT_COLLEGE_H
#define INSERT_COLLEGE_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class insert_college;
}

class insert_college : public QDialog
{
    Q_OBJECT

public:
    explicit insert_college(QWidget *parent = 0);
    QString get_college_name();
    QString get_person_name();
    QString get_phone_number();
    ~insert_college();

private:
    Ui::insert_college *ui;
};

#endif // INSERT_COLLEGE_H
