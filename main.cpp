#include <QCoreApplication>

#include "mycan.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyCAN myCan;

    return a.exec();
}
