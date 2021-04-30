#include "remote_data_protocol.h"

namespace DATA_PROTOCOL {

RemoteDataProtocol::RemoteDataProtocol()
{

}

void RemoteDataProtocol::GetRemoteDataFrame(QByteArray &m_array) {
    m_array.resize(20);
    uint8_t _cnt = 0;
    uint8_t i;
    uint16_t sum = 0;

    m_array[_cnt++] = RM_DATA_FRAME_HEAD_L;
    m_array[_cnt++] = RM_DATA_FRAME_HEAD_H;

    // CMD
    m_array[_cnt++] = md_.cmd;
    // data len
    m_array[_cnt++] = md_.data_len;

    //data
    m_array[_cnt++] = BYTE0(md_.speed);
    m_array[_cnt++] = BYTE1(md_.speed);
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;

    // heartbeat
    m_array[_cnt++] = 0;
    m_array[_cnt++] = 0;

    // check
    for (int i = 0; i < _cnt; i++) {
        sum += m_array[i];
    }
    m_array[_cnt++] = BYTE0(sum);
    m_array[_cnt++] = BYTE1(sum);

    m_array[_cnt++] = RM_DATA_FRAME_TAIL_L;
    m_array[_cnt++] = RM_DATA_FRAME_TAIL_H;
}

QByteArray RemoteDataProtocol::GetRemoteDataFrame(uint8_t cmd, uint8_t data) {

}

void RemoteDataProtocol::GetRemoteCommandFrame(QByteArray &m_array) {
    m_array.resize(8);
    uint8_t _cnt = 0;
    uint8_t i;
    uint16_t sum = 0;

    m_array[_cnt++] = RM_CMD_FRAME_HEAD_L;
    m_array[_cnt++] = RM_CMD_FRAME_HEAD_H;

    // CMD
    m_array[_cnt++] = md_.cmd;
    m_array[_cnt++] = md_.cmd_frame_data;

    // check
    for (int i = 0; i < _cnt; i++) {
        sum += m_array[i];
    }
    m_array[_cnt++] = BYTE0(sum);
    m_array[_cnt++] = BYTE1(sum);

    m_array[_cnt++] = RM_CMD_FRAME_TAIL_L;
    m_array[_cnt++] = RM_CMD_FRAME_TAIL_H;
}

QByteArray RemoteDataProtocol::GetRemoteCommandFrame(uint8_t cmd, uint8_t data) {
    QByteArray m_array;
    m_array.resize(8);
    uint8_t _cnt = 0;
    uint8_t i;
    uint16_t sum = 0;

    m_array[_cnt++] = RM_CMD_FRAME_HEAD_L;
    m_array[_cnt++] = RM_CMD_FRAME_HEAD_H;

    // CMD
    m_array[_cnt++] = cmd;
    // DATA
    m_array[_cnt++] = data;

    // check
    for (int i = 0; i < _cnt; i++) {
        sum += m_array[i];
    }
    m_array[_cnt++] = BYTE0(sum);
    m_array[_cnt++] = BYTE1(sum);

    m_array[_cnt++] = RM_CMD_FRAME_TAIL_L;
    m_array[_cnt++] = RM_CMD_FRAME_TAIL_H;
}

void RemoteDataProtocol::SetCommandFrameCommand(uint8_t cmd) {
    md_.cmd = cmd;0.0
}

void RemoteDataProtocol::SetCommandFrameData(uint8_t data) {
    md_.cmd_frame_data = data;
}

void RemoteDataProtocol::ReceiveDataFrameParse(const QByteArray &m_array) {
    int size = m_array.size();
    md_.rx_data_frame_len = size;

    // 帧头
    if (m_array[0] != RM_DATA_FRAME_HEAD_L || m_array[1] != RM_DATA_FRAME_HEAD_H) {
        return;
    }

    // 帧尾
    if (m_array[size - 2] != RM_DATA_FRAME_TAIL_L || m_array[size - 1] != RM_DATA_FRAME_TAIL_H) {
        return;
    }

    // 校验
    int check_sum = 0;
    md_.rx_check_sum = (uint16_t)(m_array[size - 3] << 8 | m_array[size - 4]);
    for (int i = 0; i < size - 4; i++) {
        check_sum += m_array[i];
    }

    if (md_.rx_check_sum != check_sum) {
        return;
    }

    // 接收数据
    int16_t tmp_fl_wheel_speed = (int16_t)(m_array[5] << 8 | m_array[4]);
    int16_t tmp_fr_wheel_speed = (int16_t)(m_array[7] << 8 | m_array[6]);
    int16_t tmp_bl_wheel_speed = (int16_t)(m_array[9] << 8 | m_array[8]);
    int16_t tmp_br_wheel_speed = (int16_t)(m_array[11] << 8 | m_array[10]);
    md_.fl_wheel_speed = (double)tmp_fl_wheel_speed / (double)DATA_SCALE;
    md_.fr_wheel_speed = (double)tmp_fr_wheel_speed / (double)DATA_SCALE;
    md_.bl_wheel_speed = (double)tmp_bl_wheel_speed / (double)DATA_SCALE;
    md_.br_wheel_speed = (double)tmp_br_wheel_speed / (double)DATA_SCALE;

    int16_t tmp_yaw = (int16_t)(m_array[13] << 8 | m_array[12]);
    int16_t tmp_pitch = (int16_t)(m_array[15] << 8 | m_array[14]);
    int16_t tmp_roll = (int16_t)(m_array[17] << 8 | m_array[16]);

    md_.yaw = (double)tmp_yaw / (double)DATA_SCALE2;
    md_.pitch = (double)tmp_pitch / (double)DATA_SCALE2;
    md_.roll = (double)tmp_roll / (double)DATA_SCALE2;


}

MiddleData RemoteDataProtocol::GetMiddleData() {
    return md_;
}

}

