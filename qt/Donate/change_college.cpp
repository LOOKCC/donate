#include "change_college.h"
#include "ui_change_college.h"

change_college::change_college(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_college)
{
    ui->setupUi(this);
}

change_college::~change_college()
{
    delete ui;
}
QString change_college::get_college_name(){
    return ui->college_name_lineEdit->text();
}
QString change_college::get_person_name(){
    return ui->person_name_lineEdit->text();
}
QString change_college::get_phone_number(){
    return ui->phone_number_lineEdit->text();
}
