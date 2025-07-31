// #include "mainwindow.h"
#include "studentdetails.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentDetails app;
     app.show();
    return a.exec();
}
