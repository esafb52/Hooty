#include "studentrepository.h"

#include "studentDataFactory.h"

#include <QSqlQuery>
#include <QSqlTableModel>

studentrepository::studentrepository() {}

QSharedPointer<QSqlQueryModel> studentrepository::GetStduents() {
    auto model = QSharedPointer<QSqlQueryModel>::create();
    openDatabase();
    model->setQuery(m_queryBuilder->GetStduents(), m_db);
    return model;
}

QSharedPointer<QSqlQueryModel>
studentrepository::GetStduents(QString &lastname, QString &stdentId) {
    auto model = QSharedPointer<QSqlQueryModel>::create();
    model->setQuery(m_queryBuilder->GetStduent(lastname, stdentId), m_db);
    return model;
}

void studentrepository::init(const QString &dbName) {
    m_db = QSqlDatabase::addDatabase(m_sqlDriver);
    m_db.setDatabaseName(m_connectionStr.arg(m_server_name, dbName));
    StudenDataFactory factory;
    m_queryBuilder = factory.create(dbName);

    openDatabase();
}

bool studentrepository::openDatabase() {
    if (m_db.isOpen())
        return true;
    return m_db.open();
}

void studentrepository::closeDatabase() {
    if (m_db.open()) {
        m_db.close();
    }
}

studentrepository::~studentrepository() { closeDatabase(); }
