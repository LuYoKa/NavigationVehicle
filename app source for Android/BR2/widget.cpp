#include "widget.h"
#include "ui_widget.h"

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString str1 = "Heading: ";
    ui->lineEdit_1->setAlignment(Qt::AlignLeft);
    ui->lineEdit_2->setAlignment(Qt::AlignLeft);
    ui->lineEdit_3->setAlignment(Qt::AlignLeft);
    ui->lineEdit_4->setAlignment(Qt::AlignLeft);
    ui->lineEdit_5->setAlignment(Qt::AlignLeft);
    ui->lineEdit_6->setAlignment(Qt::AlignLeft);
    ui->lineEdit_7->setAlignment(Qt::AlignLeft);
    ui->lineEdit_8->setAlignment(Qt::AlignLeft);

    // init
    update_count_ = 0;

    // // timer
    timer1_ = new QTimer(this);
    connect(timer1_, &QTimer::timeout, this, &Widget::Timer1Handle);
    timer1_->start(10);   //ms

    // blue tooth
    bluetooth_is_connected_ = false;

    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    localDevice = new QBluetoothLocalDevice();

    /* RfcommProtocol 属于模拟RS232模式，串口模式 */
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    connect(discoveryAgent,
            SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this,
            SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo))
            );
    connect(ui->list,
            SIGNAL(itemActivated(QListWidgetItem*)),
            this,
            SLOT(itemActivated(QListWidgetItem*))
            );
    connect(socket,
            SIGNAL(readyRead()),
            this,
            SLOT(readBluetoothDataEvent())
            );
    connect(socket,
            SIGNAL(connected()),
            this,
            SLOT(bluetoothConnectedEvent())
            );
    connect(socket,
            SIGNAL(disconnected()),
            this,
            SLOT(bluetoothDisconnectedEvent())
            );

    if( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff )
    {
        ui->pushButton_openBluetooth->setEnabled(true);
        ui->pushButton_closeDevice->setEnabled(false);
    }else
    {
        ui->pushButton_openBluetooth->setEnabled(false);
        ui->pushButton_closeDevice->setEnabled(true);
    }

    if( localDevice->hostMode() == QBluetoothLocalDevice::HostDiscoverable )
    {
        ui->checkBox_discoverable->setChecked(true);
    }else
    {
        ui->checkBox_discoverable->setChecked(false);
    }

}
void Widget::UpdateData() {

    double tmp_fl_wheel_speed = rdp_.GetMiddleData().fl_wheel_speed;
    double tmp_fr_wheel_speed = rdp_.GetMiddleData().fr_wheel_speed;
    double tmp_bl_wheel_speed = rdp_.GetMiddleData().bl_wheel_speed;
    double tmp_br_wheel_speed = rdp_.GetMiddleData().br_wheel_speed;
    double data_frame_len = rdp_.GetMiddleData().rx_data_frame_len;
    double yaw = rdp_.GetMiddleData().yaw;
    double pitch = rdp_.GetMiddleData().pitch;
    double roll = rdp_.GetMiddleData().roll;


    ui->lineEdit_1->setText(QString("航向：") + QString::number(10.22));
    ui->lineEdit_2->setText(QString("前左轮速度：") + QString::number(tmp_fl_wheel_speed));
    ui->lineEdit_3->setText(QString("前右轮速度：") + QString::number(tmp_fr_wheel_speed));
    ui->lineEdit_4->setText(QString("后左轮速度：") + QString::number(tmp_bl_wheel_speed));
    ui->lineEdit_5->setText(QString("后右轮速度：") + QString::number(tmp_br_wheel_speed));
    ui->lineEdit_6->setText(QString("---：") + QString::number(9.999));
    ui->lineEdit_7->setText(QString("---：") + QString::number(9.999));
    ui->lineEdit_8->setText(QString("--：") + QString::number(9.999));

    ui->lineEdit_10->setText(QString("接收数据帧长度：") + QString::number(data_frame_len));
    ui->lineEdit_13->setText(QString("yaw:") + QString::number(data_frame_len));
    ui->lineEdit_14->setText(QString("pitch:") + QString::number(data_frame_len));
    ui->lineEdit_15->setText(QString("roll:") + QString::number(data_frame_len));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonTurnMode_clicked()
{
    if(ui->pushButtonTurnMode->text()==tr("平移"))               //按下按键
    {
         ui->pushButtonTurnMode->setText("旋转");
    }
    else
    {
        ui->pushButtonTurnMode->setText("平移");
    }
}

void Widget::Timer1Handle()
{
    update_count_++;

    if (update_count_ > 10000) {
        update_count_ = 0;
    }

    if (update_count_ % 10 == 0) {
        UpdateData();

        if (bluetooth_is_connected_ == true)
        {
            QByteArray m_array;
            rdp_.GetRemoteCommandFrame(m_array);
            socket->write(m_array);
        }
    }
}

void Widget::on_pushButton_disconnect_clicked()
{
    socket->disconnectFromService();
}

void Widget::on_pushButton_openBluetooth_clicked()
{
    /* 调用打开本地的蓝牙设备 */
    localDevice->powerOn();

    /* 设定按键状态 */
    ui->pushButton_closeDevice->setEnabled(true);
    ui->pushButton_openBluetooth->setEnabled(false);
    ui->pushButton_scan->setEnabled(true);
}

void Widget::on_pushButton_scan_clicked()
{
    discoveryAgent->start();
    ui->pushButton_scan->setEnabled(false);
}

void Widget::on_pushButton_closeDevice_clicked()
{
    /* 关闭蓝牙设备 */
    localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
    ui->pushButton_closeDevice->setEnabled(false);
    ui->pushButton_openBluetooth->setEnabled(true);
    ui->pushButton_scan->setEnabled(false);
}

void Widget::on_pushButton_send_clicked()
{
    QByteArray m_array;
    rdp_.GetRemoteCommandFrame(m_array);
    socket->write(m_array);
}

void Widget::on_pushButton_clear_clicked()
{
    ui->textBrowser_info->clear();
}

void Widget::addBlueToothDevicesToList( const QBluetoothDeviceInfo &info )
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
    //QString label = QString("%1 ").arg(info.name());
    QList<QListWidgetItem *> items = ui->list->findItems(label, Qt::MatchExactly);

    if (items.empty())
    {
        QListWidgetItem *item = new QListWidgetItem(label);
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());

        /* 判断蓝牙是否被匹配过 */
        if (pairingStatus == QBluetoothLocalDevice::Paired
                || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired ) {
            item->setTextColor(QColor(Qt::green));
            ui->list->addItem(item);
        }
        else {
            item->setTextColor(QColor(Qt::black));
        }


    }

}

void Widget::itemActivated(QListWidgetItem *item)
{
    QString text = item->text();

    int index = text.indexOf(' ');

    if (index == -1)
        return;

    QBluetoothAddress address(text.left(index));
    QString name(text.mid(index + 1));
    qDebug() << "You has choice the bluetooth address is " << address;
    qDebug() << "The device is connneting.... ";
    QMessageBox::information(this,tr("Info"),tr("The device is connecting..."));
    socket->connectToService(address, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);

}

void Widget::readBluetoothDataEvent()
{

    QByteArray line = socket->readAll();
    uint8_t data;
    uint8_t i=0;
//    QString strData = line.toHex();
//    comStr.append(strData);
//    qDebug() <<"rec data is: "<< comStr;
//    qDebug() <<"The comStr length is: " << comStr.length();
//    if(comStr.length() >= 30) {

//        ui->textBrowser_info->append(comStr + "\n");
//        comStr.clear();
//    }

    int size = line.size();
    // DATA FRAME
    if (size == RM_DATA_FRAME_LEN) {
        rdp_.ReceiveDataFrameParse(line);
    }
    // COMMAND FRAME
    else if (size == RM_COMMAND_FAME_LEN) {

    }


}

void Widget::bluetoothConnectedEvent()
{
    qDebug() << "The android device has been connected successfully!";
    QMessageBox::information(this,tr("Info"),tr("successful connection!"));
    bluetooth_is_connected_ = true;
}

void Widget::bluetoothDisconnectedEvent()
{
    qDebug() << "The android device has been disconnected successfully!";
    QMessageBox::information(this,tr("Info"),tr("successful disconnection!"));
    bluetooth_is_connected_ = false;
}

/* 蓝牙操作函数 */
/*
打开蓝牙： localDevice->powerOn();
关闭蓝牙： localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
检查蓝牙是否打开了：if (localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff)

蓝牙可见性：
判断蓝牙是否可见，能被扫描到：localDevice->hostMode() == QBluetoothLocalDevice::HostDiscoverable
设置蓝牙为可见： localDevice->setHostMode( QBluetoothLocalDevice::HostDiscoverable )

蓝牙设备查找：
使用类 QBluetoothDeviceDiscoveryAgent


*/

void Widget::on_pushButtonMode_clicked()
{
    if(ui->pushButtonMode->text()==tr("遥控模式"))               //按下按键
    {
        ui->pushButtonMode->setText("自动模式");
        rdp_.SetCommandFrameCommand(REMOTE_MODE);
    }
    else if(ui->pushButtonMode->text()==tr("自动模式"))
    {
        ui->pushButtonMode->setText("遥控模式");
        rdp_.SetCommandFrameCommand(AUTO_MODE);
    }
}

void Widget::on_pushButtonForward_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButtonBackward_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButtonLeft_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButtonRight_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButton_fl_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButton_fr_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButton_bl_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButton_br_released()
{
    rdp_.SetCommandFrameData(STOP);
}

void Widget::on_pushButtonForward_pressed()
{
    rdp_.SetCommandFrameData(GO_FORWARD);
}

void Widget::on_pushButtonBackward_pressed()
{
    rdp_.SetCommandFrameData(GO_BACKWARD);
}

void Widget::on_pushButtonLeft_pressed()
{
    rdp_.SetCommandFrameData(TURN_LEFT);
}

void Widget::on_pushButtonRight_pressed()
{
    rdp_.SetCommandFrameData(TURN_RIGHT);
}

void Widget::on_pushButton_fl_pressed()
{
    rdp_.SetCommandFrameData(MOVE_FORWARD_LEFT);
}

void Widget::on_pushButton_fr_pressed()
{
    rdp_.SetCommandFrameData(MOVE_FORWARD_RIGHT);
}

void Widget::on_pushButton_bl_pressed()
{
    rdp_.SetCommandFrameData(MOVE_BACKWARD_LEFT);
}

void Widget::on_pushButton_br_pressed()
{
    rdp_.SetCommandFrameData(MOVE_BACKWARD_RIGHT);
}


void Widget::on_horizontalSliderSpeed_sliderMoved(int position)
{
    this->speed_ratio_ = (double)position / (double)100.0;
    std::cout << "this->speed_ratio_: " << this->speed_ratio_ << std::endl;
}
