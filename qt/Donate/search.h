#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QLineEdit>
namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    QString get_class_ID();
    int get_grade();
private:
    Ui::Search *ui;
};

#endif // SEARCH_H
