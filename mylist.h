#ifndef MYLIST_H
#define MYLIST_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QMainWindow>

class MyList: public QMainWindow
{

public:
    MyList(QObject *parent);
    ~MyList();
    void addItem(QCheckBox* item);
    void addSearch(QLineEdit* item);
    void setCheckedList(QString list);
    QString getCheckedList();
    void clear();

    static int isConstructed();



private:
    QWidget* main;
    QWidget* searchWidget;
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
    QVBoxLayout* layout;
    QString checkedList;
    int height;
    static int exist;
};
#endif
// MYLIST_H
