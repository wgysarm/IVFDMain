#ifndef IVFDMAINWIDGET_H
#define IVFDMAINWIDGET_H

#include <QWidget>
#include <QProcess>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QLocalSocket>
#include <QHostAddress>
#include <QLocalServer>
#include <QNetworkInterface>
#include <QList>
#include <QSocketNotifier>
#include <QSsl>
#include <QSslSocket>
#include <QUdpSocket>
#include <QThread>
#include <QCloseEvent>
#include <QSettings>
#include <QList>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "IVFDMainTcpServer.h"
#include "IVFDTcpClient.h"
#include "IvfdLogger.h"
#include "IVFDDriver.h"
#include "IVFDRunnable.h"
#include "IVFDHeartBeat.h"
//59000
//58891
//58890

namespace Ui {
class IVFDMainWidget;
}

using namespace IvfdLogNameSpace;

enum BYTEARRAYTYPE{ALARM, SYSINFO, DEVINFO, CMDARG};


enum ECMDTYPE {CMD_CONTROL, \
               CMD_CREATECPLAYW, \
               CMD_DOWNLOADLOG, \
               CMD_GETBRIGHT0, \
               CMD_GETBRIGHT1, \
               CMD_GETBRIGHTBALANCE0, \
               CMD_GETBRIGHTBALANCE1, \
               CMD_GETCONTRAST0, \
               CMD_GETCONTRAST1, \
               CMD_CURRENTSTATUS, \
               CMD_GETDIARYINFO, \
               CMD_GETGAIN0, \
               CMD_GETGAIN1, \
               CMD_GETNETINFO, \
               CMD_GETSATRUATION0, \
               CMD_GETSATRUATION1, \
               CMD_GETUSERINFO, \
               CMD_GETSYSINFO, \
               CMD_LOGIN, \
               CMD_SETALGPARA, \
               CMD_SETBRIGHT, \
               CMD_SETBRIGHTBALANCE, \
               CMD_SETBYTEARRAY, \
               CMD_SETEXPOSURE, \
               CMD_SETGAIN, \
               CMD_SETGPIO, \
               CMD_SETNETINFO, \
               CMD_SETSATURATION, \
               CMD_STARTALGDET, \
               CMD_STARTALL, \
               CMD_STARTRTSP0, \
               CMD_STARTRTSP1,\
               CMD_STOPALL, \
               CMD_STOPRTSP0, \
               CMD_STOPRTSP1, \
               CMD_SWITCH, \
               CMD_SWITCHRTSP, \
               CMD_SYNCTIMESTAMP, \
               CMD_UPLOADFILE, \
               NOCOMMAND
              };

enum EHWVAL{
    EHWCAM0/*0*/, EHWCAM1/*1*/, EHWSGPIO/*2*/, EHWTODEFINE/*3*/, ALGARGWEIGHT1/*4*/, ALGARGALPHA/*5*/, ALGARGBETA/*6*/, \
    SYSTEMRESET/*7*/, SETNETCONFIG/*8*/, LOGIN/*9*/, RESETSTATUS/*10*/, ALARMENABLE/*11*/, \
    CALIBRATE/*12*/, ALGFIREONOFF/*13*/, ALGSMOKEONOFF/*14*/, INITCAMERA/*15*/, SDCARD/*16*/,DIPMODULE/*17*/,HTTPMODULE/*18*/,\
    FTPMODULE/*19*/,RTSPMODULE/*20*/,MODULEALL/*21*/,SYSRESET/*22*/,APPRESET/*23*/,SYSUPDATE/*24*/,APPUPDATE/*25*/,APPBACK/*26*/,\
    APPUPLOAD/*27*/
};

enum EBAITEM{
    IPADDRESS/*0*/, NETGATE/*1*/, NETMAC/*2*/, NETMASK/*3*/, USERNAME/*4*/, PASSWORD/*5*/,FILENAME/*6*/, NOITEM/*7*/, NEWCLIENT/*8*/,\
    TIMELIMIT/*9*/, DEVTYPE/*10*/, DEVCLASS/*11*/, FUNCCODE/*12*/, USERID/*13*/, USERLEVEL/*14*/, USERMORE/*15*/,FTPSERVER/*16*/,SYNCTIME/*17*/
};

enum EFILEITEM{
    INITFILE/*0*/, FIRECFG/*1*/, SMOKECFG/*2*/, AUTHENFILE/*3*/, NOFILEITEM/**/
};

enum EREADITEM{
    BRIGHTNESS0/*0*/, BRIGHTNESS1/*1*/,GAIN0/*2*/,GAIN1/*3*/,WB0/*4*/,WB1/*5*/,CONTRAST0/*6*/, CONTRAST1/*7*/,SATURATION0/*8*/,\
    SATURATION1/*9*/, EXPOSURE0/*10*/, EXPOSURE1/*11*/,SENSEFIRE/*12*/,MINDETFIRE/*13*/,LIMIT/*14*/, TYPE/*15*/,\
    CLASS/*16*/, CODE/*17*/, ID/*18*/, LEVEL/*19*/, MORE/*20*/, NAME/*21*/, IP/*22*/, MASK/*23*/,GATE/*24*/,UPLOADFTP/*25*/
};


//定义一个函数指针
typedef void (*callback)(void);
//定义命令结构体
typedef struct cmd{
    QString name;  //命令的名字
    callback func;  //与命令相对应的函数指针
}cmd_table;

//typedef struct CtlCmd{
//    QStringList nameLIst;
//    CtlCmd(QStringList& strlist){
//        nameLIst = strlist;
//    }

//}CtlCmd;

typedef struct CmdPara{
    enum ECMDTYPE cmdtype;
    qint32 cmdval;
    char cmdstr[128];
    int cmdstrsize;
    EHWVAL id;
    EBAITEM strid;
    EFILEITEM fileid;
}CmdPara;


typedef struct CameraPara{
    int id;
    int bright;
    int gain;
    int whitebalance;
}CameraPara;


typedef struct CmdARG{
    int cmdtype;
    int argnum;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
}CmdARG;

typedef struct GeneralMsg{
    int source;//0=main 1=http, 2=ftp, 3=dip 4=client
    int dest;//0=main 1=http, 2=ftp, 3=dip 4=client
    int type;//0=cmd,1=status;
    int msgid;//defined by user;
    int val;//defined by user;
}GeneralMsg;




class IVFDMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IVFDMainWidget(QWidget *parent = 0, QString ipaddr = QString("192.168.120.166"));
    ~IVFDMainWidget();
    QProcess *m_processMain;
    QProcess *m_processFtpServer;
    QProcess *m_processHttpServer;
    QProcess *m_processRtsp;
    QProcess *m_processSystem;

    qint64 m_processFtpServerId;
    qint64 m_processMainId;
    qint64 m_processHttpServerId;
    qint64 m_processRtspId;
    qint64 m_processSystemId;

    IVFDMainTcpServer *m_tcpserver;
    IVFDTcpClient *m_tcpclient;
    QList<QString> m_tcpsocketList;

    IVFDHeartBeat *m_heartbeat;
    //T3 Main Addr
    QString m_hostAddr;
    QString m_localAddr;
    //T3 Main Tcpserver port
    QString m_tcpServerPortn;

    //T3 http port & FTP Port
    QString m_httpPortn;
    QString m_ftpPortn;
    QString m_activeXPortn;
    //T3 dip tcpserver
    QString m_dipTcpServerPortn;
    QString m_dipTcpServerAddr;
    //netgate
    QString m_netGate;

    QString m_ftpUserName;
    QString m_ftpPassWord;
    QString m_ftpRootpath;
    int m_status[2];
    int m_updatestatus;

    void InitThis(QString addr);
    void SetFtpServer(QString hostAddr, QString portn, QString username, QString password, QString rootpath);
//    QProcess *m_processFtp;
signals:
    void SIG_StartProcessMain();
    void SIG_RestartProcessMain();
    void SIG_KillProcessMain();

    void SIG_StartHeartBeat();
    void SIG_StopHeartBeat();

    void SIG_StartLocalTcpServer();
    void SIG_StopLocalTcpServer();

    void SIG_StartProcessFtp(QString hostAddr, QString portn, QString username, QString password, QString rootpath);
    void SIG_RestartProcessFtp(QString hostaddr, QString portn, QString username, QString password, QString rootpath);
    void SIG_StopProcessFtp();

    void SIG_StartProcessHttpServer(QString hostaddr, QString portn);
    void SIG_RestartProcessHttpServer(QString hostaddr, QString portn);
    void SIG_StopProcessHttpServer();

    void SIG_StartProcessRtsp();
    void SIG_RestartProcessRtsp();
    void SIG_StopProcessRtsp();

    void SIG_KillMainSelf();

    void SIG_XParseTcpServerRecv(QByteArray);
    void SIG_XParseCMDFromHttpServer(QByteArray);
    void SIG_XParseAlgOutFromDipTcpClient(QByteArray);
    void SIG_XParseMsgFromTerminalCLient(QByteArray);
    void SIG_XParseGeneralMsg(QByteArray);
    void SIG_SendCMDToDIPServer(QString serverAddr, QString serverPort, QByteArray data);
    void SIG_TellClientToSend(QString, quint16, QByteArray, QByteArray);
    void SIG_ClearAlarm();

    //for xparsecmd
    void SIG_CmdFromBrowser(QString,QString);
    void SIG_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SIG_NoIdentityCmd(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SIG_Control(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SIG_SetByteArray(enum ECMDTYPE, enum EBAITEM, QByteArray baval);
    void SIG_UploadFile(enum ECMDTYPE, enum EFILEITEM, QByteArray baval);
    void SIG_GetSysInfo(enum ECMDTYPE, enum EREADITEM id, qint32 val);


    //for singal cmd send to DIP module
    void SIG_SendCMDTypeAnd0ValToDIP(ECMDTYPE cmdtype);
    void SIG_SendCMDTypeAnd1ValToDIP(ECMDTYPE cmdtype, int val);
    void SIG_SendCMDTypeAnd2ValToDIP(ECMDTYPE cmdtype, int val1, int val2);
    void SIG_SendCMDTypeAnd3ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3);
    void SIG_SendCMDTypeAnd4ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3, int val4);

    void SIG_StartAlgDet(ECMDTYPE cmdtype, int algId);
    void SIG_CapureYUVFile(ECMDTYPE cmdtype, int num);
    void SIG_SetCameraParameter(ECMDTYPE cmdtype, int name, int val1, int val2, int val3);
    void SIG_SetDIPAlgParameter(ECMDTYPE cmdtype, int algtype, int name, int val);
    void SIG_SetGPIOOUT(ECMDTYPE cmdtype, int pin, int val);
    //
    void SIG_AnswerCmdToHttpServer(QByteArray answer);
    void SIG_UpdateTimeStamp(qlonglong);

    //for signal algoutcome to plat server
    void SIG_SendAlgOutToPlatServer(QString addr, quint16, QByteArray, QByteArray);

    //for system
    void SIG_SysReset();
    void SIG_AppReset();
    void SIG_SysUpdate();
    void SIG_AppUpdate(int);
    void SIG_AppBackup(int);
    void SIG_AppUpload(int);

    //for ActiveX cmd
    void SIG_AdjustXY(QString);

    //for Command to exucte
    void SIG_CommandExcute(QString);
private:
    Ui::IVFDMainWidget *ui;

public slots:
    void SLOT_ProcessMainFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void SLOT_ProcessFtpFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void SLOT_ProcessHttpFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void SLOT_ProcessRtspFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void SLOT_ProcessSystemFinished(int exitCode, QProcess::ExitStatus exitStatus);

    void SLOT_StartLocalTcpServer();
    void SLOT_StopLocalTcpServer();

    void SLOT_StartProcessMain();
    void SLOT_RestartProcessMain();
    void SLOT_KillProcessMain();

    void SLOT_StartProcessFtp(QString hostAddr, QString portn, QString username, QString password, QString rootpath);
    void SLOT_RestartProcessFtp(QString hostAddr, QString portn, QString username, QString password, QString rootpath);
    void SLOT_StopProcessFtp();
    void SLOT_ProcessFtpStarted();

    void SLOT_StartProcessHttpServer(QString hostaddr, QString portn);
    void SLOT_RestartProcessHttpServer(QString hostaddr, QString portn);
    void SLOT_StopProcessHttpServer();

    void SLOT_StartProcessRtsp();
    void SLOT_RestartProcessRtsp();
    void SLOT_StopProcessRtsp();

    void SLOT_KillMainSelf();

    void SLOT_XParseTcpServerRecv(QByteArray ba);
    void SLOT_XParseCMDFromHttpServer(QByteArray);
    void SLOT_XParseAlgOutFromDipTcpClient(QByteArray ba);
    void SLOT_XParseMsgFromTerminalCLient(QByteArray);
    void SLOT_XParseGeneralMsg(QByteArray);
    void SLOT_SendCMDToDIPServer(QString serverAddr, QString serverPort, QByteArray data);
    void SLOT_Started();
    //for xparsecmd and excute slot
    void SLOT_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL, qint32);
    void SLOT_NoIdentityCmd(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SLOT_Control(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SLOT_GetSysInfo(enum ECMDTYPE cmdtype, enum EREADITEM id, qint32 val);
    void SLOT_SetByteArray(enum ECMDTYPE cmdtype, enum EBAITEM ebaitem, QByteArray baval);
    void SLOT_UploadFile(enum ECMDTYPE, enum EFILEITEM, QByteArray baval);

    //cmd to DIP tcpserver
    void SLOT_SendCMDTypeAnd0ValToDIP(ECMDTYPE cmdtype);
    void SLOT_SendCMDTypeAnd1ValToDIP(ECMDTYPE cmdtype, int val);
    void SLOT_SendCMDTypeAnd2ValToDIP(ECMDTYPE cmdtype, int val1, int val2);
    void SLOT_SendCMDTypeAnd3ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3);
    void SLOT_SendCMDTypeAnd4ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3, int val4);

    void SLOT_StartAlgDet(ECMDTYPE cmdtype, int algId);
    void SLOT_CapureYUVFile(ECMDTYPE cmdtype, int num);
    void SLOT_SetCameraParameter(ECMDTYPE cmdtype, int name, int val1, int val2, int val3);
    void SLOT_SetGPIOOUT(ECMDTYPE cmdtype, int pin, int val);
    void SLOT_SetDIPAlgParameter(ECMDTYPE cmdtype, int algtype, int id , int val);
    void SLOT_ClearAlarm();

    //for slot send algoutcome to platserver
    void SLOT_SendAlgOutToPlatServer(QString, quint16, QByteArray, QByteArray);
    //for system
    void SLOT_SysReset();
    void SLOT_AppReset();
    void SLOT_SysUpdate();
    void SLOT_AppUpdate(int fileid);
    void SLOT_AppBackup(int fileid);
    void SLOT_AppUpload(int fileid);

    //for ActiveX
    void SLOT_AdjustXY(QString adj);

    //for offline
    void SLOT_Offline(bool online);

    //for excute cmd
    void SLOT_CommandExcute(QString cmd);
public:
    void closeEvent(QCloseEvent *event);

private://for xparsecmd
    //声明命令数组
    cmd_table  cmd_tbl[3];
    cmd_table* cmd_find(QString &cmdname);
    int  CtlCmdFind(QString cmd, void *cmdpara);
    void DoCtlCmdFind(CmdPara *cmd);
    void CreateEnviorment(void);

    QSettings *m_settings;
    QStringList m_cmdlist;
    qlonglong m_timeStamp;//be updated by every frame captured;
    CmdARG m_cmdarg;

};

#endif // IVFDMAINWIDGET_H
