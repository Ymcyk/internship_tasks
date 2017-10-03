#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <algorithm>

#include "reducearray.h"
#include "incrementprogressbar.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mProgressBar = std::unique_ptr<IncrementProgressBar>(new IncrementProgressBar(ui->progressBar));
    mReduce = std::unique_ptr<ReduceArray>(new ReduceArray(mProgressBar.get()));

    connect(mReduce.get(), &ReduceArray::resultReady, this, &MainWindow::onResultReady);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateArray(int size)
{
    mList.clear();
    mList.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        mList.append(1);
    }
}

void MainWindow::onResultReady(const long long &result)
{
    qDebug() << "Result retrieved in main: " << result;
    ui->resultLineEdit->setText(QString("%1").arg(result));
    ui->sumPushButton->setDisabled(false);
}


void MainWindow::on_sumPushButton_clicked()
{
    int arraySize = ui->arraySizeSpinBox->value();

    if (arraySize <= 0)
        return;

    generateArray(arraySize);
    mProgressBar->setProgressBarRange(0, arraySize);
    mProgressBar->zeroProgressBar();

    ui->sumPushButton->setDisabled(true);
    mReduce->reduce(std::begin(mList), std::end(mList), 0);
}
