#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QString>

class DbHelper : public QObject {
    Q_OBJECT
public:
    enum DbType {
        Dana = 0,
        Dip,
        Rah,
        Tos,
        Master
    };

    Q_ENUM(DbType)


    static DbType detectDbType(const QString& dbName) {
        if (dbName.startsWith("Dana", Qt::CaseInsensitive)) return DbType::Dana;
        if (dbName.startsWith("Dip", Qt::CaseInsensitive))  return DbType::Dip;
        if (dbName.startsWith("Rah", Qt::CaseInsensitive))  return DbType::Rah;
        if (dbName.startsWith("Tos", Qt::CaseInsensitive))  return DbType::Tos;
        return DbType::Master;
    }

};




#endif // DBHELPER_H
