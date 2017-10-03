#include "qmltranslator.h"

#include <QCoreApplication>
#include <QDebug>

QmlTranslator::QmlTranslator(QObject *parent) : QObject(parent)
{

}

void QmlTranslator::setTranslation(QString newLanguage)
{
    if (newLanguage != currentLanguage)
    {
        currentLanguage = newLanguage;
        if (loadLanguage())
        {
            qDebug() << "New language loaded";
        }
        emit languageChanged();
    }
    else
    {
        qDebug() << "Language not changed";
    }
}

QString QmlTranslator::getEmptyString()
{
    return "";
}

bool QmlTranslator::loadLanguage()
{
    mTranslator.load(QString("translation_%1").arg(currentLanguage), "translations");
    bool result =  QCoreApplication::instance()->installTranslator(&mTranslator);

    return result;
}
