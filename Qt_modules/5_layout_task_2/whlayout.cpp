#include "whlayout.h"

#include <algorithm>
#include <QWidget>
#include <QDebug>
#include <QSize>

WHLayout::WHLayout(QWidget *parent)
    : QLayout(parent)
{

}

void WHLayout::sortBy(SORT_BY type)
{
    qDebug() << "sortBy()";

    if (m_sortState == type)
        return;
    m_sortState = type;

    QList<QWidget*> children;
    QLayoutItem *child;

    while ((child = this->takeAt(0)) != 0)
    {
        children.append(child->widget());
    }

    switch (m_sortState)
    {
    case SORT_BY::HEIGHT:
        sortByHeight(children);
        break;
    case SORT_BY::WIDTH:
        sortByWidth(children);
        break;
    default:
        break;
    }

    for (auto &widget : children)
    {
        this->addWidget(widget);
    }

    this->setGeometry(this->geometry());
}

void WHLayout::sortByHeight(QList<QWidget *> &list)
{
    qDebug() << "sortByHeight()";
    std::sort(std::begin(list), std::end(list),
                [](QWidget *widget1, QWidget *widget2){
                    return widget1->height() > widget2->height();
                });
}

void WHLayout::sortByWidth(QList<QWidget *> &list)
{
    qDebug() << "sortByWidth()";
    std::sort(std::begin(list), std::end(list),
                [](QWidget *widget1, QWidget *widget2){
                    return widget1->width() > widget2->width();
                });
}

WHLayout::~WHLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void WHLayout::addItem(QLayoutItem *item)
{
    m_list.append(item);
}

QSize WHLayout::sizeHint() const
{
    return minimumSize();
}

QSize WHLayout::minimumSize() const
{
    QSize size;
    int height = 0;
    for (auto &item : m_list)
    {
        height += item->widget()->height();
        size = size.expandedTo(item->minimumSize());
    }

    height += m_margin * m_list.length();
    size.setHeight(height);

    qDebug() << "minimumSize(), height: " << size.height() << ", width: " << size.width();

    return size;
}

int WHLayout::count() const
{
    return m_list.size();
}

QLayoutItem *WHLayout::itemAt(int idx) const
{
    return m_list.value(idx);
}

QLayoutItem *WHLayout::takeAt(int idx)
{
    return idx >= 0 && idx < m_list.size() ? m_list.takeAt(idx) : 0;
}

void WHLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    qDebug() << "Geom width: " << rect.width() << ", height: " << rect.height();

    if (m_list.size() == 0)
        return;

    qDebug() << "setGeometry: " << rect.width() << " " << rect.height();

    int h = 0;
    for (int i = 0; i < m_list.size(); ++i)
    {
        if (i > 0)
        {
            h += m_list[i - 1]->widget()->height() + m_margin;
        }
        QRect geom(rect.x(), h, rect.width(), rect.height());
        m_list[i]->setGeometry(geom);
    }
}
