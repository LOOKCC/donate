#include "insert_college.h"
#include "ui_insert_college.h"

insert_college::insert_college(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_college)
{
    ui->setupUi(this);
}

insert_college::~insert_college()
{
    delete ui;
}
QString insert_college::get_college_name(){
    return ui->college_name_lineEdit->text();
}
QString insert_college::get_person_name(){
    return ui->peraon_name_lineEdit->text();
}
QString insert_college::get_phone_number(){
    return ui->phone_number_lineEdit->text();
}
