#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <QWidget>
#include <QTimer>
#include <QListWidgetItem>
#include <QtBluetooth/qtbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothsocket.h>
#include "QMessageBox"
#include "remote_data_protocol.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void UpdateData();

    void Timer1Handle();

private slots:

    void on_pushButtonTurnMode_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_openBluetooth_clicked();

    void on_pushButton_scan_clicked();

    void on_pushButton_closeDevice_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_clear_clicked();

    void addBlueToothDevicesToList( const QBluetoothDeviceInfo &info );

    void itemActivated(QListWidgetItem *item);

    void readBluetoothDataEvent();

    void bluetoothConnectedEvent();

    void bluetoothDisconnectedEvent();

    void on_pushButtonMode_clicked();

    void on_pushButtonForward_released();

    void on_pushButtonBackward_released();

    void on_pushButtonLeft_released();

    void on_pushButtonRight_released();

    void on_pushButton_fl_released();

    void on_pushButton_fr_released();

    void on_pushButton_bl_released();

    void on_pushButton_br_released();

    void on_pushButtonForward_pressed();

    void on_pushButtonBackward_pressed();

    void on_pushButtonLeft_pressed();

    void on_pushButtonRight_pressed();

    void on_pushButton_fl_pressed();

    void on_pushButton_fr_pressed();

    void on_pushButton_bl_pressed();

    void on_pushButton_br_pressed();

    void on_horizontalSliderSpeed_sliderMoved(int position);

private:
    Ui::Widget *ui;

    int32_t update_count_;

    QTimer* timer1_;
    bool bluetooth_is_connected_;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;
    unsigned char comBuffer[15];
    unsigned int  comCount;
    QString comStr;

    DATA_PROTOCOL::RemoteDataProtocol rdp_;

    double speed_ratio_;
};

#endif // WIDGET_H
