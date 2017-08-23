#include "insert.h"
#include "ui_insert.h"

insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
}

insert::~insert()
{
    delete ui;
}
