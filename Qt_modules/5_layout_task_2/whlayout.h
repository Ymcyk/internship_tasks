#ifndef WHLAYOUT_H
#define WHLAYOUT_H

#include <QLayoutItem>
#include <QLayout>
#include <QList>
#include <QSize>

class WHLayout : public QLayout
{
    Q_OBJECT

public:
    enum class SORT_BY {
        WIDTH, HEIGHT, NOTSETTED
    };

    explicit WHLayout(QWidget *parent = 0);
    ~WHLayout();

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    void setGeometry(const QRect &rect);

    void sortBy(SORT_BY);

private:
    void sortByHeight(QList<QWidget*> &);
    void sortByWidth(QList<QWidget*> &);

private:
    SORT_BY m_sortState = SORT_BY::NOTSETTED;
    QList<QLayoutItem*> m_list;
    int m_margin = 5;
};

#endif // WHLAYOUT_H
