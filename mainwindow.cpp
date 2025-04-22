#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addwindow.h"
#include "mylist.h"
#include "mycombobox.h"
#include "systemenvironment.h"

#include <QDebug>
#include <QMouseEvent>
#include <QStandardItemModel>
#include <QProcess>
#include <QStringList>
#include <QListView>
#include <QFile>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

MainWindow::MainWindow(QWidget *parent, QString password)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(0,10))
    , system(new SystemEnvironment())
{
    setWindowIcon(QIcon(":/icons/image.jpg"));
    ui->setupUi(this);

    /// Désactive le bouton remove au débutceptDrops(true);
    ui->remove->setDisabled(true);

    /// Titres des colonnes du model
    model->setHeaderData(0,Qt::Horizontal,"N°");
    model->setHeaderData(1,Qt::Horizontal,"Chain");
    model->setHeaderData(2,Qt::Horizontal,"Target");
    model->setHeaderData(3,Qt::Horizontal,"Interface");
    model->setHeaderData(4,Qt::Horizontal,"Protocole");
    model->setHeaderData(5,Qt::Horizontal,"Ports");
    model->setHeaderData(6,Qt::Horizontal,"Int / Ext");
    model->setHeaderData(7,Qt::Horizontal,"Source");
    model->setHeaderData(8,Qt::Horizontal,"Destination");
    model->setHeaderData(9,Qt::Horizontal,"Machine");

    ui->tableView->setColumnWidth(0,10);

    ui->tableView->setSortingEnabled(true);                 // active le triage
    ui->tableView->verticalHeader()->setVisible(false);     // cache les numéros de ligne

    ui->tableView->setModel(model);                         // Définit le model du tableView

    /// Définition des actions lors des clicks sur les items
    QObject::connect(ui->tableView, &QTableView::clicked, [&](const QModelIndex &index){
        ui->tableView->selectRow(index.row());
        ui->remove->setEnabled(true);
    });

    QObject::connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [&](const QItemSelection &selected, const QItemSelection &deselected){
        if (! selected.isEmpty()) {
            QModelIndex firstSelectedIndex = selected.indexes().first();
            ui->tableView->selectRow(firstSelectedIndex.row());
        }
        else{
            ui->remove->setDisabled(true);
            ui->tableView->selectionModel()->clearSelection();
        }
    });

    connect(ui->tableView,&QTableView::viewportEntered,ui->tableView,[&](){
        ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    });

    this->setPassword(password);

//    this->system->getCurrentSystemFilter(this->password);
//    this->displayFilter(this->system->getFilter());

    ui->apply->setDisabled(true);

    setMenuConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

SystemEnvironment* MainWindow::getSystemEnvironment(){
    return this->system;
}

QString MainWindow::getPassword(){
    return this->password;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ui->tableView->selectionModel()->clearSelection();
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFocus();
}

void MainWindow::on_remove_clicked()
{
    if(ui->remove->isEnabled()){
        QModelIndex index = ui->tableView->currentIndex();
        model->removeRow(index.row());
        ui->remove->setDisabled(true);
    }
    ui->apply->setEnabled(true);
}

void MainWindow::on_add_clicked()
{
    AddWindow* addWindow = new AddWindow(this);
    addWindow->show();
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::receiveRule(const Rule *r)
{
    addRuleToModel(r);
}

void MainWindow::displayFilter(QList<Rule*> rules)
{
    int i=0;
    for(const Rule* rule: rules){

        if(i == 0){
            ui->input->setCurrentText(rule->getTarget());
        }
        else if(i == 1){
            ui->forward->setCurrentText(rule->getTarget());
        }
        else if(i == 2){
            ui->output->setCurrentText(rule->getTarget());
        }
        else addRuleToModel(rule);
        i++;
    }
}

void MainWindow::addRuleToModel(const Rule* r)
{
    /// Order
    model->appendRow(new QStandardItem(QString::number(model->rowCount()+1)));
    model->item(model->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableView->resizeColumnToContents(0);

    /// Chain
    QStandardItemModel *comboBoxModel = new QStandardItemModel();       // Le Model pour le ComboBox
    MyComboBox *comboBox = new MyComboBox(model);                       // Le ComboBox
    comboBox->setModel(comboBoxModel);

    comboBoxModel->appendRow(new QStandardItem("INPUT"));
    comboBoxModel->appendRow(new QStandardItem("FORWARD"));
    comboBoxModel->appendRow(new QStandardItem("OUTPUT"));

    ui->tableView->setItemDelegateForColumn(1, comboBox);           // Ajout du ComboBox comme model pour la 0 column
    model->setItem(model->rowCount()-1,1,new QStandardItem(r->getChain()));

    /// Target
    comboBoxModel = new QStandardItemModel();
    comboBox = new MyComboBox(model);
    comboBox->setModel(comboBoxModel);
    comboBoxModel->appendRow(new QStandardItem("ACCEPT"));
    comboBoxModel->appendRow(new QStandardItem("DROP"));

    ui->tableView->setItemDelegateForColumn(2, comboBox);
    model->setItem(model->rowCount()-1,2,new QStandardItem(r->getTarget()));

    /// Interface
    comboBoxModel = new QStandardItemModel();
    comboBox = new MyComboBox(model);
    comboBox->setModel(comboBoxModel);

    comboBoxModel->appendRow(new QStandardItem(""));
    for(QString s : system->getInterfaces()){
        comboBoxModel->appendRow(new QStandardItem(s.toUpper()));
    }


    ui->tableView->setItemDelegateForColumn(3, comboBox);
    model->setItem(model->rowCount()-1,3,new QStandardItem(r->getInterface()));

    /// Protocole
    comboBoxModel = new QStandardItemModel();
    comboBox = new MyComboBox(model);
    comboBox->setModel(comboBoxModel);
    comboBoxModel->appendRow(new QStandardItem(""));
    comboBoxModel->appendRow(new QStandardItem("UDP"));
    comboBoxModel->appendRow(new QStandardItem("TCP"));
    comboBoxModel->appendRow(new QStandardItem("DDP"));
    comboBoxModel->appendRow(new QStandardItem("ICMP"));
    comboBoxModel->appendRow(new QStandardItem("SCTP"));

    ui->tableView->setItemDelegateForColumn(4, comboBox);
    model->setItem(model->rowCount()-1,4,new QStandardItem(r->getProtocole()));
    ui->tableView->resizeColumnToContents(4);

    // En cas de modifications des données
    connect(model,&QStandardItemModel::dataChanged,ui->tableView,[&](const QModelIndex &index){

        ui->tableView->setRowHeight(index.row(),40);

        // Triage si la colonne 0 est modifiée
        if(index.column() == 0){
            ui->tableView->sortByColumn(0,Qt::AscendingOrder);
        }

        // quand la chain est OUTPUT , on vide la machine_mac
        if(index.column() == 1 && model->index(index.row(),1).data().toString() == "OUTPUT"){
            model->setItem(index.row(),9,new QStandardItem(""));
        }

        // Quand le protocole est modifié, je le port
        if(index.column() == 4){
            model->setItem(index.row(),5,new QStandardItem(""));
            model->setItem(index.row(),6,new QStandardItem(""));
            model->item(index.row(),6)->setEditable(false);
        }

        // si le port devient vide on réinitialise le portSituation vide
        if(index.column() == 5 && model->index(index.row(),5).data().toString() != ""){
            model->setItem(index.row(),6,new QStandardItem("Intern"));
            model->item(index.row(),6)->setEditable(true);
        }

        // si le port devient non vide on initialise le portSituation à Intern
        else if(index.column() == 5 && model->index(index.row(),5).data().toString() == ""){
            model->setItem(index.row(),6,new QStandardItem(""));
            model->item(index.row(),6)->setEditable(false);
        }

        // on active le bouton apply
        ui->apply->setEnabled(true);
    });

    /// Port
    model->setItem(model->rowCount()-1,5,new QStandardItem(r->getPort()));

    // double click sur les items
    connect(ui->tableView,&QTableView::doubleClicked,this,[&](const QModelIndex &index){
        // si l'item est le port et le protocole n'est pas vide
        if(index.column() == 5 && model->index(index.row(),4).data().toString() != ""){
            QString value = index.model()->data(index).toString();
            QString currentProtocole = model->index(index.row(),4).data().toString();
            QMap<QString, QString> ports = system->getPorts()[currentProtocole.toLower()];
            QStringList list = value.split(",");

            if(! MyList::isConstructed()){

                MyList* portList = new MyList(ui->tableView);
                portList->setWindowTitle("Ports "+currentProtocole);
                portList->setCheckedList(value);      // attribut pour la maj de value dans les slots des items

                /// Recherche
                QLineEdit* search = new QLineEdit();
                search->setMinimumSize(180,30);
                portList->addSearch(search);

                connect(search,&QLineEdit::textChanged,portList,[=]() mutable -> void {
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
                            model->setItem(index.row(),index.column(),new QStandardItem(portList->getCheckedList()));
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
                        model->setItem(index.row(),index.column(),new QStandardItem(portList->getCheckedList()));
                    });
                }
            }
        }

        // si l'item est le port et le protocole est vide, on ne fait rien
        else if(index.column() == 5 && model->index(index.row(),4).data().toString() == ""){
            model->item(index.row(),5)->setEditable(false);
        }
    });

    /// PortSituation
    comboBoxModel = new QStandardItemModel();
    comboBox = new MyComboBox(model);
    comboBox->setModel(comboBoxModel);
    comboBoxModel->appendRow(new QStandardItem("Intern"));
    comboBoxModel->appendRow(new QStandardItem("Extern"));

    ui->tableView->setItemDelegateForColumn(6, comboBox);
    model->setItem(model->rowCount()-1,6,new QStandardItem(r->getPortSituation()));

    /// Source
    model->setItem(model->rowCount()-1,7,new QStandardItem(r->getSource()));

    /// Destination
    model->setItem(model->rowCount()-1,8,new QStandardItem(r->getDestination()));

    /// Machine
    model->setItem(model->rowCount()-1,9,new QStandardItem(r->getMachine()));
    ui->tableView->resizeColumnToContents(9);

    ui->tableView->setRowHeight(model->rowCount()-1,40);
    r->generateRule();
}

void MainWindow::setPassword(QString password)
{
    this->password = password;
}

void MainWindow::setMenuConnections()
{
    connect(ui->actionQuit,&QAction::triggered,this,[&](){
        this->deleteLater();
    });

    connect(ui->actionReset,&QAction::triggered,this,[&](){
        QMessageBox* dialog = new QMessageBox(this);
        //    int a = QMessageBox::question(this,"Clear","Test?",QMessageBox::Cancel | QMessageBox::Ok);
        dialog->setWindowTitle("Reset");
        dialog->setWindowIcon(QIcon(""));
        dialog->setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
        dialog->setText("Do you really want to reset ?");
        dialog->resize(100,500);
        int a = dialog->exec();
        if(a == QMessageBox::Ok){
            /// Clear
            while(model->rowCount() > 0) model->removeRow(0);

            /// Display SystemFilter
            this->displayFilter(this->system->getFilter());
            ui->apply->setDisabled(true);
        }
    });

    connect(ui->actionClear,&QAction::triggered,this,[&](){
        QMessageBox* dialog = new QMessageBox(this);
        //    int a = QMessageBox::question(this,"Clear","Test?",QMessageBox::Cancel | QMessageBox::Ok);
        dialog->setWindowTitle("Clear");
        dialog->setWindowIcon(QIcon(""));
        dialog->setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
        dialog->setText("Do you really want to clear ?");
        dialog->resize(100,500);
        int a = dialog->exec();

        if(a == QMessageBox::Ok) while(model->rowCount() > 0) model->removeRow(0);
    });

}

void MainWindow::on_apply_clicked()
{
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);

    ui->apply->setDisabled(true);
    ui->tableView->selectionModel()->clearSelection();

    QFile file("/home/arrow/MIT/L2/S3/Cpp/qtcreator/MyFireWall/apply.sh");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){


        QTextStream text(&file);

        text << "iptables -F\n";

        /// Input
        text << "iptables -P INPUT " << ui->input->currentText() << "\n";

        /// Output
        text << "iptables -P OUTPUT " << ui->output->currentText() << "\n";

        /// Froward
        text << "iptables -P FORWARD " << ui->forward->currentText() << "\n";

        for (int row = 0; row < model->rowCount(); row++){
            Rule* rule = new Rule();
            for (int column = 0; column < model->columnCount(); column++){
                // Récupérer l'index de l'item
                QModelIndex index = model->index(row, column);

                // Obtenir la valeur de l'item
                QString value = model->data(index, Qt::DisplayRole).toString();
                if(column == 1) rule->setChain(value);
                else if(column == 2) rule->setTarget(value);
                else if(column == 3) rule->setInterface(value.toLower());
                else if(column == 4) rule->setProtocole(value.toLower());
                else if(column == 5){
                    QStringList list = value.split(",");
                    QString ports;
                    for(QString s : list){
                        if(ports.isEmpty()) ports.append(s.split(" ")[0]);
                        else ports.append(","+s.split(" ")[0]);
                    }
                    rule->setPort(ports);
                }
                else if(column == 6) rule->setPortSituation(value);
                else if(column == 7) rule->setSource(value);
                else if(column == 8) rule->setDestination(value);
                else if(column == 9) rule->setMachine(value);
            }
            text << rule->generateRule() << "\n";
        }
    }
    file.close();

    this->system->applyFilter("/home/arrow/MIT/L2/S3/Cpp/qtcreator/MyFireWall/apply.sh",this->password);
}



void MainWindow::on_input_currentTextChanged(const QString &arg1)
{
    ui->apply->setEnabled(true);
}


void MainWindow::on_forward_currentTextChanged(const QString &arg1)
{
    ui->apply->setEnabled(true);
}


void MainWindow::on_output_currentTextChanged(const QString &arg1)
{
    ui->apply->setEnabled(true);
}


