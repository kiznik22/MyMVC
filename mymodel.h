#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QtWidgets>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
    int size;
    QStringList  list;
public:
    explicit MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

};

#endif // MYMODEL_H
