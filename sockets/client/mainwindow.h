#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QAbstractSocket>
#include <QStringList>

#include "temperature.h"

class Client;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum class State
    {
        DISCONNECTED,
        CONNECTED,
        REQUEST
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupSignals();
    void changeState(State);
    void enableConnectedState(bool);
    void enableRequestState(bool);

private slots:
    void onError(QAbstractSocket::SocketError error);
    void onConnected();
    void onDisconnected();
    void onDataReceived(QList<Temperature>);
    void on_connectButton_clicked();
    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    Client *client_;
    State state_;
};

#endif // MAINWINDOW_H
