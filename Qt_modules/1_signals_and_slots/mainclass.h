#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QCoreApplication>

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = 0);
    void quit();

signals:
    void finished();

public slots:
    void run();
    void abortToQuitApp();

private:
    QCoreApplication *app;
};

#endif // MAINCLASS_H
