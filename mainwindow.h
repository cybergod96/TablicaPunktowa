#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtMultimedia/QSound>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void UpdateTimeLabel();
    void UpdateScoreLabels();
public slots:
    void tick();

private slots:
    void on_btnP1Cat1C_clicked();

    void on_btnP1Cat1K_clicked();

    void on_btnP1Cat1HC_clicked();

    void on_btnP1Cat1H_clicked();

    void on_btnPlayer1AddScore_clicked();

    void on_btnReset_clicked();

    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnSettings_clicked();

    void on_pbPlayer2AddScore_clicked();

    void on_btnP2Cat1C_clicked();

    void on_btnP2Cat1K_clicked();

    void on_btnP2Cat1HC_clicked();

    void on_btnP2Cat1H_clicked();

    void on_btnP1Cat2C_clicked();

    void on_btnP1Cat2K_clicked();

    void on_btnP1Cat2HC_clicked();

    void on_btnP1Cat2H_clicked();

    void on_btnP2Cat2C_clicked();

    void on_btnP2Cat2K_clicked();

    void on_btnP2Cat2HC_clicked();

    void on_btnP2Cat2H_clicked();

private:
    Ui::MainWindow *ui;
    int time, chosen_time; //seconds
    int score1, score2;
    QTimer *timer;
    QSound *sound;
    bool settings;
    void CheckPenalties();
};

#endif // MAINWINDOW_H
