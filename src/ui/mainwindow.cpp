#include "mainwindow.h"


#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QComboBox>
#include <QSpacerItem>
#include <QIcon>
#include <QFont>
#include <QMessageBox>
#include <QHeaderView>



MainWindow::MainWindow( QWidget *parent)
    : QMainWindow(parent)

{
    setGeometry(0, 0, 1109, 455);
    setWindowTitle("همیار هوتی");
    setWindowIcon(QIcon(":/images/pencil.png")); // Requires .qrc resource

    QFont mainFont("Nazanin", 11);
    setFont(mainFont);
    setLayoutDirection(Qt::RightToLeft);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *topLayout = new QHBoxLayout(); // Empty layout
    mainLayout->addLayout(topLayout);

    QVBoxLayout *middleLayout = new QVBoxLayout();
    mainLayout->addLayout(middleLayout);

    // --- GroupBox for Search ---
    QGroupBox *groupBox = new QGroupBox("جستجو اطلاعات دانش آموز", this);
    groupBox->setMinimumHeight(80);
    groupBox->setFont(QFont("0 Nazanin Bold", 11, QFont::Bold));
    QGridLayout *gridLayout = new QGridLayout(groupBox);
    gridLayout->setContentsMargins(0, 4, 0, 0);

    QLabel *label = new QLabel("مشخصات :");
    label->setMinimumWidth(100);
    label->setMaximumWidth(200);
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    lineEdit = new QLineEdit();
    lineEdit->setMaximumWidth(300);
    lineEdit->setMinimumHeight(30);
    lineEdit->setAlignment(Qt::AlignCenter);
    lineEdit->setPlaceholderText("نام خانوادگی یا کد ملی را وارد نمایید");

    pushButtonSearch = new QPushButton("جستجو");
    pushButtonSearch->setMinimumWidth(110);
    pushButtonSearch->setMinimumHeight(30);
    pushButtonSearch->setFont(QFont("0 Nazanin Bold", 11, QFont::Bold));

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addWidget(label, 0, 0);
    gridLayout->addWidget(lineEdit, 0, 2);
    gridLayout->addWidget(pushButtonSearch, 0, 3);
    gridLayout->addItem(spacer, 0, 4);

    middleLayout->addWidget(groupBox);

    // --- Table View ---
    tbl = new QTableView(this);
    tbl->setFont(QFont("0 Nazanin Bold", 11, QFont::Bold));
    tbl->setShowGrid(true);
    tbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    middleLayout->addWidget(tbl);

    // --- GroupBox for Database Selection ---
    QGroupBox *groupBox2 = new QGroupBox("انتخاب پایگاه داده", this);
    groupBox2->setMaximumHeight(75);
    groupBox2->setFont(QFont("Nazanin", 11, QFont::Bold));

    QVBoxLayout *groupBox2Layout = new QVBoxLayout(groupBox2);
    groupBox2Layout->setContentsMargins(0, 2, 0, 0);

    QHBoxLayout *dbLayout = new QHBoxLayout();

    comboBoxDb = new QComboBox(this);
    comboBoxDb->setMinimumWidth(200);

    pushButtonSetDb = new QPushButton("ثبت", this);
    pushButtonSetDb->setMinimumWidth(110);
    pushButtonSetDb->setMaximumWidth(110);
    pushButtonSetDb->setMinimumHeight(30);
    pushButtonSetDb->setFont(QFont("0 Nazanin Bold", 11, QFont::Bold));

    QSpacerItem *dbSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    dbLayout->addWidget(comboBoxDb);
    dbLayout->addWidget(pushButtonSetDb);
    dbLayout->addItem(dbSpacer);
    groupBox2Layout->addLayout(dbLayout);
    middleLayout->addWidget(groupBox2);
    setCentralWidget(centralWidget);
    m_repository.init("Dana5011");
    loadData();
}

void MainWindow::loadData()
{
    m_model = m_repository.GetStduents();
    tbl->setModel(m_model.get());
    tbl->show();

    changeQTableViewUi(tbl);
    tbl->scrollToTop();
}

void MainWindow::changeQTableViewUi(QTableView *table)
{
    table->setColumnWidth(0, 150);
    table->setColumnWidth(1, 200);
    table->setColumnWidth(2, 300);
    table->setColumnWidth(3, 200);
    table->setColumnWidth(4, 200);
    table->setSelectionBehavior(QAbstractItemView::SelectItems);
}

void MainWindow::changeQSqlQueryModelHeaeder(QSqlQueryModel *model)
{

}
