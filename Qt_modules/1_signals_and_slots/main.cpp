#include <QCoreApplication>
#include <QTimer>

#include "mainclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainClass mainClass;

    QObject::connect(&mainClass, &MainClass::finished, &a, &QCoreApplication::quit);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &mainClass, &MainClass::abortToQuitApp);

    QTimer::singleShot(10, &mainClass, &MainClass::run);

    return a.exec();
}
