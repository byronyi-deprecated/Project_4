#include "mainwindow.h"
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadAction= menuBar()->addAction(tr("&Load"));
    bruteAction = menuBar()->addAction(tr("&Brute"));
    fastAction = menuBar()->addAction(tr("&Fast"));
    exitAction = menuBar()->addAction(tr("&Exit"));

    connect(loadAction, SIGNAL(triggered()), this, SLOT(load()));
    connect(bruteAction, SIGNAL(triggered()), this, SLOT(runBrute()));
    connect(fastAction, SIGNAL(triggered()), this, SLOT(runFast()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::runBrute()
{

}

void MainWindow::runFast()
{

}

void MainWindow::load()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load text file...",
                                                "", "*.txt");
    ifstream file(fileName.toStdString().c_str());
    if(!file.is_open())
        return;

}

void MainWindow::paintEvent(QPaintEvent *)
{

}
