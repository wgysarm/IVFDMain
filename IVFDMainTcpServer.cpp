#include "IVFDMainTcpServer.h"

IVFDMainTcpServer::IVFDMainTcpServer(QObject *parent, QString ipAddr, quint16 listenPort) : QObject(parent)
{
    InitThis(ipAddr, listenPort);
}

IVFDMainTcpServer::~IVFDMainTcpServer()
{

}


void IVFDMainTcpServer::SLOT_StartTcpServerThread()
{
    m_tcpserverThread.start();
    moveToThread(&m_tcpserverThread);
    qDebug() << "1 IVFDMainTcpServer::SLOT_StartTcpServerThread()";
}

void IVFDMainTcpServer::SLOT_StopTcpServerThread()
{

    m_tcpserverThread.quit();
}

void IVFDMainTcpServer::SLOT_HasNewConnection()
{
    qDebug() << "1 IVFDMainTcpServer::SLOT_HasNewConnection()";

    while(m_tcpserver->hasPendingConnections())
    {
        m_tcpsocket = m_tcpserver->nextPendingConnection();
        QObject::connect(m_tcpsocket, SIGNAL(readyRead()), this, SLOT(SLOT_ReadyReadAll()));
        QObject::connect(m_tcpsocket, SIGNAL(disconnected()), m_tcpsocket, SLOT(deleteLater()));
        QObject::connect(m_tcpsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SLOT_SocketError(QAbstractSocket::SocketError)));

    }
}

void IVFDMainTcpServer::SLOT_ReadyReadAll()
{
    qDebug() << "1 IVFDMainTcpServer::SLOT_ReadyReadAll()";
    m_ba = m_tcpsocket->readAll();
    XReadAll(m_ba);
}

void IVFDMainTcpServer::SLOT_SocketError(QAbstractSocket::SocketError err)
{
    qDebug() << "1 IVFDMainTcpServer::SLOT_SocketError:" << err;

}

void IVFDMainTcpServer::SLOT_WriteToTcpSocket(QByteArray ba)
{
    qDebug() << "1 IVFDMainTcpServer::SLOT_WriteToTcpSocket:" << ba;
    qDebug() << "1 IVFDMainTcpServer::SLOT_WriteToTcpSocket:"  << m_tcpsocket->peerAddress() << "-----current id---" << QThread::currentThread();
    qDebug() << "1 IVFDMainTcpServer::SLOT_WriteToTcpSocket:"  << m_tcpsocket->peerPort();
    m_tcpsocket->write(ba);
//    m_tcpsocket->flush();

}


void IVFDMainTcpServer::XReadAll(QByteArray ba)
{
    qDebug() << "1 IVFDMainTcpServer::XReadAll(QByteArray ba)" << "------" << QThread::currentThread();
//    ALARMDATAINFO *dataRecv = (ALARMDATAINFO *)ba.data();

//    int frameIndex = dataRecv->alarmTime;
//    int infoType = dataRecv->alarmType;
//    int tplX = dataRecv->pTOPLx;
//    int tplY = dataRecv->pTOPLy;
//    int recWidth = dataRecv->recWidth;
//    int recHeight = dataRecv->recHeight;
//    qDebug() << "1 IVFDMainTcpServer::XReadAll Exit. frame Index = " << frameIndex  << " width = " << recWidth << " height = " << recHeight\
//             << " tplX=" << tplX << " tplY=" << tplY << " infoType = " << infoType;
    int tsize = ba.size();
    qDebug() << "1 IVFDMainTcpServer::XReadAll len = " << tsize;
    emit SIG_TellTop(ba);//tell the top outside
    qDebug() << "after emit SIG_TellTop(ba)";
}

void IVFDMainTcpServer::InitThis(QString ipAddr, quint16 listenPort)
{
    m_hostAddr = QHostAddress(QHostAddress::Any);
    m_port = listenPort;
    m_tcpserver = new QTcpServer(this);
    m_tcpsocket = new QTcpSocket(this);
    m_tcpserver->setMaxPendingConnections(1);
    m_tcpserver->listen(m_hostAddr, m_port);


    QObject::connect(&m_tcpserverThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_tcpserver, SIGNAL(newConnection()), this, SLOT(SLOT_HasNewConnection()));

    QObject::connect(this, SIGNAL(SIG_StartTcpServerThread()), this, SLOT(SLOT_StartTcpServerThread()));
    QObject::connect(this, SIGNAL(SIG_StopTcpServerThread()), this, SLOT(SLOT_StopTcpServerThread()));
    QObject::connect(this, SIGNAL(SIG_WriteToTcpSocket(QByteArray)), this, SLOT(SLOT_WriteToTcpSocket(QByteArray)));

}

