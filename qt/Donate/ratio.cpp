#include "ratio.h"
#include "ui_ratio.h"

ratio::ratio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ratio)
{
    ui->setupUi(this);
    ui->tableWidget->setWindowTitle("Ratio");
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(4);
    QStringList header;
    header<<"Grade"<<"Ratio";
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

ratio::~ratio()
{
    delete ui;
}
void ratio::set_grade(int raw,int column,QString info){
    ui->tableWidget->setItem(raw,column,new QTableWidgetItem(info));
}
