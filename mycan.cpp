#include "mycan.h"

#include <QDebug>

#include <QCanBus>
#include <QCanBusDeviceInfo>

MyCAN::MyCAN(QObject *parent) : QObject(parent)
{

//    for( const auto &interface : QNetworkInterface::allInterfaces() )
//    {
//        qDebug() << "interface: " << interface.name();
//    }


//    if (QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
//        qDebug() << "plugin available";
//    }




//    QString errorString;
//    const QList<QCanBusDeviceInfo> devices = QCanBus::instance()->availableDevices(
//        QStringLiteral("socketcan"), &errorString);

//    if (!errorString.isEmpty())
//        qDebug() << errorString;


//    qDebug() << devices.size();

//    for( const auto & can : devices )
//    {
//        qDebug() << "description: " << can.description();
//        qDebug() << "name: " << can.name();
//        qDebug() << "channels: " << can.channel();
//        qDebug() << "serialNumber: " << can.serialNumber();
//    }


    QString errorString;

    QCanBusDevice *m_canDevice = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);


    if( m_canDevice->connectDevice() )
    {
        connect(m_canDevice, &QCanBusDevice::framesReceived, [ m_canDevice ]() {

            auto frames = m_canDevice->readAllFrames();

            for( const auto &frame : frames  )
            {
                qDebug() << "frameId: " << frame.frameId();
            }
        } );


        // запишем id
        QCanBusFrame frame;
        frame.setFrameId( 0x103 );
        m_canDevice->writeFrame( frame );
    }
}
