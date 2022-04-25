#ifndef SOCKETCAN_H
#define SOCKETCAN_H

#include <QObject>

#include <QNetworkInterface>

class SocketCAN : public QObject
{
    Q_OBJECT
public:
    explicit SocketCAN(QObject *parent = nullptr);

signals:

};

#endif // SOCKETCAN_H
