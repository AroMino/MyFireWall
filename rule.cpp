#include "rule.h"

Rule::Rule()
{

}

Rule::~Rule()
{

}

void Rule::setChain(QString chain)
{
    this->chain = chain;
}

void Rule::setTarget(QString target)
{
    this->target = target;
}

void Rule::setProtocole(QString protocole)
{
    this->protocole = protocole;
}
void Rule::setPort(QString port)
{
    this->port = port;
}

void Rule::setInterface(QString interface)
{
    this->interface = interface;
}

void Rule::setSource(QString source)
{
    this->source = source;
}

void Rule::setDestination(QString destination)
{
    this->destination = destination;
}

void Rule::setPortSituation(QString situation)
{
    this->portSituation = situation;
}

void Rule::setMachine(QString machine)
{
    this->machine = machine;
}

QString Rule::getChain() const
{
    return this->chain;
}

QString Rule::getTarget() const
{
    return this->target;
}

QString Rule::getProtocole() const
{
    return this->protocole;
}

QString Rule::getPort() const
{
    return this->port;
}

QString Rule::getInterface() const
{
    return this->interface;
}

QString Rule::getSource() const
{
    return this->source;
}

QString Rule::getDestination() const
{
    return this->destination;
}

QString Rule::getPortSituation() const
{
    return this->portSituation;
}

QString Rule::getMachine() const
{
    return this->machine;
}


QString Rule::generateRule() const
{
    QString rule = "iptables";

    rule.append(" -A "+this->getChain());
    rule.append(" -j "+this->getTarget());

    if(!this->getInterface().isEmpty())
    {
        rule.append(" -i "+this->getInterface().toLower());
    }


    if(!this->getProtocole().isEmpty())
    {
        rule.append(" -p "+this->getProtocole().toLower());
        if(!this->getPort().isEmpty())
        {
            QStringList list = this->getPort().split(",");
            QString ports;
            for(QString s : list){
                if(ports.isEmpty()) ports.append(s.split(" ")[0]);
                else ports.append(","+s.split(" ")[0]);
            }

            if(this->getPortSituation() == "Intern") rule.append(" -m multiport --dports "+ports);
            else rule.append(" -m multiport --sports "+ports);
        }
    }

    if(!this->getSource().isEmpty()){
        rule.append(" -s "+this->getSource());
    }

    if(!this->getDestination().isEmpty()){
        rule.append(" -d "+this->getDestination());
    }

    if(!this->getMachine().isEmpty())
    {
        if(this->getChain() == "INPUT") rule.append(" -m mac --mac-source "+this->getMachine());          // input
        else if(this->getChain() == "FORWARD") rule.append(" -m mac --mac-source "+this->getMachine());   // forward
    }

    return rule;
}
