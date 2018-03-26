#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->buildInitialList(ui->targetList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildInitialList(QListWidget *xList)
{
    if (!xList) return;
    emit addListItem("this is a test");
    emit addListItem("This is another test");
}

void MainWindow::addListItem(QString xAdd)
{
    this->ui->targetList->addItem(xAdd);
}

void MainWindow::startScan()
{
    emit addListItem("from timer");
    emit addListItem("From timer 2");
}
