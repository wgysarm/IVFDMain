#ifndef IVFDHEARTBEAT_H
#define IVFDHEARTBEAT_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QRegExp>
#include <QProcess>
#include <QHostInfo>
//#include <QNetworkConfigurationManager>
#include "sys/statfs.h"
#include "IVFDDriver.h"

class IVFDHeartBeat : public QObject
{
    Q_OBJECT
public:
    explicit IVFDHeartBeat(QObject *parent = 0);
    ~IVFDHeartBeat();

    QTimer *m_timer;
    QThread m_thread;
    double m_cpu_total__;
    double m_cpu_use__;
    double m_send_bytes__;
    double m_recv_bytes__;
    double m_disk_read__;
    double m_disk_write__;
    int m_timer_interval__;
    QTcpSocket *m_tcpsocket;
//    bool Get_StatusOnline(bool *online);

signals:
    void SIG_TellTop(QByteArray sysstat);
    void SIG_StartHeartBeat();
    void SIG_StopHeatBeat();
public slots:
    void SLOT_StartHeartBeat();
    void SLOT_StopHeartBeat();
    void SLOT_GetSysStatus();

private:
     bool Get_Cpu_Usage__(QString *cpu_usg);
     bool Get_Mem_Usage__(QString *mem_usg);
     bool Get_Net_Usage__(QString *net_stat);
     bool Get_Path_Space(QString *path_space);
     bool Get_Disk_Space__(QString *disk_space);
     bool Get_Disk_Speed__(QString *dsk_speed);

     int CombineMsg(QString *msg);
};

#endif // IVFDHEARTBEAT_H
