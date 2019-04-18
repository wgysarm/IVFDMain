#ifndef IVFDMAINTCPSERVER_H
#define IVFDMAINTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QLocalSocket>
#include <QLocalServer>
#include <QSocketNotifier>
#include <QSsl>
#include <QSslSocket>
#include <QUdpSocket>
#include <QThread>
#include <QByteArray>
#include <QAbstractSocket>
#include <QList>

typedef struct ALARMDATAINFO{
    int alarmType;
    int alarmTime;
    int pTOPLx;
    int pTOPLy;
    int recHeight;
    int recWidth;
}ALARMDATAINFO;

class IVFDMainTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit IVFDMainTcpServer(QObject *parent = 0, QString ipAddr = QString("0.0.0.0"), quint16 listenPort = 58890);
    QTcpServer *m_tcpserver;
    QTcpSocket *m_tcpsocket;

    QThread m_tcpserverThread;
    QHostAddress m_hostAddr;
    quint16 m_port;
    QByteArray m_ba;

    ~IVFDMainTcpServer();
    void InitThis(QString ipAddr, quint16 listenPort);
    void XReadAll(QByteArray);
signals:
    void SIG_StartTcpServerThread();
    void SIG_StopTcpServerThread();
    void SIG_WriteToTcpSocket(QByteArray);
    void SIG_TellTop(QByteArray);// output signal to tell the top

public slots:

    void SLOT_StartTcpServerThread();
    void SLOT_StopTcpServerThread();
    void SLOT_HasNewConnection();
    void SLOT_ReadyReadAll();
    void SLOT_WriteToTcpSocket(QByteArray);
    void SLOT_SocketError(QAbstractSocket::SocketError);

};

#endif // IVFDMAINTCPSERVER_H
