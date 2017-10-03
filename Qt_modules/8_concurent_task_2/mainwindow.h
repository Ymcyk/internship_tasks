#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include <memory>

class IncrementProgressBar;
class ReduceArray;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SumPushButton_clicked();

private:
    void generateArray(int);

private:
    Ui::MainWindow *ui;
    QList<int> mList;
    std::unique_ptr<ReduceArray> mReduce;
    std::unique_ptr<IncrementProgressBar> mProgressBar;
};

#endif // MAINWINDOW_H
