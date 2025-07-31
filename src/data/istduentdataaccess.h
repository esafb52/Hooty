#ifndef ISTDUENTDATAACCESS_H
#define ISTDUENTDATAACCESS_H


#include <QList>

struct Student;
struct StudentHistory;

class IStudentDataAccess
{
public:
    IStudentDataAccess() {}
    virtual QList<Student> GetStduent(QString &lastname,QString &stdentId)=0;
    virtual QList<StudentHistory> GetStduentHistory(QString &stdentId)=0;
};

#endif // ISTDUENTDATAACCESS_H
