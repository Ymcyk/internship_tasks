#include "triangle.h"

void Triangle::adjustLabels(QLabel *label1, QLabel *label2)
{
    label1->setText(m_label1);
    label2->setText(m_label2);
}

void Triangle::adjustLineEdits(QLineEdit *edit1, QLineEdit *)
{
    edit1->setDisabled(false);
}

double Triangle::area(double vall, double valr) const
{
    return vall * valr / 2;
}
