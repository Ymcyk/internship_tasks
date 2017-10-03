#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QProgressBar;

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void onStarted(int);
    void onValueChanged(int);
    void onFinished();

private:
    QProgressBar *mProgressBar;
};

#endif // DIALOG_H
