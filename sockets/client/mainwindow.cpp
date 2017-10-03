#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDateTime>
#include <sstream>

#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , client_(new Client(this))
{
    ui->setupUi(this);

    setupSignals();
    changeState(State::DISCONNECTED);
    //TODO get address from label and delete line below
    ui->addressEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupSignals()
{
    connect(client_, &Client::connected, this, &MainWindow::onConnected);
    connect(client_, &Client::disconnected, this, &MainWindow::onDisconnected);
    connect(client_, &Client::error, this, &MainWindow::onError);
    connect(client_, &Client::dataReceived, this, &MainWindow::onDataReceived);
}

void MainWindow::changeState(MainWindow::State state)
{
    switch(state)
    {
    case State::DISCONNECTED:
    {
        enableConnectedState(false);
        break;
    }
    case State::CONNECTED:
    {
        enableConnectedState(true);
        break;
    }
    case State::REQUEST:
    {
        enableRequestState(true);
        break;
    }
    default:
        break;
    }

    state_ = state;
}

void MainWindow::enableConnectedState(bool enable)
{
    ui->connectButton->setEnabled(!enable);

    ui->responseGroupBox->setEnabled(enable);
    ui->requestGroupBox->setEnabled(enable);

    enableRequestState(false);
}

void MainWindow::enableRequestState(bool)
{
//    ui->sendButton->setEnabled(!enable);
}

void MainWindow::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "onError: " << error;
    switch(error)
    {
    case QAbstractSocket::ConnectionRefusedError:
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, "Connection refused", "Cannot connect to host");
        break;
    default:
        QMessageBox::critical(this, "Error", "Connection error");
        break;
    }
}

void MainWindow::onConnected()
{
    qDebug() << "onConnected";
    changeState(State::CONNECTED);
}

void MainWindow::onDisconnected()
{
    qDebug() << "onDisconnected";
    changeState(State::DISCONNECTED);
}

void MainWindow::onDataReceived(QList<Temperature> temp_list)
{
    std::stringstream sstream;

    for (const auto &temp : temp_list)
    {
       sstream << "Date: " << temp.getDate().toString(Qt::ISODate).toStdString()
               << ", temp: " << temp.getTemperature() << '\n';
    }

    ui->responseTextBrowser->setText(QString::fromStdString(sstream.str()));
}

void MainWindow::on_connectButton_clicked()
{
    client_->connectToHost();
}

void MainWindow::on_sendButton_clicked()
{
    changeState(State::REQUEST);
    if (ui->newestRadioButton->isChecked())
    {
        client_->sendRequest(Client::Request::NEWEST_TEMPERATURE);
    }
    else if (ui->allRadioButton->isChecked())
    {
        client_->sendRequest(Client::Request::ALL_TEMPERATURES);
    }
}
