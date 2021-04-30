#ifndef DATA_PROTOCOL_H
#define DATA_PROTOCOL_H

#include <QObject>

/*
 ***************************************************************
 *                    Êý¾ÝÐ­ÒéÏà¹Øºê¶¨Òå
 ***************************************************************
 */
/* »ñÈ¡¸ßµÍ°ËÎ»Êý¾Ý */
#define BYTE0(dwTemp)       			 ( *( (char *)(&dwTemp)	   ) )
#define BYTE1(dwTemp)      				 ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       			 ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       			 ( *( (char *)(&dwTemp) + 3) )

#define FRAME_LENGTH_MAX                   50u

 /* PC ---> ECU */
#define PC_FRAME_HEAD_L                    0xAA
#define PC_FRAME_HEAD_H                    0xAF
/*  */
#define PC_FRAME_TYPE_DATA                 0x01
#define PC_FRAME_TYPE_REQUEST              0x02
#define PC_FRAME_TYPE_ANSWER               0x03
/*  */

/*  */
#define PC_DATA_IDENTIFIER_TEST      0x01
/*  */
#define PC_REQ_IDENTFIER_TEST              0xFF
#define PC_FRAME_REQ_DATA_ONCE             0x10
#define PC_FRAME_REQ_DATA_TX_EVERY_10MS    0x11
#define PC_FRAME_REQ_DATA_TX_EVERY_20MS    0x12
#define PC_FRAME_REQ_DATA_TX_EVERY_50MS    0x13

/* Ó¦´ðÖ¡±êÊ¶·û */


 /* ECU ---> PC */
#define ECU_FRAME_HEAD_L                   0xAA
#define ECU_FRAME_HEAD_H                   0xAA

#define ECU_FRAME_TYPE_DATA                0x01
#define ECU_FRAME_TYPE_REQUEST             0x02
#define ECU_FRAME_TYPE_ANSWER              0x03

/*  */
#define ECU_ANSWER_PC_REQ_TEST 						 0x01
#define ECU_SEND_TEST_DATA    						 0x02
#define ECU_SEND_CAR_REAL_DATA             0x03
#define ECU_SEND_CAR_RAW_DATA              0x04
#define ECU_ATIVE_UPLOAD_DATA              0x05
/*  */
#define ECU_IDENTFIER_REQ_TEST             0xFF
/* Ó¦´ðÖ¡±êÊ¶·û */
#define ECU_IDENTIFIER_ANSWER_TEST         0xEE

/*  */
/*  extern use */
#define DP_ERROR                           0xFF
#define DP_NORMAL                          0x00
#define DP_FALSE                           0xFF
#define DP_TRUE                            0x00

/*
 ***************************************************************
 *
 ***************************************************************
 */
typedef struct
{
    uint8_t  frame_type;
    uint8_t  data_identifier;
    uint8_t  request_identifier;
    uint8_t  answer_identifier;
    uint8_t  identifier;
    uint8_t  data_len;
    uint8_t  check_sum;
    uint16_t heart_beat_data;
    int16_t  data_test;
    uint8_t  data[FRAME_LENGTH_MAX];
}FrameInfo_t;

typedef struct
{
  uint8_t  is_check_error;
    uint8_t  connect_statue;
}Statue_t;

typedef struct
{
    FrameInfo_t RxFrameInfo;
    FrameInfo_t TxFrameInfo;
    Statue_t Statue;
}DataProtocolInfo_t;

typedef struct
{
    /* mm/s */
    int16_t speed;
    /*
    0x01 --- N档
    0x02 --- P档
    0x03 --- D档
    */
    int8_t gear_position;
    /*
    0x21 --- 转左
    0x22 --- 转右
    */
    int8_t steer_dir;

    int16_t dir;

    int16_t pos_x;
    int16_t pos_y;
    uint8_t mode;

    int16_t imu_acc_x;
    int16_t imu_acc_y;
    int16_t imu_acc_z;
    int16_t imu_gyro_x;
    int16_t imu_gyro_y;
    int16_t imu_gyro_z;
    int16_t imu_pitch;
    int16_t imu_yaw;
    int16_t imu_roll;
}CarGloVal_t;

#define CAR_GEAR_POS_N   0X01
#define CAR_GEAR_POS_D   0X02
#define CAR_GEAR_POS_P   0X03

#define CAR_STEER_DIR_STOP         0X20
#define CAR_STEER_DIR_TURN_LEFT    0X21
#define CAR_STEER_DIR_TURN_RIGHT   0X22

#define STOP_MODE                  0X30
#define USER_CTL_MODE              0X31

/* 刹车状态 */
#define SET_BRAKE_NONE     0x00
#define SET_BRAKE_1        0X01
#define SET_BRAKE_2        0X02
#define SET_BRAKE_3        0X03

typedef struct
{
    /* 运行模式 */
    uint8_t running_mode;
    uint8_t running_statue;

    /*
    0x01 --- N档
    0x02 --- D档
    0x03 --- P档
    */
    uint8_t gear_position;
    /*
    0x21 --- 转左
    0x22 --- 转右
    */
    uint8_t steer_dir;
    uint8_t brake_state;

    /* mm/s */
    uint16_t throttle;
    uint16_t steer_angle;
    uint16_t turn_torque;

}CarCtlData_t;

typedef struct
{
    uint8_t running_mode;
    uint8_t running_statue;
    uint8_t gear_position;
    uint8_t steer_dir;
    uint16_t throttle;
    uint16_t torque;
    int16_t speed;
    int16_t angle;
    int16_t set_angle;
    int8_t test_1;
    int8_t test_2;
    int8_t test_3;
    int16_t test_4;
    int16_t test_5;
    int16_t fb_steer_out;

}CarFeedbackInfo_t;


class data_protocol : public QObject
{
    Q_OBJECT
public:
    explicit data_protocol(QObject *parent = nullptr);
    ~data_protocol();
    void DataProtocolPrepareParsed(uint8_t data);
    void DataProtocolRarsed(uint8_t *data_buf, uint8_t num);

    void sendDataFrameForCarCtlData();
    QByteArray getDataFrameForCarCtlData();
    uint16_t getCarCtlDataThrottle();
    uint8_t getGearPosition();
    uint8_t getSteerDir();
    uint8_t getRunningMode();
    uint8_t getRunningStatue();
    uint16_t getSteerAngle();
    uint8_t  getBrakeStatue();
    void addSteerAngle(int16_t add_val);

    void setCarCtlDataThrottle(uint16_t set_val);
    void setTurnTorque(uint16_t set_val);
    void setGearPosition(uint8_t set_val);
    void setSteerDir(uint8_t set_val);
    void setRunningMode(uint8_t set_val);
    void setRunningStatue(uint8_t set_val);
    void addHeartBeatData();
    void setSteerAngle(int16_t set_val);
    void setBrakeStatue(uint8_t set_val);
    uint16_t getHeartBeatData(void);

    CarFeedbackInfo_t CarFeedbackInfo;

private:
     CarCtlData_t CarCtlData;
     DataProtocolInfo_t DataProtocolInfo;


signals:

public slots:
};

#endif // DATA_PROTOCOL_H
