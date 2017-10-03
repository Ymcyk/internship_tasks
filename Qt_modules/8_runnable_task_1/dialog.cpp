#include "dialog.h"

#include <QHBoxLayout>
#include <QProgressBar>

#include <QDebug>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    this->mProgressBar = new QProgressBar;

    layout->addWidget(mProgressBar);
    this->setLayout(layout);
}

Dialog::~Dialog()
{
    qDebug() << "Dialog destructor";
}

void Dialog::onStarted(int value)
{
    qDebug() << "Range changed. New range: " << value;
    this->show();
    this->mProgressBar->setRange(0, value);
}

void Dialog::onValueChanged(int value)
{
    qDebug() << "Value changed. New value: " << value;
    this->mProgressBar->setValue(value);
}

void Dialog::onFinished()
{
    qDebug() << "Dialog onFinished";
    this->done(0);
}
