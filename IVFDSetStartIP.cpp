#include "IVFDSetStartIP.h"

IVFDSetStartIP::IVFDSetStartIP(QObject *parent) : QObject(parent)
{
    m_ipaddr = QString("192.168.120.166");
}

IVFDSetStartIP::~IVFDSetStartIP()
{

}

void IVFDSetStartIP::run(){
//  modifyAutoRunFile(AUTORUN_SH,"ifconfig eth0 192.168",QString("ifconfig eth0 ").append(m_ipaddr));
}

void IVFDSetStartIP::SLOT_SetIP(QString ipaddr)
{
    m_ipaddr = ipaddr;

}
