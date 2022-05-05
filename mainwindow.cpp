#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TLog->setText("1. Начать игру \n"
                      "2. Продолжить");
    ui->BtnOk->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BtnFarther_clicked()
{
    buff = ui->LEdit->text().toInt();

    switch (buff) {

    case NULL:
        NULL;
        break;

    case 1:
        ui->TLog->setText("Введите имя");
        ui->BtnOk->show();
        break;

    case 2:
        NULL;
        break;
    }
}

void MainWindow::on_BtnOk_clicked()
{
    Name=ui->LEdit->text();
    db.setDatabaseName("D:/db/DB.db");
    bool ok=db.open();
    if(!ok)
    {
        throw tr("Cannot open database");
    }

    QSqlQuery query(db);

}
