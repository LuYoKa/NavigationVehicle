#ifndef REMOTE_DATA_PROTOCOL_H
#define REMOTE_DATA_PROTOCOL_H

#include <QObject>

namespace DATA_PROTOCOL { // DATA_PROTOCOL


#define BYTE0(dwTemp)       			 ( *( (char *)(&dwTemp)	   ) )
#define BYTE1(dwTemp)      				 ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       			 ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       			 ( *( (char *)(&dwTemp) + 3) )


//
#define DATA_SCALE   1000.0f
#define DATA_SCALE2  100.0f

// data frame
#define RM_DATA_FRAME_LEN  24
#define RM_DATA_FRAME_HEAD_L 0xAB
#define RM_DATA_FRAME_HEAD_H 0xAB

#define RM_DATA_FRAME_TAIL_L 0xEF
#define RM_DATA_FRAME_TAIL_H 0xEF



// command frame
#define RM_COMMAND_FAME_LEN  8
#define RM_CMD_FRAME_HEAD_L 0x12
#define RM_CMD_FRAME_HEAD_H 0x12

#define RM_CMD_FRAME_TAIL_L 0x89
#define RM_CMD_FRAME_TAIL_H 0x89


// CMD DATA
#define AUTO_MODE   0x00
#define REMOTE_MODE 0x10


#define STOP        0x00
#define GO_FORWARD  0X01
#define GO_BACKWARD 0X02
#define TURN_LEFT   0X03
#define TURN_RIGHT  0X04
#define MOVE_LEFT   0X05
#define MOVE_RIGHT  0X06

#define MOVE_FORWARD_LEFT   0X07
#define MOVE_FORWARD_RIGHT  0X08
#define MOVE_BACKWARD_LEFT   0X09
#define MOVE_BACKWARD_RIGHT  0X0A


class MiddleData {
public:
    MiddleData() {
        cmd = 0;
        cmd_frame_data = 0;
        heartbeat = 0;
        speed = 0;
        data_len = 0;
        rx_command_frame_len = 0;
        rx_data_frame_len = 0;
        rx_check_sum = 0;

        rx_check_sum = 0;
        fl_wheel_speed = 0;
        fr_wheel_speed = 0;
        bl_wheel_speed = 0;
        br_wheel_speed = 0;
    }

    uint8_t cmd;
    uint8_t cmd_frame_data;
    uint16_t heartbeat;
    uint16_t speed;
    uint16_t data_len;
    uint16_t rx_command_frame_len;
    uint16_t rx_data_frame_len;
    uint16_t rx_check_sum;

    // vehicle data
    double fl_wheel_speed;
    double fr_wheel_speed;
    double bl_wheel_speed;
    double br_wheel_speed;

    double yaw;
    double pitch;
    double roll;

    double vehicle_speed;
    double agl_speed;

};

class RemoteDataProtocol
{
public:
    RemoteDataProtocol();

    void GetRemoteDataFrame(QByteArray& m_array);
    void GetRemoteCommandFrame(QByteArray& m_array);
    QByteArray GetRemoteCommandFrame(uint8_t cmd, uint8_t data);
    QByteArray GetRemoteDataFrame(uint8_t cmd, uint8_t data);
    //
    void SetCommandFrameCommand(uint8_t cmd);
    void SetCommandFrameData(uint8_t data);

    // receive
    void ReceiveDataFrameParse(const QByteArray& m_array);
    MiddleData GetMiddleData();
private:
    MiddleData md_;

};

} // END DATA_PROTOCOL

#endif // REMOTE_DATA_PROTOCOL_H
