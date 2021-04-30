#ifndef UPDATE_THREAD_H
#define UPDATE_THREAD_H

#include <QObject>
#include <QThread>
#include "plot.h"

class update_thread : public QObject
{
    Q_OBJECT
public:
    explicit update_thread(QObject *parent = nullptr);
    ~update_thread();

    void dealTask(void);
    void setWhileState(bool set_val);

    plot *_plot;
private:
    bool isWhile;


signals:


public slots:
};

#endif // UPDATE_THREAD_H
