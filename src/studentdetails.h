#ifndef STUDENTDETAILS_H
#define STUDENTDETAILS_H

#include <QWidget>

class QTableView;
class QLabel;

class StudentDetails : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDetails(QWidget *parent = nullptr);

private:
    QLabel *labelFullName;
    QLabel *labelFatherName;
    QTableView *tbl;
};

#endif // STUDENTDETAILS_H
