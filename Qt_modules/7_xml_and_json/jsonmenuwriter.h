#ifndef JSONMENUWRITER_H
#define JSONMENUWRITER_H

#include <QJsonObject>
#include <QString>

#include "menu.h"

class JsonMenuWriter
{
public:
    JsonMenuWriter(const Menu &);

    void write();

    QString data();

private:
    const Menu &m_menu;
    QJsonObject m_json;
};

#endif // JSONMENUWRITER_H
