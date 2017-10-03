#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QComboBox>

#include "whlayout.h"
/*
namespace Ui {
class MainWindow;
}
*/
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_comboBoxActivated(int idx);

private:
    void setUpLayout();

    void setUpCustomWidgets();

private:
    WHLayout *whLayout;
    QComboBox *comboBox;
};

#endif // MAINWINDOW_H
