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
    int row = tableWidget->rowCount();
    tableWidget->setRowCount(row+1);
    ui->tableWidget->setItem(raw,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(raw,1,new QTableWidgetItem(money));
}
