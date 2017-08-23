#include "insert_student.h"
#include "ui_insert_student.h"

insert_student::insert_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_student)
{
    ui->setupUi(this);
}

insert_student::~insert_student()
{
    delete ui;
}
QString insert_student::get_name(){
    return ui->name_lineEdit->text();
}
QString insert_student::get_ID(){
    return ui->ID_lineEdit->text();
}
QChar insert_student::get_gender(){
    QString temp = ui->gender_lineEdit->text();
    return temp[0];
}
int insert_student::get_age(){
    QString temp = ui->age_lineEdit->text();
    return temp.toInt();
}
float insert_student::get_money(){
    QString temp = ui->money_lineEdit->text();
    return temp.toFloat();
}
