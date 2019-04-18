#include "IVFDMainWidget.h"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QTextCodec>
#include <QThreadPool>
#include <IVFDRunnable.h>
#include <QThread>

#include "IvfdLogger.h"
#include "IVFDDriver.h"
#include "IVFDSetStartIP.h"

QThreadPool *GlobalThreadPool;
QReadWriteLock lock;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc < 5)
    {
        qDebug() << "please input (./IVFDMain arg1 arg2 arg3 arg4), *args should be 0 or 1 , to call rtsp, ftp, http, dipMain)";
        return -1;
    }

    GlobalThreadPool = QThreadPool::globalInstance();
    GlobalThreadPool->setMaxThreadCount(3);

    QProcess m_process;
    QStringList m_processargs;

    QVariant keyval;
    QString ipAddr("192.168.120.166");
    QString mac("36:09:C8:A5:03:66");
    int brightness0, brightness1;

    QString loginname;
    QString pixval;

    QString ftpServerPort("2001");
    QString ftpRootpath("/ftproot/");
    QString ftpUserName("admin");
    QString ftpPassWord("password");
    QString httpServerPort("58891");

    int camera0sense;
    int camera1sense;
//backup copy important files to ftproot
    m_processargs << IVFDINIT_INI << AUTORUN_SH << IVFDALGFIRE_INI << IVFDAUTHEN_INI << FTPROOTDIR;
    m_process.start("cp", m_processargs);
    if(!m_process.waitForStarted()){
        qDebug() << "backcopy files start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
        qDebug() << "0 main backup the important file to ftpserver root. " << m_processOutput;
    }

    m_process.close();
    GetCFG(IVFDALGFIRE_INI, "camera0", "sense", &keyval);
    camera0sense = keyval.toInt();
    qDebug() << camera0sense;
    GetCFG("/ivfdalgfire.ini", "camera1", "sense", &keyval);
    camera1sense = keyval.toInt();
    qDebug() << camera1sense;

    GetEnviroment("netconfig", "address", &keyval);
    ipAddr = keyval.toString();
    GetEnviroment("cameraset", "brightness0", &keyval);
    brightness0 = keyval.toInt();
    GetEnviroment("cameraset", "brightness1", &keyval);
    brightness1 = keyval.toInt();
    GetEnviroment("logininfo", "admin", &keyval);
    loginname = keyval.toString();
    GetEnviroment("videoparaset", "pix", &keyval);
    pixval = keyval.toString();

    modifyInitFile(CAMERACHANGE_INI, "camerasetchange=", "camerasetchange=1", lock);

    m_processargs << "lo" << "127.0.0.1";
    m_process.start("ifconfig", m_processargs);
    if(!m_process.waitForStarted()){
        qDebug() << "ifconfig lo start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
        qDebug() << "0 main config lo " << m_processOutput;
    }
    m_process.close();

    gpio_export(GPIO_OUTBUZZ);
    gpio_direction(GPIO_OUTBUZZ, 1);
    gpio_write(GPIO_OUTBUZZ, 1);//buzzer
    QThread::msleep(1000);
    gpio_write(GPIO_OUTBUZZ, 0);//silence

    GetEnviroment("netconfig", "mac", &keyval);
    mac = keyval.toString();

    m_processargs << "eth0" << "down";
    m_process.start("ifconfig", m_processargs);
    if(!m_process.waitForStarted()){
        qDebug() << "ifconfig lo start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
        qDebug() << "0 main config lo " << m_processOutput;
    }
    m_process.close();

    m_processargs << "eth0" << "hw" << "ether" << mac;
    m_process.start("ifconfig", m_processargs);
    if(!m_process.waitForStarted()){
        qDebug() << "ifconfig lo start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
        qDebug() << "0 main config lo " << m_processOutput;
    }
    m_process.close();


    m_processargs << "eth0" << "up";
    m_process.start("ifconfig", m_processargs);
    if(!m_process.waitForStarted()){
        qDebug() << "ifconfig lo start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
        qDebug() << "0 main config lo " << m_processOutput;
    }
    m_process.close();

//begin to scan current ps list, refresh the pid list we need to know;
    m_process.start(SCANPS_SH);
    if(!m_process.waitForStarted()){
        qDebug() << "scanps  start error!";
    }else{
        m_process.closeWriteChannel();
        QByteArray m_processOutput;
        if(m_process.waitForStarted(-1)){
            while(m_process.waitForReadyRead(-1)){
                m_processOutput = m_process.readAllStandardOutput();
            }
        }
    }
    m_process.close();

    GetCFG(SCANFS_INI, "pid", "IVFDHTTPSERVER", &keyval);
    QString pidhttp = keyval.toString();
    QStringList pidListhttp = pidhttp.split(" ");
    int pid_httpserver = pidListhttp.at(0).toInt();

    GetCFG(SCANFS_INI, "pid", "RTSP", &keyval);
    QString pidrtsp = keyval.toString();
    QStringList pidListrtsp = pidrtsp.split(" ");
    int pid_rtspserver = pidListrtsp.at(0).toInt();

    GetCFG(SCANFS_INI, "pid", "IVFDFTPSERVER", &keyval);
    QString pidftp = keyval.toString();
    QStringList pidListftp = pidftp.split(" ");
    int pid_ftpserver = pidListftp.at(0).toInt();

    GetCFG(SCANFS_INI, "pid", "DVRUI", &keyval);
    QString piddvr = keyval.toString();
    QStringList pidListdvr = piddvr.split(" ");
    int pid_dvrserver = pidListdvr.at(0).toInt();

#if 1
    if(pid_dvrserver){
        m_processargs << "-9" << QString::number(pid_dvrserver);
        m_process.start("kill", m_processargs);
        if(!m_process.waitForStarted()){
            qDebug() << "kill dipserver start error!";
        }else{
            m_process.closeWriteChannel();
            QByteArray m_processOutput;
            if(m_process.waitForStarted(-1)){
                while(m_process.waitForReadyRead(-1)){
                    m_processOutput = m_process.readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill dip " << m_processOutput;
        }
        m_process.close();
    }
#endif
    if(pid_httpserver){
        m_processargs << "-9" << QString::number(pid_httpserver);
        m_process.start("kill", m_processargs);
        if(!m_process.waitForStarted()){
            qDebug() << "kill httpserver start error!";
        }else{
            m_process.closeWriteChannel();
            QByteArray m_processOutput;
            if(m_process.waitForStarted(-1)){
                while(m_process.waitForReadyRead(-1)){
                    m_processOutput = m_process.readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill http " << m_processOutput;
        }
        m_process.close();
    }

    if(pid_ftpserver){
        m_processargs << "-9" << QString::number(pid_ftpserver);
        m_process.start("kill", m_processargs);
        if(!m_process.waitForStarted()){
            qDebug() << "kill ftpserver start error!";
        }else{
            m_process.closeWriteChannel();
            QByteArray m_processOutput;
            if(m_process.waitForStarted(-1)){
                while(m_process.waitForReadyRead(-1)){
                    m_processOutput = m_process.readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill ftp " << m_processOutput;
        }
        m_process.close();
    }

    if(pid_rtspserver){
        m_processargs << "-9" << QString::number(pid_rtspserver);
        m_process.start("kill", m_processargs);
        if(!m_process.waitForStarted()){
            qDebug() << "kill rtspserver start error!";
        }else{
            m_process.closeWriteChannel();
            QByteArray m_processOutput;
            if(m_process.waitForStarted(-1)){
                while(m_process.waitForReadyRead(-1)){
                    m_processOutput = m_process.readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill dip " << m_processOutput;
        }
        m_process.close();
    }

//    foreach (QString str, pidListhttp) {
//        qDebug() << "pidListhttp." << str;
//    }
    qDebug() << pid_httpserver << "---" << pid_ftpserver << " " << pid_rtspserver << " " << pid_dvrserver;
    qDebug() << "netconfig-address is:" << ipAddr;
    qDebug() << "cameraset-brightness0 is:" << brightness0;
    qDebug() << "logininfo-admin is:" << loginname;
    qDebug() << "videoset-pix is:" << pixval;

    QString arg1 = QString(argv[1]);
    QString arg2 = QString(argv[2]);
    QString arg3 = QString(argv[3]);
    QString arg4 = QString(argv[4]);

    int flag1 = arg1.toInt();
    int flag2 = arg2.toInt();
    int flag3 = arg3.toInt();
    int flag4 = arg4.toInt();

    qDebug() << "Rtsp process flag is :" << flag1;
    qDebug() << "Ftp     process flag is :" << flag2;
    qDebug() << "Http    process flag is :" << flag3;
    qDebug() << "Dipmain    process flag is :" << flag4;

    qDebug() << "Mac read is:" << Get_LocalMachine();
    qDebug() << "IP address read is:" << Get_HostIpAddress();
    qDebug() << "NetMask read is:" << Get_NetMask();


    IVFDMainWidget w(0, ipAddr);//create by the ipaddress read from ini file.

    gpio_export(GPIO_OUTBUZZ);
    gpio_direction(GPIO_OUTBUZZ, 1);
    gpio_write(GPIO_OUTBUZZ, 1);//buzzer
    QThread::msleep(500);
    gpio_write(GPIO_OUTBUZZ, 0);//silence

//    gpio_setstate(GPIO_OUTLED3, 1, 1);

    GetCFG(IVFDINIT_INI, "status", "relayalarm", &keyval);
    int relayalarm = keyval.toInt();
    if(relayalarm == 1){
        IVFDRunnable *myRunnable = new IVFDRunnable();
        myRunnable->SIG_Runnable(GPIO_ALL, INITALL1, 0, 0);
        myRunnable->setAutoDelete(true);
        GlobalThreadPool->start(myRunnable);
    }else{
        IVFDRunnable *myRunnable = new IVFDRunnable();
        myRunnable->SIG_Runnable(GPIO_ALL, INITALL2, 0, 0);
        myRunnable->setAutoDelete(true);
        GlobalThreadPool->start(myRunnable);
    }



    if(flag1 >= 1)
    {
        qDebug() << "start rtsp";
        w.SIG_StartProcessRtsp();
//        QThread::msleep(200);
        qDebug() << "rtsp start sucess!";
    }else
    {

    }
    if(flag2 >= 1)
    {
        qDebug() << "start ftp";
        w.SetFtpServer(ipAddr, ftpServerPort, ftpUserName, ftpPassWord, ftpRootpath);
        w.SIG_StartProcessFtp(ipAddr, ftpServerPort, ftpUserName, ftpPassWord, ftpRootpath);
    }else
    {

    }
    if(flag3 >= 1)
    {
        qDebug() << "start httpserver";
        w.SIG_StartProcessHttpServer(ipAddr, httpServerPort);
    }else
    {

    }

    if(flag4 >= 1)
    {
        qDebug() << "start dip";
        w.SIG_StartProcessMain();
    }else
    {

    }

    w.SIG_StartLocalTcpServer();

    if(w.m_heartbeat != NULL)
    {
        emit w.SIG_StartHeartBeat();
    }

//    w.SIG_SetCameraParameter(CMD_SETBRIGHT, 0, brightness0, 5, 5);
//    w.SIG_SetCameraParameter(CMD_SETBRIGHT, 1, brightness1, 5, 5);
//    a.setMainWindow(&w);
    w.show();

    QApplication::setQuitOnLastWindowClosed(true);
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    QLog_("main", InfoLevel, QString("new main start!"));
    gpio_setstate(GPIO_OUTLED3, 1, 1);
    modifyInitFile(CAMERACHANGE_INI, "camerasetchange=", "camerasetchange=0", lock);
    return a.exec();
}
