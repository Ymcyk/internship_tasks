#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThreadPool>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mDialog(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destructor";
    delete ui;
}

void MainWindow::generateArray(int size)
{
    mList.clear();
    mList.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        mList.append(i + 1);
    }
}

void MainWindow::makeConnections(Reduce *reduce)
{
    connect(reduce, &Reduce::started, &mDialog, &Dialog::onStarted);
    connect(reduce, &Reduce::finished, &mDialog, &Dialog::onFinished);
    connect(reduce, &Reduce::finished, this, &MainWindow::onReduced);
    connect(reduce, &Reduce::valueChanged, &mDialog, &Dialog::onValueChanged);
}

void MainWindow::onValueChanged(int newValue)
{
    qDebug() << "New value: " << newValue;
}

void MainWindow::on_reducePushButton_clicked()
{
    int arraySize = ui->SizeSpinBox->value();

    if (arraySize <= 0)
        return;

    qDebug() << "Before generate";

    generateArray(arraySize);

    qDebug() << "Before Reduce start";

    Reduce *reduce = new Reduce(mList);
    makeConnections(reduce);

    QThreadPool::globalInstance()->start(reduce);
}

void MainWindow::onReduced(int result)
{
    ui->resultLineEdit->setText(QString("%1").arg(result));
    qDebug() << "In onReduced";
}
