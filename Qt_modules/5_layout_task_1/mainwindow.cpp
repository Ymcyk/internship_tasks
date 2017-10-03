#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personcard.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cancelButton_clicked()
{
    QCoreApplication::exit();
}

void MainWindow::on_okButton_clicked()
{
    PersonCard card;
    card.setName(ui->nameEdit->text());
    card.setSecondName(ui->lastNameEdit->text());
    card.setAge(ui->ageSpinBox->text().toUInt());
    card.setCountry(ui->countryComboBox->currentText());

    auto group = ui->groupBox->findChildren<QCheckBox*>();

    for (const auto &ref : group)
    {
        if (ref->isChecked())
        {
            card.addSport(ref->text());
        }
    }

    qDebug() << card;
    QCoreApplication::exit();
}
