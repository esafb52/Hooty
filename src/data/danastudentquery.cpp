#include "danastudentquery.h"
#include <QStringLiteral>

DanaStudentQuery::DanaStudentQuery() {}

QString DanaStudentQuery::GetStduents()const
{
    const QString q = QStringLiteral(R"(
            SELECT TOP 100
            StudentCode,
            FirstName,
            LastName,
            FatherName,
            Address
            FROM Students
            ORDER BY LastName, FatherName
        )").trimmed();
    return q;
}

QString DanaStudentQuery::GetStduent(QString &lastname, QString &stdentId)const
{
    const QString q = QStringLiteral(
        "SELECT TOP 100 "
        "StudentCode, "
        "FirstName, "
        "LastName, "
        "FatherName, "
        "Address "
        "FROM Students "
        "WHERE LastName LIKE :lastname OR StudentCode = :studentId "
        "ORDER BY LastName, FatherName"
        );
    return q;
}

QString DanaStudentQuery::GetStduentHistory(QString &stdentId) const
{
    const QString cmd =
        QString("SELECT distinct StudentCode,Timeyear, case   "
                "  when TimeDore=1 then N'ضمن سال'   "
                "  when TimeDore=2 then N'تابستان'   "
                "  when TimeDore=3 then N'دی ماه'   ELSE N'سایر' "
                "     end as TimeDore,"
                "     Grade  ,"
                "     PassedUnits ,"
                "     TotalUnits, "
                "     s.SchoolCode,"
                "     s.Name as school        FROM Histories as h  "
                "     inner join Schools as s "
                "     on h.SchoolCode = s.SchoolCode"
                "     where StudentCode=%1  order by Timeyear ")
            .arg(stdentId);
    return cmd;
}

QString DanaStudentQuery::GetStduentsHistoryCount() const
{
    return  QStringLiteral("SELECT COUNT(DISTINCT StudentCode)FROM Histories");
}
