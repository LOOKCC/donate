#ifndef MORE_H
#define MORE_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
namespace Ui {
class more;
}

class more : public QDialog
{
    Q_OBJECT

public:
    explicit more(QWidget *parent = 0);
    ~more();
    void Add_info(QString name, QString money);
private:
    Ui::more *ui;
};

#endif // MORE_H
