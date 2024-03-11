#ifndef RULE_H
#define RULE_H

#include <QString>
#include <QStringList>

class Rule
{
private:
    QString chain;
    QString target;
    QString protocole;
    QString port;
    QString interface;
    QString source;
    QString destination;
    QString portSituation;
    QString machine;

public:
    Rule();
    ~Rule();

    /// Setters
    void setChain(QString chain);
    void setTarget(QString target);
    void setProtocole(QString protocole);
    void setPort(QString port);
    void setInterface(QString interface);
    void setSource(QString source);
    void setDestination(QString destination);
    void setPortSituation(QString situation);
    void setMachine(QString machine);

    /// Getters
    QString getChain() const;
    QString getTarget() const;
    QString getProtocole() const;
    QString getPort() const;
    QString getInterface() const;
    QString getSource() const;
    QString getDestination() const;
    QString getPortSituation() const;
    QString getMachine() const;

    /// Generator
    QString generateRule() const;

};

#endif // RULE_H
