#include "client.h"

#include <QtGlobal>
#include <stdexcept>
#include <QTextStream>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

#include "temperature.h"

Client::Client(QObject *parent)
    : QObject(parent)
    , socket_(new QTcpSocket(this))
{
    setupSignals();
}

Client::~Client()
{

}

void Client::connectToHost(const std::string &host, int port)
{
    Q_UNUSED(host);
    Q_UNUSED(port);
    socket_->connectToHost(QHostAddress::LocalHost, 8888);
}

void Client::sendRequest(Request request)
{
    QString request_str;

    switch (request)
    {
    case Request::NEWEST_TEMPERATURE:
    {
        request_str = "newest_temperature";
        break;
    }
    case Request::ALL_TEMPERATURES:
    {
        request_str = "all_temperatures";
        break;
    }
    default:
    {
        throw(std::logic_error("Request not implemented"));
        break;
    }
    }

    QJsonObject json_object;
    json_object.insert("request", request_str);
    QJsonDocument json_document(json_object);

    socket_->write(json_document.toJson(QJsonDocument::Compact));
}

void Client::setupSignals()
{
    connect(socket_, &QTcpSocket::connected, this, &Client::onConnected);
    connect(socket_, &QTcpSocket::connected, this, &Client::connected);
    connect(socket_, &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(socket_, static_cast<void (QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
            this, &Client::error);
    connect(socket_, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::onConnected()
{
    qDebug() << "Client: connected";
}

void Client::onReadyRead()
{
    qDebug() << "onReadyRead";
    auto byteArray = socket_->readAll();
    auto document = QJsonDocument::fromJson(byteArray);

    QList<Temperature> temp_list;

    if (document.isArray())
    {
        auto array = document.array();
        for (const auto &obj : array)
        {
            Temperature temp;

            temp.setTemperature(obj.toObject()["temperature"].toDouble());
            temp.setDate(obj.toObject()["date"].toString());

            temp_list.append(temp);
        }
    }
    else
    {
        auto object = document.object();
        Temperature temp;

        temp.setTemperature(object["temperature"].toDouble());
        temp.setDate(object["date"].toString());

        temp_list.append(temp);
    }

    emit dataReceived(temp_list);
}
