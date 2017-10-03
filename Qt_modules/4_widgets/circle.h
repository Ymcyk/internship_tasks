#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <QString>

class Circle : public Shape
{
public:
    virtual void adjustLabels(QLabel *, QLabel *);
    virtual void adjustLineEdits(QLineEdit *, QLineEdit *);
    virtual double area(double, double) const;

private:
    QString m_label1 = QObject::tr("PI");
    QString m_label2 = QObject::tr("Radius");
};

#endif // CIRCLE_H
