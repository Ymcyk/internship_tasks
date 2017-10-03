#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "qmltranslator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QmlTranslator translator;
    engine.rootContext()->setContextProperty("qmlTranslator", &translator);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
