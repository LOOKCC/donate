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
    head = NULL;
    now_index[0] = -1;
    now_index[1] = -1;
    now_index[2] = -1;
    change_college_win = new change_college(this);
    change_class_win = new change_class(this);
    change_student_win = new change_student(this);
    insert_college_win = new insert_college(this);
    insert_class_win = new insert_class(this);
    insert_student_win = new insert_student(this);
    more_win = new more(this);
    ratio_win = new ratio(this);
    search_win = new Search(this);


//qt connect
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(Show_info(QTreeWidgetItem* ,int)));

    connect(ui->insertButton,SIGNAL(clicked()),this,SLOT(Insert_Show()));
    connect(ui->changeButton,SIGNAL(clicked()),this,SLOT(Change_Show()));
    connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(Delete()));

    connect(ui->sortsButton,SIGNAL(clicked()),this,SLOT(Sort_student()));
    connect(ui->sortdButton,SIGNAL(clicked()),this,SLOT(Sort_donate()));
    connect(ui->moreButton,SIGNAL(clicked()),this,SLOT(More_than()));
    connect(ui->searchButton,SIGNAL(clicked()),this,SLOT(Search_Class_show()));
    connect(ui->ratioButton,SIGNAL(clicked()),this,SLOT(Ratio()));
    //change
    connect(change_college_win,SIGNAL(accepted()),this,SLOT(Change_College()));
    connect(change_class_win,SIGNAL(accepted()),this,SLOT(Change_Class()));
    connect(change_student_win,SIGNAL(accepted()),this,SLOT(Change_Student()));
    //insert
    connect(insert_college_win,SIGNAL(accepted()),this,SLOT(Insert_College()));
    connect(insert_class_win,SIGNAL(accepted()),this,SLOT(Insert_Class()));
    connect(insert_student_win,SIGNAL(accepted()),this,SLOT(Insert_Student()));
    //search
    connect(search_win,SIGNAL(accepted()),this,SLOT(Search_Class()));

    //for test
    struct college_info temp1;
    temp1.class_head = NULL;
    temp1.next = NULL;
    strcpy(temp1.college_name ,"CS");
    strcpy(temp1.person_name , "wzh");
    strcpy(temp1.phone_number , "123456");
    struct class_info temp2;
    strcpy(temp2.class_ID , "01");
    temp2.grade = 16;
    temp2.person_number = 29;
    strcpy(temp2.college_name , "CS");
    strcpy(temp2.counselor , "hhh");
    temp2.student_head = NULL;
    temp2.next = NULL;
    struct student_info temp3;
    strcpy(temp3.name , "wang");
    strcpy(temp3.ID , "U2016");
    temp3.gender = 'm';
    temp3.age = 19;
    temp3.money = 14.3f;
    temp3.next = NULL;
    head = create_college(temp1,head);
    head = create_class(temp2,head,0);
    head = create_student(temp3,head,0,0);

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
    qDebug()<<now_index[0]<<now_index[1]<<now_index[2];
}
void MainWindow::Show_tree(){
    ui->treeWidget->clear();
    qDebug()<<"show_tree_begin";
    QTreeWidgetItem *All = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("All")));
    //for test
    //QTreeWidgetItem *test = new QTreeWidgetItem(All,QStringList(QString("test")));
    //All->addChild(test);
    struct college_info* college_temp = head;
    while(college_temp != NULL){
        QTreeWidgetItem *college = new QTreeWidgetItem(QStringList(QString(college_temp->college_name)));
        All->addChild(college);
        struct class_info* class_temp = college_temp->class_head;
        while(class_temp != NULL){
            QTreeWidgetItem *clas_s = new QTreeWidgetItem(QStringList(QString::number(class_temp->grade, 10) + QString(class_temp->class_ID)));
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
    qDebug()<<"show_tree_over";
}
void MainWindow::Show_info(QTreeWidgetItem* item,int n){
    Mouse_position(item);
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
        ui->tableWidget->setItem(3, 0, new QTableWidgetItem(" "));
        ui->tableWidget->setItem(4, 0, new QTableWidgetItem(" "));

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(college_temp->college_name)));
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString(college_temp->person_name)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString(college_temp->phone_number)));
        ui->tableWidget->setItem(3, 1, new QTableWidgetItem(" "));
        ui->tableWidget->setItem(4, 1, new QTableWidgetItem(" "));
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
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(class_temp->grade, 10)));
        ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(class_temp->person_number, 10)));
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
        ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(student_temp->age, 10)));
        ui->tableWidget->setItem(4, 1, new QTableWidgetItem( QString("%1").arg(student_temp->money)));
    }
}
void MainWindow::Insert_Show(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        insert_college_win->show();
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        insert_class_win->show();
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        insert_student_win->show();
    }
}
void MainWindow::Insert_College(){
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
    Show_tree();
}
void MainWindow::Insert_Class(){
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
    Show_tree();
}
void MainWindow::Insert_Student(){
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
    temp.gender = gender.unicode();
    temp.age = age;
    temp.money = money;
    head = Insert_student(temp,head,now_index[2],now_index[1],now_index[0]);
    Show_tree();
}
void MainWindow::Delete(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        head = delete_college(head,now_index[0]);
        Show_tree();
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        head = delete_class(head,now_index[1],now_index[0]);
        Show_tree();
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        head = delete_student(head,now_index[2],now_index[1],now_index[0]);
        Show_tree();
    }
}
void MainWindow::Change_Show(){
    //nothig
    if(now_index[0] == -1 && now_index[1] == -1 && now_index[2] == -1){
       return;
    }
    //college
    if(now_index[0] != -1 && now_index[1] == -1 && now_index[2] == -1){
        change_college_win->show();
    }
    //class
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] == -1){
        change_class_win->show();
    }
    //student
    if(now_index[0] != -1 && now_index[1] != -1 && now_index[2] != -1){
        change_student_win->show();
    }
}
void MainWindow::Change_College(){
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
    Show_tree();
}

void MainWindow::Change_Class(){
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
    Show_tree();
}

void MainWindow::Change_Student(){
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
    temp.gender = gender.unicode();
    temp.age = age;
    temp.money = money;
    head = Change_student(temp,head,now_index[2],now_index[1],now_index[0]);
    Show_tree();
}

void MainWindow::Sort_student(){
    qDebug()<<"he";
    head = sort_student_all(head);
    qDebug()<<"here";
    QMessageBox::information(NULL,"Information","Sorted by student",QMessageBox::Ok);
    Show_tree();
}
void MainWindow::Sort_donate(){
    head = sort_donate_all(head);
    QMessageBox::information(NULL,"Information","Sorted by donate",QMessageBox::Ok);
    Show_tree();
}
void MainWindow::More_than(){
    struct college_info* temp_college = head;
    while(temp_college != NULL){
        struct class_info* temp_class = temp_college->class_head;
        while(temp_class != NULL){
            struct student_info* temp_student = temp_class->student_head;
            while(temp_student != NULL){
                if(temp_student->money > 200.0f){
                    //QString s = QString::number(temp_student->money,10);
                    QString s = QString("%1").arg(temp_student->money);
                    more_win->Add_info(QString(QLatin1String(temp_student->name)),s);
                }
                temp_student = temp_student->next;
            }
            temp_class = temp_class->next;
        }
        temp_college = temp_college->next;
    }
    more_win->show();
}
void MainWindow::Ratio(){
    int total_number[4] = {0,0,0,0};
    int money_number[4] = {0,0,0,0};
    struct college_info* temp_college = head;
    while(temp_college != NULL){
        if(strcmp(temp_college->college_name,"CS") == 0){
            struct class_info* temp_class = temp_college->class_head;
            while(temp_class != NULL){
                struct student_info* temp_student = temp_class->student_head;
                while(temp_student != NULL){
                    total_number[temp_class->grade-14]++;
                    if(temp_student->money > 0.0f){
                        money_number[temp_class->grade-14]++;
                    }
                    temp_student = temp_student->next;
                }
                temp_class = temp_class->next;
            }
        }
        else{
            temp_college = temp_college->next;
        }
    }
    float res[4];
    float temp_ratio[4];
    for(int i = 0; i < 4; ++i){
        res[i] = money_number[i]/total_number[i];
        temp_ratio[i] = res[i];
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3 ; ++j){
            if(temp_ratio[j] < temp_ratio[j+1]){
                float change = temp_ratio[j];
                temp_ratio[j] = temp_ratio[j+1];
                temp_ratio[j+1] = change;
            }
        }
    }
    for(int i = 0; i < 4; ++i){
        int position;
        for(int j = 0; j < 4; ++j){
            if(res[j] == temp_ratio[i]){
                position = j;
            }
        }
        QString s1 = QString::number(position+14, 10);
        QString s2 = QString("%1").arg(temp_ratio[i]);
        //QString s2 = QString::number(temp_ratio[i], 10);
        ratio_win->set_grade(i,0,s1);
        ratio_win->set_grade(i,1,s2);
    }
    ratio_win->show();
}
void MainWindow::Search_Class_show(){
    search_win->show();
}
void MainWindow::Search_Class(){
    QString class_ID = search_win->get_class_ID();
    QByteArray ba1 = class_ID.toLatin1();
    char* class_ID_char;
    strcpy(class_ID_char,ba1.data());
    int grade = search_win->get_grade();
    if(search_CS_class(head,grade,class_ID_char)){
        QMessageBox::information(NULL,"Information","Find",QMessageBox::Ok);
    }
    else {
        QMessageBox::information(NULL,"Information","Not Find",QMessageBox::Ok);
    }
}
