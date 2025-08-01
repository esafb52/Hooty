#ifndef STUDENTDATAFACTORY_H
#define STUDENTDATAFACTORY_H

#include "istudentquery.h"

#include "danastudentquery.h"



class StudenDataFactory
{

public:
    std::unique_ptr<IStudentQuery> create(const QString& dbName)
    {
        if (dbName.startsWith("Dana", Qt::CaseInsensitive) == 0) return std::make_unique<DanaStudentQuery>();
        if (dbName.startsWith("Dip", Qt::CaseInsensitive) == 0)  return std::make_unique<DanaStudentQuery>();
        if (dbName.startsWith("Rah", Qt::CaseInsensitive) == 0)  return std::make_unique<DanaStudentQuery>();
        if (dbName.startsWith("Tos", Qt::CaseInsensitive) == 0) return std::make_unique<DanaStudentQuery>();
        return std::make_unique<DanaStudentQuery>();
    }

};

#endif // STUDENTDATAFACTORY_H
