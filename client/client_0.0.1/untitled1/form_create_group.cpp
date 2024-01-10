#include "form_create_group.h"
#include "ui_form_create_group.h"
#include <QTcpSocket>
#include "iostream"
#include "QTime"
form_create_group::form_create_group(QWidget *parent, network_client *nt) :
    QWidget(parent),
    ui(new Ui::form_create_group)
{
    ui->setupUi(this);
    network_obj = nt;
    connect(network_obj, &network_client::signalOkToCreateGroup, this, &form_create_group::slotOkToCreateGroup);
    connect(network_obj, &network_client::signalSecondLogin, [this](){
        qDebug()<<"signalSecondLogin";
        ui->label_5->setText(network_obj->login_secondUser);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
    });
    connect(network_obj, &network_client::signalRecvMessageFromAnotherUser,[this]()
            {
                ui->textBrowser->append('[' + QTime::currentTime().toString("HH:mm:ss") + "] " + network_obj->login_secondUser + " : " + network_obj->messageToUser);
            });

    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
}

form_create_group::~form_create_group()
{
    delete ui;
}

void form_create_group::SendToServer(QString str)
{
    Data.clear();
    QDataStream out (&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;

    qDebug() << socket->state();
    socket->write(Data);
    qDebug() << socket->state();
}

void form_create_group::on_pb_create_group_clicked()
{
    qDebug() << "on_pb_create_group_clicked";
    network_obj->SendToServer("C " + ui->lineEdit->text() + " " + (ui->lineEdit_2->text().size() > 0 ? ui->lineEdit_2->text() : " "));
    QString msg = "C " + ui->lineEdit->text() + " " + (ui->lineEdit_2->text().size() > 0 ? ui->lineEdit_2->text() : " ");
    qDebug() << msg;
    std::cout << msg.toStdString();
}

void form_create_group::slotReadyRead()
{
   //qDebug() << str;
   //ui->textBrowser->append(str);

   QString data;
   for (int i = 0; i < dataSocket->size();i++)
   {
       data.push_back(dataSocket->at(i));
   }

   RequaredRecvMessage(data);
}

void form_create_group::nextPage()
{
    ui->stackedWidgetGroup->setCurrentIndex(1);
    ui->label_3->setText(nameFirstUser);
    ui->label_5->setVisible(true);
    //ui->label_5->setText(nameSecondUser);
    ui->label_6->setVisible(true);
    ui->label_2->setText("Группа " + ui->lineEdit->text());
}


void form_create_group::RequaredRecvMessage(QString message)
{

}

void form_create_group::slotOkToCreateGroup()
{
    ui->stackedWidgetGroup->setCurrentIndex(1);
    ui->label_3->setText(network_obj->login);
    ui->label_2->setText("Группа " + ui->lineEdit->text());
}

void form_create_group::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        ui->lineEdit_2->setEnabled(true);
    }
    else
    {
        ui->lineEdit_2->setEnabled(false);
    }
}

void form_create_group::on_pushButton_2_clicked()
{
    emit signalExit();
}

void form_create_group::on_pushButton_4_clicked()
{
    ui->stackedWidgetGroup->setCurrentIndex(0);
    network_obj->SendToServer("DG");
}

void form_create_group::on_pushButton_clicked()
{
    network_obj->SendToServer('T' + ui->lineEdit_3->text());
    ui->textBrowser->append('[' + QTime::currentTime().toString("HH:mm:ss") + "] " + network_obj->login + " : " + ui->lineEdit_3->text());
    ui->lineEdit_3->clear();
}
