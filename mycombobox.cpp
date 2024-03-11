#include "mycombobox.h"

MyComboBox::MyComboBox(QObject *parent = nullptr)
    : QItemDelegate(parent)
{

}

QWidget* MyComboBox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->setModel(model); // Utilisez le modèle pour le QComboBox
    return editor;
}

void MyComboBox::setModel(QStandardItemModel *itemModel)
{
    model = itemModel;
}

QStandardItemModel* MyComboBox::getModel() const
{
    return model;
}
