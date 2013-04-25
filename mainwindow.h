#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Point.h"
#include "Brute.h"
#include "Fast.h"

#include <fstream>
#include <QMainWindow>
#include <QPainter>
#include <QMenuBar>
#include <QAction>
#include <QTime>
#include <QFileDialog>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void load();
    void runFast();
    void runBrute();
private:
    vector<Point> raw_input;
    vector<vector<Point> > result;
    QString timer;
    bool isRunning;

    QAction* loadAction;
    QAction* fastAction;
    QAction* bruteAction;
    QAction* exitAction;
};

#endif // MAINWINDOW_H
