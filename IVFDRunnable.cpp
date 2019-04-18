#include "IVFDRunnable.h"
#include <QDebug>
#include "IVFDDriver.h"

IVFDRunnable::IVFDRunnable(QObject *parent) : QObject(parent)
{
    m_devid = 0;
    m_devstate = 0;
    m_times =0 ;
    m_interval = 0;
    QObject::connect(this, SIGNAL(SIG_Runnable(int, int , int ,int)), this, SLOT(SLOT_SetCmdId(int, int, int, int)));
}

IVFDRunnable::~IVFDRunnable()
{

}

void IVFDRunnable::run()
{
    if(m_devid == 0){
        qDebug() << "temp thread exe no opererate!";
    }else if(m_devid == GPIO_OUTLED1){
        qDebug() << "led1 action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);

    }else if(m_devid == GPIO_OUTLED2){
        qDebug() << "led2 action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }else if(m_devid == GPIO_OUTLED3){
        qDebug() << "led3 action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }else if(m_devid == GPIO_RELAYOUT1){
        qDebug() << "relay1 action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }else if(m_devid == GPIO_RELAYOUT2){
        qDebug() << "relay2 action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }else if(m_devid == GPIO_OUTBUZZ){
        qDebug() << "buzzer action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }else if(m_devid == GPIO_ALL){
        qDebug() << "LED RELAY AND BUZZER action!";
        ControlGPIODev(m_devid, (enum GPIOSTATUS)m_devstate, m_interval, m_times);
    }

    ResetVal();

}

void IVFDRunnable::SLOT_SetCmdId(int devid, int devstate, int interval, int times)
{
    m_devid = devid;
    m_devstate = devstate;
    m_interval = interval;
    m_times = times;
}

void IVFDRunnable::ResetVal()
{
    m_devid = 0;
    m_devstate = 0;
    m_interval = 0;
    m_times = 0;
}
