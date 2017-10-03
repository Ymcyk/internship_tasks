#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QSqlDatabase>

class QTcpServer;
class QTcpSocket;
class RequestHandler;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void startListening(std::string host = "localhost", int port = 8888);

private:
    void setupSignals();

private slots:
    void onNewConnection();
    void onDisconnected();
    void onReadyRead();

private:
    const QString db_path_ = "/home/intpize/test.db";
    QTcpServer *server_;
    QSqlDatabase db_;
};

#endif // SERVER_H
