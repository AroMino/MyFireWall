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
//    QThread::sleep(0);
    m->getSystemEnvironment()->getCurrentSystemFilter(m->getPassword());
//    m->displayFilter(m->getSystemEnvironment()->getFilter());

}
