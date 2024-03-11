#include "addwindow.h"
#include "ui_addwindow.h"
#include "mainwindow.h"
#include "mylist.h"
#include <QDebug>


AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::AddWindow)
    , rule(new Rule)
    , system(new SystemEnvironment())
{
    setWindowModality(Qt::WindowModal);
    ui->setupUi(this);

    /// Ajout des interfaces disponible
    ui->interface_2->addItem("");
    for(QString s : system->getInterfaces()){
        ui->interface_2->addItem(s.toUpper());
    }

    /// Connecter la fenetre à MainWindow
    connect(this,SIGNAL(addSignal(const Rule*)),parent,SLOT(receiveRule(const Rule*)));
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::mousePressEvent(QMouseEvent *event)
{
    emit sigCloseEditor("test");
}

void AddWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        emit ui->addButton->click();
    }
}

void AddWindow::on_addButton_clicked()
{
    rule->setChain(ui->chain->currentText());
    rule->setTarget(ui->target->currentText());
    rule->setProtocole(ui->protocole->currentText());
    rule->setPort(ui->port->text());
    rule->setInterface(ui->interface_2->currentText());
    rule->setSource(ui->source->text());
    rule->setDestination(ui->destination->text());
    if(ui->intern->isChecked()) rule->setPortSituation("Intern");
    else rule->setPortSituation("Extern");
    if(ui->port->text().isEmpty()) rule->setPortSituation("");
    rule->setMachine(ui->machine_mac->text());

    /// Emission du signal avec le rule
    emit addSignal(rule);
    this->deleteLater();
}

void AddWindow::on_protocole_currentTextChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->portLabel->setDisabled(true);
        ui->port->setDisabled(true);
        ui->clear->setDisabled(true);
        ui->intern->setDisabled(true);
        ui->extern_2->setDisabled(true);
    }
    else{
        ui->port->setEnabled(true);
    }
}

void AddWindow::getAvailableInterface()
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
        if(s[0] == ' ' || s.isEmpty()) l.removeOne(s);
        else{
            list.append(s.split(":")[0]);
        }
    }
    this->availableInterface = list;
}


void AddWindow::on_port_clicked()
{
    QString value = ui->port->text();
    QString currentProtocole = ui->protocole->currentText();
    QMap<QString, QString> ports = system->getPorts()[currentProtocole.toLower()];
    QStringList list = value.split(",");

    if(! MyList::isConstructed()){

        MyList* portList = new MyList(nullptr);
        portList->setWindowTitle("Ports "+currentProtocole);
        portList->setAttribute(Qt::WA_DeleteOnClose);
        portList->setCheckedList(value);      // attribut pour la maj de value dans les slots des items

        /// Recherche
        QLineEdit* search = new QLineEdit();
        search->setMinimumSize(180,30);
        portList->addSearch(search);

        connect(search,&QLineEdit::textChanged,portList,[=](){
            portList->clear();
            for(auto it = ports.begin() ; it != ports.end() ; it++){
                QString s = it.key()+" "+it.value();
                QCheckBox* item = new QCheckBox(s);
                if(s.contains(search->text())) portList->addItem(item);
                if(list.contains(s)) item->setChecked(true);

                // connecter les items pour qu'ils ajoutent et suppriment leurs valeur à value quand on les checkent ou les decheckent
                connect(item,&QCheckBox::toggled,item,[=]() mutable -> void {
                    value = portList->getCheckedList();  // je mets à jour la value par portValue
                    if(item->isChecked()){
                        if(value.isEmpty()) value.append(s);
                        else value.append(","+s);
                    }
                    else{
                        QStringList l = value.split(",");
                        l.removeOne(s);
                        value = l.join(",");
                    }
                    portList->setCheckedList(value);  // je mets à jour portValue
                    ui->port->setText(portList->getCheckedList());
                });
            }
        });

        /// Par défaut
        for(auto it = ports.begin() ; it != ports.end() ; it++){
            QString s = it.key()+" "+it.value();
            QCheckBox* item = new QCheckBox(s);
            portList->addItem(item);
            if(list.contains(s)) item->setChecked(true);

            // connecter les items pour qu'ils ajoutent et suppriment leurs valeur à value quand on les checkent ou les decheckent
            connect(item,&QCheckBox::toggled,item,[=]() mutable -> void {
                value = portList->getCheckedList();  // je mets à jour la value par portValue
                if(item->isChecked()){
                    if(value.isEmpty()) value.append(s);
                    else value.append(","+s);
                }
                else{
                    QStringList l = value.split(",");
                    l.removeOne(s);
                    value = l.join(",");
                }
                portList->setCheckedList(value);  // je mets à jour portValue
                ui->port->setText(portList->getCheckedList());
                if(ui->port->text().isEmpty()){
                    ui->intern->setDisabled(true);
                    ui->extern_2->setDisabled(true);
                    ui->clear->setDisabled(true);
                }
                else{
                    ui->intern->setEnabled(true);
                    ui->extern_2->setEnabled(true);
                    ui->clear->setEnabled(true);
                }
            });
        }
    }
}


void AddWindow::on_clear_clicked()
{
    ui->port->setText("");
    ui->intern->setDisabled(true);
    ui->extern_2->setDisabled(true);
    ui->clear->setDisabled(true);
}

void AddWindow::on_chain_currentTextChanged(const QString &arg1)
{
    if(ui->chain->currentText() == "OUTPUT"){
        ui->machine_mac->setDisabled(true);
        ui->machineLabel->setDisabled(true);
    }
    else{
        ui->machine_mac->setEnabled(true);
        ui->machineLabel->setEnabled(true);
    }
}

