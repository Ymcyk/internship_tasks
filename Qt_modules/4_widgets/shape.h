#ifndef SHAPE_H
#define SHAPE_H

#include <QLabel>
#include <QLineEdit>

class Shape
{
public:
    virtual void adjustLabels(QLabel *, QLabel *) = 0;
    virtual void adjustLineEdits(QLineEdit *, QLineEdit *) = 0;
    virtual double area(double, double) const = 0;
    virtual ~Shape() {}
};

#endif // SHAPE_H
