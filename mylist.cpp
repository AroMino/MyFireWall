#include "mylist.h"
#include <QDebug>
#include <QLabel>

int MyList::exist = 0;

MyList::MyList(QObject *parent = nullptr)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->height = 0;
    this->exist++;

    this->main = new QWidget(this);
    this->searchWidget = new QWidget(this->main);
    this->scrollArea = new QScrollArea(this->main);
    this->scrollWidget = new QWidget(this->scrollArea);
    this->layout = new QVBoxLayout();

    this->scrollArea->move(0,40);
    this->show();

    this->setMinimumSize(220,240);
    this->setMaximumSize(220,240);
    this->searchWidget->setMinimumSize(220,40);
    this->scrollArea->setMinimumSize(220,195);
    this->scrollArea->setWidget(scrollWidget);
    this->scrollWidget->setLayout(layout);
    this->scrollWidget->setMinimumSize(190,height);
    this->main->setMinimumSize(220,240);
}

MyList::~MyList()
{
    qDebug() << "Destruction";
    qDebug() << exist--;
}

void MyList::setCheckedList(QString list)
{
    this->checkedList = list;
}

QString MyList::getCheckedList()
{
    return this->checkedList;
}

void MyList::clear()
{
    this->height = 0;

    this->layout->deleteLater();
    this->scrollWidget->deleteLater();
    this->scrollArea->deleteLater();

    this->scrollArea = new QScrollArea(this->main);
    this->scrollWidget = new QWidget(this->scrollArea);
    this->layout = new QVBoxLayout();

    this->scrollArea->setMinimumSize(220,195);
    this->scrollWidget->setMinimumSize(190,height);
    this->scrollArea->move(0,40);
    this->scrollWidget->setLayout(this->layout);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->show();
    this->scrollArea->show();
}

int MyList::isConstructed()
{
    return exist;
}

void MyList::addItem(QCheckBox* item)
{
    height += 30;
    item->setMaximumHeight(30);
    item->setMinimumHeight(30);
    this->layout->addWidget(item);
    this->scrollWidget->setMinimumHeight(height);
}

void MyList::addSearch(QLineEdit *item)
{
    QVBoxLayout* layout = new QVBoxLayout();
    this->searchWidget->setLayout(layout);
    layout->addWidget(item);
}

