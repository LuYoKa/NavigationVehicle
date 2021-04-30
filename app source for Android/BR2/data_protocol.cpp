#include "data_protocol.h"

data_protocol::data_protocol(QObject *parent) : QObject(parent)
{
    DataProtocolInfo.TxFrameInfo.heart_beat_data = 0;

    CarCtlData.gear_position = 0x00;
    CarCtlData.running_mode = 0x00;
    CarCtlData.running_statue = 0x00;
    CarCtlData.steer_dir = 0x00;
    CarCtlData.throttle = 0x00;
    CarCtlData.steer_angle = 50;
    CarCtlData.brake_state = SET_BRAKE_NONE;
}

data_protocol::~data_protocol()
{

}

void data_protocol::DataProtocolPrepareParsed(uint8_t data)
{
    static uint8_t RxBuffer[50];
    static uint8_t _data_len = 0, _data_cnt = 0;
    static uint8_t state = 0;

    if(state == 0 && data == ECU_FRAME_HEAD_L)                 /* Ö¡Í·-µÍ8Î» */
    {
        state = 1;
        RxBuffer[0] = data;
    }
    else if(state == 1 && data == ECU_FRAME_HEAD_H)            /* Ö¡Í·-¸ß8Î» */
    {
        state=2;
        RxBuffer[1] = data;
    }
    else if(state == 2 && data < 0x04)             						 /* Ö¡ÀàÐÍ */
    {
        state=3;
        RxBuffer[2]=data;
    }
    else if(state == 3 )             												   /* Êý¾Ý±êÊ¶·û */
    {
        state=4;
        RxBuffer[3]=data;
    }
    else if(state == 4 && data < 50)              						 /* Êý¾Ý³¤¶ÈLED */
    {
        state = 5;
        RxBuffer[4] = data;
        _data_len = data;
        _data_cnt = 0;
    }
    else if(state == 5 && _data_len > 0)            					 /* RxBuffer[4]¿ªÊ¼±£´æÊý¾Ý  RxBuffer[]=Êý¾Ý£¬³¤¶È¾ö¶¨±£´æÊý¾ÝµÄ¶àÉÙ */
    {
        _data_len--;
        RxBuffer[5 + _data_cnt++] = data;
        if(_data_len == 0)
         state = 6;
    }
    else if(state==6)                                					/* ¼ìÑé  ·ÅÔÚÊý¾ÝÖ¡ºóÃæ */
    {
        state = 0;
        RxBuffer[5 + _data_cnt] = data;
        DataProtocolRarsed(RxBuffer, _data_cnt + 6); 				 /* Ò»Ö¡Êý¾Ý±£´æÍê±Ï£¬½øÈëº¯Êý½øÐÐ Êý¾ÝµÄ±£´æ´¦Àí */
    }
    else
    {
        state = 0;
    }
}

/*
 ***************************************************************
 * @
 * @
 * @
 ***************************************************************
 */
void data_protocol::DataProtocolRarsed(uint8_t *data_buf, uint8_t num)
{
    uint8_t sum = 0;
    uint8_t i = 0;

    /*  */
    for(i=0; i<(num-1); i++)
        sum += *(data_buf + i);
    /*  */
    if(!(sum==*(data_buf + num - 1)))
        return;
    if(!(*(data_buf + 0) == ECU_FRAME_HEAD_L && *(data_buf+1) == ECU_FRAME_HEAD_H))
        return;

    /*  */
    DataProtocolInfo.RxFrameInfo.frame_type = *(data_buf + 2);
    /*  */
    DataProtocolInfo.RxFrameInfo.identifier = *(data_buf + 3);
    /*  */
    DataProtocolInfo.RxFrameInfo.data_len = *(data_buf + 4);

    /*  */
    if ( DataProtocolInfo.RxFrameInfo.frame_type == ECU_FRAME_TYPE_DATA )
    {
//        /*  */
//        if ( DataProtocolInfo.RxFrameInfo.identifier ==  PC_DATA_IDENTIFIER_TEST )
//        {
//            DataProtocolInfo.RxFrameInfo.data_test = (uint16_t)(*(data_buf + 5) << 8) | *( data_buf + 6 );
//            DataProtocolInfo.RxFrameInfo.heart_beat_data = (uint16_t)(*(data_buf + 7) << 8) | *( data_buf + 8 );
//        }

        CarFeedbackInfo.speed = (uint16_t)(*(data_buf + 6) << 8) | *( data_buf + 5 );
        CarFeedbackInfo.angle = (uint16_t)(*(data_buf + 8) << 8) | *( data_buf + 7 );
         CarFeedbackInfo.set_angle = (uint16_t)(*(data_buf + 10) << 8) | *( data_buf + 9 );
          CarFeedbackInfo.fb_steer_out = (uint16_t)(*(data_buf + 12) << 8) | *( data_buf + 11 );
//        CarFeedbackInfo.running_mode = *(data_buf + 9);
//        CarFeedbackInfo.gear_position = *(data_buf + 10);
//        CarFeedbackInfo.throttle = *(data_buf + 11);
        //CarFeedbackInfo.test_4 = *(data_buf + 12);
    }

}


uint16_t data_protocol::getCarCtlDataThrottle()
{
    return CarCtlData.throttle;
}
uint8_t data_protocol::getGearPosition()
{
    return CarCtlData.gear_position;
}
uint8_t data_protocol::getSteerDir()
{
    return CarCtlData.steer_dir;
}
uint16_t data_protocol::getSteerAngle()
{
    return CarCtlData.steer_angle;
}
void data_protocol::addSteerAngle(int16_t add_val)
{
    CarCtlData.steer_angle += add_val;
    if ( CarCtlData.steer_angle >= 100 )    { CarCtlData.steer_angle = 100; }
    else if ( CarCtlData.steer_angle <= 0 ) { CarCtlData.steer_angle = 0; }
}
uint8_t data_protocol::getRunningMode()
{
    return CarCtlData.running_mode;
}
uint8_t data_protocol::getRunningStatue()
{
    return CarCtlData.running_statue;
}
uint8_t data_protocol::getBrakeStatue()
{
    return CarCtlData.brake_state;
}
void data_protocol::setCarCtlDataThrottle(uint16_t set_val)
{
    CarCtlData.throttle = set_val;
}
void data_protocol::setGearPosition(uint8_t set_val)
{
    CarCtlData.gear_position = set_val;
}
void data_protocol::setSteerDir(uint8_t set_val)
{
    CarCtlData.steer_dir = set_val;
}
void data_protocol::setRunningMode(uint8_t set_val)
{
    CarCtlData.running_mode = set_val;
}
void data_protocol::setRunningStatue(uint8_t set_val)
{
    CarCtlData.running_statue = set_val;
}
void data_protocol::setSteerAngle(int16_t set_val)
{
    CarCtlData.steer_angle = set_val;
}
void data_protocol::setBrakeStatue(uint8_t set_val)
{
    CarCtlData.brake_state = set_val;
}
void data_protocol::addHeartBeatData()
{
    DataProtocolInfo.TxFrameInfo.heart_beat_data ++;
    if (DataProtocolInfo.TxFrameInfo.heart_beat_data > 50000)
    {
        DataProtocolInfo.TxFrameInfo.heart_beat_data = 0;
    }
}
uint16_t data_protocol::getHeartBeatData()
{
    return DataProtocolInfo.TxFrameInfo.heart_beat_data;
}
void data_protocol::setTurnTorque(uint16_t set_val)
{
    CarCtlData.turn_torque = set_val;
}
/*
 ***************************************************************
 * @
 * @
 *
 * @
 ***************************************************************
 */
void data_protocol::sendDataFrameForCarCtlData()
{
    QByteArray data_to_send;
    data_to_send.resize(12);

    uint8_t _cnt = 0;
    uint8_t i;
    uint8_t sum = 0;

    data_to_send[_cnt++] = ECU_FRAME_HEAD_L;
    data_to_send[_cnt++] = ECU_FRAME_HEAD_H;
    data_to_send[_cnt++] = ECU_FRAME_TYPE_DATA;
    data_to_send[_cnt++] = ECU_SEND_TEST_DATA;
    data_to_send[_cnt++] = 0;

    data_to_send[_cnt++] = CarCtlData.running_mode;
    data_to_send[_cnt++] = CarCtlData.running_statue;
    data_to_send[_cnt++] = CarCtlData.gear_position;
    data_to_send[_cnt++] = CarCtlData.steer_dir;
    data_to_send[_cnt++] = BYTE0(CarCtlData.throttle);
    data_to_send[_cnt++] = BYTE1(CarCtlData.throttle);

    data_to_send[4] = _cnt-5;

    for(i=0; i<_cnt; i++)
        sum += data_to_send[i];

    data_to_send[_cnt++] = sum;
    //Serial_Send_Data(data_to_send, _cnt);
}

QByteArray data_protocol::getDataFrameForCarCtlData()
{
    QByteArray data_to_send;
    data_to_send.resize(14);

    uint8_t _cnt = 0;
    uint8_t i;
    uint8_t sum = 0;

    data_to_send[_cnt++] = PC_FRAME_HEAD_L;
    data_to_send[_cnt++] = PC_FRAME_HEAD_H;
    data_to_send[_cnt++] = PC_FRAME_TYPE_DATA;
    data_to_send[_cnt++] = 0x00;  /* 标识符 */
    data_to_send[_cnt++] = 0;

    data_to_send[_cnt++] = CarCtlData.running_mode;
    data_to_send[_cnt++] = CarCtlData.running_statue;
    data_to_send[_cnt++] = CarCtlData.gear_position;
    data_to_send[_cnt++] = CarCtlData.steer_dir;
    data_to_send[_cnt++] = CarCtlData.brake_state;
    data_to_send[_cnt++] = BYTE0(CarCtlData.throttle);
    data_to_send[_cnt++] = BYTE1(CarCtlData.throttle);
    data_to_send[_cnt++] = BYTE0(CarCtlData.turn_torque);
    data_to_send[_cnt++] = BYTE1(CarCtlData.turn_torque);
    data_to_send[_cnt++] = BYTE0(CarCtlData.steer_angle);
    data_to_send[_cnt++] = BYTE1(CarCtlData.steer_angle);
    /* 心跳数据 */
    data_to_send[_cnt++] = BYTE0(DataProtocolInfo.TxFrameInfo.heart_beat_data);
    data_to_send[_cnt++] = BYTE1(DataProtocolInfo.TxFrameInfo.heart_beat_data);
    data_to_send[4] = _cnt-5;

    for(i=0; i<_cnt; i++)
        sum += data_to_send[i];

    data_to_send[_cnt++] = sum;

    return data_to_send;
}
