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
    connect(ui->insertButton,SIGNAL(clicked()),this,SLOT(Insert()));
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
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem("name"));
        ui->tableWidget->setItem(1, 0, new QTableWidgetItem("ID"));
        ui->tableWidget->setItem(2, 0, new QTableWidgetItem("gender"));
        ui->tableWidget->setItem(3, 0, new QTableWidgetItem("age"));
        ui->tableWidget->setItem(4, 0, new QTableWidgetItem("money"));

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(student_temp->name)));
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString(student_temp->ID)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString(student_temp->gender)));
        ui->tableWidget->setItem(3, 1, new QTableWidgetItem(student_temp->age));
        ui->tableWidget->setItem(4, 1, new QTableWidgetItem(student_temp->money));
    }
}
void MainWindow::Insert(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        insert_college_win = new insert_college(this);
        insert_college_win->show();
        QString college_name = insert_college_win->get_college_name();
        QString person_name = insert_college_win->get_person_name();
        QString phone_number = insert_college_win->get_phone_number();
        struct college_info temp ;
        QByteArray ba1 = college_name.toLatin1();
        strcpy(temp.college_name,ba1.data());
        QByteArray ba2 = person_name.toLatin1();
        strcpy(temp.person_name,ba2.data());
        QByteArray ba3 = phone_number.toLatin1();
        strcpy(temp.phone_number,ba3.data());
        head = Insert_college(temp,head,now_index[0]);
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        insert_class_win = new insert_class(this);
        insert_class_win->show();
        QString class_ID = insert_class_win->get_class_ID();
        int grade = insert_class_win->get_grade();
        int person_number = insert_class_win->get_person_number();
        QString college_name = insert_class_win->get_college_name();
        QString counselor = insert_class_win->get_counselor();
        struct class_info temp ;
        QByteArray ba1 = class_ID.toLatin1();
        strcpy(temp.class_ID,ba1.data());
        temp.grade = grade;
        temp.person_number = person_number;
        QByteArray ba2 = college_name.toLatin1();
        strcpy(temp.college_name,ba2.data());
        QByteArray ba3 = counselor.toLatin1();
        strcpy(temp.counselor,ba3.data());
        head = Insert_class(temp,head,now_index[1],now_index[0]);
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        insert_student_win = new insert_student(this);
        insert_student_win->show();
        QString name = insert_student_win->get_name();
        QString ID = insert_student_win->get_ID();
        QChar gender = insert_student_win->get_gender();
        int age = insert_student_win->get_age();
        float money = insert_student_win->get_money();
        struct student_info temp;
        QByteArray ba1 = name.toLatin1();
        strcpy(temp.name,ba1.data());
        QByteArray ba2 = ID.toLatin1();
        strcpy(temp.ID,ba2.data());
        temp.gender = gender;
        temp.age = age;
        temp.money = money;
        head = Insert_student(temp,head,now_index[2],now_index[1],now_index[0]);
    }
}
void MainWindow::Delete(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        head = delete_college(head,now_index[0]);
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        head = delete_class(head,now_index[1],now_index[0]);
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        head = delete_student(head,now_index[2],now_index[1],now_index[0]);
    }
}
void MainWindow::Change(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        change_college_win = new change_college(this);
        change_college_win->show();
        QString college_name = change_college_win->get_college_name();
        QString person_name = change_college_win->get_person_name();
        QString phone_number = change_college_win->get_phone_number();
        struct college_info temp ;
        QByteArray ba1 = college_name.toLatin1();
        strcpy(temp.college_name,ba1.data());
        QByteArray ba2 = person_name.toLatin1();
        strcpy(temp.person_name,ba2.data());
        QByteArray ba3 = phone_number.toLatin1();
        strcpy(temp.phone_number,ba3.data());
        head = Change_college(temp,head,now_index[0]);
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        change_class_win = new change_class(this);
        change_class_win->show();
        QString class_ID = change_class_win->get_class_ID();
        int grade = change_class_win->get_grade();
        int person_number = change_class_win->get_person_number();
        QString college_name = change_class_win->get_college_name();
        QString counselor = change_class_win->get_counselor();
        struct class_info temp ;
        QByteArray ba1 = class_ID.toLatin1();
        strcpy(temp.class_ID,ba1.data());
        temp.grade = grade;
        temp.person_number = person_number;
        QByteArray ba2 = college_name.toLatin1();
        strcpy(temp.college_name,ba2.data());
        QByteArray ba3 = counselor.toLatin1();
        strcpy(temp.counselor,ba3.data());
        head = Change_class(temp,head,now_index[1],now_index[0]);
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        change_student_win = new change_student(this);
        change_student_win->show();
        QString name = change_student_win->get_name();
        QString ID = change_student_win->get_ID();
        QChar gender = change_student_win->get_gender();
        int age = change_student_win->get_age();
        float money = change_student_win->get_money();
        struct student_info temp;
        QByteArray ba1 = name.toLatin1();
        strcpy(temp.name,ba1.data());
        QByteArray ba2 = ID.toLatin1();
        strcpy(temp.ID,ba2.data());
        temp.gender = gender;
        temp.age = age;
        temp.money = money;
        head = Change_student(temp,head,now_index[2],now_index[1],now_index[0]);
    }
}
void MainWindow::Sort_student(){
    sort_student_all(head);
}
void MainWindow::Sort_donate(){
    sort_donate_all(head);
}
void MainWindow::More_than(){

}
void MainWindow::Ratio(){

}
