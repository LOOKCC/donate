#ifndef INSERT_H
#define INSERT_H

#include <QDialog>

namespace Ui {
class insert;
}

class insert : public QDialog
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = 0);
    ~insert();

private:
    Ui::insert *ui;
};

#endif // INSERT_H
