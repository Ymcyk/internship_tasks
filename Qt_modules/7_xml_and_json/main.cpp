#include "translatorwindow.h"
#include <QApplication>

#include "xmlmenureader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TranslatorWindow w;
    w.show();

    return a.exec();
}
