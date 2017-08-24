#ifndef RATIO_H
#define RATIO_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class ratio;
}

class ratio : public QDialog
{
    Q_OBJECT

public:
    explicit ratio(QWidget *parent = 0);
    ~ratio();
    void set_grade(int raw,int column,QString info);
private:
    Ui::ratio *ui;
};

#endif // RATIO_H
