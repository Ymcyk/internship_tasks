#ifndef XMLMENUREADER_H
#define XMLMENUREADER_H

#include "menu.h"

#include <QString>
#include <QXmlStreamReader>

class XmlMenuReader
{
public:
    XmlMenuReader(const QString &, Menu &);
    virtual ~XmlMenuReader() { }

    void read();

private:
    void processMenu();
    void processPopups();
    void processMenuItem();

private:
    QXmlStreamReader m_xmlReader;
    Menu &m_menu;
};

#endif // XMLMENUREADER_H
