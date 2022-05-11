#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TLog->setText("1. Создать персонажа \n"
                      "2. Продолжить");
    ui->LogDB->hide();
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
        ui->Log->hide();
        ui->LogDB->show();
        ui->TLog->setText("Здраствуйте. Выберите персонажа");
        db.setDatabaseName("C:/qt_creator/MyProjectQ/myproject.db");
        bool ok=db.open();
        if(!ok)
        {
            throw QObject::tr("Cannot open database");
        }
        QSqlQueryModel *modelTerminals = new QSqlQueryModel();
            modelTerminals->setQuery("select * from Players",db);
            modelTerminals->setHeaderData(1,Qt::Horizontal,"ФИО");
            ui->LogDB->setModel(modelTerminals);
            db.close();
        break;
    }
}

void MainWindow::on_BtnOk_clicked()
{
    db.setDatabaseName("C:/qt_creator/MyProjectQ/myproject.db");
    bool ok=db.open();
    if(!ok)
    {
        throw tr("Cannot open database");
    }

    QSqlQuery query(db);

    query.prepare("INSERT INTO Players (Name, LVL, ATK, DEF) "
                  "VALUES (:NameP, :LVLP, :ATKP, :DEFP)");
    query.bindValue(":NameP", ui->LEdit->text());
    query.bindValue(":LVLP", 1);
    query.bindValue(":ATKP", 5);
    query.bindValue(":DEFP", 5);

//    query.prepare("INSERT INTO Info_Porsh (id_player, info_completeGuide) "
//                  "VALUES (:id_playerP, :info_completeGuideP)");
//    query.bindValue(":info_completeGuideP", 0);
//    int id_buff = query.prepare("SELECT id FROM Players WHERE :NameP");
//    query.bindValue(":id_playerP", id_buff);

    query.exec();

    db.close();

    ui->BtnOk->hide();
    ui->TLog->setText("1. Создать персонажа \n"
                      "2. Продолжить");
}
