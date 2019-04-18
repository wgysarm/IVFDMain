#include "IVFDDriver.h"
#include "IvfdLogger.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include <unistd.h>
#include <QDebug>

using namespace IvfdLogNameSpace;

#ifdef GPIO_TEST
//added by hxy


enum GPIOVAL{LOW, HIGH};
//函数声明
int gpio_export(int pin)
{
    char buffer[64];
    int len;
    int fd;

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
//        LOGE("Failed to open export for writing!\n");
        return(-1);
    }

    len = snprintf(buffer, sizeof(buffer), "%d", pin);
    if (write(fd, buffer, len) < 0) {
//        LOGE("Failed to export gpio!");
        return -1;
    }
    qDebug() << "gpio_export";
    close(fd);
    return 0;
}

int gpio_unexport(int pin)
{
    char buffer[64];
    int len;
    int fd;

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
//        LOGE("Failed to open unexport for writing!\n");
        return -1;
    }

    len = snprintf(buffer, sizeof(buffer), "%d", pin);
    if (write(fd, buffer, len) < 0) {
//        LOGE("Failed to unexport gpio!");
        return -1;
    }

    close(fd);
    return 0;
}

//dir: 0-->IN, 1-->OUT
int gpio_direction(int pin, int dir)
{
    static const char dir_str[] = "in\0out";
    char path[64];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
//        LOGE("Failed to open gpio direction for writing!\n");
        return -1;
    }

    if (write(fd, &dir_str[dir == 0 ? 0 : 3], dir == 0 ? 2 : 3) < 0) {
//        LOGE("Failed to set direction!\n");
        return -1;
    }
//    qDebug() << "gpio_direction";
    close(fd);
    return 0;
}

//value: 0-->LOW, 1-->HIGH
int gpio_write(int pin, int value)
{
    static const char values_str[] = "01";
    char path[64];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
//        LOGE("Failed to open gpio value for writing!\n");
        return -1;
    }

    if (write(fd, &values_str[value == 0 ? 0 : 1], 1) < 0) {
//        LOGE("Failed to write value!\n");
        return -1;
    }
//    qDebug() << "gpio_write";
    close(fd);
    return 0;
}

int gpio_read(int pin)
{
    char path[64];
    char value_str[3];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (fd < 0) {
//        LOGE("Failed to open gpio value for reading!\n");
        return -1;
    }

    if (read(fd, value_str, 3) < 0) {
//        LOGE("Failed to read value!\n");
        return -1;
    }

    close(fd);
    return (atoi(value_str));
}

// none表示引脚为输入，不是中断引脚
// rising表示引脚为中断输入，上升沿触发
// falling表示引脚为中断输入，下降沿触发
// both表示引脚为中断输入，边沿触发
// 0-->none, 1-->rising, 2-->falling, 3-->both
int gpio_edge(int pin, int edge)
{
    const char dir_str[] = "none\0rising\0falling\0both";
    char ptr;
    char path[64];
    int fd;
    switch(edge){
    case 0:
        ptr = 0;
        break;
    case 1:
        ptr = 5;
        break;
    case 2:
        ptr = 12;
        break;
    case 3:
        ptr = 20;
        break;
    default:
        ptr = 0;
    }

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/edge", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
//        LOGE("Failed to open gpio edge for writing!\n");
        return -1;
    }

    if (write(fd, &dir_str[ptr], strlen(&dir_str[ptr])) < 0) {
//        LOGE("Failed to set edge!\n");
        return -1;
    }

    close(fd);
    return 0;
}

int gpio_test()
{
    int gpio_fd, ret;
    struct pollfd fds[1];
    char buff[10];
    unsigned char cnt = 0;
    char path[64];
    //LED引脚初始化
    for(int i = 0; i < 5; i++)
    {
        gpio_export(GPIO_OUTLED1);
        gpio_direction(GPIO_OUTLED1, 1);
        gpio_write(GPIO_OUTLED1, 1);
        gpio_export(GPIO_OUTLED2);
        gpio_direction(GPIO_OUTLED2, 1);
        gpio_write(GPIO_OUTLED2, 1);
        gpio_export(GPIO_OUTLED3);
        gpio_direction(GPIO_OUTLED3, 1);
        gpio_write(GPIO_OUTLED3, 1);
        QThread::msleep(500);
        gpio_write(GPIO_OUTLED1, 0);
        gpio_write(GPIO_OUTLED2, 0);
        gpio_write(GPIO_OUTLED3, 0);
    }
    gpio_write(GPIO_OUTLED2, 1);
    gpio_write(GPIO_OUTLED3, 1);

    gpio_export(GPIO_OUTBUZZ);
    gpio_direction(GPIO_OUTBUZZ, 1);
    gpio_write(GPIO_OUTBUZZ, 0);
    QThread::msleep(1000);
    gpio_write(GPIO_OUTBUZZ, 1);
    gpio_export(GPIO_RELAYOUT1);
    gpio_direction(GPIO_RELAYOUT1, 1);
    gpio_write(GPIO_RELAYOUT1, 0);
    gpio_export(GPIO_RELAYOUT2);
    gpio_direction(GPIO_RELAYOUT2, 1);
    gpio_write(GPIO_RELAYOUT2, 1);

#if 0//中断测试部分
    //按键引脚初始化
    gpio_export(GPIO_EXAMPLE_INT);
    gpio_direction(GPIO_EXAMPLE_INT, 0);
    gpio_edge(GPIO_EXAMPLE_INT,1);


    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", GPIO_EXAMPLE_INT);
    gpio_fd = open(path,O_RDONLY);
    if(gpio_fd < 0){
        LOGE("Failed to open %s!\n", path);
        return -1;
    }
    fds[0].fd = gpio_fd;
    fds[0].events = POLLPRI;
    ret = read(gpio_fd,buff,10);
    if( ret == -1 )	LOGE("read\n");
    while(1){
        ret = poll(fds,1,0);
        if( ret == -1 )		LOGE("poll\n");

        if( fds[0].revents & POLLPRI)
        {
            ret = lseek(gpio_fd,0,SEEK_SET);
            if( ret == -1 )		LOGE("lseek\n");


            ret = read(gpio_fd,buff,10);
            if( ret == -1 )		LOGE("read\n");

            gpio_write(GPIO_EXAMPLE_OUT, cnt++%2);
        }
        usleep(100000);
    }
    return 0;
#endif
}
//end
#endif



void gpio_setstate(int pinnum, int derection, int val)
{
    int pin = pinnum;
    gpio_export(pin);
    gpio_direction(pin, derection);
    gpio_write(pin, val);//silence
}

int gpio_getstate(int pinnum, int derection)
{
    int pin = pinnum;
    gpio_export(pin);
    gpio_direction(pin, derection);
    return gpio_read(pin);
}


void ControlGPIODev(int dev, enum GPIOSTATUS state, int ms, int cnt = 10){
    enum GPIOSTATUS sta = state;
    switch (sta)
    {
    case ON:
    {
        gpio_setstate(dev, 1, 1);//1 for output, 1 for turn on light;
        //        QThread::msleep(ms);
        //        gpio_setstate(dev, 1, 0);//1 for output, 0 for low off;
        break;
    }
    case OFF:
    {
        gpio_setstate(dev, 1, 0);//1 for output, 0 for turn off light;
        break;
    }
    case FLASH:
    {
        for(int i = 0 ; i < cnt; ++i){
            gpio_setstate(dev, 1, 1);//1 for output, 1 for high light;
            QThread::msleep(ms);
            gpio_setstate(dev, 1, 0);//1 for output, 0 for low off;
            QThread::msleep(ms);
        }
        break;
    }
    case FLASHOFF:
    {
        cnt = (cnt > 10)?10:cnt;
        for(int i = 0 ; i < cnt; ++i){
            gpio_setstate(dev, 1, 1);//1 for output, 1 for high light;
            QThread::msleep(ms);
            gpio_setstate(dev, 1, 0);//1 for output, 0 for low off;
            QThread::msleep(ms);
        }
        gpio_setstate(dev, 1, 0);//1 for output, 1 for high light;
    }
    case FLASHON:
    {
        cnt = (cnt > 10)?10:cnt;
        for(int i = 0 ; i < cnt; ++i){
            gpio_setstate(dev, 1, 1);//1 for output, 1 for high light;
            QThread::msleep(ms);
            gpio_setstate(dev, 1, 0);//1 for output, 0 for low off;
            QThread::msleep(ms);
        }
        gpio_setstate(dev, 1, 1);//1 for output, 1 for high light;
    }
    case ALARMIO:
    {
//        cnt = (cnt > 10)?10:cnt;
//        for(int i = 0 ; i < cnt; ++i){
//            gpio_setstate(GPIO_OUTLED2, 1, 1);//1 for output, 1 for high light;
//            QThread::msleep(ms);
//            gpio_setstate(GPIO_OUTLED2, 1, 0);//1 for output, 0 for low off;
//            QThread::msleep(ms);
//        }
        gpio_setstate(GPIO_OUTLED2, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTBUZZ, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT1, 1, REVERSE);//1 for output, 1 for high light; DEFAULT OPEN, 1 = REVERSE

    }
    case CLEARALARMIO:
    {
        gpio_setstate(GPIO_OUTLED1, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED2, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED3, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTBUZZ, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT1, 1, KEEP);//1 for output, 1 for high light;
    }
    case INITALL1:
    {
        gpio_setstate(GPIO_OUTLED1, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED2, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED3, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTBUZZ, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT1, 1, KEEP);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT2, 1, REVERSE);//1 for output, 1 for high light;//origin close, should reverse to open OPENL MEANS NO REVERSE
    }
    case INITALL2:
    {
        gpio_setstate(GPIO_OUTLED1, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED2, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED3, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTBUZZ, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT1, 1, KEEP);//1 for output, 1 for high light; alarm open
        gpio_setstate(GPIO_RELAYOUT2, 1, REVERSE);//1 for output, 1 for high light; error close,reverse
    }
    case INITALL3:
    {
        gpio_setstate(GPIO_OUTLED1, 1, 1);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED2, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTLED3, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_OUTBUZZ, 1, 0);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT1, 1, KEEP);//1 for output, 1 for high light;
        gpio_setstate(GPIO_RELAYOUT2, 1, KEEP);//1 for output, 1 for high light;
    }
    }
}

int InitFileExist(QString filepath)
{
    QFile inifile(filepath);

    if(!inifile.exists())
    {
        QLog_("init", ErrorLevel, filepath.append((QString("not exisit"))));
        qDebug() << filepath <<  " not exist";
        return 0;
    }else
    {
        return 1;
    }
}


int modifyAutoRunFile(QString filename, QString findstr, QString altstr, QReadWriteLock &lock)
{
    if(!InitFileExist(QString(AUTORUN_SH)))
    {
        return 0;
    }

    QFile fileHardConfigHtml(filename);
    if(!fileHardConfigHtml.exists())
    {
        return 0;
    }

    if(!fileHardConfigHtml.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return 0;
    }

    QString strAll;
    QStringList strList;

    QFile readFile(filename);
    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&readFile);
        stream.setCodec(QTextCodec::codecForName("UTF-8"));
        lock.lockForRead();
        strAll = stream.readAll();
//        qDebug() << strAll;
        lock.unlock();
        strList = strAll.split("\n");
//        qDebug() << "1 strList.length is:" << strList.length();
        for(int i = 0; i < strList.length(); i++)
        {
//            qDebug() << strList.at(i);
        }
    }
    readFile.close();

    qDebug() << "1 modifyAutoRunFile:now begin to write the autorun.sh";
    QFile writeFile(filename);
    if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream stream(&writeFile);
        stream.setCodec(QTextCodec::codecForName("UTF-8"));
//        strList=strAll.split("\n");
        qDebug() << "2 strList.length is:" << strList.length();
        lock.lockForWrite();
        for(int i = 0;i < strList.length();i++)
        {
            QString tempStr = strList.at(i);

            if(strList.at(i).contains(findstr) && i!= strList.length()-1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                tempStr = altstr;
                stream << tempStr << '\n';
//                i+=1;
            }else if(strList.at(i).contains(findstr) && i == strList.length() - 1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                tempStr = altstr;
                stream << tempStr;
            }else if(!strList.at(i).contains(findstr) && i != strList.length() -1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                stream << tempStr << '\n';
            }else if(!strList.at(i).contains(findstr) && i == strList.length() -1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                stream << tempStr ;
            }
        }
        lock.unlock();
    }
    writeFile.close();

    return 1;
}


int modifyInitFile(QString filename, QString findstr, QString altstr, QReadWriteLock &lock)
{
    QFile IniFile(filename);
    if(!IniFile.exists())
    {
        return 0;
    }

    if(!IniFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return 0;
    }

    QString strAll;
    QStringList strList;

    QFile readFile(filename);
    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&readFile);
        stream.setCodec(QTextCodec::codecForName("UTF-8"));
        lock.lockForRead();
        strAll = stream.readAll();
//        qDebug() << strAll;
        lock.unlock();
        strList = strAll.split("\n");
//        qDebug() << "1 strList.length is:" << strList.length();
        for(int i = 0; i < strList.length(); i++)
        {
//            qDebug() << strList.at(i);
        }
    }
    readFile.close();

    qDebug() << "1 modifyInitFile:now begin to write the ivfdinit.ini";
    QFile writeFile(filename);
    if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream stream(&writeFile);
        stream.setCodec(QTextCodec::codecForName("UTF-8"));
//        strList=strAll.split("\n");
        qDebug() << "2 strList.length is:" << strList.length();
        lock.lockForWrite();
        for(int i = 0;i < strList.length();i++)
        {
            QString tempStr = strList.at(i);

            if(strList.at(i).contains(findstr) && i!= strList.length()-1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                tempStr = altstr;
                stream << tempStr << '\n';
//                i+=1;
            }else if(strList.at(i).contains(findstr) && i == strList.length() - 1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                tempStr = altstr;
                stream << tempStr;
            }else if(!strList.at(i).contains(findstr) && i != strList.length() -1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                stream << tempStr << '\n';
            }else if(!strList.at(i).contains(findstr) && i == strList.length() -1)
            {
//                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
                stream << tempStr ;
            }
            lock.unlock();
        }
    }
    writeFile.close();

    return 1;
}


int GetCFG(QString filename, QString mainkey, QString subkey, QVariant *subkeyval)
{
    if(!InitFileExist(filename))
    {
        return 0;
    }
    QSettings initsetting(filename, QSettings::IniFormat);
    QStringList mainkeylist = initsetting.childGroups();

    foreach(QString str, mainkeylist)
    {
        if(str == mainkey)
        {
            qDebug() << "mainkey found is: " << str;
            initsetting.beginGroup(mainkey);

            QStringList keylist = initsetting.allKeys();

            foreach(QString key, keylist)
            {
                if(subkey == key)
                {
                    *subkeyval = initsetting.value(key);
                    qDebug() << subkey << " :subkey found value is-----" << *subkeyval;
                    return 1;
                }else
                {
                    continue;
                }
            }
            initsetting.endGroup();
            break;
        }else
        {
            continue;
        }
    }
    qDebug() << "not right found mainkey or subkey";
    return 0;
}



int GetEnviroment(QString mainkey, QString subkey, QVariant *subkeyval)
{

    if(!InitFileExist(IVFDINIT_INI))
    {
        return 0;
    }

    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
    QStringList mainkeylist = initsetting.childGroups();

    foreach(QString str, mainkeylist)
    {
        if(str == mainkey)
        {
            qDebug() << "mainkey found is: " << str;
            initsetting.beginGroup(mainkey);

            QStringList keylist = initsetting.allKeys();

            foreach(QString key, keylist)
            {
                if(subkey == key)
                {
                    *subkeyval = initsetting.value(key);
                    qDebug() << subkey << " :subkey found value is-----" << *subkeyval;
                    return 1;
                }else
                {
                    continue;
                }
            }
            initsetting.endGroup();
            break;
        }else
        {
            continue;
        }
    }
    qDebug() << "not right found mainkey or subkey";
    return 0;
}

int SetEnviroment(QString mainkey, QString subkey, QVariant subkeyval)
{
    if(!InitFileExist(QString(IVFDINIT_INI)))
    {
        return 0;
    }

    QStringList keylist;
    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
    initsetting.beginGroup(mainkey);
    keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        qDebug() << key << "-----" << initsetting.value(key);
    }
    qDebug() << "begin to set the SetEnviroment!";
    initsetting.setValue(subkey, subkeyval);
    qDebug() << "begin to sync the SetEnviroment!";
//    initsetting.sync();
    qDebug() << "end the SetEnviroment!";
    foreach(QString key, keylist)
    {
        qDebug() << key << "-----" << initsetting.value(key);
    }
    initsetting.endGroup();


    return 1;
}

QString Get_LocalMachine()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}
QString Get_HostIpAddress()
{
    qDebug() << "Get_HostIpAddress begin";
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    qDebug() << "Get_HostIpAddress 1";
    // 获取第一个本主机的IPv4地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; ++i)
    {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               strIpAddress = ipAddressesList.at(i).toString();
               break;
           }
     }
     // 如果没有找到，则以本地IP地址为IP
     if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
     qDebug() << "Get_HostIpAddress 2";
     return strIpAddress;
}

QString Get_NetMask()
{
    qDebug() << "Get_NetMask begin";
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    qDebug() << "Get_NetMask 1 " << nCnt;
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            QList<QNetworkAddressEntry> entryList =nets[i].addressEntries();
            //获取IP地址条目列表，每个条目中包含一个IP地址，一个子网掩码和一个广播地址
            foreach(QNetworkAddressEntry entry,entryList)
            {
                //遍历每一个IP地址条目
                qDebug() << "IP Address:" << entry.ip().toString();
                //IP地址
                qDebug() <<"Netmask:" << entry.netmask().toString();
                //子网掩码
                qDebug() << "Broadcast:" << entry.broadcast().toString();
                //广播地址
                return entry.netmask().toString();
            }
        }
    }
    return QString("255.255.255.0");
}



int GetAnswerRegistString(QString *msg){
    QString str;
    QVariant subkeyval;
    GetCFG("/ivfdinit.ini", "status", "onwatch", &subkeyval);
    int onwatch = subkeyval.toInt();
    GetCFG("/ivfdinit.ini", "status", "posoffsetx", &subkeyval);
    QString posoffsetx = subkeyval.toString();
    GetCFG("/ivfdinit.ini", "status", "posoffsety", &subkeyval);
    QString posoffsety = subkeyval.toString();
    str = QString("status=%1&%2&%3").arg(onwatch).arg(posoffsetx).arg(posoffsety);
    *msg = str;
    return 0;
}


int ConvertMsgToByteArray(QString *str, QByteArray *bytearray, int cmdtype, int cmdval)
{
    QByteArray ba;
//        GeneralMsg *gmsg = (GeneralMsg *)malloc(sizeof(GeneralMsg));
//        gmsg->source = 3;
//        gmsg->dest = 4;//4=client
//        gmsg->msgid = 1;//0=tell
//        gmsg->type = 2;//cmd
//        gmsg->val = 5;//0:not running;1:running;
//        ba.resize(sizeof(*gmsg));
//        memcpy(ba.data(), gmsg, sizeof(*gmsg));
    CmdActiveX *msg = (CmdActiveX *)malloc(sizeof(CmdActiveX));

    msg->cmdtype = cmdtype;
    msg->cmdval = cmdval;
    memset(msg->cmdstr, 0 ,128);
    QByteArray strba = str->toLatin1();
    int len = strba.length() < 128?strba.length():128;
    memcpy(msg->cmdstr, strba.data(), len);
    ba.resize(sizeof(*msg));
    memcpy(ba.data(), msg, sizeof(*msg));
    *bytearray = ba;
    free(msg);
    return 0;
}



