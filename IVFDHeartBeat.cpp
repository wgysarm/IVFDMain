#include "IVFDHeartBeat.h"

IVFDHeartBeat::IVFDHeartBeat(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    m_tcpsocket = NULL;
    m_cpu_total__ = 0;
    m_cpu_use__ = 0;
    m_send_bytes__ = 0;
    m_recv_bytes__ = 0;
    m_disk_read__ = 0;
    m_disk_write__ = 0;
    m_timer_interval__ = 5000;

    m_thread.start();
    this->moveToThread(&m_thread);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(SLOT_GetSysStatus()));
    QObject::connect(this, SIGNAL(SIG_StartHeartBeat()), this, SLOT(SLOT_StartHeartBeat()));
    QObject::connect(&m_thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_StopHeatBeat()), &m_thread, SLOT(quit()));
    QObject::connect(this, SIGNAL(SIG_StopHeatBeat()), this, SLOT(SLOT_StopHeartBeat()));
    QObject::connect(m_tcpsocket, SIGNAL(disconnected()), m_tcpsocket, SLOT(deleteLater()));
}

IVFDHeartBeat::~IVFDHeartBeat()
{

}

//bool IVFDHeartBeat::Get_StatusOnline(bool *online)
//{
//    QVariant keyval;
//    GetCFG("ivfdinit.ini", "netconfig", "netgate", &keyval);
//    QString netgate = keyval.toString();

//    if(m_tcpsocket == NULL){
//        m_tcpsocket = new QTcpSocket(this);
//        m_tcpsocket->abort();
//        m_tcpsocket->connectToHost(netgate,80);
//        *online = m_tcpsocket->waitForConnected(1000);
//        m_tcpsocket->disconnectFromHost();
//    }
//}

void IVFDHeartBeat::SLOT_GetSysStatus()
{
//    qDebug() << "1 IVFDHeartBeat::SLOT_GetSysStatus():" << QThread::currentThread();
    QString msg;
    CombineMsg(&msg);
//    qDebug() << msg;
    QByteArray ba_hbinfo;//
    ba_hbinfo.resize(sizeof(CmdActiveX));

    ConvertMsgToByteArray(&msg, &ba_hbinfo, 2, 0);//msg->cmdtype = 2, msg->cmdval = 0; send heartbeat msg
    emit SIG_TellTop(ba_hbinfo);

//    bool online;
//    bool ret = Get_StatusOnline(&online);
//    int led1 = gpio_getstate(GPIO_OUTLED1, 0);
//    int relay1 = gpio_getstate(GPIO_RELAYOUT2, 0);

//    if(online){
//        if(gpio_getstate(GPIO_OUTLED1, 0) == 0){
//            qDebug() << "1 IVFDHeartBeat::SLOT_GetSysStatus(): GPIO_OUTLED1 read = 0" << online;
//        }else{//ERROR
//            qDebug() << "1 IVFDHeartBeat::SLOT_GetSysStatus(): GPIO_OUTLED1 read = 1" << ret << online;
//            gpio_setstate(GPIO_OUTLED1, 1, 1);
//            gpio_setstate(GPIO_RELAYOUT2, 1, KEEP);
//        }

//        ConvertMsgToByteArray(&msg, &ba_regist, 2, 0);//msg->cmdtype = 2, msg->cmdval = 0; send heartbeat msg
//        emit SIG_TellTop(ba_regist);
//    }else if(!online){
//        qDebug() << "1 IVFDHeartBeat::SLOT_GetSysStatus(): offline" << online << " led1=" << " relay1= "<< relay1;
//        if(led1 == 0){
//            gpio_setstate(GPIO_OUTLED1, 1 ,1);
//        }
//        if(relay1 == KEEP){
//            gpio_setstate(GPIO_RELAYOUT2, 1, REVERSE);
//        }
//    }
}
void IVFDHeartBeat::SLOT_StartHeartBeat()
{
    qDebug() << "start heartbeat!";

    if(m_timer != NULL){
        m_timer->setInterval(5000);
        m_timer->start();
    }
}
void IVFDHeartBeat::SLOT_StopHeartBeat()
{
    if(m_timer != NULL)
    {
        m_timer->stop();
    }


}

bool IVFDHeartBeat::Get_Cpu_Usage__(QString *cpu_usg)
{
    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    QString str = process.readLine();
    str.replace("\n","");
    str.replace(QRegExp("( ){1,}")," ");
    QStringList lst = str.split(" ");
    if(lst.size() > 3)
    {
        double use = lst[1].toDouble() + lst[2].toDouble() + lst[3].toDouble();
        double total = 0;
        for(int i = 1;i < lst.size();++i)
            total += lst[i].toDouble();
        if(total - m_cpu_total__ > 0)
        {
            QString str;
            str.sprintf("cpu rate:%.2lf%%",(use - m_cpu_use__) / (total - m_cpu_total__) * 100.0);
//            qDebug("cpu rate:%.2lf%%",(use - m_cpu_use__) / (total - m_cpu_total__) * 100.0);
//            qDebug() << str;
            m_cpu_total__ = total;
            m_cpu_use__ = use;
            *cpu_usg = str;
            return true;
        }
    }
    process.close();
    return false;
}


bool IVFDHeartBeat::Get_Mem_Usage__(QString *mem_usg)
{
    QProcess process;
    process.start("free -m"); //使用free完成获取
    process.waitForFinished();
    process.readLine();
    QString str = process.readLine();
    str.replace("\n","");
    str.replace(QRegExp("( ){1,}")," ");//将连续空格替换为单个空格 用于分割
    QStringList lst = str.split(" ");
//    qDebug() << "list.size= " << lst.size();
    if(lst.size() > 5)
    {
        QString memstr;
        memstr.sprintf("mem free:%.2lf%%",(lst[3].toDouble() / lst[1].toDouble()) * 100.0);
//        qDebug("mem total:%.0lfMB free:%.0lfMB",lst[1].toDouble(),lst[3].toDouble());
        *mem_usg = memstr;
        return true;
    }
    process.close();
    return false;
}

bool IVFDHeartBeat::Get_Net_Usage__(QString *net_stat)
{
    QProcess process;
    process.start("cat /proc/net/dev"); //读取文件/proc/net/dev获取网络收发包数量，再除取样时间得到网络速度
    process.waitForFinished();
//    process.readLine();
//    process.readLine();
//    process.readLine();
//    process.readLine();
//    process.readLine();
    while(!process.atEnd())
    {
        QString str = process.readLine();
//        qDebug() << str;
        str.replace("\n","");
        str.replace(QRegExp("( ){1,}")," ");
        QStringList lst = str.split(" ");
//        qDebug() << "net info lst.size=" << lst.size();
//        qDebug() << "net info lst(0) = " << lst.at(0);
        if(lst.size() > 9 && lst[1] == "eth0:")
        {
            QString netstr;
            double recv = 0;
            double send = 0;
            if(lst.size() > 1)
                recv = lst[2].toDouble();
            if(lst.size() > 9)
                send = lst[10].toDouble();
            netstr.sprintf("%s recv:%.0lfkbyte/s send:%.0lfkbyte/s",lst[1].toStdString().c_str(),((recv - m_recv_bytes__) / 1000.0) / (m_timer_interval__ / 1000.0),((send - m_send_bytes__) / 1000.0) / (m_timer_interval__ / 1000.0));
//            qDebug("%s recv:%.0lfkbyte/s send:%.0lfkbyte/s",lst[1].toStdString().c_str(),((recv - m_recv_bytes__) / 1000.0) / (m_timer_interval__ / 1000.0),((send - m_send_bytes__) / 1000.0) / (m_timer_interval__ / 1000.0));
            m_recv_bytes__ = recv;
            m_send_bytes__ = send;
            *net_stat = netstr;
        }
    }
    process.close();
    return true;
}

bool IVFDHeartBeat::Get_Disk_Speed__(QString *dsk_speed)
{
    QProcess process;
    process.start("iostat -k -d");
    process.waitForFinished();
    process.readLine();
    process.readLine();
    process.readLine();
    QString str = process.readLine();
    str.replace("\n","");
    str.replace(QRegExp("( ){1,}")," ");
    QStringList lst = str.split(" ");
    if(lst.size() > 5)
    {
        qDebug("disk read:%.0lfkb/s disk write:%.0lfkb/s",(lst[4].toDouble() - m_disk_read__ ) / (m_timer_interval__ / 1000.0),(lst[5].toDouble() - m_disk_write__) / (m_timer_interval__ / 1000.0));
        m_disk_read__ = lst[4].toDouble();
        m_disk_write__ = lst[5].toDouble();
        return true;
    }
    process.close();
    return false;
}

bool IVFDHeartBeat::Get_Disk_Space__(QString *disk_space)
{
    QProcess process;
    process.start("df -k");
    process.waitForFinished();
    process.readLine();
    while(!process.atEnd())
    {
        QString str = process.readLine();
        if(str.startsWith("/dev/sda"))
        {
            str.replace("\n","");
            str.replace(QRegExp("( ){1,}")," ");
            QStringList lst = str.split(" ");
            if(lst.size() > 5)
                qDebug("挂载点:%s 已用:%.0lfMB 可用:%.0lfMB",lst[5].toStdString().c_str(),lst[2].toDouble()/1024.0,lst[3].toDouble()/1024.0);
        }
    }
    process.close();
    return true;
}
bool IVFDHeartBeat::Get_Path_Space(QString *path_space)
{
//    struct statfs diskInfo;
//    statfs(path.toUtf8().data(), &diskInfo);
//    qDebug("%s 总大小:%.0lfMB 可用大小:%.0lfMB",path.toStdString().c_str(),(diskInfo.f_blocks * diskInfo.f_bsize)/1024.0/1024.0,(diskInfo.f_bavail * diskInfo.f_bsize)/1024.0/1024.0);
    return true;
}

int IVFDHeartBeat::CombineMsg(QString *msg)
{
    QString msg_combine;
    QString msg_cpu;
    QString msg_mem;
    QString msg_net;

    Get_Cpu_Usage__(&msg_cpu);
    Get_Mem_Usage__(&msg_mem);
    Get_Net_Usage__(&msg_net);

    msg_combine = QString("%1$%2$%3").arg(msg_cpu).arg(msg_mem).arg(msg_net);

    *msg = msg_combine;
    return 0;
}
