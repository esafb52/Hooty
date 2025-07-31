#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

struct Student {
    QString studentId;
    QString firstName;
    QString lastName;
    QString fatherName;
    QString birthPlace;


    Student() = default;

    Student(const QString& id,
            const QString& first,
            const QString& last,
            const QString& father,
            const QString& birth)
        : studentId(id),
        firstName(first),
        lastName(last),
        fatherName(father),
        birthPlace(birth) {}
};


#endif // STUDENT_H
