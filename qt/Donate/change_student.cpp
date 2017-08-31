#include "change_student.h"
#include "ui_change_student.h"

change_student::change_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
}

change_student::~change_student()
{
    delete ui;
}
QString change_student::get_name(){
    return ui->name_lineEdit->text();
}
QString change_student::get_ID(){
    return ui->ID_lineEdit->text();
}
QChar change_student::get_gender(){
    QString temp = ui->gender_lineEdit->text();
    return temp[0];
}
int change_student::get_age(){
    QString temp = ui->age_lineEdit->text();
    return temp.toInt();
}
float change_student::get_money(){
    QString temp = ui->monet_lineEdit->text();
    return temp.toFloat();
}
void change_student::show_info(struct student_info *temp){
    ui->name_lineEdit->setText(QString(temp->name));
    ui->ID_lineEdit->setText(QString(temp->ID));
    ui->gender_lineEdit->setText(QString(temp->gender));
    ui->age_lineEdit->setText(QString::number(temp->age, 10));
    ui->monet_lineEdit->setText(QString("%1").arg(temp->money));
}
