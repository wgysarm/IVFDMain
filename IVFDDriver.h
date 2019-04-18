#ifndef IVFDDRIVER_H
#define IVFDDRIVER_H


#include <QThread>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QSettings>
#include <QList>
#include <QNetworkInterface>
#include <QNetworkConfigurationManager>
#include <QHostAddress>
#include <QHostInfo>
#include <QTcpSocket>
#include <QVariant>
#include <QByteArray>
#include <QReadWriteLock>
#include <QTcpSocket>

#define GPIO_TEST 1
#define GPIO_SDCDPIN 238 //PH14 sd cd pin
#define GPIO_OUTLED1 237 //PH13 YELLOW
#define GPIO_OUTLED2 239 //PH15 RED
#define GPIO_OUTLED3 240 //PH16 GREEN
#define GPIO_OUTBUZZ 244 //PH20
#define GPIO_ALL 1 //ALL GPIO

#define GPIO_RELAYOUT1 241 //PH17  origin open, R15 remain, R14 delete ALARM RELAY1
#define GPIO_RELAYOUT2 242 //PH18VENT, TOOLIGHT, TOODARK, FIREDET, VLOST}; origin close, init open, R16 remain, R17 delete RELAY2 ERROR

#define AUTORUN_SH "/autorun.sh"
#define FTPROOTDIR "/ftproot/"


//#define UPLOADFILE_SH "/data/uploadfile.sh"
//#define SCANPS_SH "/data/scanps.sh"
//#define RESNMPD_SH "/data/resnmpd.sh"
//#define TIMESYNC_SH "/data/timesync.sh"
//#define UPDATEDVR_SH "/data/updatedvr.sh"
//#define UPDATEHTTP_SH "/data/updatehttp.sh"
//#define UPDATEFTP_SH "/data/updateftp.sh"
//#define UPDATERTSP_SH "/data/updatertsp.sh"
//#define UPLOADMAIN_SH "/data/uploadmain.sh"

//#define IVFDINIT_INI "/data/ivfdinit.ini"
//#define IVFDINITBAK_INI "/data/ftproot/ivfdinitbak.ini"
//#define IVFDALGFIRE_INI "/data/ivfdalgfire.ini"
//#define IVFDALGFIREBAK_INI "/data/ftproot/ivfdalgfirebak.ini"
//#define IVFDALGSMOKE_INI "/data/ivfdalgsmoke.ini"
//#define IVFDALGSMOKEBAK_INI "/data/ftproot/ivfdalgsmokebak.ini"
//#define ALGFIRECFG_INI "/data/algfireconfig.ini"
//#define ALGFIRECFGBAK_INI "/data/ftproot/algfireconfigbak.ini"
//#define IVFDAUTHEN_INI "/data/ivfdauthen.ini"
//#define IVFDAUTHENBAK_INI "/data/ftproot/ivfdauthenbak.ini"

//#define MAINMODULE_INI "/data/mainmodule.ini"
//#define CAMERACHANGE_INI "/data/camerachange.ini"
//#define SCANFS_INI "/data/scanfs.ini"

//#define DVRUI_EXE "/data/DvrUI_n"
//#define DVRUIBAK_EXE "/data/ftproot/DvrUI_nbak"
//#define HTTP_EXE "/data/IVFDHttpServer"
//#define HTTPBAK_EXE "/data/ftproot/IVFDHttpServerbak"
//#define FTP_EXE "/data/IVFDFtpServer"
//#define FTPBAK_EXE "/data/ftproot/IVFDFtpServerbak"
//#define RTSP_EXE "/data/rtsp-second.out"
//#define RTSPBAK_EXE "/data/ftproot/rtsp-secondbak.out"
//#define MAIN_EXE "/data/IVFDMain"
//#define MAINBAK_EXE "/data/ftproot/IVFDMainbak"

//#define FTPROOT_IVFDINIT_INI "/data/ftproot/ivfdinit.ini"
//#define FTPROOT_IVFDALGSMOKE_INI "/data/ftproot/ivfdalgsmoke.ini"
//#define FTPROOT_IVFDALGFIRE_INI "/data/ftproot/ivfdalgfire.ini"
//#define FTPROOT_AUTHENFILE_INI "/data/ftproot/authenfile.ini"


#define UPLOADFILE_SH "/uploadfile.sh"
#define SCANPS_SH "/scanps.sh"
#define RESNMPD_SH "/resnmpd.sh"
#define TIMESYNC_SH "/timesync.sh"
#define UPDATEDVR_SH "/updatedvr.sh"
#define UPDATEHTTP_SH "/updatehttp.sh"
#define UPDATEFTP_SH "/updateftp.sh"
#define UPDATERTSP_SH "/updatertsp.sh"
#define UPLOADMAIN_SH "/uploadmain.sh"

#define IVFDINIT_INI "/ivfdinit.ini"
#define IVFDINITBAK_INI "/ftproot/ivfdinitbak.ini"
#define IVFDALGFIRE_INI "/ivfdalgfire.ini"
#define IVFDALGFIREBAK_INI "/ftproot/ivfdalgfirebak.ini"
#define IVFDALGSMOKE_INI "/ivfdalgsmoke.ini"
#define IVFDALGSMOKEBAK_INI "/ftproot/ivfdalgsmokebak.ini"
#define ALGFIRECFG_INI "/algfireconfig.ini"
#define ALGFIRECFGBAK_INI "/ftproot/algfireconfigbak.ini"
#define IVFDAUTHEN_INI "/ivfdauthen.ini"
#define IVFDAUTHENBAK_INI "/ftproot/ivfdauthenbak.ini"

#define MAINMODULE_INI "/mainmodule.ini"
#define CAMERACHANGE_INI "/camerachange.ini"
#define SCANFS_INI "/scanfs.ini"

#define DVRUI_EXE "/DvrUI_n"
#define DVRUIBAK_EXE "/ftproot/DvrUI_nbak"
#define HTTP_EXE "/IVFDHttpServer"
#define HTTPBAK_EXE "/ftproot/IVFDHttpServerbak"
#define FTP_EXE "/IVFDFtpServer"
#define FTPBAK_EXE "/ftproot/IVFDFtpServerbak"
#define RTSP_EXE "/rtsp-second.out"
#define RTSPBAK_EXE "/ftproot/rtsp-secondbak.out"
#define MAIN_EXE "/IVFDMain"
#define MAINBAK_EXE "/ftproot/IVFDMainbak"

#define FTPROOT_IVFDINIT_INI "/ftproot/ivfdinit.ini"
#define FTPROOT_IVFDALGSMOKE_INI "/ftproot/ivfdalgsmoke.ini"
#define FTPROOT_IVFDALGFIRE_INI "/ftproot/ivfdalgfire.ini"
#define FTPROOT_AUTHENFILE_INI "/ftproot/authenfile.ini"



enum GPIOTERM{RED, GREEN, YELLOW, RELAY1, RELAY2, BUZZER};
enum GPIOSTATUS{ON, OFF, FLASH, FLASHON, FLASHOFF, ALARMIO, CLEARALARMIO, INITALL1, INITALL2, INITALL3};
enum RELAYSTATUS{KEEP, REVERSE};

typedef struct CmdActiveX{
    int cmdtype;
    int cmdval;
    char cmdstr[128];
}CmdActiveX;


int gpio_export(int pin);
int gpio_unexport(int pin);

int gpio_direction(int pin, int dir);
int gpio_write(int pin, int value);
int gpio_read(int pin);
int gpio_edge(int pin, int edge);
int gpio_test();
void gpio_setstate(int pinnum, int derection, int val);
int gpio_getstate(int pinnum, int derection);

int InitFileExist(QString filepath);
int modifyAutoRunFile(QString filename, QString findstr, QString altstr, QReadWriteLock &lock);
int modifyInitFile(QString filename, QString findstr, QString altstr, QReadWriteLock &lock);
int GetCFG(QString filename, QString mainkey, QString subkey, QVariant *subkeyval);
QString Get_NetMask();
QString Get_HostIpAddress();
QString Get_LocalMachine();
//bool Get_StatusOnline(void *socket, bool *online);
int SetEnviroment(QString mainkey, QString subkey, QVariant subkeyval);
int GetEnviroment(QString mainkey, QString subkey, QVariant *subkeyval);

int ConvertMsgToByteArray(QString *msg, QByteArray *bytearray, int cmdtype, int cmdval);
int GetAnswerRegistString(QString *msg);

void ControlGPIODev(int dev, enum GPIOSTATUS state, int ms, int cnt);
#endif // IVFDDRIVER_H

