#ifndef REQUESTHANDLERIMPL_H
#define REQUESTHANDLERIMPL_H

#include <QObject>
#include <memory>

class TemperatureReader;
class QByteArray;
class QTcpSocket;
class Task;

class RequestHandler : public QObject
{
    Q_OBJECT

public:
    explicit RequestHandler(QTcpSocket *socket, QObject *parent = nullptr);
    virtual ~RequestHandler();

    void handle();

private:
    void sendErrorResponse(const char *error_text);


private:
    QTcpSocket *socket_;
    std::unique_ptr<TemperatureReader> reader_;
};

#endif // REQUESTHANDLERIMPL_H
