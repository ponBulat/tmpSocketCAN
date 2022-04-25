#include <QCoreApplication>

#include "socketcan.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketCAN myCan;

    return a.exec();
}
