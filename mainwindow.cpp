#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer->start(1000);
    time = 10;
    std::stringstream s;
    int tmp = time/60;
    s<<tmp<<":"<<time-tmp*60;
    ui->lblTime->setText(QString(s.str().c_str()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::tick()
{
    time -= 1;
    if(time == 0) timer->stop();

    //warning
    //if(time == 30 || time == 10)

    //label
    std::stringstream s;
    int tmp = time/60;
    s<<tmp<<":";
    tmp = time-tmp*60;
    if(tmp<10)s<<"0";
    s<<tmp;
    ui->lblTime->setText(QString(s.str().c_str()));
}
