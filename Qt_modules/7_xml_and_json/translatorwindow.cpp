#include "translatorwindow.h"
#include "ui_translatorwindow.h"

#include "xmlmenureader.h"
#include "xmlmenuwriter.h"
#include "jsonmenuwriter.h"
#include "jsonmenureader.h"

#include <QString>

TranslatorWindow::TranslatorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TranslatorWindow)
{
    ui->setupUi(this);
}

TranslatorWindow::~TranslatorWindow()
{
    delete ui;
}

void TranslatorWindow::on_translateButton_clicked()
{
    if (ui->comboBox->currentIndex() == 0)
    {
        QString data = ui->inputEdit->toPlainText();
        Menu menu;
        XmlMenuReader xml(data, menu);
        xml.read();

        qDebug() << menu;

        JsonMenuWriter writer(menu);
        writer.write();

        ui->outputBrowser->setText(writer.data());
    } else {
        QString data = ui->inputEdit->toPlainText();
        Menu menu;
        JsonMenuReader json(data, menu);
        json.read();

        qDebug() << menu;

        XmlMenuWriter writer(menu);
        writer.write();

        ui->outputBrowser->setText(writer.data());
    }
}
