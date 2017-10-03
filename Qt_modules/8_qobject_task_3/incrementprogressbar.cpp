#include "incrementprogressbar.h"

#include <QProgressBar>
#include <QDebug>

IncrementProgressBar::IncrementProgressBar(QObject *parent) : QObject(parent)
{

}

IncrementProgressBar::IncrementProgressBar(QProgressBar *progressBar)
    : mBar(progressBar)
{
    mBar->setValue(0);
}

void IncrementProgressBar::setProgressBarRange(int min, int max)
{
    mBar->setRange(min, max);
}

void IncrementProgressBar::zeroProgressBar()
{
    mBar->setValue(0);
    mBarValue = 0;
}

void IncrementProgressBar::onProgressValueChanged()
{
    mMutex.lock();

    ++mBarValue;
    mBar->setValue(mBarValue);

    mMutex.unlock();
}
