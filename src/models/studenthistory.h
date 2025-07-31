#ifndef STUDENTHISTORY_H
#define STUDENTHISTORY_H

#include <QString>

struct StudentHistory {

    QString name;
    QString lastName;
    QString timeYear;
    QString school;
    QString grade;
    QString doreh;
    QString average;

    StudentHistory() = default;

    StudentHistory(const QString& name,
                   const QString& last,
                   const QString& year,
                   const QString& school,
                   const QString& grade,
                   const QString& doreh,
                   const QString& average)
        : name(name),
        lastName(last),
        timeYear(year),
        school(school),
        grade(grade),
        doreh(doreh),
        average(average) {}
};


#endif // STUDENTHISTORY_H
