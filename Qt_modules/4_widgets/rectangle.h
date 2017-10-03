#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

#include <QString>

class Rectangle : public Shape
{
public:
    virtual void adjustLabels(QLabel *, QLabel *);
    virtual void adjustLineEdits(QLineEdit *, QLineEdit *);
    virtual double area(double, double) const;

private:
    QString m_label1 = QObject::tr("Side A");
    QString m_label2 = QObject::tr("Side B");
};

#endif // RECTANGLE_H
