#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent)
{
    QFile file("D:/QT/MyMVC/test.txt");
    file.open(QIODevice::ReadOnly);
    list = QString(file.readAll()).split("\r\n");
    qDebug() << list;
    size = list.size();
    size /= 2;
    file.close();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return size;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(index.row() >= size) return QVariant();
    if((role == Qt::DisplayRole || role == Qt::EditRole))
        return list[index.row()*2 + index.column()];
    if((role == Qt::ToolTipRole))
        return list[index.row()*2 + index.column()];
    else return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal) return QString("Column%1").arg(section);
    else return QString("Row%1").arg(section);
}


Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()) return Qt::ItemIsEnabled;
    return Qt::ItemIsEditable|QAbstractItemModel::flags(index);
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role==Qt::EditRole) {
        list[index.row()*2 + index.column()] = value.toString();
        //qDebug() << ("'"+list[index.row()*2 + index.column()]+"'");
        emit dataChanged(index,index);
        QFile file("D:/QT/MyMVC/test.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        for(int i = 0; i<list.size(); i++){
            stream << list[i] << "\r\n";
        }
        file.close();
        return true;
    }
    else return false;
}
