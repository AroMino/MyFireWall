#include "systemenvironment.h"
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>


SystemEnvironment::SystemEnvironment()
{
    this->getAvailableInterfaceFromSystem();
    this->getAvailablePortsFromSystem();
}

SystemEnvironment::~SystemEnvironment()
{

}

void SystemEnvironment::getAvailableInterfaceFromSystem()
{

    QProcess process;

    // Définition de la commande à exécuter
    QString command = "ifconfig";
    process.start(command);
    process.waitForFinished();

    // Récupération de la sortie standard du processus (résultat de la commande)
    QByteArray result = process.readAllStandardOutput();

    /// Traitements

    QStringList l, list;
    l = QString::fromUtf8(result).split("\n");
    for(auto s : l)
    {
        if(!s.isEmpty() && s[0] != ' ')
        {
            list.append(s.split(":")[0]);
        }
    }
    this->availableInterface = list;
}

void SystemEnvironment::getAvailablePortsFromSystem()
{
    QFile file("/home/arrow/MIT/L2/S3/Cpp/qtcreator/MyFireWall/services.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        QString line;
        QString service,port,protocole;
        QStringList list = {};
        while(!stream.atEnd()){
            service = "";
            port = "";
            protocole = "";
            line = stream.readLine();
            QString tmp = "";
            if(!line.isEmpty() && line[0] != "#"){
                list = line.split("\t");
                for(auto s : list){
                    if(!s.isEmpty()) tmp.append(s+" ");
                }
                if(!tmp.isEmpty()){
                    service = tmp.split(" ")[0];
                    port = tmp.split(" ")[1].split("/")[0];
                    protocole = tmp.split(" ")[1].split("/")[1];
                }
                if(! protocole.isEmpty()){
                    ports[protocole].insert(port,service);      // tcp => ((22 => ssh), ...), udp => (...)
                    services[protocole].insert(service,port);   // tcp => ((ssh => 22), ...), udp => (...)
                }

            }
        }
        file.close();
        qInfo() << ports.size();
    }
    else qDebug() << "Echec lors de l'ouverture du fichier service";
}

QStringList SystemEnvironment::getInterfaces()
{
    return this->availableInterface;
}

QMap<QString, QMap<QString, QString> > SystemEnvironment::getPorts()
{
    return this->ports;
}

QMap<QString, QMap<QString, QString> > SystemEnvironment::getServices()
{
    return this->services;
}

QList<Rule *> SystemEnvironment::getFilter()
{
    return this->filter;
}

void SystemEnvironment::applyFilter(QString path, QString password)
{
    QString command = "sudo";   // Commande à exécuter
    QStringList args;           // Arguments de la commande
    args << path;               // Ajoutez vos arguments ici

    args.prepend("-kS");         // Ajoutez l'option -S pour lire le mot de passe depuis l'entrée standard
    qInfo() << args;
    QProcess process;
    process.start(command, args);
    process.write(password.toUtf8() + "\n");    // Écrivez le mot de passe dans l'entrée standard du processus

    if (!process.waitForStarted()) {
        qDebug() << "Erreur: Impossible de démarrer la commande.";
    }

    if (!process.waitForFinished()) {
        qDebug() << "Erreur: La commande n'a pas pu être exécutée correctement.";
        process.kill();
    }

    qDebug() << "La commande a été exécutée avec succès.";
}

int SystemEnvironment::testPassword(QString password)
{
    QString command = "sudo";   // Commande à exécuter
    QStringList args;           // Arguments de la commande
    args << "ifconfig";               // Ajoutez vos arguments ici

    args.prepend("-kS");         // Ajoutez l'option -S pour lire le mot de passe depuis l'entrée standard

    QProcess process;
    process.start(command, args);
    process.write(password.toUtf8() + "\n");    // Écrivez le mot de passe dans l'entrée standard du processus
    if (!process.waitForStarted(200)) {
        qDebug() << "Erreur: Impossible de démarrer la commande.";
        return 0;
    }

    if (!process.waitForFinished(800)){
        qDebug() << "Erreur: La commande n'a pas pu être exécutée correctement.\n";
        process.kill();
        return 0;
    }
    return 1;
}

void SystemEnvironment::getCurrentSystemFilter(QString password)
{
    QProcess process;

    QString command = "sudo";
    QStringList args;
    args << "-S" << "iptables" << "-L";


    process.start(command,args);
    process.write(password.toUtf8() + "\n");

    process.waitForFinished();

    QByteArray result = process.readAllStandardOutput();

    QStringList lines = QString::fromUtf8(result).split("\n");

    QList<Rule*> rules;

    QString currentChain;

    for(QString line : lines){
        /// Elimination des espaces en trop

        while(line.contains("  ")) line.replace("  "," ");
        if(!line.isEmpty()){
            if(line.contains("Chain")){
                Rule* rule = new Rule();
                QStringList li = line.split(" ");
                currentChain = li[1];
                rule->setChain(li[1]);

                if(li[3].contains("ACCEPT")) rule->setTarget("ACCEPT");
                else rule->setTarget("DROP");
                filter.append(rule);
            }
            else if(line.contains("target") && line.contains("prot") && line.contains("opt")) continue;
            else{
                Rule* rule = new Rule();
                QStringList li = line.split(" ");
                // Chain
                rule->setChain(currentChain);

                // Target
                rule->setTarget(li[0]);

                // Source
                if(li[3] == "anywhere"){
                    rule->setSource("");
                }
                else rule->setSource(li[3]);

                // Destination
                if(li[4] == "anywhere"){
                    rule->setDestination("");
                }
                else rule->setDestination(li[4]);

                // Protocole et port
                if(li[1] == "all"){
                    rule->setProtocole("");
                    rule->setPort("");
                }
                else rule->setProtocole(li[1].toUpper());

                // MAC et port
                if(li.size() > 6){
                    QStringList l = {li.begin()+5,li.end()};
                    QString lo = l.join(" ");

                    if(lo.contains("dpt:")){
                        rule->setPortSituation("Intern");
                        QString ports = lo.split("dpt:")[1].split(" ")[0];
                        QString tmp;
                        for(QString port : ports.split(",")){
                            if(this->services[rule->getProtocole().toLower()].find(port) != this->services[rule->getProtocole().toLower()].end()){
                                if(tmp.isEmpty()) tmp.append(this->services[rule->getProtocole().toLower()][port]+" "+port);
                                else tmp.append(","+this->services[rule->getProtocole().toLower()][port]+" "+port);
                            }
                        }
                        rule->setPort(tmp);
                    }
                    else if(lo.contains("spt:")){
                        rule->setPortSituation("Extern");
                        QString ports = lo.split("spt:")[1].split(" ")[0];
                        QString tmp;
                        for(QString port : ports.split(",")){
                            if(this->services[rule->getProtocole().toLower()].find(port) != this->services[rule->getProtocole().toLower()].end()){
                                if(tmp.isEmpty()) tmp.append(this->services[rule->getProtocole().toLower()][port]+" "+port);
                                else tmp.append(","+this->services[rule->getProtocole().toLower()][port]+" "+port);
                            }
                        }
                        rule->setPort(tmp);
                    }
                    else if(lo.contains("dports ")){
                        rule->setPortSituation("Intern");
                        QString ports = lo.split("dports ")[1].split(" ")[0];
                        QString tmp;
                        for(QString port : ports.split(",")){
                            if(this->services[rule->getProtocole().toLower()].find(port) != this->services[rule->getProtocole().toLower()].end()){
                                if(tmp.isEmpty()) tmp.append(this->services[rule->getProtocole().toLower()][port]+" "+port);
                                else tmp.append(","+this->services[rule->getProtocole().toLower()][port]+" "+port);
                            }
                        }
                        rule->setPort(tmp);
                    }
                    else if(lo.contains("sports ")){
                        rule->setPortSituation("Extern");
                        QString ports = lo.split("sports ")[1].split(" ")[0];
                        QString tmp;
                        for(QString port : ports.split(",")){
                            if(this->services[rule->getProtocole().toLower()].find(port) != this->services[rule->getProtocole().toLower()].end()){
                                if(tmp.isEmpty()) tmp.append(this->services[rule->getProtocole().toLower()][port]+" "+port);
                                else tmp.append(","+this->services[rule->getProtocole().toLower()][port]+" "+port);
                            }
                        }
                        rule->setPort(tmp);
                    }

                    if(lo.contains("MAC ")){
                        rule->setMachine(lo.split("MAC ")[1].split(" ")[0]);
                    }
                }

                rules.append(rule);
            }

        }
    }
    filter += rules;
}
