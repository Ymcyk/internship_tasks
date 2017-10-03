#include "jsonmenuwriter.h"

#include <QJsonDocument>
#include <QJsonArray>

JsonMenuWriter::JsonMenuWriter(const Menu &menu)
    : m_menu(menu)
{

}

void JsonMenuWriter::write()
{
    QJsonArray array;

    for(const auto &ref : m_menu.getPopups())
    {
        QJsonObject pop;
        if (!ref.onClick.isEmpty())
        {
            pop["onclick"] = ref.onClick;
        }
        if (!ref.value.isEmpty())
        {
            pop["value"] = ref.value;
        }

        array.append(pop);
    }

    QJsonObject menuitem;
    menuitem["menuitem"] = array;

    QJsonObject menuJson;
    menuJson["id"] = m_menu.getId();
    menuJson["value"] = m_menu.getValue();
    menuJson["popup"] = menuitem;

    m_json["menu"] = menuJson;
}

QString JsonMenuWriter::data()
{
    QJsonDocument doc(m_json);

    return QString(doc.toJson(QJsonDocument::Indented));
}
