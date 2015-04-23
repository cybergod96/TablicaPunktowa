#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void tick();

private:
    Ui::MainWindow *ui;
    int time; //seconds
    int score1, score2;
    QTimer *timer;
};

#endif // MAINWINDOW_H
