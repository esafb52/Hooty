#ifndef STUDENTDATAFACTORY_H
#define STUDENTDATAFACTORY_H

#include "istudentquery.h"
#include "dbhelper.h"
#include "danastudentquery.h"



class StudenDataFactory
{

public:
    std::unique_ptr<IStudentQuery> create(const QString& dbType)
    {

        const auto type=DbHelper::detectDbType(dbType);

        switch (type) {
        case DbHelper::DbType::Dana :
            return std::make_unique<DanaStudentQuery>();
        case DbHelper::Dip :
            return std::make_unique<DanaStudentQuery>();
        case DbHelper::Rah  :
            return std::make_unique<DanaStudentQuery>();
        case DbHelper::Tos  :
            return std::make_unique<DanaStudentQuery>();
        case DbHelper::Master :
            return std::make_unique<DanaStudentQuery>();
        }
    }


};

#endif // STUDENTDATAFACTORY_H
