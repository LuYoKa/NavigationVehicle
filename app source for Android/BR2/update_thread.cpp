#include "update_thread.h"
#include <QDebug>
#include "data_protocol.h"
#include "widget.h"

extern  data_protocol BlueTooth_DP;

update_thread::update_thread(QObject *parent) : QObject(parent)
{
    isWhile = false;
    _plot = new plot;
}
update_thread::~update_thread()
{

}
void update_thread::dealTask(void)
{
    static uint16_t count;
    while ( isWhile == true )
    {
        count++;
        QThread::msleep(100);
        qDebug() << "count" << count;


        _plot->update();
    }

    QThread::msleep(10);
}
void update_thread::setWhileState(bool set_val)
{
   isWhile = set_val;

}
