#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QPushButton;
class QTableView;
class QComboBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QLineEdit *lineEdit;
    QPushButton *pushButtonSearch;
    QTableView *tbl;
    QComboBox *comboBoxDb;
    QPushButton *pushButtonSetDb;
};

#endif // MAINWINDOW_H
