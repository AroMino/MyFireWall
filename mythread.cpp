#include "mythread.h"

MyThread::MyThread()
{
    this->m = m;
}

MyThread::MyThread(MainWindow* m)
{
    this->m = m;
}

void MyThread::run()
{
    m->getSystemEnvironment()->getCurrentSystemFilter(m->getPassword());
    // QThread::sleep(5);
}
