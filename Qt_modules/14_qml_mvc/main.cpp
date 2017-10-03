#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "animalmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AnimalModel animalModel;
    animalModel.addAnimal(Animal("Dog", "Burek", 12, 4, 0.5));
    animalModel.addAnimal(Animal("Cat", "Stefan", 5, 4, 0.3));

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cppModel", &animalModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
