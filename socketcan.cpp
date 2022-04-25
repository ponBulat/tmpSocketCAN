#include "socketcan.h"

#include <QDebug>

#include <QCanBus>
#include <QCanBusDeviceInfo>

SocketCAN::SocketCAN(QObject *parent) : QObject(parent)
{

    for( const auto &interface : QNetworkInterface::allInterfaces() )
    {
        qDebug() << "interface: " << interface.name();
    }

    if (QCanBus::instance()->plugins().contains(QStringLiteral("socketcan"))) {
        qDebug() << "plugin available";
    }


    // =========================================

    // проверка доступных для SocketCAN устройств
    QString availableDevicesErrorString;

    const QList<QCanBusDeviceInfo> devicesInfo = QCanBus::instance()->availableDevices(
        QStringLiteral("socketcan"), &availableDevicesErrorString);

    if (!availableDevicesErrorString.isEmpty())
        qDebug() << availableDevicesErrorString;


    qDebug() << "devicesInfo size: " << devicesInfo.size();

    for( const auto & deviceInfo : devicesInfo )
    {
        qDebug() << "description: "  << deviceInfo.description();
        qDebug() << "name: "         << deviceInfo.name();
        qDebug() << "channels: "     << deviceInfo.channel();
        qDebug() << "serialNumber: " << deviceInfo.serialNumber();
        qDebug() << "alias: " << deviceInfo.alias();
    }

    // ==============================================

    // соединение с устройством CAN и запись фрейма    
//    QString errorString;

//    QCanBusDevice *m_canDevice = QCanBus::instance()->createDevice(
//        QStringLiteral("socketcan"), QStringLiteral("can0"), &errorString);


//    if( m_canDevice->connectDevice() )
//    {
//        connect(m_canDevice, &QCanBusDevice::framesReceived, [ m_canDevice ]() {

//            auto frames = m_canDevice->readAllFrames();

//            for( const auto &frame : frames  )
//            {
//                qDebug() << "frameId: " << frame.frameId();
//            }
//        } );


//        // запишем id
//        QCanBusFrame frame;
//        frame.setFrameId( 0x103 );
//        m_canDevice->writeFrame( frame );
//    }

    // ==============================================

}
