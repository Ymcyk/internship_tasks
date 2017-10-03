#ifndef QMLTRANSLATOR_H
#define QMLTRANSLATOR_H

#include <QObject>
#include <QString>
#include <QTranslator>

class QmlTranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

public:
    explicit QmlTranslator(QObject *parent = nullptr);

    Q_INVOKABLE void setTranslation(QString);
    QString getEmptyString();

private:
    bool loadLanguage();

signals:
    void languageChanged();

private:
    QTranslator mTranslator;
    QString currentLanguage = "";
};

#endif // QMLTRANSLATOR_H
