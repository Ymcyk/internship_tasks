#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>
#include <QAbstractSocket>

#include "temperature.h"

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    ~Client();

    enum class Request
    {
        NEWEST_TEMPERATURE,
        ALL_TEMPERATURES
    };

    void connectToHost(const std::string &host = "localhost", int port = 8888);
    void sendRequest(Request request);

private:
    void setupSignals();

signals:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError);
    void dataReceived(QList<Temperature>);

private slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket *socket_;
};

#endif // CLIENT_H
