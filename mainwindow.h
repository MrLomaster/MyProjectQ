#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QMessageBox>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    MainWindow(QWidget *parent = nullptr);
    QString Name;
    int buff;
    ~MainWindow();

private slots:
    void on_BtnFarther_clicked();

    void on_BtnOk_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
