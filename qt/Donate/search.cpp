#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}
QString Search::get_class_ID(){
    return ui->class_ID_lineEdit->text();
}
int Search::get_grade(){
    QString temp = ui->grade_lineEdit->text();
    return temp.toInt();
}
