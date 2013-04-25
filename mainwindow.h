#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QAction>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void runBrute();
    void runFast();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void load();
private:
    QTimer* timer;
    QWidget* canvas;

    QAction* loadAction;
    QAction* bruteAction;
    QAction* fastAction;
    QAction* exitAction;

};

#endif // MAINWINDOW_H
