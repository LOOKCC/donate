#include "insert_class.h"
#include "ui_insert_class.h"

insert_class::insert_class(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_class)
{
    ui->setupUi(this);
}

insert_class::~insert_class()
{
    delete ui;
}
QString insert_class::get_class_ID(){
    return ui->class_NO_lineEdit->text();
}
int insert_class::get_grade(){
    QString temp = ui->grade_lineEdit->text();
    return temp.toInt();
}
int insert_class::get_person_number(){
    QString temp = ui->person_number_lineEdit->text();
    return temp.toInt();
}
QString insert_class::get_college_name(){
    return ui->college_name_lineEdit->text();
}
QString insert_class::get_counselor(){
    return ui->counselor_lineEdit->text();
}
