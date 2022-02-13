#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "libs/include/main.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    return (PiDMX::_main(argc, argv));
}
