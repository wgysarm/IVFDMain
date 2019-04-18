#include "IVFDMainWidget.h"
#include "ui_IVFDMainWidget.h"
#include "IVFDDriver.h"
#include <QThreadPool>

extern QThreadPool *GlobalThreadPool;
extern QReadWriteLock lock;

static int ConvertStructToByteArray(void *input, BYTEARRAYTYPE batype, QByteArray *output)
{
    if(input == NULL || output == NULL)
    {
        qDebug() << "Error data in or out!";
        return -1;
    }

    QByteArray ba;


    switch(batype)
    {
    case ALARM:
    {
        break;
    }
    case SYSINFO:
    {
        break;
    }
    case DEVINFO:
    {
        break;
    }
    case CMDARG:
    {
        CmdARG *in = (CmdARG*)input;
        qDebug() << in->cmdtype << " " << in->argnum << "  " << in->arg4;
        ba.resize(sizeof(*in));
        output->resize(sizeof(*in));
        memcpy(output->data(), in, sizeof(*in));
        CmdARG *tmp = (CmdARG*)output->data();
        qDebug() << "ConvertStructToByteArray :tmp.cmdtype = " << tmp->cmdtype;
        break;
    }
    default:
    {
        qDebug() << "Type Error!";
        return 1;
    }

    }

    return 0;
}


static void ConvertCMDArgToByteArray(CmdARG *cmdarg, ECMDTYPE cmdtype, QByteArray *ba)
{
    if(cmdarg == NULL || ba == NULL)
        return;
    cmdarg->cmdtype = (int)cmdtype;
    cmdarg->argnum = 0;
    ConvertStructToByteArray(cmdarg, CMDARG, ba);
    CmdARG *tmp = (CmdARG *)(ba->data());
    qDebug() << "1 ConvertCMDArgToByteArray: tmp.cmdtype = " << tmp->cmdtype;
}
static void ConvertCMDArgToByteArray(CmdARG *cmdarg, ECMDTYPE cmdtype, int val1, QByteArray *ba)
{
    if(cmdarg == NULL || ba == NULL)
        return;
    cmdarg->cmdtype = (int)cmdtype;
    cmdarg->argnum = 1;
    cmdarg->arg1 = val1;

    ConvertStructToByteArray(cmdarg, CMDARG, ba);
    CmdARG *tmp = (CmdARG *)(ba->data());
    qDebug() << "1 ConvertCMDArgToByteArray: tmp.cmdtype = " << tmp->cmdtype;
}
static void ConvertCMDArgToByteArray(CmdARG *cmdarg, ECMDTYPE cmdtype, int val1, int val2, QByteArray *ba)
{
    if(cmdarg == NULL || ba == NULL)
        return;
    cmdarg->cmdtype = (int)cmdtype;
    cmdarg->argnum = 2;
    cmdarg->arg1 = val1;
    cmdarg->arg2 = val2;

    ConvertStructToByteArray(cmdarg, CMDARG, ba);
    CmdARG *tmp = (CmdARG *)(ba->data());
    qDebug() << "1 ConvertCMDArgToByteArray: tmp.cmdtype = " << tmp->cmdtype;
}
static void ConvertCMDArgToByteArray(CmdARG *cmdarg, ECMDTYPE cmdtype, int val1, int val2, int val3, QByteArray *ba)
{
    if(cmdarg == NULL || ba == NULL)
        return;
    cmdarg->cmdtype = (int)cmdtype;
    cmdarg->argnum = 3;
    cmdarg->arg1 = val1;
    cmdarg->arg2 = val2;
    cmdarg->arg3 = val3;

    ConvertStructToByteArray(cmdarg, CMDARG, ba);
    CmdARG *tmp = (CmdARG *)(ba->data());
    qDebug() << "1 ConvertCMDArgToByteArray: tmp.cmdtype = " << tmp->cmdtype;

}
static void ConvertCMDArgToByteArray(CmdARG *cmdarg, ECMDTYPE cmdtype, int val1, int val2, int val3, int val4, QByteArray *ba)
{
    if(cmdarg == NULL || ba == NULL)
        return;
    cmdarg->cmdtype = (int)cmdtype;
    cmdarg->argnum = 4;
    cmdarg->arg1 = val1;
    cmdarg->arg2 = val2;
    cmdarg->arg3 = val3;
    cmdarg->arg4 = val4;

    ConvertStructToByteArray(cmdarg, CMDARG, ba);
    CmdARG *tmp = (CmdARG *)(ba->data());
    qDebug() << "1 ConvertCMDArgToByteArray: tmp.cmdtype = " << tmp->cmdtype;
}


IVFDMainWidget::IVFDMainWidget(QWidget *parent, QString ipaddr) :
    QWidget(parent),
    ui(new Ui::IVFDMainWidget)
{
    ui->setupUi(this);
    InitThis(ipaddr);

}

QByteArray  IntToByte(int i)
{
    QByteArray abyte0;
    abyte0.resize(4);
    abyte0[0] = (uchar)  (0x000000ff & i);
    abyte0[1] = (uchar) ((0x0000ff00 & i) >> 8);
    abyte0[2] = (uchar) ((0x00ff0000 & i) >> 16);
    abyte0[3] = (uchar) ((0xff000000 & i) >> 24);
    return abyte0;
}

int BytesToInt(QByteArray bytes) {
    int addr = bytes[0] & 0x000000FF;
    addr |= ((bytes[1] << 8) & 0x0000FF00);
    addr |= ((bytes[2] << 16) & 0x00FF0000);
    addr |= ((bytes[3] << 24) & 0xFF000000);
    return addr;
}


IVFDMainWidget::~IVFDMainWidget()
{

    delete ui;

}
void IVFDMainWidget::SetFtpServer(QString hostAddr, QString portn, QString username, QString password, QString rootpath)
{
    qDebug() << hostAddr;
    m_ftpPortn = portn;
    m_ftpPassWord = password;
    m_ftpUserName = username;
    m_ftpRootpath = rootpath;
}

void IVFDMainWidget::SLOT_ProcessMainFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessMainFinished";
    qDebug() << exitCode;
    qDebug() << exitStatus;
    qDebug() << "m_updatestatus=" << m_updatestatus;
    if(exitStatus == QProcess::CrashExit)
    {
//        qDebug() << "1 Dip process crashed";
        QLog_("survey", InfoLevel, QString("Dip process crashed!"));
        if(m_updatestatus == 0){//m_updatestatus == 1 means now are updating program,no need to restart
            emit SIG_StartProcessMain();
        }
    }else{
//        qDebug() << "1 Dip process exit in normal.";
        QLog_("survey", InfoLevel, QString("Dip process exit in normal!"));
        if(m_updatestatus == 0){
            emit SIG_StartProcessMain();
        }
    }

}

void IVFDMainWidget::SLOT_ProcessFtpFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessFtpFinished";
    qDebug() << exitCode;
    qDebug() << exitStatus;
    qDebug() << "m_updatestatus=" << m_updatestatus;
    if(exitStatus == QProcess::CrashExit)
    {
//        qDebug() << "1 Ftp process crashed";
        QLog_("survey", InfoLevel, QString("Ftp process crashed!"));
        if(m_updatestatus == 0){
            emit SIG_StartProcessFtp(m_hostAddr, m_ftpPortn, m_ftpUserName, m_ftpPassWord, m_ftpRootpath);
        }
    }else{
//        qDebug() << "1 Ftp process exit in normal.";
        QLog_("survey", InfoLevel, QString("Ftp process exit in normal!"));
        if(m_updatestatus == 0){
            emit SIG_StartProcessFtp(m_hostAddr, m_ftpPortn, m_ftpUserName, m_ftpPassWord, m_ftpRootpath);
        }
    }
}

void IVFDMainWidget::SLOT_ProcessHttpFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessHttpFinished";
    qDebug() << exitCode;
    qDebug() << exitStatus;
    qDebug() << "m_updatestatus=" << m_updatestatus;
    if(exitStatus == QProcess::CrashExit)
    {
//        qDebug() << "1 ProcesHttp process crashed";
        QLog_("survey", InfoLevel, QString("Http process crashed!"));
        if(m_updatestatus == 0)
        {
            emit SIG_StartProcessHttpServer(m_hostAddr, m_ftpPortn);
        }
    }else{
//        qDebug() << "1 ProcesHttp process exit in normal.";
        QLog_("survey", InfoLevel, QString("Http process exit in normal!"));
        if(m_updatestatus == 0)
        {
            emit SIG_StartProcessHttpServer(m_hostAddr, m_ftpPortn);
        }

    }
}

void IVFDMainWidget::SLOT_ProcessRtspFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessRtspFinished";
    qDebug() << exitCode;
    qDebug() << exitStatus;
    qDebug() << "m_updatestatus=" << m_updatestatus;
    if(exitStatus == QProcess::CrashExit)
    {
//        qDebug() << "1 ProcesRtsp process crashed";
        QLog_("survey", InfoLevel, QString("Rtsp process crashed!"));
        if(m_updatestatus == 0){
            emit SIG_StartProcessRtsp();
        }
    }else{
//        qDebug() << "1 ProcesRtsp process exit in normal.";
        QLog_("survey", InfoLevel, QString("Rtsp process exit in normal!"));
        if(m_updatestatus == 0){
            emit SIG_StartProcessRtsp();
        }
    }
}

void IVFDMainWidget::SLOT_ProcessSystemFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessSystemFinished";
    qDebug() << exitCode;
    qDebug() << exitStatus;
    qDebug() << "m_updatestatus=" << m_updatestatus;
    if(exitStatus == QProcess::CrashExit)
    {
//        qDebug() << "1 ProcesSystem process crashed";
        QLog_("survey", InfoLevel, QString("system process crashed!"));
    }else{
//        qDebug() << "1 ProcesSystem process exit in normal.";
        QLog_("survey", InfoLevel, QString("system process exit in normal!"));
    }
}

void IVFDMainWidget::SLOT_Started()
{
    qDebug() << "1 process main started;";
}

void IVFDMainWidget::SLOT_StartProcessMain()
{

    qDebug() << "1 IVFDMainWidget::SLOT_StartProcessMain()";
    m_updatestatus = 0;
    QString filePath(DVRUI_EXE);
    QFile file(filePath);
    if(!file.exists())
    {
        qDebug() << "1 no such a file to exec";
        return;
    }
    m_processMain->start(QString(DVRUI_EXE));
    m_processMainId = m_processMain->processId();
    if(m_processMainId){
        QVariant var;
        var.setValue((int)m_processMainId);
        qDebug() << var.toInt();
//        SetEnviroment("status", "dippid", var);
    }
    qDebug() << "1 m_processMain->start the id is:" << m_processMainId;
    IVFDRunnable *myRunnable = new IVFDRunnable();
    myRunnable->SIG_Runnable(GPIO_OUTBUZZ, FLASH, 200, 1);
    myRunnable->setAutoDelete(true);
    GlobalThreadPool->start(myRunnable);
}

void IVFDMainWidget::SLOT_KillProcessMain()
{
    //begin to scan current ps list, refresh the pid list we need to know;
    QVariant keyval;
    QStringList m_processargs;
    qDebug() << "1 IVFDMainWidget::SLOT_KillProcessMain: m_updatestatus=" << m_updatestatus;
    m_processSystem->start(SCANPS_SH);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "scanps  start error!";
        QLog_("main", ErrorLevel, QString("kill processmain excute scanps.sh error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
    GetCFG(SCANFS_INI, "pid", "DVRUI", &keyval);
    QString piddvr = keyval.toString();
    QStringList pidListdvr = piddvr.split(" ");
    int pid_dvrserver = pidListdvr.at(0).toInt();

    if(pid_dvrserver){
        m_processargs << "-9" << QString::number(pid_dvrserver);
        m_processSystem->start("kill", m_processargs);
        if(!m_processSystem->waitForStarted()){
//            qDebug() << "kill dipserver start error!";
            QLog_("main", ErrorLevel, QString("kill processmain excute scanfs.sh error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill dip " << m_processOutput;
        }
        m_processSystem->close();
    }

}

void IVFDMainWidget::SLOT_KillMainSelf()
{
    //begin to scan current ps list, refresh the pid list we need to know;
    QVariant keyval;
    QStringList m_processargs;
    qDebug() << "1 IVFDMainWidget::SLOT_KillMainSelf: m_updatestatus=" << m_updatestatus;
    m_processSystem->start(SCANPS_SH);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "scanps  start error!";
        QLog_("main", ErrorLevel, QString("kill mainself error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
    GetCFG(SCANFS_INI, "pid", "IVFDMAIN", &keyval);
    QString piddvr = keyval.toString();
    QStringList pidListdvr = piddvr.split(" ");
    int pid_mainself = pidListdvr.at(0).toInt();

    if(pid_mainself){
        m_processargs << "-9" << QString::number(pid_mainself);
        m_processSystem->start("kill", m_processargs);
        if(!m_processSystem->waitForStarted()){
//            qDebug() << "kill dipserver start error!";
            QLog_("main", ErrorLevel, QString("kill dipserver start error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill mainself " << m_processOutput;
        }
        m_processSystem->close();
    }
}

void IVFDMainWidget::SLOT_RestartProcessMain()
{
    if(m_processMain->state() == QProcess::Running)
    {
        m_processMain->terminate();
    }
    if(m_processMain != NULL)
    {
        emit SIG_StartProcessMain();
    }
}

void IVFDMainWidget::SLOT_StartProcessFtp(QString hostAddr, QString portn, QString username, QString password, QString rootpath)
{
    qDebug() << "1 IVFDMainWidget::SLOT_StartProcessFtp()";
    m_updatestatus = 0;
    QString filePath(FTP_EXE);
    QFile file(filePath);
    if(!file.exists())
    {
        qDebug() << "1 no such a file to exec";
        return;
    }

    QStringList arglist;
    arglist.append(hostAddr);
    arglist.append(portn);
    arglist.append(username);
    arglist.append(password);
    arglist.append(rootpath);

    m_processFtpServer->start(QString(FTP_EXE), arglist);
    m_processFtpServerId = m_processFtpServer->processId();

    if(m_processFtpServerId){
        QVariant var;
        var.setValue((int)m_processFtpServerId);
        qDebug() << var.toInt();
//        SetEnviroment("status", "ftppid", var);
    }
    qDebug() << "1 m_processFtp->start the id is:" << m_processFtpServerId;
    IVFDRunnable *myRunnable = new IVFDRunnable();
    myRunnable->SIG_Runnable(GPIO_OUTBUZZ, FLASH, 500, 1);
    myRunnable->setAutoDelete(true);
    GlobalThreadPool->start(myRunnable);
}

void IVFDMainWidget::SLOT_RestartProcessFtp(QString hostAddr, QString portn, QString username, QString password, QString rootpath)
{
    if(m_processFtpServer->state() == QProcess::Running)
    {
        m_processFtpServer->terminate();
    }
    if(m_processFtpServer != NULL)
    {
        emit SIG_StartProcessFtp(hostAddr, portn, username, password, rootpath);
    }
}

void IVFDMainWidget::SLOT_StopProcessFtp()
{
//    QStringList arguments;
//    arguments << "-9" << QString::number(m_processFtpServerId);
//    m_processSystem->start("kill", arguments);
//    m_processSystem->waitForFinished(100);
    //begin to scan current ps list, refresh the pid list we need to know;
    QVariant keyval;
    QStringList m_processargs;
    qDebug() << "1 IVFDMainWidget::SLOT_StopProcessFtp: m_updatestatus=" << m_updatestatus;
    m_processSystem->start(SCANPS_SH);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "scanps  start error!";
        QLog_("main", ErrorLevel, QString("kill ftp, scanps start error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
    GetCFG(SCANFS_INI, "pid", "IVFDFTPSERVER", &keyval);
    QString pidftp = keyval.toString();
    QStringList pidListftp = pidftp.split(" ");
    int pid_ftpserver = pidListftp.at(0).toInt();
    if(pid_ftpserver){
        m_processargs << "-9" << QString::number(pid_ftpserver);
        m_processSystem->start("kill", m_processargs);
        if(!m_processSystem->waitForStarted()){
//            qDebug() << "kill ftpserver start error!";
            QLog_("main", ErrorLevel, QString("kill dipserver error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill ftp " << m_processOutput;
        }
        m_processSystem->close();
    }
}


void IVFDMainWidget::SLOT_StartProcessRtsp()
{
    qDebug() << "1 IVFDMainWidget::SLOT_StartProcessRtsp()";
    m_updatestatus = 0;
    QString filePath(RTSP_EXE);
    QFile file(filePath);
    if(!file.exists())
    {
        qDebug() << "1 no such a file to exec";
        return;
    }
    qDebug() << "begin to start rtsp";
    QStringList arglist;
    arglist << "&";
    if(m_processRtsp != NULL){
        m_processRtsp->start(QString(RTSP_EXE), arglist);
        m_processRtspId = m_processRtsp->processId();
        if(m_processRtspId){
            QVariant var;
            var.setValue((int)m_processRtspId);
            qDebug() << var.toInt();
//            SetEnviroment("status", "rtsppid", var);
        }

        qDebug() << "1 m_processRtsp->start the id is:" << m_processRtspId;
    }
    IVFDRunnable *myRunnable = new IVFDRunnable();
    myRunnable->SIG_Runnable(GPIO_OUTBUZZ, FLASH, 400, 1);
    myRunnable->setAutoDelete(true);
    GlobalThreadPool->start(myRunnable);
}

void IVFDMainWidget::SLOT_RestartProcessRtsp()
{
    if(m_processRtsp->state() == QProcess::Running)
    {
        m_processRtsp->terminate();
    }
    if(m_processRtsp != NULL)
    {
        emit SLOT_StartProcessRtsp();
    }
}

void IVFDMainWidget::SLOT_StopProcessRtsp()
{
//    QStringList arguments;
//    arguments << "-9" << QString::number(m_processRtspId);
//    m_processSystem->start("kill", arguments);
//    m_processSystem->waitForFinished(100);

    //begin to scan current ps list, refresh the pid list we need to know;
    QVariant keyval;
    QStringList m_processargs;
    qDebug() << "1 IVFDMainWidget::SLOT_StopProcessRtsp: m_updatestatus=" << m_updatestatus;
    m_processSystem->start(SCANPS_SH);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "scanps  start error!";
        QLog_("main", ErrorLevel, QString("kill rtsp scanps.sh error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
    GetCFG(SCANFS_INI, "pid", "RTSP", &keyval);
    QString pidrtsp = keyval.toString();
    QStringList pidListrtsp = pidrtsp.split(" ");
    int pid_rtspserver = pidListrtsp.at(0).toInt();

    if(pid_rtspserver){
        m_processargs << "-9" << QString::number(pid_rtspserver);
        m_processSystem->start("kill", m_processargs);
        if(!m_processSystem->waitForStarted()){
//            qDebug() << "kill rtspserver start error!";
            QLog_("main", ErrorLevel, QString("kill dipserver start error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill rtsp " << m_processOutput;
        }
        m_processSystem->close();
    }

    QThread::msleep(100);

}


void IVFDMainWidget::SLOT_StartLocalTcpServer()
{
    qDebug() << "1 IVFDMainWidget::SLOT_StartLocalTcpServer()";
    m_tcpserver->SIG_StartTcpServerThread();
}
void IVFDMainWidget::SLOT_StopLocalTcpServer()
{

}

void IVFDMainWidget::SLOT_StartProcessHttpServer(QString hostaddr, QString portn)
{
    qDebug() << "1 IVFDMainWidget::SLOT_StartProcessHttpServer()";
    m_updatestatus = 0;
    m_hostAddr = hostaddr;
    m_httpPortn = portn;

    QString filePath(HTTP_EXE);
    QFile file(filePath);
    if(!file.exists())
    {
        qDebug() << "1 no such a file to exec";
        return;
    }
    m_processHttpServer->start(QString(HTTP_EXE));
    m_processHttpServerId = m_processHttpServer->processId();
    if(m_processHttpServerId){
        QVariant var;
        var.setValue((int)m_processHttpServerId);
        qDebug() << var.toInt();
//        SetEnviroment("status", "httppid", var);
    }
    qDebug() << "1 m_processHttp->start the id is:" << m_processHttpServerId;
    IVFDRunnable *myRunnable = new IVFDRunnable();
    myRunnable->SIG_Runnable(GPIO_OUTBUZZ, FLASH, 800, 1);
    myRunnable->setAutoDelete(true);
    GlobalThreadPool->start(myRunnable);
}

void IVFDMainWidget::SLOT_RestartProcessHttpServer(QString hostaddr, QString portn)
{
    if(m_processHttpServer->state() == QProcess::Running)
    {
        m_processHttpServer->terminate();
    }
    if(m_processHttpServer != NULL)
    {
        emit SIG_StartProcessHttpServer(hostaddr, portn);
    }

}


void IVFDMainWidget::SLOT_StopProcessHttpServer()
{
    QVariant keyval;
    QStringList m_processargs;
    qDebug() << "1 IVFDMainWidget::SLOT_StopProcessHttpServer: m_updatestatus=" << m_updatestatus;
    m_processSystem->start(SCANPS_SH);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "scanps  start error";
        QLog_("main", ErrorLevel, QString("kill httpserver scanps.sh error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
    GetCFG(SCANFS_INI, "pid", "IVFDHTTPSERVER", &keyval);
    QString pidhttp = keyval.toString();
    QStringList pidListhttp = pidhttp.split(" ");
    int pid_httpserver = pidListhttp.at(0).toInt();

    if(pid_httpserver){
        m_processargs << "-9" << QString::number(pid_httpserver);
        m_processSystem->start("kill", m_processargs);
        if(!m_processSystem->waitForStarted()){
            qDebug() << "kill httpserver start error!";
            QLog_("main", ErrorLevel, QString("kill httpserver start error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
            qDebug() << "0 main kill httpserver " << m_processOutput;
        }
        m_processSystem->close();
    }

}


void IVFDMainWidget::closeEvent(QCloseEvent *event)
{
//    if(m_processFtpServer->state() == QProcess::Running)
    QStringList arguments;
    if(m_processFtpServerId > 0)
    {
        arguments << "-9" << QString::number(m_processFtpServerId);
        m_processSystem->start("kill", arguments);
        m_processSystem->waitForFinished(100);
        m_processSystem->close();
    }

//    if(m_processHttpServer->state() == QProcess::Running)
    if(m_processHttpServerId > 0)
    {
        arguments << "-9" << QString::number(m_processHttpServerId);
        m_processSystem->start("kill", arguments);
        m_processSystem->waitForFinished(100);
        m_processSystem->close();
    }


//    if(m_processMain->state() == QProcess::Running)
    if(m_processRtspId > 0)
    {      
        arguments << "-9" << QString::number(m_processRtspId);
        m_processSystem->start("kill", arguments);
        m_processSystem->waitForFinished(100);
        m_processSystem->close();
    }

    if(m_processMainId > 0)
    {
        arguments << "-9" << QString::number(m_processMainId);
        m_processSystem->start("kill", arguments);
        m_processSystem->waitForFinished(100);
        m_processSystem->close();
    }

    qDebug() << "1 All sub process closed";

    event->ignore();
}
void IVFDMainWidget::SLOT_SendCMDToDIPServer(QString serverAddr, QString serverPort, QByteArray data)
{
    CmdARG *tmp = (CmdARG *)(data.data());
    qDebug() << "1 IVFDMainWidget::SLOT_SendCMDToDIPServer:" << serverAddr << "@" << serverPort << "----argnum = " << tmp->argnum;
    qDebug() << "1 IVFDMainWidget::SLOT_SendCMDToDIPServer: tmp.cmdtype = " << tmp->cmdtype;
    if(m_tcpclient != NULL)
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SendCMDToDIPServer: emit SIG_TellClientToSend(QString(data),QString(data))";
        emit SIG_TellClientToSend(serverAddr, serverPort.toInt(), data, data);
    }
}

//for xparsecmd
void IVFDMainWidget::SLOT_XParseCMDFromHttpServer(QByteArray data)
{
//    qDebug() << "1 IVFDMainWidget::SLOT_XParseCMDFromHttpServer:SIG_ClientWirteToServer:" << data;
    //here insert the xparsecmd
    CmdPara *cmdpara = (CmdPara *)malloc(sizeof(CmdPara));
    if(cmdpara != NULL){
        int mycmdpara = CtlCmdFind(QString(data), (void *)cmdpara);
    }
    DoCtlCmdFind(cmdpara);
    free(cmdpara);
    cmdpara = NULL;
//    qDebug() << "1 IVFDMainWidget::SLOT_XParseCMDFromHttpServer:DoCtlCmdFind done";
    //after xparse send the cmd to DIP
}

void IVFDMainWidget::SLOT_XParseAlgOutFromDipTcpClient(QByteArray ba)
{
//    qDebug() << "1 IVFDMainWidget::SLOT_XParseAlgOutFromDipTcpClient" << ba;
    foreach(QString str, m_tcpsocketList){
//        qDebug() << "1 IVFDMainWidget::SLOT_XParseAlgOutFromDipTcpClient:emit SIG_TellClientToSend ";
        emit SIG_TellClientToSend(str, 59000, ba, ba);//59000 is the ActiveXN's server port listening;
    }
}

void IVFDMainWidget::SLOT_XParseMsgFromTerminalCLient(QByteArray ba){
    CmdActiveX *cmdrecv = (CmdActiveX *)ba.data();
    if(cmdrecv == NULL){
        return;
    }

//    qDebug() << "cmdrecv->cmdtype = " << cmdrecv->cmdtype << " cmdrecv->cmdval = " << cmdrecv->cmdval;
    if(cmdrecv->cmdtype == 0){//regist command
        QString registrClientIp = QString(cmdrecv->cmdstr);
        modifyInitFile(IVFDINIT_INI, "lastclientip=", QString("lastclientip=").append(registrClientIp), lock);
        if(m_tcpsocketList.isEmpty()){
            m_tcpsocketList.append(registrClientIp);
        }else{
            if(m_tcpsocketList.contains(registrClientIp)){

            }else{
                m_tcpsocketList.append(registrClientIp);
            }
        }
        foreach(QString str, m_tcpsocketList){//answer back to client
//            qDebug() << "1 IVFDMainWidget::SIG_XParseMsgFromTerminalCLient: " << str;
            SIG_TellClientToSend(str, 59000, ba, ba);
        }
    }else if(cmdrecv->cmdtype == 1){//unregist command
        QString registrClientIp = QString(cmdrecv->cmdstr);
        if(m_tcpsocketList.contains(registrClientIp)){
            m_tcpsocketList.removeOne(registrClientIp);
        }else{

        }
        foreach(QString str, m_tcpsocketList){//answer back  to client
//            qDebug() << "1 IVFDMainWidget::SIG_XParseMsgFromTerminalCLient: " << str;
            SIG_TellClientToSend(str, 59000, ba, ba);
        }
    }else if(cmdrecv->cmdtype == 2){//send heartbeat,this command is from local heartbeat
//        SIG_TellClientToSend(m_netGate, 80, ba, ba);//to judge the connect

        foreach(QString str, m_tcpsocketList){//answer back  to client
//            qDebug() << "1 IVFDMainWidget::SIG_XParseMsgFromTerminalCLient: " << str;
            SIG_TellClientToSend(str, 59000, ba, ba);//send heartbeat info
        }
    }else if(cmdrecv->cmdtype == 3){//x,y adjust
        QString recvstr = QString(cmdrecv->cmdstr);
//        qDebug() << "1 IVFDMainWidget::SIG_XParseMsgFromTerminalCLient: adjust xy pos:" << recvstr;
        emit SIG_AdjustXY(recvstr);
    }else if(cmdrecv->cmdtype == 4){//cmd to excute
        QString recvstr = QString(cmdrecv->cmdstr);//
        emit SIG_CommandExcute(recvstr);
    }
}

void IVFDMainWidget::SLOT_XParseTcpServerRecv(QByteArray ba)//all recv here classed
{
//    qDebug() << "1 IVFDMainWidget::SLOT_XParseTcpServerRecv:the data size is " << ba.size();
    if(ba.size() == 11 || ba.size() == 12 || ba.size() == 13 ){
        emit SIG_XParseCMDFromHttpServer(ba);
    }else if(ba.size() == 24){
//            m_status[0] = m_status[1];
//            m_status[1] = type;
        emit SIG_XParseAlgOutFromDipTcpClient(ba);
        ALARMDATAINFO *myRecvData = (ALARMDATAINFO *)ba.data();
        if(myRecvData->alarmType == 3)
        {
            gpio_setstate(GPIO_OUTLED2, 1, 1);
            gpio_setstate(GPIO_RELAYOUT1, 1 ,1);
            gpio_setstate(GPIO_OUTBUZZ, 1, 1);

        }else if(myRecvData->alarmType == 6)//enum EOUTCOMETYPE{NOEVENT, TOOLIGHT, TOODARK, FIREDET, FIREDETEND, VLOST, RUNSTATUS};
        {

        }else if(myRecvData->alarmType == 4){
            //Here no operate ,up to the clientterminal
        };


    }else if(ba.size() == 136){//136 is size of CmdActiveX
        emit SIG_XParseMsgFromTerminalCLient(ba);
    }else if(ba.size() == 20){//20 is size of general msg
        emit SIG_XParseGeneralMsg(ba);
    }else {
        emit SIG_XParseCMDFromHttpServer(ba);
        qDebug() << ba.size();
    }

}
void IVFDMainWidget::SLOT_XParseGeneralMsg(QByteArray ba)
{
    qDebug() << "1 IVFDMainWidget::SLOT_XParseGeneralMsg ba size = " << ba.size();
    GeneralMsg *gmsgrecv = (GeneralMsg *)ba.data();

    qDebug() << "source = " << gmsgrecv->source << " type =" << gmsgrecv->type << " msgid= " << gmsgrecv->msgid << " val =" << gmsgrecv->val << " dest=" << gmsgrecv->dest;

    if(gmsgrecv->dest == 4){//tell the client terminal
        foreach(QString str, m_tcpsocketList){
            SIG_TellClientToSend(str, 59000, ba, ba);
        }
    }else if(gmsgrecv->dest == 0 && gmsgrecv->msgid == 1){//msgid == 1:regist
        QString msg;
        GetAnswerRegistString(&msg);

        QByteArray ba_regist;//
        ba_regist.resize(sizeof(CmdActiveX));

        ConvertMsgToByteArray(&msg, &ba_regist, 1, 0);//msg->cmdtype = 1, cmdval = 0;

        foreach(QString str, m_tcpsocketList){
            SIG_TellClientToSend(str, 59000, ba_regist, ba_regist);
        }

    }else if(gmsgrecv->dest == 0 && gmsgrecv->msgid == 2){//msgid == 2:clear alarm
        emit SIG_ClearAlarm();
        qDebug() << "";
    }
}


cmd_table* IVFDMainWidget::cmd_find(QString &cmdname){
    int i;
    for(i = 0; i < sizeof(cmd_tbl)/sizeof(cmd_tbl[0]); i++){
        if(cmdname == cmd_tbl[i].name){
            return &cmd_tbl[i];
            qDebug() << i;
        }
    }
    qDebug("cant find a command");
    return 0;
}

//by the cmd from browser to find the CMDTYPE
int IVFDMainWidget::CtlCmdFind(QString cmd, void *cmdpara)
{
//    qDebug() << "1 IVFDMainWidget::CtlCmdFind:";
    if(cmdpara == NULL){
        return 1;
    }
    CmdPara *cmdpararet = (CmdPara *)cmdpara;
    cmdpararet->cmdtype = NOCOMMAND;
    cmdpararet->cmdval = 0;
    memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
    cmdpararet->cmdstrsize = 0;
    cmdpararet->id = EHWTODEFINE;

    enum ECMDTYPE reterror = NOCOMMAND;
    QStringList strlist = m_cmdlist;

//    qDebug() << "begin to print strlist:" << strlist.length();
    if(cmd.isEmpty())
    {
        return reterror;
    }

    for(int index = 0; index < strlist.length(); index++)
    {
        qDebug() << strlist.at(index);

    }
    //special for CmdParaStr struct;
    if(cmd.contains("$"))
    {
        QString mycmdstr("");
        QString mycmdparastr("0");

        QStringList mycmdlist = cmd.split("$");
        if(mycmdlist.length() > 2)
        {
            qDebug() << "parameter too much";
            cmdpararet->cmdtype = reterror;
            cmdpararet->cmdval = 0;
            memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
            return reterror;
        }
        mycmdstr = mycmdlist.at(0);
        if(mycmdstr == strlist.at(int(CMD_SETBYTEARRAY)))
        {
            cmdpararet->cmdtype = CMD_SETBYTEARRAY;
            if(mycmdlist.at(1).contains("@"))
            {
                QStringList valuelist = mycmdlist.at(1).split("@");
                mycmdparastr = valuelist.at(0);
                QByteArray ba = mycmdparastr.toLatin1();
                if(ba.size() < 128)
                {
                    cmdpararet->cmdstrsize = ba.size();
                    memcpy(cmdpararet->cmdstr, ba.data(), ba.size());//this should be set to bytearray is better.
                }

                cmdpararet->strid = (EBAITEM)valuelist.at(1).toInt();
                cmdpararet->cmdval = 0;
                return 1;
            }else
            {
                mycmdparastr = mycmdlist.at(1);
                QByteArray ba = mycmdparastr.toLatin1();
                if(ba.size() < 128)
                {
                    cmdpararet->cmdstrsize = ba.size();
                    memcpy(cmdpararet->cmdstr, ba.data(), ba.size());//this should be set to bytearray is better.
                }
                cmdpararet->strid = NOITEM;
                cmdpararet->cmdval = 0;
                return 1;
            }
        }else if(mycmdstr == strlist.at(int(CMD_UPLOADFILE)))
        {
            cmdpararet->cmdtype = CMD_UPLOADFILE;
            if(mycmdlist.at(1).contains("@"))
            {
                QStringList valuelist = mycmdlist.at(1).split("@");
                mycmdparastr = valuelist.at(0);
                QByteArray ba = mycmdparastr.toLatin1();
                if(ba.size() < 128)
                {
                    cmdpararet->cmdstrsize = ba.size();
                    memcpy(cmdpararet->cmdstr, ba.data(), ba.size());//this should be set to bytearray is better.
                }

                cmdpararet->fileid = (EFILEITEM)valuelist.at(1).toInt();
                cmdpararet->cmdval = 0;
                return 1;
            }else
            {
                mycmdparastr = mycmdlist.at(1);
                QByteArray ba = mycmdparastr.toLatin1();
                if(ba.size() < 128)
                {
                    cmdpararet->cmdstrsize = ba.size();
                    memcpy(cmdpararet->cmdstr, ba.data(), ba.size());//this should be set to bytearray is better.
                }
                cmdpararet->fileid = NOFILEITEM;
                cmdpararet->cmdval = 0;
                return 1;
            }
        }
    }
//    qDebug() << "control&val1@id";

    for(int index = 0; index < strlist.length(); index++)
    {
        QString mycmd("");
        QString mycmdpara("0");
//        qDebug() << strlist.at(index);
        if(cmd.contains("$"))
        {
            QStringList mycmdlist = cmd.split("$");
            if(mycmdlist.length() > 2)
            {
                qDebug() << "parameter too much";
                cmdpararet->cmdtype = reterror;
                cmdpararet->cmdval = 0;
                memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
                return reterror;
            }
            mycmd = mycmdlist.at(0);
//            qDebug() << mycmd;
            if(mycmd == strlist.at(index))
            {
                cmdpararet->cmdtype = ECMDTYPE(index);
                if(mycmdlist.at(1).contains("@"))
                {
                    QStringList valuelist = mycmdlist.at(1).split("@");
                    mycmdpara = valuelist.at(0);
//                    qDebug() << mycmdpara;
                    cmdpararet->cmdval = mycmdpara.toInt();//this should be set to int number
                    cmdpararet->id = (EHWVAL)valuelist.at(1).toInt();
//                    qDebug() << cmdpararet->id;
                    memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
                    return 1;
                }else
                {
                    mycmdpara = mycmdlist.at(1);
                    cmdpararet->cmdval = mycmdpara.toInt();
                    cmdpararet->id = EHWTODEFINE;
                    memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
                    return 1;
                }
            }else
            {
                continue;
            }

        }else{
            mycmd = cmd;
            if(strlist.at(index) == mycmd)
            {
                qDebug() << index;
                cmdpararet->cmdtype = ECMDTYPE(index);
                memcpy(cmdpararet->cmdstr, "0", sizeof("0"));
                return 1;
            }
        }
    }
    qDebug("cmd not found");
    cmdpararet->cmdtype = reterror;
    return 1;
}

void IVFDMainWidget::DoCtlCmdFind(CmdPara *cmd)
{
    if(cmd == NULL){
        return;
    }
    qDebug() << "1 IVFDMainWidget::DoCtlCmdFind cmd.cmdtype = "  <<  cmd->cmdtype;
    int index = (int)(cmd->cmdtype);

    qDebug() << "1 IVFDMainWidget::DoCtlCmdFind length = " << m_cmdlist.length() << "index = " << index;
    if(index < 0 || index > m_cmdlist.length() - 1)
    {
        qDebug() << "index out of range";
        return;
    }

    enum ECMDTYPE cmdtype = ECMDTYPE(index);
    qDebug() << "1 IVFDMainWidget::DoCtlCmdFind:" << cmdtype;

    switch(cmdtype)
    {
    case CMD_CONTROL:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_Control(cmdtype, cmd->id ,cmd->cmdval);
        break;
    }

    case CMD_SETBYTEARRAY:
    {
        qDebug() << m_cmdlist.at(index);
        QByteArray ba;
        ba.resize(cmd->cmdstrsize);
        memcpy(ba.data(), cmd->cmdstr, cmd->cmdstrsize);
        emit SIG_SetByteArray(cmdtype, cmd->strid, ba);
    }
    case NOCOMMAND:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_NoIdentityCmd(cmdtype, cmd->id ,cmd->cmdval);
        break;
    }
    case CMD_GETBRIGHT0:
    {
        qDebug() << "ready to write the bright value to client" << m_cmdlist.at(index);
        emit SIG_AnswerCmdToHttpServer("20");
        break;
    }
    case CMD_SETALGPARA:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }
    case CMD_SETBRIGHT:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }
    case CMD_SETGAIN:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }
    case CMD_SETEXPOSURE:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }

    case CMD_SETSATURATION:
    {
        qDebug() << "----in DoCtlCmdFind---"  <<  m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id ,cmd->cmdval);
        break;
    }
    case CMD_SETBRIGHTBALANCE:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }

    case CMD_SETNETINFO:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id, cmd->cmdval);
        break;
    }

    case CMD_STARTALGDET:
    {
        qDebug() << "get the cmd ----in DoCtlCmdFind startalgdet---"  <<  m_cmdlist.at(index);
        emit SIG_StartAlgDet(cmdtype, 1);//1 for camera0 det fire.
        break;
    }
    case CMD_SETGPIO:
    {
        qDebug() << "get the cmd -----int DoCtlCmdFind setgpio----" << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd->id ,cmd->cmdval);
        break;
    }
    case CMD_UPLOADFILE:
    {
        qDebug() << "get the cmd -----int DoCtlCmdFind uploadfile----" << m_cmdlist.at(index);
        QByteArray ba;
        ba.resize(cmd->cmdstrsize);
        memcpy(ba.data(), cmd->cmdstr, cmd->cmdstrsize);
        qDebug() << cmd->id << "-------" << cmd->fileid;
        emit SIG_UploadFile(cmdtype, cmd->fileid, ba);
        break;
    }
    case CMD_CURRENTSTATUS:
    {
        qDebug() <<  "get the cmd -----int DoCtlCmdFind currentstatus----" << m_cmdlist.at(index);
        emit SIG_SendCMDTypeAnd0ValToDIP(cmdtype);
    }
    case CMD_GETSYSINFO:
    {
        qDebug() <<  "get the cmd -----int DoCtlCmdFind getsysinfo----" << m_cmdlist.at(index);
        emit SIG_GetSysInfo(cmdtype, (EREADITEM)cmd->id ,cmd->cmdval);
    }
    default://only send cmd type ,no val
    {
        qDebug() << "get the cmd -----int DoCtlCmdFind, Send cmdtype and 0 val to DIP Server----" << m_cmdlist.at(index);
        emit SIG_SendCMDTypeAnd0ValToDIP(cmdtype);
    }

    }
    return;
}
void IVFDMainWidget::SLOT_NoIdentityCmd(ECMDTYPE, EHWVAL id, qint32 val)
{
    qDebug() << "1 IVFDMainWidget::SLOT_NoIdentityCmd------NOCOMMAND FIND ";
}

void IVFDMainWidget::SLOT_SetInitFilesVal(enum ECMDTYPE cmdtype, EHWVAL id, qint32 cmdval)
{
    qDebug("1 IVFDMainWidget::SLOT_SetInitFilesVal:CMDTYPE = %d, HWID= %d  HWVALSET = %d", cmdtype, id, cmdval);
    enum ECMDTYPE mycmdtype = cmdtype;
    //    QSettings mysettings("/ivfdinit.ini", QSettings::IniFormat);
    QSettings *mysetting = new QSettings(IVFDINIT_INI, QSettings::IniFormat);
    if(mysetting == NULL)
    {
        qDebug() << "mysetting = NULL";
        return;
    }
    int m_id = (int)id;
    switch(mycmdtype)
    {
    qDebug() << "begin to write the value to /ivfdinit.ini";
    case CMD_SETBRIGHT:
    {
        QString keybright = QString("brightness").append(QString::number(m_id));
//        QString keyexposure = QString("exposurer").append(QString::number(m_id));
//        QString keygain = QString("gain").append(QString::number(m_id));

        mysetting->beginGroup("cameraset");
        qDebug() << "brightness = " << mysetting->value(keybright);
//        qDebug() << "exposure = " << mysetting->value(keyexposure);
//        qDebug() << "gain = " << mysetting->value(keygain);
//        mysetting->setValue(keybright, cmdval);
//        mysetting->sync();
        modifyInitFile("/ivfdinit.ini", keybright, keybright.append(QString("=").append((QString::number(cmdval)))),lock);
        qDebug() << "after write now read the bright val =" << mysetting->value(keybright);
        int val1 = 0;
        int val2 = mysetting->value(keybright).toInt();//mysetting->value(keyexposure).toInt();
        int val3 = 0;//mysetting->value(keygain).toInt();
        qDebug() << keybright << "=" << val2;
        mysetting->endGroup();
        //after set the file ,should update the hardware!
        emit SIG_SetCameraParameter(CMD_SETBRIGHT, m_id, val1, val2, val3);

        qDebug() << "1 IVFDMainWidget::SLOT_SetInitFilesVal:emit SIG_SetCameraParameter(mycmdtype, id, val1, val2, val3)";

        break;
    }
    case CMD_SETGAIN:
    {
        QString keygain = QString("gain").append(QString::number(m_id));
        mysetting->beginGroup("cameraset");
        qDebug() << "keywb = " << mysetting->value(keygain);
//        mysetting->setValue(keygain, cmdval);
//        mysetting->sync();
        modifyInitFile(IVFDINIT_INI, keygain, keygain.append(QString("=").append((QString::number(cmdval)))), lock);
        qDebug() << "after write now read the gain val =" << mysetting->value(keygain);
        int val1 = 1;//1 for gain
        int val2 = mysetting->value(keygain).toInt();//
        int val3 = 0;//mysetting->value(keygain).toInt();//not used
        qDebug() << keygain << "=" << val2;
        mysetting->endGroup();
        //after set the file ,should update the hardware!
        emit SIG_SetCameraParameter(CMD_SETGAIN, m_id, val1, val2, val3);
        break;
    }
    case CMD_SETEXPOSURE:
    {
        QString keyexposure = QString("exposure").append(QString::number(m_id));
        mysetting->beginGroup("cameraset");
        qDebug() << "exposure = " << mysetting->value(keyexposure);
//        mysetting->setValue(keyexposure, cmdval);
//        mysetting->sync();
        modifyInitFile(IVFDINIT_INI, keyexposure, keyexposure.append(QString("=").append((QString::number(cmdval)))), lock);
        qDebug() << "after write now read the exposure val =" << mysetting->value(keyexposure);
        int val1 = 2;
        int val2 = mysetting->value(keyexposure).toInt();//mysetting->value(keyexposure).toInt();
        int val3 = 0;//mysetting->value(keygain).toInt();
        qDebug() << keyexposure << "=" << val2;
        mysetting->endGroup();
        //after set the file ,should update the hardware!
        emit SIG_SetCameraParameter(CMD_SETEXPOSURE, m_id, val1, val2, val3);
        qDebug() << "1 IVFDMainWidget::SLOT_SetInitFilesVal:emit SIG_SetCameraParameter(mycmdtype, id, val1, val2, val3)";
        break;
    }

    case CMD_SETSATURATION:
    {
        QString keysaturation = QString("saturation").append(QString::number(m_id));
        mysetting->beginGroup("cameraset");
        qDebug() << "keywb = " << mysetting->value(keysaturation);
//        mysetting->setValue(keysaturation, cmdval);
//        mysetting->sync();
        modifyInitFile(IVFDINIT_INI, keysaturation, keysaturation.append(QString("=").append((QString::number(cmdval)))), lock);
        qDebug() << "after write now read the saturation val =" << mysetting->value(keysaturation);
        int val1 = 3;//3 for saturation
        int val2 = mysetting->value(keysaturation).toInt();//
        int val3 = 0;//mysetting->value(keygain).toInt();//not used
        qDebug() << keysaturation << "=" << val2;
        mysetting->endGroup();
        //after set the file ,should update the hardware!
        emit SIG_SetCameraParameter(CMD_SETSATURATION, m_id, val1, val2, val3);
        break;
    }
    case CMD_SETBRIGHTBALANCE:
    {
        QString keywb = QString("brightbalance").append(QString::number(m_id));
        mysetting->beginGroup("cameraset");
        qDebug() << "keywb = " << mysetting->value(keywb);
//        mysetting->setValue(keywb, cmdval);
//        mysetting->sync();
        modifyInitFile(IVFDINIT_INI, keywb, keywb.append(QString("=").append((QString::number(cmdval)))), lock);
        qDebug() << "after write now read the brightbalance val =" << mysetting->value(keywb);
        int val1 = 5;//for wb
        int val2 = mysetting->value(keywb).toInt();//mysetting->value(keyexposure).toInt();
        int val3 = 0;//mysetting->value(keygain).toInt();//not used
        qDebug() << keywb << "=" << val2;
        mysetting->endGroup();
        //after set the file ,should update the hardware!
        emit SIG_SetCameraParameter(CMD_SETBRIGHTBALANCE, m_id, val1, val2, val3);
        break;
    }

    case CMD_SETALGPARA:
    {
//        QSettings *myalgsetting = new QSettings("/ivfdalgcfg.ini", QSettings::IniFormat);
//        if(myalgsetting == NULL)
//        {
//            qDebug() << "myalgsetting = NULL";
//            return;
//        }
        QString keysense = QString("sensefire");
        QString keydelay = QString("delayfire");
        QString keyalarmdelay = QString("alarmdelayfire");
        QString keymindetfactor = QString("mindetfactorfire");

        mysetting->beginGroup("algo");
        qDebug() << "sense = " << mysetting->value(keysense);
        qDebug() << "delay = " << mysetting->value(keydelay) << " m_id =" << m_id << " cmdval = " << cmdval;
        qDebug() << "alarmdelay = " << mysetting->value(keyalarmdelay);
//        mysetting->setValue(keysense, cmdval);
//        mysetting->sync();
        if(m_id == SENSEFIRE){
            modifyInitFile(IVFDINIT_INI, keysense, keysense.append("=").append(QString::number(cmdval)), lock);
        }else if(m_id == MINDETFIRE){
            modifyInitFile(IVFDINIT_INI, keymindetfactor, keymindetfactor.append("=").append(QString::number(cmdval)), lock);
        }
        qDebug() << "after write now read the algo sense val =" << mysetting->value(keysense);
        int val1 = mysetting->value(keysense).toInt();
        int val2 = mysetting->value(keydelay).toInt();
        int val3 = mysetting->value(keyalarmdelay).toInt();
        qDebug() << "keysense =" << val1;
        mysetting->endGroup();
        //after set the file ,should update the hardware!

        if(id > 10){
            qDebug() << "send args to smoke alg";
            emit SIG_SetDIPAlgParameter(CMD_SETALGPARA, 1, m_id, cmdval);
            //for smoke arg
        }else if(id < 10){
            qDebug() << "send args to fire alg";
            emit SIG_SetDIPAlgParameter(CMD_SETALGPARA, 0, m_id, cmdval);
            //for fire arg
        }

        qDebug() << "1 IVFDMainWidget::SLOT_SetInitFilesVal:emit SIG_SetCameraParameter(mycmdtype, id, val1, val2, val3)";

        break;
    }
    case CMD_SETGPIO:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetInitFilesVal:CMD_SETGPIO !" ;
//        mysetting->beginGroup("relayoutset");
//        QString relayout = QString("relayout").append(QString::number(id));

//        mysetting->setValue(relayout, cmdval);
//        mysetting->sync();
//        qDebug() << mysetting->value(relayout);
//        mysetting->endGroup();
        emit SIG_SetGPIOOUT(mycmdtype, id, cmdval);
        break;
    }
    }
//    modifyInitFile("/camerachange.ini", "camerasetchange=", "camerasetchange=1", lock);
    delete mysetting;
}

void IVFDMainWidget::SLOT_Control(ECMDTYPE cmdtype, EHWVAL id, qint32 val)
{
    qDebug() << "1 IVFDMainWidget::SLOT_Control :cmdtype = " << cmdtype;
    EHWVAL idrecv = id;

    switch(idrecv)
    {
    case ALGARGALPHA:
    {
        qDebug() << "beging to set algalpha:" << val;
        break;
    }
    case ALGARGBETA:
    {
        qDebug() << "beging to set algbeta:" << val;
        break;
    }
    case ALGARGWEIGHT1:
    {
        qDebug() << "beging to set algweight1:" << val;
        break;
    }
    case SYSTEMRESET:
    {
        qDebug() << "being to reset the system:" << val;
        break;
    }
    case SETNETCONFIG:
    {
        qDebug() << "being to config net:" << val;
        break;
    }
    case LOGIN:
    {
        qDebug() << "being to login system:" << val;
        break;
    }
    case RESETSTATUS:
    {
        qDebug() << "being to reset status:" << val;
        break;
    }
    case ALARMENABLE:
    {
        qDebug() << "being to enable or disable alarm:" << val;
        break;
    }
    case CALIBRATE:
    {
        qDebug() << "being to calibrate the scene:" << val;
        break;
    }
    case INITCAMERA:
    {
        qDebug() << "being to stop init CameraBy initfile cfg" << val;

        qDebug() << "m_videoCapture != NULL";

        break;
    }
    case SDCARD:
    {
        qDebug() << "being to operate sdcard " << val;
        emit SIG_SendCMDTypeAnd2ValToDIP(cmdtype, (int)idrecv, val);

        break;
    }
    case ALGFIREONOFF:
    {
        qDebug() << "being to set the fire det on or off " << val;
        emit SIG_SendCMDTypeAnd2ValToDIP(cmdtype, (int)idrecv, val);

        QByteArray ba = IntToByte(val);
        qDebug() << ba.size();
        foreach(QString str, m_tcpsocketList){
            SIG_TellClientToSend(str, 59000, ba, ba);
        }


        break;
    }
    case ALGSMOKEONOFF:
    {
        qDebug() << "being to set the smoke det on or off " << val;
        emit SIG_SendCMDTypeAnd2ValToDIP(cmdtype, (int)idrecv, val);

        break;
    }
    case DIPMODULE:
    {
        qDebug() << "beging to set dipModule:" << val;
        if(val == 0){
            emit SIG_KillProcessMain();
        }
        break;
    }
    case HTTPMODULE:
    {
        if(val == 0){
            emit SIG_StopProcessHttpServer();
        }
        break;
    }
    case FTPMODULE:
    {
        if(val == 0){
            emit SIG_StopProcessFtp();
        }
        break;
    }
    case RTSPMODULE:
    {
        if(val == 0){
            emit SIG_StopProcessRtsp();
        }
        break;
    }
    case MODULEALL:
    {
        if(val == 0){
            emit SIG_KillProcessMain();
            emit SIG_StopProcessHttpServer();
            emit SIG_StopProcessRtsp();
            emit SIG_StopProcessFtp();
        }
    }
    case SYSRESET:
    {
        if(val == 0){
            emit SIG_SysReset();
        }
        break;
    }
    case APPRESET:
    {
        if(val == 0){
            emit SIG_AppReset();
        }
        break;
    }
    case SYSUPDATE:
    {
        if(val == 0){
            emit SIG_SysUpdate();
        }
        break;
    }
    case APPUPDATE:
    {
        qDebug() << "beging to update file " << val;
        emit SIG_AppUpdate(val);
        break;
    }
    case APPBACK:
    {
        qDebug() << "beging to backup file " << val;
        if(val == 0){
            emit SIG_AppBackup(val);
        }
        break;
    }
    case APPUPLOAD:
    {
        qDebug() << "begin to upload file " << val;
        emit SIG_AppUpload(val);
        break;
    }

    default:
    {
        qDebug() << "no operate";
    }

    }
}

void IVFDMainWidget::SLOT_GetSysInfo(ECMDTYPE cmdtype, EREADITEM id, qint32 val)
{
    qDebug() << "1 IVFDMainWidget::SLOT_GetSysInfo :cmdtype = " << cmdtype << " id = " << id << " val = " << val;
    EREADITEM idrecv = id;

    CmdActiveX readsend;
    readsend.cmdtype = (int)cmdtype;//cmdtype = 1:modify xyoffset command
    readsend.cmdval = 0;
    memset(readsend.cmdstr, 0 ,128);

    QByteArray readba;
    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);

    switch(idrecv){
    case BRIGHTNESS0:
    {
        int readval = initsetting.value("/cameraset/brightness0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case BRIGHTNESS1:
    {
        int readval = initsetting.value("/cameraset/brightness1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case GAIN0:
    {
        int readval = initsetting.value("/cameraset/gain0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case GAIN1:
    {
        int readval = initsetting.value("/cameraset/gain1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case SATURATION0:
    {
        int readval = initsetting.value("/cameraset/saturation0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case SATURATION1:
    {
        int readval = initsetting.value("/cameraset/saturation1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case CONTRAST0:
    {
        int readval = initsetting.value("/cameraset/contrast0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case CONTRAST1:
    {
        int readval = initsetting.value("/cameraset/contrast1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case EXPOSURE0:
    {
        int readval = initsetting.value("/cameraset/exposure0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case EXPOSURE1:
    {
        int readval = initsetting.value("/cameraset/exposure1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case WB0:
    {
        int readval = initsetting.value("/cameraset/brightbalance0").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case WB1:
    {
        int readval = initsetting.value("/cameraset/brightbalance1").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case SENSEFIRE:
    {
        int readval = initsetting.value("/algo/sensefire").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case MINDETFIRE:
    {
        int readval = initsetting.value("/algo/mindetfactorfire").toInt();
        readsend.cmdval = readval;
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case LIMIT:
    {
        QString readval = initsetting.value("/userinfo/timelimit").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case TYPE:
    {
        QString readval = initsetting.value("/userinfo/authendevicename").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case CLASS:
    {
        QString readval = initsetting.value("/userinfo/authendeviceclass").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case CODE:
    {
        QString readval = initsetting.value("/userinfo/authenfunccode").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case LEVEL:
    {
        QString readval = initsetting.value("/userinfo/userauthen").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case ID:
    {
        QString readval = initsetting.value("/userinfo/userid").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case MORE:
    {
        QString readval = initsetting.value("/userinfo/others").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case NAME:
    {
        QString readval = initsetting.value("/userinfo/username").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case IP:
    {
        QString readval = initsetting.value("/netconfig/address").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case MASK:
    {
        QString readval = initsetting.value("/netconfig/mask").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case GATE:
    {
        QString readval = initsetting.value("/netconfig/netgate").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    case UPLOADFTP:
    {
        QString readval = initsetting.value("/netconfig/ftpserver").toString();
        readsend.cmdval = 555;
        int len = readval.toLatin1().length() < 128?readval.length():128;
        memcpy(readsend.cmdstr, readval.toLatin1(), len);
        readba.resize(sizeof(readsend));
        memcpy(readba.data(), &readsend, sizeof(readsend));
        if(m_tcpclient != NULL){
            foreach(QString str, m_tcpsocketList){
                SIG_TellClientToSend(str, 59000, readba, readba);
            }
        }
//        qDebug() << "send the readdata to client pc" << readsend.cmdval;
        break;
    }
    }

}

void IVFDMainWidget::SLOT_SetByteArray(ECMDTYPE cmdtype, EBAITEM ebaitem, QByteArray baval)
{
    qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray :cmdtype = " << cmdtype;
    EBAITEM idrecv = ebaitem;
    switch(idrecv)
    {
    case IPADDRESS:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray ipaddress:val = " << QString(baval);
        QString ipaddr = QString(baval);
        modifyAutoRunFile(AUTORUN_SH,"ifconfig eth0 192.168.",QString("ifconfig eth0 %1").arg(ipaddr), lock);
        modifyInitFile(IVFDINIT_INI, "address=", QString("address=").append(ipaddr), lock);
        break;
    }
    case NETGATE:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray netgate:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"netgate=",QString("netgate=").append(QString(baval)), lock);
        break;
    }
    case NETMAC:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray netmac:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"mac=",QString("mac=").append(QString(baval)), lock);
        break;
    }
    case NETMASK:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray netmask:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"mask=",QString("mask=").append(QString(baval)), lock);
        break;
    }
    case USERNAME:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray username:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"username=",QString("username=").append(QString(baval)), lock);
        break;
    }
    case PASSWORD:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray password:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"password=",QString("password=").append(QString(baval)), lock);
        break;
    }
    case FILENAME:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray filename:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"filename=",QString("filename=").append(QString(baval)), lock);
        break;
    }
    case NEWCLIENT:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray NEWCLIENT:val = " << QString(baval);
        QVariant var;
        var.setValue(QString(baval));
        if(m_tcpsocketList.isEmpty()){
            m_tcpsocketList.append(QString(baval));
            modifyInitFile(IVFDINIT_INI, "lastclientip=", QString("lastclientip=").append(QString(baval)), lock);
//            SetEnviroment("status","lastclientip", var);
        }else{
            if(m_tcpsocketList.contains(QString(baval))){

            }else{
                m_tcpsocketList.append(QString(baval));
                modifyInitFile(IVFDINIT_INI, "lastclientip=", QString("lastclientip=").append(QString(baval)), lock);
//                SetEnviroment("status","lastclientip", var);
            }
        }

        foreach(QString str, m_tcpsocketList){
            qDebug() << "1 IVFDMainWidget::SLOT_XParseAlgOutFromDipTcpClient:emit SIG_TellClientToSend " << str;
            //send the onwatch status to the client
        }

        break;
    }

    case TIMELIMIT:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray timelimit:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"timelimit=",QString("timelimit=").append(QString(baval)), lock);
        break;
    }
    case DEVTYPE:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray : devtype val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"authendevicename=",QString("authendevicename=").append(QString(baval)), lock);
        break;
    }
    case DEVCLASS:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray : dev class val = " << QString(baval);
        QString devclass = QString(baval);
        modifyInitFile(IVFDINIT_INI, "authendeviceclass=", QString("authendeviceclass=").append(QString(baval)), lock);
        break;
    }
    case FUNCCODE:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray : funcode val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"authenfunccode=",QString("authenfunccode=").append(QString(baval)), lock);
//        QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
//        QString funcode = QString(baval);
//        initsetting.setValue("/userinfo/authenfunccode", funcode);
//        initsetting.sync();
        break;
    }
    case USERID:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray : userid val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"userid=",QString("userid=").append(QString(baval)), lock);

        break;
    }
    case USERLEVEL:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray usrlevel:val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"userauthen=",QString("userauthen=").append(QString(baval)), lock);
        break;
    }
    case USERMORE:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray :usermore val = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"others=",QString("others=").append(QString(baval)), lock);
        break;
    }
    case FTPSERVER:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray :FTPSERVER = " << QString(baval);
        modifyInitFile(IVFDINIT_INI,"ftpserver=",QString("ftpserver=").append(QString(baval)), lock);
        break;
    }
    case SYNCTIME:
    {
        qDebug() << "1 IVFDMainWidget::SLOT_SetByteArray :SYNCTIME = " << QString(baval);
        QStringList arguments;
        arguments << QString(baval);
        m_processSystem->start(TIMESYNC_SH, arguments);
        if(!m_processSystem->waitForStarted()){
//            qDebug() << "timesync  start error!";
            QLog_("main", ErrorLevel, QString("timesync start error!"));
        }else{
            m_processSystem->closeWriteChannel();
            QByteArray m_processOutput;
            if(m_processSystem->waitForStarted(-1)){
                while(m_processSystem->waitForReadyRead(-1)){
                    m_processOutput = m_processSystem->readAllStandardOutput();
                }
            }
        }
        m_processSystem->close();
        break;

    }

    default:
    {
        qDebug() << "no operate";
    }
    }

}

//end for xparsecmd

void IVFDMainWidget::SLOT_SendCMDTypeAnd0ValToDIP(ECMDTYPE cmdtype)
{
    QByteArray ba;
    ConvertCMDArgToByteArray(&m_cmdarg, cmdtype, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SendCMDTypeAnd1ValToDIP(ECMDTYPE cmdtype, int val)
{
    QByteArray ba;
    ConvertCMDArgToByteArray(&m_cmdarg, cmdtype, val, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SendCMDTypeAnd2ValToDIP(ECMDTYPE cmdtype, int val1, int val2)
{
    QByteArray ba;
    ConvertCMDArgToByteArray(&m_cmdarg, cmdtype, val1, val2, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SendCMDTypeAnd3ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3)
{
    QByteArray ba;
    ConvertCMDArgToByteArray(&m_cmdarg, cmdtype, val1, val2, val3, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SendCMDTypeAnd4ValToDIP(ECMDTYPE cmdtype, int val1, int val2, int val3, int val4)
{
    QByteArray ba;
    ConvertCMDArgToByteArray(&m_cmdarg, cmdtype, val1, val2, val3, val4, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_StartAlgDet(ECMDTYPE cmdtype, int algId)
{
    m_cmdarg.cmdtype = (int)cmdtype;
    m_cmdarg.argnum = 1;
    m_cmdarg.arg1 = algId;
    QByteArray ba;
    ConvertStructToByteArray(&m_cmdarg, CMDARG, &ba);
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);

}

void IVFDMainWidget::SLOT_SetCameraParameter(ECMDTYPE cmdtype, int name, int val1, int val2, int val3)
{
    qDebug() << "1 IVFDMainWidget::SLOT_SetCameraParameter:start, name = " << name;
    m_cmdarg.cmdtype = (int)cmdtype;
    m_cmdarg.argnum = 4;
    m_cmdarg.arg1 = name;
    m_cmdarg.arg2 = val1;
    m_cmdarg.arg3 = val2;
    m_cmdarg.arg4 = val3;

    QByteArray ba;
    ConvertStructToByteArray(&m_cmdarg, CMDARG, &ba);
    CmdARG *tmp = (CmdARG *)(ba.data());
    qDebug() << "1 IVFDMainWidget::SLOT_SetCameraParameter: tmp.cmdtype = " << tmp->cmdtype;
//    ba = QString("waht").toLatin1();
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SetDIPAlgParameter(ECMDTYPE cmdtype, int algtype, int id, int val)
{
     qDebug() << "1 IVFDMainWidget::SLOT_SetDIPAlgParameter:start, algtype = " << algtype;
     m_cmdarg.cmdtype = (int)cmdtype;
     m_cmdarg.argnum = 3;
     m_cmdarg.arg1 = algtype;
     m_cmdarg.arg2 = id;
     m_cmdarg.arg3 = val;
//     m_cmdarg.arg4 = val3;

     QByteArray ba;
     ConvertStructToByteArray(&m_cmdarg, CMDARG, &ba);
     CmdARG *tmp = (CmdARG *)(ba.data());
     qDebug() << "1 IVFDMainWidget::SLOT_SetCameraParameter: tmp.cmdtype = " << tmp->cmdtype;
 //    ba = QString("waht").toLatin1();
     emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_CapureYUVFile(ECMDTYPE cmdtype, int num)
{
    m_cmdarg.cmdtype = (int)cmdtype;
    m_cmdarg.argnum = 1;
    m_cmdarg.arg1 = num;
    QByteArray ba;
    ConvertStructToByteArray(&m_cmdarg, CMDARG, &ba);
    CmdARG *tmp = (CmdARG *)(ba.data());
    qDebug() << "1 IVFDMainWidget::SLOT_CapureYUVFile: tmp.cmdtype = " << tmp->cmdtype;
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}

void IVFDMainWidget::SLOT_SetGPIOOUT(ECMDTYPE cmdtype, int pin, int val)
{
    qDebug() << "IVFDMainWidget::SLOT_SetGPIOOUT:";
    m_cmdarg.cmdtype = (int)cmdtype;
    m_cmdarg.argnum = 2;
    m_cmdarg.arg1 = pin;
    m_cmdarg.arg2 = val;
    m_cmdarg.arg3 = 0;
    m_cmdarg.arg4 = 0;

    QByteArray ba;
    ConvertStructToByteArray(&m_cmdarg, CMDARG, &ba);
    CmdARG *tmp = (CmdARG *)(ba.data());
    qDebug() << "1 IVFDMainWidget::SLOT_SetGPIOOUT: tmp.cmdtype = " << tmp->cmdtype;
    emit SIG_SendCMDToDIPServer(m_dipTcpServerAddr, m_dipTcpServerPortn, ba);
}



void IVFDMainWidget::SLOT_SendAlgOutToPlatServer(QString addr, quint16 portn, QByteArray val1, QByteArray val2)
{



}


void IVFDMainWidget::SLOT_UploadFile(ECMDTYPE type, EFILEITEM id, QByteArray baval){
    qDebug() << "1 IVFDMainWidget::SLOT_UploadFile()---" << type << " id= " << id;
    switch(id){
    case(INITFILE):
    {
        qDebug() << "1 IVFDMainWidget::SLOT_UploadFile()-----INITFILE" << id;
        QStringList arguments;
        arguments << IVFDINIT_INI << "IVFDINIT_INI.back";
        m_processSystem->start("cp", arguments);
//        m_processSystem->start("ls");
        m_processSystem->waitForFinished(100);
        qDebug() << m_processSystem->readAll();
        m_processSystem->close();
        break;
    }
    case (FIRECFG):
    {
        qDebug() << "1 IVFDMainWidget::SLOT_UploadFile()-----FIRECFG" << id;
        QStringList arguments;
        arguments << ALGFIRECFG_INI << ALGFIRECFGBAK_INI;
        m_processSystem->start("cp", arguments);
//        m_processSystem->start("ls");
        m_processSystem->waitForFinished(100);
        qDebug() << m_processSystem->readAll();
        m_processSystem->close();
        break;
    }
    case (SMOKECFG):
    {
        break;
    }
    case (AUTHENFILE):
    {
        break;
    }

    }
}

void IVFDMainWidget::SLOT_ProcessFtpStarted()
{
    qDebug() << "1 IVFDMainWidget::SLOT_ProcessFtpStarted: Ftp Started success!";
}

void IVFDMainWidget::InitThis(QString addr)
{

    CreateEnviorment();

    IVFDRunnable *myRunnable = new IVFDRunnable();
    myRunnable->SIG_Runnable(GPIO_OUTLED1, FLASH, 500, 5);
    myRunnable->setAutoDelete(true);
    GlobalThreadPool->start(myRunnable);

    m_tcpserver = new IVFDMainTcpServer(0);//create forever, parent be 0 to create a thread.
    m_tcpclient = new IVFDTcpClient(0);//create forever, parent be 0 to create a theread;

    m_heartbeat = new IVFDHeartBeat(0);


    m_hostAddr = addr;
    m_localAddr = QString("127.0.0.1");//for main, local ip address is needed;

    m_tcpServerPortn = QString("58890");//FOR ANY module, is the main's tcpserver listening port;
    m_httpPortn = QString("58891");//FOR HTTP, is httpserver's listening port;
    m_ftpPortn = QString("2000");//FOR FTP, is ftpserver's listening port;
    m_ftpPassWord = QString("password");
    m_ftpUserName = QString("username");
    m_ftpRootpath = QString("/mnt/sdcard/mmcblk1p1/1/");

    m_dipTcpServerAddr = QString("127.0.0.1");//for dip, local ip address is needed;
    m_dipTcpServerPortn = QString("58892");//for dip, is dip's listening port;
    m_activeXPortn = QString("58893");

    m_processMain = new QProcess(this);
    m_processFtpServer = new QProcess(this);
    m_processRtsp = new QProcess(this);
    m_processHttpServer = new QProcess(this);
    m_processSystem = new QProcess(this);


    m_processMainId = -1000;
    m_processFtpServerId = -1001;
    m_processHttpServerId = -1002;
    m_processSystemId = -1003;

    m_cmdarg.arg1 = 0;
    m_cmdarg.arg2 = 0;
    m_cmdarg.arg3 = 0;
    m_cmdarg.arg4 = 0;
    m_cmdarg.argnum = 0;
    m_cmdarg.cmdtype = 0;

    m_updatestatus = 0;
    QVariant keyval;
    GetCFG(IVFDINIT_INI, "status", "lastclientip", &keyval);
    if(keyval.toString() != NULL){
        m_tcpsocketList.append(keyval.toString());
    }
    GetCFG(IVFDINIT_INI, "netconfig", "netgate", &keyval);
    m_netGate = keyval.toString();

    qDebug() << "1 new m_processMain()!";
    QObject::connect(m_processMain, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(SLOT_ProcessMainFinished(int,QProcess::ExitStatus)));
    QObject::connect(m_processFtpServer, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(SLOT_ProcessFtpFinished(int,QProcess::ExitStatus)));
    QObject::connect(m_processHttpServer, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(SLOT_ProcessHttpFinished(int,QProcess::ExitStatus)));
    QObject::connect(m_processRtsp, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(SLOT_ProcessRtspFinished(int,QProcess::ExitStatus)));
    QObject::connect(m_processSystem, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(SLOT_ProcessSystemFinished(int,QProcess::ExitStatus)));

    QObject::connect(m_processFtpServer, SIGNAL(started()), this, SLOT(SLOT_ProcessFtpStarted()));

    QObject::connect(this, SIGNAL(SIG_StartHeartBeat()), m_heartbeat, SIGNAL(SIG_StartHeartBeat()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_StopHeartBeat()), m_heartbeat, SIGNAL(SIG_StopHeatBeat()), Qt::QueuedConnection);
    QObject::connect(m_heartbeat, SIGNAL(SIG_TellTop(QByteArray)), this, SIGNAL(SIG_XParseTcpServerRecv(QByteArray)), Qt::QueuedConnection);

    QObject::connect(this, SIGNAL(SIG_StartProcessMain()), this, SLOT(SLOT_StartProcessMain()));
    QObject::connect(this, SIGNAL(SIG_RestartProcessMain()), this, SLOT(SLOT_RestartProcessMain()));
    QObject::connect(this, SIGNAL(SIG_KillProcessMain()), this, SLOT(SLOT_KillProcessMain()));

    QObject::connect(this, SIGNAL(SIG_KillMainSelf()), this, SLOT(SLOT_KillMainSelf()));

    QObject::connect(this, SIGNAL(SIG_StartProcessFtp(QString, QString, QString, QString, QString)), this, SLOT(SLOT_StartProcessFtp(QString, QString, QString, QString, QString)));
    QObject::connect(this, SIGNAL(SIG_RestartProcessFtp(QString, QString, QString, QString, QString)), this, SLOT(SLOT_RestartProcessFtp(QString, QString, QString, QString, QString)));
    QObject::connect(this, SIGNAL(SIG_StopProcessFtp()), this, SLOT(SLOT_StopProcessFtp()));

    QObject::connect(this, SIGNAL(SIG_StartProcessHttpServer(QString, QString)), this, SLOT(SLOT_StartProcessHttpServer(QString, QString)));
    QObject::connect(this, SIGNAL(SIG_RestartProcessHttpServer(QString, QString)), this, SLOT(SLOT_RestartProcessHttpServer(QString, QString)));
    QObject::connect(this, SIGNAL(SIG_StopProcessHttpServer()), this, SLOT(SLOT_StopProcessHttpServer()));

    QObject::connect(this, SIGNAL(SIG_StartProcessRtsp()), this, SLOT(SLOT_StartProcessRtsp()));
    QObject::connect(this, SIGNAL(SIG_RestartProcessRtsp()), this, SLOT(SLOT_RestartProcessRtsp()));
    QObject::connect(this, SIGNAL(SIG_StopProcessRtsp()), this, SLOT(SLOT_StopProcessRtsp()));

    QObject::connect(this, SIGNAL(SIG_StartLocalTcpServer()), this, SLOT(SLOT_StartLocalTcpServer()));

    //main tcp server get cmd from http, and the tell local client to send cmd to dip tcp server;
    QObject::connect(m_tcpserver, SIGNAL(SIG_TellTop(QByteArray)), this, SIGNAL(SIG_XParseTcpServerRecv(QByteArray)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_XParseTcpServerRecv(QByteArray)), this, SLOT(SLOT_XParseTcpServerRecv(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_XParseAlgOutFromDipTcpClient(QByteArray)), this, SLOT(SLOT_XParseAlgOutFromDipTcpClient(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_XParseCMDFromHttpServer(QByteArray)), this, SLOT(SLOT_XParseCMDFromHttpServer(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_XParseMsgFromTerminalCLient(QByteArray)), this, SLOT(SLOT_XParseMsgFromTerminalCLient(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_XParseGeneralMsg(QByteArray)), this, SLOT(SLOT_XParseGeneralMsg(QByteArray)));
    //signals from xparsecmd part, and the slot function to call SIG_TellClientToSend to send
    QObject::connect(this, SIGNAL(SIG_SendCMDToDIPServer(QString, QString, QByteArray)), this, SLOT(SLOT_SendCMDToDIPServer(QString, QString, QByteArray)));
    QObject::connect(this, SIGNAL(SIG_TellClientToSend(QString, quint16, QByteArray,QByteArray)), m_tcpclient, SIGNAL(SIG_SendMsgToServer(QString, quint16, QByteArray, QByteArray)), Qt::QueuedConnection);
    QObject::connect(m_tcpclient, SIGNAL(SIG_Offline(bool)), this, SLOT(SLOT_Offline(bool)), Qt::QueuedConnection);

    QObject::connect(this, SIGNAL(SIG_SetCameraParameter(ECMDTYPE, int, int, int, int)), this, SLOT(SLOT_SetCameraParameter(ECMDTYPE ,int, int, int, int)));
    QObject::connect(this, SIGNAL(SIG_SetDIPAlgParameter(ECMDTYPE,int,int,int)), this, SLOT(SLOT_SetDIPAlgParameter(ECMDTYPE,int,int,int)));

    QObject::connect(this, SIGNAL(SIG_StartAlgDet(ECMDTYPE, int)), this, SLOT(SLOT_StartAlgDet(ECMDTYPE, int)));
    QObject::connect(this, SIGNAL(SIG_Control(ECMDTYPE, EHWVAL, qint32)), this, SLOT(SLOT_Control(ECMDTYPE,EHWVAL,qint32)));
    QObject::connect(this, SIGNAL(SIG_GetSysInfo(ECMDTYPE, EREADITEM, qint32)), this, SLOT(SLOT_GetSysInfo(ECMDTYPE,EREADITEM,qint32)));

    QObject::connect(this, SIGNAL(SIG_SetByteArray(ECMDTYPE, EBAITEM, QByteArray)), this, SLOT(SLOT_SetByteArray(ECMDTYPE, EBAITEM, QByteArray)));
    QObject::connect(this, SIGNAL(SIG_SetGPIOOUT(ECMDTYPE,int,int)), this, SLOT(SLOT_SetGPIOOUT(ECMDTYPE,int,int)));

    QObject::connect(this, SIGNAL(SIG_SetInitFilesVal(ECMDTYPE,EHWVAL,qint32)), this, SLOT(SLOT_SetInitFilesVal(ECMDTYPE,EHWVAL,qint32)));
    QObject::connect(this, SIGNAL(SIG_SendCMDTypeAnd0ValToDIP(ECMDTYPE)), this, SLOT(SLOT_SendCMDTypeAnd0ValToDIP(ECMDTYPE)));
    QObject::connect(this, SIGNAL(SIG_SendCMDTypeAnd1ValToDIP(ECMDTYPE, int)), this, SLOT(SLOT_SendCMDTypeAnd1ValToDIP(ECMDTYPE, int)));
    QObject::connect(this, SIGNAL(SIG_SendCMDTypeAnd2ValToDIP(ECMDTYPE, int, int)), this, SLOT(SLOT_SendCMDTypeAnd2ValToDIP(ECMDTYPE, int, int)));
    QObject::connect(this, SIGNAL(SIG_SendCMDTypeAnd3ValToDIP(ECMDTYPE, int, int, int)), this, SLOT(SLOT_SendCMDTypeAnd3ValToDIP(ECMDTYPE, int, int, int)));
    QObject::connect(this, SIGNAL(SIG_SendCMDTypeAnd4ValToDIP(ECMDTYPE, int, int, int, int)), this, SLOT(SLOT_SendCMDTypeAnd4ValToDIP(ECMDTYPE, int, int, int, int)));
    QObject::connect(this, SIGNAL(SIG_SendAlgOutToPlatServer(QString,quint16,QByteArray,QByteArray)), this, SLOT(SLOT_SendAlgOutToPlatServer(QString,quint16,QByteArray,QByteArray)));
    QObject::connect(this, SIGNAL(SIG_UploadFile(ECMDTYPE,EFILEITEM,QByteArray)), this, SLOT(SLOT_UploadFile(ECMDTYPE,EFILEITEM,QByteArray)));

    QObject::connect(this, SIGNAL(SIG_AppBackup(int)), this, SLOT(SLOT_AppBackup(int)));
    QObject::connect(this, SIGNAL(SIG_AppReset()), this, SLOT(SLOT_AppReset()));
    QObject::connect(this, SIGNAL(SIG_AppUpdate(int)), this, SLOT(SLOT_AppUpdate(int)));
    QObject::connect(this, SIGNAL(SIG_AppUpload(int)), this, SLOT(SLOT_AppUpload(int)));
    QObject::connect(this, SIGNAL(SIG_SysReset()), this, SLOT(SLOT_SysReset()));
    QObject::connect(this, SIGNAL(SIG_SysUpdate()), this, SLOT(SLOT_SysUpdate()));

    QObject::connect(this, SIGNAL(SIG_ClearAlarm()), this, SLOT(SLOT_ClearAlarm()));

    QObject::connect(this, SIGNAL(SIG_AdjustXY(QString)), this, SLOT(SLOT_AdjustXY(QString)));
    QObject::connect(this, SIGNAL(SIG_CommandExcute(QString)), this, SLOT(SLOT_CommandExcute(QString)));

}

void IVFDMainWidget::CreateEnviorment()
{
    m_timeStamp = 0;
    m_status[0] = 0;
    m_status[1] = 0;
    //声明命令数组
    m_settings = new QSettings(this);
    QFile inifile(IVFDINIT_INI);

    if(!inifile.exists())
    {
        QLog_("init", ErrorLevel, QString("IVFDINIT_INI not exisit"));
        qDebug() << "1 In IVFDMainWidget::InitThis ---inifile not exist";
        return;
    }

    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);

    initsetting.beginGroup("command");
    QStringList keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        if(initsetting.value(key) != false)
        {
            m_cmdlist.append(key);
            qDebug() << key;
        }
    }
    initsetting.endGroup();

    m_cmdlist.sort();

    initsetting.beginGroup("cameraset");
    keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        qDebug() << key << "-----" << initsetting.value(key);
    }
    initsetting.endGroup();

    initsetting.beginGroup("status");
    keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        qDebug() << key << "-----" << initsetting.value(key);
    }
    initsetting.endGroup();
}



void IVFDMainWidget::SLOT_SysReset()
{
    m_processSystem->start("reboot");
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "reboot system error!";
        QLog_("reset", ErrorLevel, QString("reboot system error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
}
void IVFDMainWidget::SLOT_AppReset()
{
    emit SIG_KillProcessMain();
    emit SIG_StopProcessHttpServer();
    emit SIG_StopProcessRtsp();
    emit SIG_StopProcessFtp();
}
void IVFDMainWidget::SLOT_SysUpdate()
{

}

//0 = dip; 1 = http; 2 = ftp; 3 = rtsp; 4 = firealgcfg; 5 = smokealgcfg; 6 = ivfdinit ; 7 = autenfile;
void IVFDMainWidget::SLOT_AppUpdate(int fileid)
{
    //kill the all application without restart them
//    emit SIG_KillMainSelf();
    m_updatestatus = 1;

    qDebug() << "fileid=" << fileid;
    switch (fileid){
    case 0:{//dip update
        //kill the applications
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        emit SIG_KillProcessMain();
        QThread::msleep(100);
        m_processSystem->start(UPDATEDVR_SH);
        break;
    }
    case 1:{//http
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        emit SIG_StopProcessHttpServer();
        QThread::msleep(100);
        m_processSystem->start(UPDATEHTTP_SH);
//        if(InitFileExist("/ftproot/IVFDHttpServer")){
//            QStringList m_processargs;
//            m_processargs << "/ftproot/IVFDHttpServer" << "/IVFDHttpServer";
//            m_processSystem->start("cp", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - cp httpserver start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no new IVFDHttpServer exisit.";
//        }

//        if(InitFileExist("/IVFDHttpServer")){
//            QStringList m_processargs;
//            m_processargs << "777" << "IVFDHttpServer";
//            m_processSystem->start("chmod", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - chmod IVFDHttpServer start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no IVFDHttpServer exisit.";
//        }
        break;
    }
    case 2:{//ftp
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        emit SIG_StopProcessFtp();
        QThread::msleep(100);
        m_processSystem->start(UPDATEFTP_SH);
//        if(InitFileExist("/ftproot/IVFDFtpServer")){
//            QStringList m_processargs;
//            m_processargs << "/ftproot/IVFDFtpServer" << "/IVFDFtpServer";
//            m_processSystem->start("cp", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - cp ftpserver start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no new IVFDFtpServer exisit.";
//        }
//        if(InitFileExist("/IVFDFtpServer")){
//            QStringList m_processargs;
//            m_processargs << "777" << "IVFDFtpServer";
//            m_processSystem->start("chmod", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - chmod IVFDHttpServer start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no IVFDFtpServer exisit.";
//        }
        break;
    }
    case 3:{//rtsp
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        emit SIG_StopProcessRtsp();
        QThread::msleep(100);
        m_processSystem->start(UPDATERTSP_SH);
//        if(InitFileExist("/ftproot/rtsp-second.out")){
//            QStringList m_processargs;
//            m_processargs << "/ftproot/rtsp-second.out" << "/rtsp-second.out";
//            m_processSystem->start("cp", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - cp rtsp-second.out start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no new rtsp-second.out exisit.";
//        }
//        if(InitFileExist("/rtsp-second.out")){
//            QStringList m_processargs;
//            m_processargs << "777" << "rtsp-second.out";
//            m_processSystem->start("chmod", m_processargs);
//            if(!m_processSystem->waitForStarted()){
//                QLog_("update", ErrorLevel, QString("update file - chmod rtsp-second.out start error!"));
//            }else{
//                m_processSystem->closeWriteChannel();
//                QByteArray m_processOutput;
//                if(m_processSystem->waitForStarted(-1)){
//                    while(m_processSystem->waitForReadyRead(-1)){
//                        m_processOutput = m_processSystem->readAllStandardOutput();
//                    }
//                }
//            }
//            m_processSystem->close();
//        }else{
//            qDebug() << "no rtsp-second.out exisit.";
//        }
        break;
    }
    case 4:{//algfirecfg
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        if(InitFileExist(IVFDALGFIRE_INI)){
            QStringList m_processargs;
            m_processargs << IVFDALGFIRE_INI << IVFDALGFIREBAK_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                QLog_("update", ErrorLevel, QString("update file - cp ivfdalgfire.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }else{
            qDebug() << "no new ivfdalgfire.ini exisit.";
        }
        break;
    }
    case 5:{//algsmokecfg
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        if(InitFileExist("/ftproot/ivfdalgsmoke.ini")){
            QStringList m_processargs;
            m_processargs << FTPROOT_IVFDALGSMOKE_INI << IVFDALGSMOKE_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                QLog_("update", ErrorLevel, QString("update file - cp ivfdalgsmoke.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }else{
            qDebug() << "no new ivfdalgsmoke.ini exisit.";
        }
        break;
    }
    case 6:{//ivfdinit.ini
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        if(InitFileExist(FTPROOT_IVFDINIT_INI)){
            QStringList m_processargs;
            m_processargs << FTPROOT_IVFDINIT_INI << IVFDINIT_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                QLog_("update", ErrorLevel, QString("update file - cp ivfdinit.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }else{
            qDebug() << "no new ivfdinit.ini exisit.";
        }
        break;
    }
    case 7:{//authenfile.ini
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        if(InitFileExist(FTPROOT_AUTHENFILE_INI)){
            QStringList m_processargs;
            m_processargs << FTPROOT_AUTHENFILE_INI << IVFDAUTHEN_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                QLog_("update", ErrorLevel, QString("update file - cp authenfile.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }else{
            qDebug() << "no new authenfile.ini exisit.";
        }
        break;
    }
    case 8:{//IVFDMain,just set update=1
        qDebug() << "1 IVFDMainWidget::SLOT_AppUpdate:m_updatestatus = " << m_updatestatus;
        if(InitFileExist(MAINMODULE_INI)){
            QVariant keyval;
            GetCFG("mainmodule.ini", "update", "update", &keyval);
            if(keyval.toInt() == 0){
                modifyInitFile("mainmodule.ini","update=","update=1", lock);
            };

        }else{
            qDebug() << "no mainmodule.ini exisit.";
        }
        break;
    }
    }

    qDebug() << "All update finished!";
//    m_updatestatus = 0;
}

//0 = dip; 1 = http; 2 = ftp; 3 = rtsp; 4 = firealgcfg; 5 = smokealgcfg; 6 = ivfdinit ; 7 = autenfile;
void IVFDMainWidget::SLOT_AppBackup(int fileid)
{
    qDebug() << "fileid=" << fileid;
    switch (fileid){
    case 0:{//dip update
        if(InitFileExist(DVRUI_EXE)){
            QStringList m_processargs;
            m_processargs << DVRUI_EXE << DVRUIBAK_EXE;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp DvrUI_n error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp DvrUI_n start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
        break;
    }
    case 1:{//http
        if(InitFileExist(HTTP_EXE)){
            QStringList m_processargs;
            m_processargs << HTTP_EXE << HTTPBAK_EXE;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                qDebug() << "cp IVFDHttpServer error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp httpserver start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
        break;
    }
    case 2:{//ftp
        if(InitFileExist(FTP_EXE)){
            QStringList m_processargs;
            m_processargs << FTP_EXE << FTPBAK_EXE;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp ftpserver error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp ftpserver start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
        break;
    }
    case 3:{//rtsp
        if(InitFileExist(RTSP_EXE)){
            QStringList m_processargs;
            m_processargs << RTSP_EXE << RTSPBAK_EXE;
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp rtsp-second.out error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp rtsp-second.out start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
//        m_processargs << "rtsp-second.out" << ftpserver;
        break;
    }
    case 4:{//algfirecfg
        if(InitFileExist(IVFDALGFIRE_INI)){
            QStringList m_processargs;
            m_processargs << IVFDALGFIRE_INI << IVFDALGFIREBAK_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp ivfdalgfire.ini error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp ivfdalgfire.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
//        m_processargs << "ivfdalgfire.ini" << ftpserver;
        break;
    }
    case 5:{//algsmokecfg
        if(InitFileExist(IVFDALGSMOKE_INI)){
            QStringList m_processargs;
            m_processargs << IVFDALGSMOKE_INI << IVFDALGSMOKEBAK_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp ivfdalgsmoke.ini error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp ivfdalgsmoke.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
//        m_processargs << "ivfdalgsmoke.ini" << ftpserver;
        break;
    }
    case 6:{//ivfdinit.ini
        if(InitFileExist(IVFDINIT_INI)){
            QStringList m_processargs;
            m_processargs << IVFDINIT_INI << IVFDINITBAK_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp ivfdinit.ini error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp ivfdinit.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
//        m_processargs << "ivfdinit.ini" << ftpserver;
        break;
    }
    case 7:{//authenfile.ini
        if(InitFileExist(IVFDAUTHEN_INI)){
            QStringList m_processargs;
            m_processargs << IVFDAUTHEN_INI << IVFDAUTHENBAK_INI;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
    //            qDebug() << "cp authenfile.ini error!";
                QLog_("backup", ErrorLevel, QString("backup file - cp authenfile.ini start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
//        m_processargs << "authenfile.ini" << ftpserver;
        break;
    }
    case 8:{//IVFDMain
        if(InitFileExist(MAIN_EXE)){
            QStringList m_processargs;
            m_processargs << MAIN_EXE << MAINBAK_EXE;
            m_processSystem->start("cp", m_processargs);
            if(!m_processSystem->waitForStarted()){
                QLog_("backup", ErrorLevel, QString("backup file - cp IVFDMain start error!"));
            }else{
                m_processSystem->closeWriteChannel();
                QByteArray m_processOutput;
                if(m_processSystem->waitForStarted(-1)){
                    while(m_processSystem->waitForReadyRead(-1)){
                        m_processOutput = m_processSystem->readAllStandardOutput();
                    }
                }
            }
            m_processSystem->close();
        }
        break;
    }
    }
}

//0 = dip; 1 = http; 2 = ftp; 3 = rtsp; 4 = firealgcfg; 5 = smokealgcfg; 6 = ivfdinit ; 7 = autenfile;
void IVFDMainWidget::SLOT_AppUpload(int fileid)
{
//do nothing ,from client copy app to ftproot.

    QStringList m_processargs;
    QVariant keyval;
    GetCFG(IVFDINIT_INI, "netconfig", "ftpserver",&keyval);
    QString ftpserver = keyval.toString();
    qDebug() << "fileid=" << fileid;
    switch (fileid){
    case 0:{//dip update
        m_processargs << "DvrUI_n" << ftpserver;
        break;
    }
    case 1:{//http
        m_processargs << "IVFDHttpServer" << ftpserver;
        break;
    }
    case 2:{//ftp
        m_processargs << "IVFDFtpServer" << ftpserver;
        break;
    }
    case 3:{//rtsp
        m_processargs << "rtsp-second.out" << ftpserver;
        break;
    }
    case 4:{//algfirecfg
        m_processargs << "ivfdalgfire.ini" << ftpserver;
        break;
    }
    case 5:{//algsmokecfg
        m_processargs << "ivfdalgfire.ini" << ftpserver;
        break;
    }
    case 6:{//ivfdinit.ini
        m_processargs << "ivfdinit.ini" << ftpserver;
        break;
    }
    case 7:{//authenfile.ini
        m_processargs << "authenfile.ini" << ftpserver;
        break;
    }
    case 8:{
        m_processargs << "IVFDMain" << ftpserver;
        break;
    }
    }

    m_processSystem->start(UPLOADFILE_SH, m_processargs);
    if(!m_processSystem->waitForStarted()){
//        qDebug() << "upload file error!";
        QLog_("upload", ErrorLevel, QString("upload file uploadfile.sh start error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();
}

void IVFDMainWidget::SLOT_ClearAlarm()
{
    gpio_setstate(GPIO_OUTLED1, 1, 0);
    gpio_setstate(GPIO_OUTLED2, 1, 0);
    gpio_setstate(GPIO_OUTLED3, 1, 1);
    gpio_setstate(GPIO_OUTBUZZ, 1, 0);
    gpio_setstate(GPIO_RELAYOUT1, 1, REVERSE);
//    IVFDRunnable *myRunnable = new IVFDRunnable();
//    myRunnable->SIG_Runnable(GPIO_ALL, CLEARALARMIO, 0, 0);
//    myRunnable->setAutoDelete(true);
//    GlobalThreadPool->start(myRunnable);

//    IVFDRunnable *myRunnableBuzzer = new IVFDRunnable();
//    myRunnableBuzzer->SIG_Runnable(GPIO_OUTBUZZ, OFF, 0, 0);
//    myRunnableBuzzer->setAutoDelete(true);
//    GlobalThreadPool->start(myRunnableBuzzer);

//    IVFDRunnable *myRunnableRelay = new IVFDRunnable();
//    myRunnableRelay->SIG_Runnable(GPIO_RELAYOUT1, OFF, 0, 0);
//    myRunnableRelay->setAutoDelete(true);
//    GlobalThreadPool->start(myRunnableRelay);
}

void IVFDMainWidget::SLOT_AdjustXY(QString adj)
{
    QString adjitem = adj.split("=").at(0);
    QVariant keyval;
    int adjval = adj.split("=").at(1).toInt();
    if(adjitem == "xinc"){
        GetCFG(IVFDINIT_INI, "status", "posoffsetx", &keyval);
        int newval = keyval.toInt()+adjval;
        modifyInitFile(IVFDINIT_INI, "posoffsetx=", QString("posoffsetx=%1").arg(newval), lock);
    }else if(adjitem == "xdec"){
        GetCFG("/ivfdinit.ini", "status", "posoffsetx", &keyval);
        int newval = keyval.toInt()-adjval;
        modifyInitFile(IVFDINIT_INI, "posoffsetx=", QString("posoffsetx=%1").arg(newval), lock);

    }else if(adjitem == "yinc"){
        GetCFG(IVFDINIT_INI, "status", "posoffsety", &keyval);
        int newval = keyval.toInt()+adjval;
        modifyInitFile(IVFDINIT_INI, "posoffsety=", QString("posoffsety=%1").arg(newval), lock);
    }else if(adjitem == "ydec"){
        GetCFG(IVFDINIT_INI, "status", "posoffsety", &keyval);
        int newval = keyval.toInt()-adjval;
        modifyInitFile(IVFDINIT_INI, "posoffsety=", QString("posoffsety=%1").arg(newval), lock);
    }

}


void IVFDMainWidget::SLOT_Offline(bool online)
{
    if(online == true){
        if(gpio_getstate(GPIO_OUTLED1, 0) == 0){
//                qDebug() << "1 IVFDTcpClient::SLOT_NewConnect: GPIO_OUTLED1 read = 0" << online;
        }else{//ERROR
//                qDebug() << "1 IVFDTcpClient::SLOT_NewConnect: GPIO_OUTLED1 read = 1" << online;
            gpio_setstate(GPIO_OUTLED1, 1, 0);
            gpio_setstate(GPIO_RELAYOUT2, 1, KEEP);
//            IVFDRunnable *myRunnable = new IVFDRunnable();
//            myRunnable->SIG_Runnable(GPIO_RELAYOUT2, KEEP, 0, 0);
//            myRunnable->setAutoDelete(true);
//            GlobalThreadPool->start(myRunnable);
        }
    }else{
        gpio_setstate(GPIO_OUTLED1, 1 ,1);
//        IVFDRunnable *myRunnable1 = new IVFDRunnable();
//        myRunnable1->SIG_Runnable(GPIO_RELAYOUT2, REVERSE, 0, 0);
//        myRunnable1->setAutoDelete(true);
//        GlobalThreadPool->start(myRunnable1);
        gpio_setstate(GPIO_RELAYOUT2, 1, REVERSE);
    }
}


void IVFDMainWidget::SLOT_CommandExcute(QString cmd)
{
    qDebug() << "1 IVFDMainWidget::SLOT_CommandExcute: cmd to excute is:" << cmd;
    if(cmd == "closemain"){
        this->close();
    }
    QStringList cmdstrlist = cmd.split(" ");
    if(cmdstrlist.isEmpty()){
        return;
    }
    QStringList arglist;
    int len = cmdstrlist.length();
    qDebug() << "len = " << len;
    for(int i = 1; i < len; i++){
        arglist << cmdstrlist.at(i);
    }

    m_processSystem->start(cmdstrlist.at(0), arglist);
    if(!m_processSystem->waitForStarted()){
        QLog_("main", ErrorLevel, QString(cmd).append(" excute error!"));
    }else{
        m_processSystem->closeWriteChannel();
        QByteArray m_processOutput;
        if(m_processSystem->waitForStarted(-1)){
            while(m_processSystem->waitForReadyRead(-1)){
                m_processOutput = m_processSystem->readAllStandardOutput();
            }
        }
    }
    m_processSystem->close();

}
