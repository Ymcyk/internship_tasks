#ifndef JSONMENUREADER_H
#define JSONMENUREADER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

#include "menu.h"

class JsonMenuReader
{
public:
    JsonMenuReader(const QString &, Menu &);

    void read();

private:
    void process(const QJsonObject &);

private:
    QJsonDocument m_doc;
    Menu &m_menu;
};

#endif // JSONMENUREADER_H
