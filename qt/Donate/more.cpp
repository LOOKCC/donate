#include "more.h"
#include "ui_more.h"

more::more(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::more)
{
    ui->setupUi(this);
    ui->tableWidget->setWindowTitle("More_than_200");
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<"Name"<<"Money";
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

more::~more()
{
    delete ui;
}
void more::Add_info(QString name, QString money){
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(money));
}
