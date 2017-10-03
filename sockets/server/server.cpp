#include "server.h"

#include <QtGlobal>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include "requesthandler.h"

Server::Server(QObject *parent)
    : QObject(parent)
    , server_(new QTcpServer(this))
    , db_(QSqlDatabase::addDatabase("QSQLITE"))
{
    setupSignals();

    db_.setDatabaseName(db_path_);
    if (!db_.open())
    {
        throw std::runtime_error("Can't open database");
    }
}

void Server::startListening(std::string host, int port)
{
    Q_UNUSED(host);
    Q_UNUSED(port);
    if (server_->listen(QHostAddress::Any, 8888))
    {
        qDebug() << "Server is listening";
    }
    else
    {
        qDebug() << "Server didn't start";
    }
}

void Server::setupSignals()
{
    connect(server_, &QTcpServer::newConnection, this, &Server::onNewConnection);
}

void Server::onNewConnection()
{
    //TODO make asynchronous
    qDebug() << "New connection";
    QTcpSocket *socket = server_->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
}

void Server::onDisconnected()
{
    qDebug() << "Disconnected";
}

void Server::onReadyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    RequestHandler *handler = new RequestHandler(socket, this);
    handler->handle();
}
