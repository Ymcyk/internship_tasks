#include "menu.h"

#include <QDebug>

Menu::Menu()
{

}

QString Menu::getId() const
{
    return m_id;
}

void Menu::setId(const QString &id)
{
    m_id = id;
}

QString Menu::getValue() const
{
    return m_value;
}

void Menu::setValue(const QString &value)
{
    m_value = value;
}

QList<Popup> Menu::getPopups() const
{
    return m_popups;
}

void Menu::addPopup(const Popup &popup)
{
    m_popups.append(popup);
}

Menu::operator QString()
{
    QString data = QString("id: %1, value: %2").arg(m_id).arg(m_value);
    for (auto &pop : m_popups)
    {
        qDebug() << "Writing popup";
        data.append(pop);
    }
    return data;
}

Popup::operator QString()
{
    QString data = QString("value: %1, onClick: %2").arg(value).arg(onClick);
    return data;
}
