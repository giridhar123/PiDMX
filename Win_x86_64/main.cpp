#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <libs/lib/PiDMXLib/main.h>
#include <QtQml/qqmlextensionplugin.h>

int main(int argc, char *argv[])
{
    Q_IMPORT_QML_PLUGIN(ExtraModulePlugin);

    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    return (_main(argc, argv));
}
