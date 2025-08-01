#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include <QList>

struct Student;
struct StudentHistory;

class studentrepository
{
public:
    studentrepository();
    QList<Student> GetStduents(QString &lastname,QString &stdentId);
    QList<StudentHistory> GetStduentHistory(QString &stdentId);
    int GetStduentsHistoryCount();
    ~studentrepository() = default;
};

#endif // STUDENTREPOSITORY_H
