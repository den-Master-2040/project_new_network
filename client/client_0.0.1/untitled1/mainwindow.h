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
    void RequaredRecvMessage(QString message);
    QString login = "DEN_CHIK_master";
    QString token = "1qaz";
    QTimer *t_ping = nullptr;
private slots:
    void on_connect_clicked();
    void slotReadyRead();
    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();
    void ping_to_server();
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    int mysocketDescriptor = -1; // дескриптор который присвоил нам сервер
};
#endif // MAINWINDOW_H
