#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <reduce.h>
#include <QList>

#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void generateArray(int);
    void makeConnections(Reduce *);

public slots:
    void onValueChanged(int newValue);

private slots:
    void on_reducePushButton_clicked();
    void onReduced(int);

private:
    Ui::MainWindow *ui;
    QList<int> mList;
    Dialog mDialog;
};

#endif // MAINWINDOW_H
