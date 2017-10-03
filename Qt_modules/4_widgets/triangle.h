#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <shape.h>

#include <QString>

class Triangle : public Shape
{
public:
    virtual void adjustLabels(QLabel *, QLabel *);
    virtual void adjustLineEdits(QLineEdit *, QLineEdit *);
    virtual double area(double, double) const;

private:
    QString m_label1 = QObject::tr("Base");
    QString m_label2 = QObject::tr("Height");
};

#endif // TRIANGLE_H
