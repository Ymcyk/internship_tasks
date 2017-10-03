#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QFileSystemModel;
class FileProxyModel;

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
    void on_pushButton_clicked();

private:
    void changePath(const QString &path);
    void makeConnections();
    void prepareUi();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model_;
    FileProxyModel *proxy_;
};

#endif // MAINWINDOW_H
