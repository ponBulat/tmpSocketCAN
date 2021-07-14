#ifndef MYCAN_H
#define MYCAN_H

#include <QObject>

#include <QNetworkInterface>

class MyCAN : public QObject
{
    Q_OBJECT
public:
    explicit MyCAN(QObject *parent = nullptr);

signals:

};

#endif // MYCAN_H
