#ifndef IVFDSETSTARTIP_H
#define IVFDSETSTARTIP_H

#include <QObject>
#include <QRunnable>
#include "IVFDDriver.h"

class IVFDSetStartIP : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit IVFDSetStartIP(QObject *parent = 0);
    ~IVFDSetStartIP();
    QString m_ipaddr;
signals:
    void SIG_SetIP(QString);
protected:
    void run();
public slots:
    void SLOT_SetIP(QString ipaddr);

};

#endif // IVFDSETSTARTIP_H
