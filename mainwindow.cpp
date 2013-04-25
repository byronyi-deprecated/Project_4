#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadAction = menuBar()->addAction(tr("Load"));
    bruteAction = menuBar()->addAction(tr("Brute"));
    fastAction = menuBar()->addAction(tr("Fast"));
    exitAction = menuBar()->addAction(tr("Exit"));

    connect(loadAction, SIGNAL(triggered()),
            this, SLOT(load()));
    connect(bruteAction, SIGNAL(triggered()),
            this, SLOT(runBrute()));
    connect(fastAction, SIGNAL(triggered()),
            this, SLOT(runFast()));
    connect(exitAction, SIGNAL(triggered()),
            this, SLOT(close()));

    setMinimumSize(600, 500);
    setMaximumSize(600, 500);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QColor(Qt::red));

    for(vector<Point>::iterator iter = raw_input.begin();
        iter != raw_input.end(); ++iter) {
        painter.drawArc(iter->getX() / 64 - 3,
                        menuBar()->height() + iter->getY() / 64 - 3,
                        5, 5, 0, 360 * 16);
    }

    for(vector<vector<Point> >::iterator iter1 = result.begin();
        iter1 != result.end(); ++iter1)
    {
        for(vector<Point>::iterator iter2 = iter1->begin();
            iter2 != iter1->end(); ++iter2)
        {
            painter.drawLine(iter1->begin()->getX() / 64,
                             menuBar()->height() + iter1->begin()->getY() / 64,
                             iter2->getX() / 64,
                             menuBar()->height() + iter2->getY() / 64);
        }
    }

    painter.drawText(QRect(500, 450, 100, 50), timer);
}

void MainWindow::load()
{
    raw_input.clear();
    result.clear();
    QString fileName = QFileDialog::getOpenFileName(this, "", ".", "*.txt");
    ifstream file(fileName.toStdString().c_str());
    int num_input = 0;

    if(!file.is_open())
        return;

    file >> num_input;

    for(int i = 0; i != num_input; ++i)
    {
        if(file.eof())
            return;

        int x, y;
        file >> x >> y;
        raw_input.push_back(Point(x, y));
    }

    update();
}

void MainWindow::runBrute()
{
    QTime time;
    time.start();
    Brute(raw_input, result);
    timer = "Time elapsed: " + QString::number(time.elapsed()) + " ms";
    update();
}

void MainWindow::runFast()
{
    QTime time;
    time.start();
    Fast(raw_input, result);
    timer = "Time elapsed: " + QString::number(time.elapsed()) + " ms";
    update();
}
