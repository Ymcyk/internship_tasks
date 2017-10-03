#include "jsonmenureader.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonValueRef>

JsonMenuReader::JsonMenuReader(const QString &data, Menu &menu)
    : m_doc(QJsonDocument::fromJson(data.toUtf8())),
      m_menu(menu)
{

}

void JsonMenuReader::read()
{
    qDebug() << "Started reading";

    if (!m_doc.isNull())
    {
        if (m_doc.isObject())
        {
            process(m_doc.object());
        } else
        {
            qDebug() << "Document is not an object";
        }
    } else
    {
        qDebug() << "Invalid JSON";
    }

    qDebug() << "Ended reading";
}

void JsonMenuReader::process(const QJsonObject &obj)
{
    qDebug() << "Processing object";

    QJsonObject menu = obj["menu"].toObject();

    m_menu.setId(menu["id"].toString());
    m_menu.setValue(menu["value"].toString());

    QJsonArray array = menu["popup"].toObject()["menuitem"].toArray();

    Popup popup;
    for(const QJsonValueRef &ref : array)
    {
        popup.value = ref.toObject()["value"].toString();
        popup.onClick = ref.toObject()["onclick"].toString();
        m_menu.addPopup(popup);
    }
}
