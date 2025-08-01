#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data/studentrepository.h"


class QLineEdit;
class QPushButton;
class QTableView;
class QComboBox;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void loadData();
    void changeQTableViewUi(QTableView* tbl);
    void changeQSqlQueryModelHeaeder(QSqlQueryModel * model);

private:
    QLineEdit *lineEdit;
    QPushButton *pushButtonSearch;
    QTableView *tbl;
    QComboBox *comboBoxDb;
    QPushButton *pushButtonSetDb;
    studentrepository m_repository;
    QSharedPointer<QSqlQueryModel> m_model;


};

#endif // MAINWINDOW_H
