#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SendToServer(QString str);
private slots:
    void on_connect_clicked();
    void slotReadyRead();
    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();
    QString login = "DEN_CHIK_master";
    QString token = "1qaz";
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
};
#endif // MAINWINDOW_H
