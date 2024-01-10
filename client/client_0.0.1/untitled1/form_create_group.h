#ifndef FORM_CREATE_GROUP_H
#define FORM_CREATE_GROUP_H
#include <QWidget>
#include <QTcpSocket>
#include "network_client.h"
namespace Ui {
class form_create_group;
}

class form_create_group : public QWidget
{
    Q_OBJECT

public:
    explicit form_create_group(QWidget *parent = nullptr, network_client * nt = nullptr);
    ~form_create_group();

    void nextPage();
    QString nameFirstUser;
    QString nameSecondUser;
private slots:

    void SendToServer(QString str);
    void on_pb_create_group_clicked();
    void slotReadyRead();
    void RequaredRecvMessage(QString message);
    void slotOkToCreateGroup();

    void on_radioButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

signals:
    void signalExit();

private:
    Ui::form_create_group *ui;
    QByteArray Data;
    QTcpSocket *socket = nullptr;
    QString *dataSocket = nullptr;
    network_client *network_obj;
};

#endif // FORM_CREATE_GROUP_H
