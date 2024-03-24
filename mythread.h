#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "mainwindow.h"
#include <QThread>

class MyThread: public QThread
{
public:
    MyThread();
    MyThread(MainWindow* m);
    void run() override;

private:
    MainWindow* m;
};

#endif // MYTHREAD_H
