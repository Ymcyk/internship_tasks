#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QLocale>
#include <QMainWindow>
#include <QTranslator>
#include "shape.h"

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

    enum class Languages
    {
        ENGLISH, POLISH
    };

public:
    explicit CalculatorWindow(QWidget *parent = 0);
    ~CalculatorWindow();

    void adjustForShape(int);

private:
    void instantiateShape(int);
    void setUpTranslation(Languages);
    void loadTranslation(QString);

protected:
    void changeEvent(QEvent *);

private slots:
    void on_calculateButton_clicked();
    void on_comboBox_activated(int index);

    void on_actionPolish_triggered();

    void on_actionEnglish_triggered();

private:
    Ui::CalculatorWindow *ui;
    Shape *shape;
    QTranslator m_translator;
    Languages language;
    QLocale locale;
};

#endif // CALCULATORWINDOW_H
