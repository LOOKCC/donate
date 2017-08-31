#include "change_class.h"
#include "ui_change_class.h"

change_class::change_class(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_class)
{
    ui->setupUi(this);
}

change_class::~change_class()
{
    delete ui;
}
QString change_class::get_class_ID(){
    return ui->class_NO_lineEdit->text();
}
int change_class::get_grade(){
    QString temp = ui->grade_lineEdit->text();
    return temp.toInt();
}
int change_class::get_person_number(){
    QString temp = ui->person_numberlineEdit->text();
    return temp.toInt();
}
QString change_class::get_college_name(){
    return ui->college_name_lineEdit->text();
}
QString change_class::get_counselor(){
    return ui->counselor_lineEdit->text();
}
void change_class::show_info(struct class_info *temp){
    ui->class_NO_lineEdit->setText(QString(temp->class_ID));
    ui->grade_lineEdit->setText(QString::number(temp->grade, 10));
    ui->person_numberlineEdit->setText(QString::number(temp->person_number, 10));
    ui->college_name_lineEdit->setText(QString(temp->college_name));
    ui->counselor_lineEdit->setText(QString(temp->counselor));
}
