#ifndef IVFDRUNNABLE_H
#define IVFDRUNNABLE_H

#include <QObject>
#include <QRunnable>
#include "IVFDDriver.h"

class IVFDRunnable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit IVFDRunnable(QObject *parent = 0);
    ~IVFDRunnable();

    int m_devid, m_devstate, m_interval, m_times;
    void ResetVal();
protected:
    void run();
signals:
    void SIG_Runnable(int devid, int devstate, int interval, int times);//dev, on off flash, interval, times

public slots:
    void SLOT_SetCmdId(int devid, int devstate, int interval, int times);
};

#endif // IVFDRUNNABLE_H
