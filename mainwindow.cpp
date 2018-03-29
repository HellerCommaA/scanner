#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QListWidget>
#include <QFileDialog>
#include <QString>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


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
    try
    {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::Options::Url>("http://google.com");

        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();

    }

    catch(curlpp::RuntimeError & e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(curlpp::LogicError & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void MainWindow::fileOpen()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr(""),
                ".",
                "*.json",
                nullptr,
                nullptr
    );
    std::cerr << "filename " << filename.toStdString() << std::endl;
}
