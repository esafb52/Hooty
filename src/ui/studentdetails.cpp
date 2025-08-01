#include "studentdetails.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSpacerItem>
#include <QTableView>
#include <QFont>

StudentDetails::StudentDetails(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(0, 0, 845, 368);
    setWindowTitle("Form");
    setLayoutDirection(Qt::RightToLeft);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *topEmptyLayout = new QHBoxLayout();  // Unused but part of XML
    mainLayout->addLayout(topEmptyLayout);

    QVBoxLayout *verticalLayout = new QVBoxLayout();
    mainLayout->addLayout(verticalLayout);

    // --- GroupBox for student info ---
    QGroupBox *groupBox = new QGroupBox(" اطلاعات تحصیلی دانش آموز ", this);
    groupBox->setFont(QFont("0 Nazanin Bold", 12, QFont::Bold));
    QGridLayout *gridLayout = new QGridLayout(groupBox);

    QLabel *labelName = new QLabel("نام و نام خانوادگی");
    labelName->setMinimumWidth(100);
    labelName->setMaximumWidth(200);
    labelName->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    labelFullName = new QLabel("عیسی مهرنیا");
    labelFullName->setMinimumWidth(200);
    labelFullName->setMaximumWidth(200);
    labelFullName->setAlignment(Qt::AlignCenter);

    QLabel *labelFatherTitle = new QLabel("نام پدر :");
    labelFatherTitle->setMinimumWidth(100);
    labelFatherTitle->setMaximumWidth(200);
    labelFatherTitle->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    labelFatherName = new QLabel("مراد");
    labelFatherName->setMinimumWidth(100);
    labelFatherName->setMaximumWidth(200);
    labelFatherName->setAlignment(Qt::AlignCenter);

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addWidget(labelName,        0, 0);
    gridLayout->addWidget(labelFullName,    0, 1);
    gridLayout->addWidget(labelFatherTitle, 0, 2);
    gridLayout->addWidget(labelFatherName,  0, 3);
    gridLayout->addItem(spacer,             0, 4);

    verticalLayout->addWidget(groupBox);

    // --- Table view ---
    tbl = new QTableView(this);
    tbl->setFont(QFont("0 Nazanin Bold", 11, QFont::Bold));
    verticalLayout->addWidget(tbl);
}
