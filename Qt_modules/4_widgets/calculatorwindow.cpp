#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

#include <QDoubleValidator>
#include <QTranslator>
#include <QDebug>

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorWindow),
    shape(nullptr)
{
    ui->setupUi(this);
    ui->lineEdit1->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->lineEdit2->setValidator(new QDoubleValidator(0, 100, 2, this));

    adjustForShape(ui->comboBox->currentIndex());
    setUpTranslation(Languages::ENGLISH);
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
    delete shape;
}

void CalculatorWindow::adjustForShape(int index)
{
    delete shape;
    shape = nullptr;

    instantiateShape(index);
    shape->adjustLabels(ui->labelValue1, ui->labelValue2);
    shape->adjustLineEdits(ui->lineEdit1, ui->lineEdit2);
}

void CalculatorWindow::instantiateShape(int index)
{
    switch(index)
    {
    case 0:
        shape = new Rectangle();
        break;
    case 1:
        shape = new Triangle();
        break;
    case 2:
        shape = new Circle();
        break;
    default:
        break;
    }
}

void CalculatorWindow::setUpTranslation(Languages newLanguage)
{
    if(newLanguage == language)
        return;
    language = newLanguage;

    switch(language)
    {
    case Languages::ENGLISH:
        loadTranslation("en");
        break;
    case Languages::POLISH:
        loadTranslation("pl");
        break;
    default:
        break;
    }
}

void CalculatorWindow::loadTranslation(QString code)
{
    QString file = QString("calculator_%1.qm").arg(code);
    qDebug() << "Loaded " << file;
    m_translator.load(file, "./languages/");
    QCoreApplication::instance()->installTranslator(&m_translator);
}

void CalculatorWindow::changeEvent(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        QMainWindow::changeEvent(event);
        break;
    }
}

void CalculatorWindow::on_calculateButton_clicked()
{
//    double val1 = ui->lineEdit1->text().toDouble();
//    double val2 = ui->lineEdit2->text().toDouble();

    double val1 = locale.toDouble(ui->lineEdit1->text());
    double val2 = locale.toDouble(ui->lineEdit2->text());

    qDebug() << val1 << " podana wartość";
    qDebug() << val2 << " podana wartość";

    ui->lcdNumber->display(shape->area(val1, val2));
}

void CalculatorWindow::on_comboBox_activated(int index)
{
    adjustForShape(index);
}

void CalculatorWindow::on_actionPolish_triggered()
{
    setUpTranslation(Languages::POLISH);
}

void CalculatorWindow::on_actionEnglish_triggered()
{
    setUpTranslation(Languages::ENGLISH);
}
