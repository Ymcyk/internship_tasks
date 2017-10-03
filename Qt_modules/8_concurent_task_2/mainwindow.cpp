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

void MainWindow::on_SumPushButton_clicked()
{
    int arraySize = ui->arraySizeSpinBox->value();
    int objectsAmount = ui->objectsAmountSpinBox->value();

    if (arraySize <= 0)
        return;

    generateArray(arraySize);
    mProgressBar->setProgressBarRange(0, arraySize);
    mProgressBar->zeroProgressBar();

    long long result = mReduce->reduce(std::begin(mList), std::end(mList), objectsAmount);

    ui->resultLineEdit->setText(QString("%1").arg(result));
}

