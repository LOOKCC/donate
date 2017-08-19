#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
// qt UI initialization
    ui->setupUi(this);
// treeWidget settings
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("colleges"));
// tableWidget settings
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "                    " <<"                    ");
    ui->tableWidget->verticalHeader()->setVisible(false);//hide
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    //ui->tableWidget->setRowHeight(60);
    //ui->tableWidget->resizeColumnsToContents();
    //ui->tableWidget->resizeRowsToContents();

//qt connect
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(test(QTreeWidgetItem*)));
//donate
    //head = create_with_file("");
    //Show_tree();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Mouse_position(QTreeWidgetItem* item){
    now_index[0] = -1;
    now_index[1] = -1;
    now_index[2] = -1;
    int i = 0;
    QTreeWidgetItem* parent = item->parent();
    while(parent != NULL){
        now_index[i] = parent->indexOfChild(item);
        i++;
        item = parent;
        parent = item->parent();
    }
}
void MainWindow::Show_tree(struct college_info* head){
    QTreeWidgetItem *All = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("All")));
    struct college_info* college_temp = head;
    while(college_temp != NULL){
        QTreeWidgetItem *college = new QTreeWidgetItem(QStringList(QString(college_temp->college_name)));
        All->addChild(college);
        struct class_info* class_temp = college_temp->class_head;
        while(class_temp != NULL){
            QTreeWidgetItem *clas_s = new QTreeWidgetItem(QStringList(QString(class_temp->grade) + QString(class_temp->class_ID)));
            college->addChild((clas_s));
            struct student_info* student_temp = class_temp->student_head;
            while(student_temp != NULL){
                QTreeWidgetItem *student = new QTreeWidgetItem(QStringList(QString(student_temp->name)));
                clas_s->addChild(student);
                student_temp = student_temp->next;
            }
            class_temp = class_temp->next;
        }
        college_temp = college_temp->next;
    }
}
void MainWindow::Show_info(){
    //nothing
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        struct college_info* college_temp = head;
        for(int i = 0; i < now_index[0]; ++i){
            college_temp = college_temp->next;
        }
        if(college_temp == NULL){
            return ;
        }
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("college_name"));
        ui->tableWidget->setItem(1, 0, new QTableWidgetItem("person_name"));
        ui->tableWidget->setItem(2, 0, new QTableWidgetItem("phone_number"));

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(college_temp->college_name)));
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString(college_temp->person_name)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString(college_temp->phone_number)));
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        struct college_info* college_temp = head;
        for(int i = 0; i < now_index[1]; ++i){
            college_temp = college_temp->next;
        }
        struct class_info* class_temp = college_temp->class_head;
        for(int i = 0; i < now_index[0]; ++i){
            class_temp = class_temp->next;
        }
        if(class_temp == NULL){
            return ;
        }
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("class_ID"));
        ui->tableWidget->setItem(1, 0, new QTableWidgetItem("grade"));
        ui->tableWidget->setItem(2, 0, new QTableWidgetItem("person_number"));
        ui->tableWidget->setItem(3, 0, new QTableWidgetItem("college_name"));
        ui->tableWidget->setItem(4, 0, new QTableWidgetItem("counselor"));

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(class_temp->class_ID)));
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString(class_temp->grade)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString(class_temp->person_number)));
        ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString(class_temp->college_name)));
        ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString(class_temp->counselor)));

    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        struct college_info* college_temp = head;
        for(int i = 0; i < now_index[2]; ++i){
            college_temp = college_temp->next;
        }
        struct class_info* class_temp = college_temp->class_head;
        for(int i = 0; i < now_index[1]; ++i){
            class_temp = class_temp->next;
        }
        struct student_info* student_temp = class_temp->student_head;
        for(int i = 0; i < now_index[0]; ++i){
            student_temp = student_temp->next;
        }
        if(student_temp == NULL){
            return;
        }
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("class_ID"));
        ui->tableWidget->setItem(1, 0, new QTableWidgetItem("grade"));
        ui->tableWidget->setItem(2, 0, new QTableWidgetItem("person_number"));
        ui->tableWidget->setItem(3, 0, new QTableWidgetItem("college_name"));
        ui->tableWidget->setItem(4, 0, new QTableWidgetItem("counselor"));

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(student_temp->name)));
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString(student_temp->ID)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString(student_temp->gender)));
        ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString(student_temp->age)));
        ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString(student_temp->money)));
    }




}
