#ifndef ISTUDENTQUERY_H
#define ISTUDENTQUERY_H

#include <QString>

class IStudentQuery
{
public:
    virtual QString GetStduents()const =0;
    virtual QString GetStduent(QString &lastname,QString &stdentId)const=0;
    virtual QString GetStduentHistory(QString &stdentId)const=0;
    virtual QString GetStduentsHistoryCount()const=0;
    virtual ~IStudentQuery() = default;
};
#endif // ISTUDENTQUERY_H
