#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"
#include "mydelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyModel * mo = new MyModel;
    ui->tableView->setItemDelegate(new MyDelegate);
    ui->tableView->setModel(mo);
}

MainWindow::~MainWindow()
{
    delete ui;
}
