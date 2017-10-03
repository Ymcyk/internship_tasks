#include "circle.h"

#include <cmath>

void Circle::adjustLabels(QLabel *label1, QLabel *label2)
{
    label1->setText(m_label1);
    label2->setText(m_label2);
}

void Circle::adjustLineEdits(QLineEdit *edit1, QLineEdit *)
{
    edit1->setText(QString::number(M_PI));
    edit1->setDisabled(true);
}

double Circle::area(double vall, double valr) const
{
    return vall * valr * valr;
}
