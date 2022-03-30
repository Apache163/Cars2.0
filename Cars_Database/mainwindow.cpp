#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("Not open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE ABOUT_CARS(CAR_ID INT, BRAND TEXT, MODEL TEXT, MODEL_YEAR INT, FIRST_MODEL_YEAR INT, BODY_TYPE TEXT, DOORS INT, ENGINE_POWER INT);");
    model = new QSqlTableModel(this, db);
    model->setTable("ABOUT_CARS");
    model->select();
    ui->tableView->setModel(model);

    model2 = new QSqlTableModel(this, db);
    model2->setTable("ABOUT_CARS");
    model2->select();
    ui->tableView->setModel(model2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());

}


void MainWindow::on_pushButton_2_clicked()
{
    model->removeRow(row);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}




