#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "donate.h"
#include "change_college.h"
#include "change_class.h"
#include "change_student.h"
#include "insert_college.h"
#include "insert_class.h"
#include "insert_student.h"
#include "search.h"
#include "ratio.h"
#include "more.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QByteArray>
#include <QByteArrayData>
#include <string.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Show_tree();


    ~MainWindow();


private:
    Ui::MainWindow *ui;
    change_college* change_college_win;
    change_class* change_class_win;
    change_student* change_student_win;
    insert_college* insert_college_win;
    insert_class* insert_class_win;
    insert_student* insert_student_win;
    Search* search_win;
    ratio* ratio_win;
    more* more_win;
    int now_index[3];
    struct college_info* head;
private slots:
    void Mouse_position(QTreeWidgetItem* item);
    void Show_info(QTreeWidgetItem* ,int);
    void Insert_Show();
    void Delete();
    void Change_Show();
    void Sort_student();
    void Sort_donate();
    void More_than();
    void Ratio();
    void Search_Class_show();
    void Insert_College();
    void Insert_Class();
    void Insert_Student();
    void Change_College();
    void Change_Class();
    void Change_Student();
    void Search_Class();
    void Create_College();
    void Create_Class();
    void Create_Student();
};

#endif // MAINWINDOW_H
