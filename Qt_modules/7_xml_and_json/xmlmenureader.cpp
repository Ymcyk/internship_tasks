#include "xmlmenureader.h"
#include <QDebug>

XmlMenuReader::XmlMenuReader(const QString &data, Menu &menu)
    : m_menu(menu)
{
    m_xmlReader.addData(data);
}

void XmlMenuReader::read()
{
    qDebug() << "Started read()";
    if (m_xmlReader.readNextStartElement() && m_xmlReader.name() == "menu")
    {
        processMenu();
    }
    qDebug() << "Ended read()";
}

void XmlMenuReader::processMenu()
{
    qDebug() << "Started processMenu(). name() == " << m_xmlReader.name();
    if (!m_xmlReader.isStartElement() || m_xmlReader.name() != "menu")
    {
        return;
    }
    qDebug() << "Iterate over attributes";
    for (const QXmlStreamAttribute &attr : m_xmlReader.attributes())
    {
        if (attr.name().toString() == "id")
        {
            qDebug() << "id attribute: " << attr.value().toString();
            m_menu.setId(attr.value().toString());
        } else if (attr.name().toString() == "value")
        {
            qDebug() << "value attribute: " << attr.value().toString();
            m_menu.setValue(attr.value().toString());
        }
    }
    qDebug() << "Ended iterating over attributes";
    if (m_xmlReader.readNextStartElement() && m_xmlReader.name() == "popup")
    {
        processPopups();
    }
}

void XmlMenuReader::processPopups()
{
    qDebug() << "processPopups";
    if (!m_xmlReader.isStartElement() || m_xmlReader.name() != "popup")
        return;

    while (m_xmlReader.readNextStartElement())
    {
        if (m_xmlReader.name() == "menuitem")
        {
            processMenuItem();
        }
        m_xmlReader.skipCurrentElement();
    }
}

void XmlMenuReader::processMenuItem()
{
    qDebug() << "processMenuItem";
    if (!m_xmlReader.isStartElement() || m_xmlReader.name() != "menuitem")
        return;

    qDebug() << "reding popup attributes";
    Popup popup;
    for (const auto &attr : m_xmlReader.attributes())
    {
        if (attr.name().toString() == "value")
        {
            popup.value = attr.value().toString();
        } else if (attr.name().toString() == "onclick")
        {
            popup.onClick = attr.value().toString();
        }
    }
    m_menu.addPopup(popup);
    qDebug("Ended reading popup attributes");
}
