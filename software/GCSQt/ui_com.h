/********************************************************************************
** Form generated from reading UI file 'com.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COM_H
#define UI_COM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Com
{
public:
    QGroupBox *groupBox;
    QComboBox *cb_serial_port;
    QLabel *label;
    QLabel *label_3;
    QComboBox *cb_baud;
    QPushButton *btn_open_com;
    QPushButton *btn_open_socket;
    QLineEdit *tb_server_ip;
    QLabel *label_4;
    QLineEdit *tb_server_port;
    QLabel *label_5;
    QLineEdit *tb_connected_ip;

    void setupUi(QWidget *Com)
    {
        if (Com->objectName().isEmpty())
            Com->setObjectName(QString::fromUtf8("Com"));
        Com->resize(651, 99);
        groupBox = new QGroupBox(Com);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 651, 91));
        groupBox->setFlat(true);
        cb_serial_port = new QComboBox(groupBox);
        cb_serial_port->setObjectName(QString::fromUtf8("cb_serial_port"));
        cb_serial_port->setGeometry(QRect(60, 30, 171, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 41, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 41, 16));
        cb_baud = new QComboBox(groupBox);
        cb_baud->addItem(QString());
        cb_baud->addItem(QString());
        cb_baud->addItem(QString());
        cb_baud->setObjectName(QString::fromUtf8("cb_baud"));
        cb_baud->setGeometry(QRect(60, 60, 171, 22));
        btn_open_com = new QPushButton(groupBox);
        btn_open_com->setObjectName(QString::fromUtf8("btn_open_com"));
        btn_open_com->setGeometry(QRect(240, 30, 61, 51));
        btn_open_socket = new QPushButton(groupBox);
        btn_open_socket->setObjectName(QString::fromUtf8("btn_open_socket"));
        btn_open_socket->setGeometry(QRect(580, 30, 61, 51));
        tb_server_ip = new QLineEdit(groupBox);
        tb_server_ip->setObjectName(QString::fromUtf8("tb_server_ip"));
        tb_server_ip->setGeometry(QRect(430, 30, 91, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 30, 111, 16));
        tb_server_port = new QLineEdit(groupBox);
        tb_server_port->setObjectName(QString::fromUtf8("tb_server_port"));
        tb_server_port->setGeometry(QRect(530, 30, 41, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 60, 121, 16));
        tb_connected_ip = new QLineEdit(groupBox);
        tb_connected_ip->setObjectName(QString::fromUtf8("tb_connected_ip"));
        tb_connected_ip->setGeometry(QRect(430, 60, 141, 20));

        retranslateUi(Com);

        QMetaObject::connectSlotsByName(Com);
    } // setupUi

    void retranslateUi(QWidget *Com)
    {
        Com->setWindowTitle(QApplication::translate("Com", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Com", "Connection", nullptr));
        label->setText(QApplication::translate("Com", "COM:", nullptr));
        label_3->setText(QApplication::translate("Com", "Baud:", nullptr));
        cb_baud->setItemText(0, QApplication::translate("Com", "57600", nullptr));
        cb_baud->setItemText(1, QApplication::translate("Com", "115200", nullptr));
        cb_baud->setItemText(2, QApplication::translate("Com", "9600", nullptr));

        btn_open_com->setText(QApplication::translate("Com", "Open", nullptr));
        btn_open_socket->setText(QApplication::translate("Com", "Open", nullptr));
        tb_server_ip->setText(QApplication::translate("Com", "192.168.4.1", nullptr));
        label_4->setText(QApplication::translate("Com", "Sever address:", nullptr));
        tb_server_port->setText(QApplication::translate("Com", "8888", nullptr));
        label_5->setText(QApplication::translate("Com", "Connected from:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Com: public Ui_Com {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COM_H
