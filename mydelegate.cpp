#include "mydelegate.h"

MyDelegate::MyDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *MyDelegate::createEditor(QWidget *parent,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
{
    if(index.column() == 1) {
        QSpinBox * editor = new QSpinBox(parent);
        editor->setMinimum(0); editor->setMaximum(100);
    return editor;
    }else return new QLineEdit(parent);
}

void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 1) {
        int value = index.model()->data(index,Qt::EditRole).toInt();
        QSpinBox * spin = static_cast<QSpinBox*>(editor);
        spin->setValue(value);
    } else {
        QString value = index.model()->data(index,Qt::EditRole).toString();
        QLineEdit * line = static_cast<QLineEdit*>(editor);
        line->setText(value);
    }
}

void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                              const QModelIndex &index) const
{
    if(index.column() == 1) {
        QSpinBox * spin = static_cast<QSpinBox*>(editor);
        spin->interpretText();
        int value = spin->value();
        model->setData(index,value,Qt::EditRole);
    } else {
        QLineEdit * line = static_cast<QLineEdit*>(editor);
        model->setData(index,line->text(),Qt::EditRole);
    }
}

void MyDelegate::updateEditorGeometry(QWidget *editor,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    //editor->setGeometry(30,30,200,200);
}
