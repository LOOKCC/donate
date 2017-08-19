#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Donate");
    w.Show_tree();
    w.Show_info();
    w.show();

    return a.exec();
}
