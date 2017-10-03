#include "mainwindow.h"

#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    setUpLayout();
    QWidget::connect(comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),
                     this, &MainWindow::on_comboBoxActivated);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_comboBoxActivated(int idx)
{
    qDebug() << "on_comboBoxActivated()";
    switch (idx)
    {
    case 0:
        whLayout->sortBy(WHLayout::SORT_BY::WIDTH);
        break;
    case 1:
        whLayout->sortBy(WHLayout::SORT_BY::HEIGHT);
        break;
    default:
        break;
    }
}

void MainWindow::setUpLayout()
{
    QLabel *label = new QLabel("Sort by:");
    comboBox = new QComboBox();
    comboBox->addItem("Width");
    comboBox->addItem("Height");
    QSpacerItem *spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(label);
    hLayout1->addWidget(comboBox);
    hLayout1->addSpacerItem(spacer1);

    this->whLayout = new WHLayout();

    setUpCustomWidgets();
    //this->whLayout->setDirection(QBoxLayout::BottomToTop);

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addLayout(hLayout1);
    vLayout2->addLayout(whLayout);
    QSpacerItem *spacer2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vLayout2->addSpacerItem(spacer2);

    this->setLayout(vLayout2);

    this->on_comboBoxActivated(comboBox->currentIndex());
}

void MainWindow::setUpCustomWidgets()
{
    QWidget *widget1 = new QWidget();
    widget1->setMinimumSize(20, 50);
    widget1->setMaximumSize(20, 20);
    widget1->setStyleSheet("background-color:black;");

    QWidget *widget2 = new QWidget();
    widget2->setMinimumSize(50, 20);
    widget2->setMaximumSize(50, 20);
    widget2->setStyleSheet("background-color:black;");

    QWidget *widget3 = new QWidget();
    widget3->setMinimumSize(40, 40);
    widget3->setMaximumSize(40, 20);
    widget3->setStyleSheet("background-color:black;");

    QWidget *widget4 = new QWidget();
    widget4->setMinimumSize(30, 30);
    widget4->setMaximumSize(30, 20);
    widget4->setStyleSheet("background-color:black;");

    this->whLayout->addWidget(widget1);
    this->whLayout->addWidget(widget2);
    this->whLayout->addWidget(widget3);
    this->whLayout->addWidget(widget4);
}
