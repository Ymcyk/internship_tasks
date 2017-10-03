#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileSystemModel>
#include <QTableView>
#include <QDebug>
#include <QFileDialog>
#include <QStringList>

#include "fileproxymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model_ = new QFileSystemModel(this);
    proxy_ = new FileProxyModel(this);

    prepareUi();
    makeConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::prepareUi()
{
    ui->lineEdit->setReadOnly(true);

    model_->setRootPath("");
    proxy_->setSourceModel(model_);
    ui->tableView->setModel(proxy_);
    changePath(QDir::currentPath());

    ui->tableView->verticalHeader()->setMinimumWidth(25);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < ui->tableView->horizontalHeader()->count(); ++i)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
}

void MainWindow::makeConnections()
{
    connect(ui->lineEdit_2, &QLineEdit::textChanged, proxy_, &FileProxyModel::onSearchTextChanged);
}

void MainWindow::changePath(const QString &path)
{
//    QStringList list;
//    list << "*.o";
//    model_->setNameFilters(list);
//    model_->setNameFilterDisables(false);
    ui->lineEdit->setText(path);
    QModelIndex index = model_->index(path);
    ui->tableView->setRootIndex(proxy_->mapFromSource(index));
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    changePath(fileNames[0]);
}
