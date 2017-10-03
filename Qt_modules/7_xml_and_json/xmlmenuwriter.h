#ifndef XMLMENUWRITER_H
#define XMLMENUWRITER_H

#include <QXmlStreamWriter>
#include <QString>
#include <memory>

#include "menu.h"

class XmlMenuWriter
{
public:
    XmlMenuWriter(const Menu &);

    Menu menu() const;

    void write();

    QString data() const;

private:
    QString m_data;
    std::unique_ptr<QXmlStreamWriter> m_StreamWriter;
    const Menu &m_menu;
};

#endif // XMLMENUWRITER_H
