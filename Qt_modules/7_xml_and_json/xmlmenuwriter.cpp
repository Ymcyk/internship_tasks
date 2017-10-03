#include "xmlmenuwriter.h"

#include <QDebug>

XmlMenuWriter::XmlMenuWriter(const Menu &menu)
    : m_menu(menu)
{
    m_StreamWriter = std::unique_ptr<QXmlStreamWriter>(new QXmlStreamWriter(&m_data));
}

Menu XmlMenuWriter::menu() const
{
    return m_menu;
}

void XmlMenuWriter::write()
{
    m_StreamWriter->setAutoFormatting(true);

    m_StreamWriter->writeStartElement("menu");

    m_StreamWriter->writeAttribute("id", m_menu.getId());
    m_StreamWriter->writeAttribute("value", m_menu.getValue());

    m_StreamWriter->writeStartElement("popup");

    for(const auto &pop : m_menu.getPopups())
    {
        m_StreamWriter->writeStartElement("menuitem");
        m_StreamWriter->writeAttribute("value", pop.value);
        m_StreamWriter->writeAttribute("onclick", pop.onClick);
        m_StreamWriter->writeEndElement();
    }

    m_StreamWriter->writeEndDocument();
}

QString XmlMenuWriter::data() const
{
    return m_data;
}
