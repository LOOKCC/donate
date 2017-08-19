#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "donate.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Show_tree();
    void Show_info();
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int now_index;
    struct college_info* head;
private slots:
    void Mouse_position(QTreeWidgetItem* item);
};

#endif // MAINWINDOW_H
