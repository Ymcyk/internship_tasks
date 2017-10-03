#ifndef INCREMENTPROGRESSBAR_H
#define INCREMENTPROGRESSBAR_H

#include <QObject>
#include <QMutex>

class QProgressBar;

class IncrementProgressBar : public QObject
{
    Q_OBJECT
public:
    explicit IncrementProgressBar(QObject *parent = nullptr);
    IncrementProgressBar(QProgressBar *);

    void setProgressBarRange(int min, int max);
    void zeroProgressBar();

public slots:
    void onProgressValueChanged();

private:
    QProgressBar *mBar;
    QMutex mMutex;
    int mBarValue = 0;
};

#endif // INCREMENTPROGRESSBAR_H
