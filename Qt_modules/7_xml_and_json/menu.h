#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QList>
#include <QDebug>

struct Popup
{
    QString value = "";
    QString onClick = "";

    operator QString();
};

class Menu
{
public:
    Menu();

    QString getId() const;
    void setId(const QString &value);

    QString getValue() const;
    void setValue(const QString &value);

    QList<Popup> getPopups() const;
    void addPopup(const Popup &);

    operator QString();

private:
    QString m_id = "";
    QString m_value = "";
    QList<Popup> m_popups;
};

#endif // MENU_H
