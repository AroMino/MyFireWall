#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QItemDelegate>
#include <QComboBox>
#include <QStandardItemModel>

class MyComboBox : public QItemDelegate {
    Q_OBJECT
public:
    MyComboBox(QObject *parent);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setModel(QStandardItemModel *itemModel);
    QStandardItemModel *getModel() const;

private:
    QStandardItemModel *model = nullptr;
};
#endif // MYCOMBOBOX_H
