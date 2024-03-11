#ifndef SYSTEMENVIRONMENT_H
#define SYSTEMENVIRONMENT_H

#include <QStringList>
#include <QList>
#include <QMap>
#include "rule.h"

class SystemEnvironment
{
public:
    SystemEnvironment();
    ~SystemEnvironment();

    void getAvailableInterfaceFromSystem();
    void getAvailablePortsFromSystem();
    void applyFilter(QString path, QString password);
    void getCurrentSystemFilter(QString password);

    QStringList getInterfaces();
    QMap<QString,QMap<QString,QString>> getPorts();
    QMap<QString,QMap<QString,QString>> getServices();
    QList<Rule*> getFilter();


    int testPassword(QString password);


private:
    QStringList availableInterface;
    QMap<QString,QMap<QString,QString>> ports;
    QMap<QString,QMap<QString,QString>> services;
    QList<Rule*> filter;
};

#endif // SYSTEMENVIRONMENT_H
