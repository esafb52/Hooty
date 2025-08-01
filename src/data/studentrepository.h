#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include "istudentquery.h"

#include <QSharedPointer>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class studentrepository {
public:
    explicit studentrepository();
    QSharedPointer<QSqlQueryModel> GetStduents();
    QSharedPointer<QSqlQueryModel> GetStduents(QString &lastname,
                                               QString &stdentId);
    QSharedPointer<QSqlQueryModel> GetStduentHistory(QString &stdentId);

    int GetStduentsHistoryCount();
    void init(const QString &dbName);
    bool openDatabase();
    void closeDatabase();

    ~studentrepository();

private:
    std::unique_ptr<IStudentQuery> m_queryBuilder;
    QSqlDatabase m_db;
    const QString m_server_name = ".\\SQLEXPRESS";
    const QString m_sqlDriver = "QODBC";
    const QString m_connectionStr = QString("DRIVER={SQL Server};"
                                            "SERVER=%1;Database=%2;"
                                            "Trusted_Connection=Yes;");
};

#endif // STUDENTREPOSITORY_H
