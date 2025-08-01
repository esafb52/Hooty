#ifndef DANASTUDENTQUERY_H
#define DANASTUDENTQUERY_H

#include "istudentquery.h"


class DanaStudentQuery : public IStudentQuery
{

public:
    DanaStudentQuery();
    QString GetStduents() const override;
    QString GetStduent(QString &lastname,QString &stdentId)const override;
    QString GetStduentHistory(QString &stdentId) const override;
    QString GetStduentsHistoryCount() const override;
};

#endif // DANASTUDENTQUERY_H
