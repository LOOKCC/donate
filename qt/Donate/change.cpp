#include "change.h"
#include "ui_change.h"

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
}

change::~change()
{
    delete ui;
}
