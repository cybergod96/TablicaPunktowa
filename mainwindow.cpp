#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnPlayer1AddScore->hide();
    ui->pbPlayer2AddScore->hide();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(tick()));
    score1 = score2 = time = chosen_time = 0;
    UpdateScoreLabels();
    UpdateTimeLabel();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::tick()
{
    time -= 1;
    if(time == 0) { timer->stop(); QSound::play("/horn.wav"); }

    //warning
    if(time == 30 || time == 10) { QSound::play("/horn.wav"); }

    if(score1-score2 == 8 || score2-score1 == 8)
    {
        timer->stop();
        ui->btnPlayer1AddScore->hide();
        ui->pbPlayer2AddScore->hide();
        QSound::play("/horn.wav");
    }

    if(        ui->btnP1Cat1C->isChecked() && ui->btnP1Cat1K->isChecked()
            && ui->btnP1Cat1HC->isChecked()&& ui->btnP1Cat1H->isChecked()
            && ui->btnP1Cat2C->isChecked() && ui->btnP1Cat2H->isChecked()
            && ui->btnP1Cat2HC->isChecked()&& ui->btnP1Cat2K->isChecked())
    {
        QSound::play("/horn.wav");
        timer->stop();
        ui->btnPlayer1AddScore->hide();
        ui->pbPlayer2AddScore->hide();
    }

    if(        ui->btnP2Cat1C->isChecked() && ui->btnP2Cat1K->isChecked()
            && ui->btnP2Cat1HC->isChecked()&& ui->btnP2Cat1H->isChecked()
            && ui->btnP2Cat2C->isChecked() && ui->btnP2Cat2H->isChecked()
            && ui->btnP2Cat2HC->isChecked()&& ui->btnP2Cat2K->isChecked())
    {
        QSound::play("/horn.wav");
        timer->stop();
        ui->btnPlayer1AddScore->hide();
        ui->pbPlayer2AddScore->hide();
    }

    //label
    /*std::stringstream s;
    int tmp = time/60;
    s<<tmp<<":";
    tmp = time-tmp*60;
    if(tmp<10)s<<"0";
    s<<tmp;
    ui->lblTime->setText(QString(s.str().c_str()));*/
    UpdateTimeLabel();
}

void MainWindow::on_btnP1Cat1C_clicked()
{
    if(ui->btnP1Cat1C->isChecked()) ui->btnP1Cat1C->setStyleSheet("background-color: yellow;");
    else ui->btnP1Cat1C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat1K_clicked()
{
    if(ui->btnP1Cat1K->isChecked()) ui->btnP1Cat1K->setStyleSheet("background-color: yellow;");
    else ui->btnP1Cat1K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat1HC_clicked()
{
    if(ui->btnP1Cat1HC->isChecked()) ui->btnP1Cat1HC->setStyleSheet("background-color: yellow;");
    else ui->btnP1Cat1HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat1H_clicked()
{
    if(ui->btnP1Cat1H->isChecked()) ui->btnP1Cat1H->setStyleSheet("background-color: yellow;");
    else ui->btnP1Cat1H->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnPlayer1AddScore_clicked()
{
    score1++;
    UpdateScoreLabels();
}

void MainWindow::on_btnReset_clicked()
{
    score1 = score2 = 0;
    time = chosen_time;
    timer->stop();
    UpdateScoreLabels();
    UpdateTimeLabel();
    ui->btnStart->show();
    ui->btnPlayer1AddScore->hide();
    ui->pbPlayer2AddScore->hide();
    ui->btnP1Cat1C->setChecked(false);
    ui->btnP1Cat1C->setStyleSheet("background-color: grey;");
    ui->btnP1Cat1H->setChecked(false);
    ui->btnP1Cat1H->setStyleSheet("background-color: grey;");
    ui->btnP1Cat1HC->setChecked(false);
    ui->btnP1Cat1HC->setStyleSheet("background-color: grey;");
    ui->btnP1Cat1K->setChecked(false);
    ui->btnP1Cat1K->setStyleSheet("background-color: grey;");
    ui->btnP1Cat2C->setChecked(false);
    ui->btnP1Cat2C->setStyleSheet("background-color: grey;");
    ui->btnP1Cat2H->setChecked(false);
    ui->btnP1Cat2H->setStyleSheet("background-color: grey;");
    ui->btnP1Cat2HC->setChecked(false);
    ui->btnP1Cat2HC->setStyleSheet("background-color: grey;");
    ui->btnP1Cat2K->setChecked(false);
    ui->btnP1Cat2K->setStyleSheet("background-color: grey;");
    ui->btnP2Cat1C->setChecked(false);
    ui->btnP2Cat1C->setStyleSheet("background-color: grey;");
    ui->btnP2Cat1H->setChecked(false);
    ui->btnP2Cat1H->setStyleSheet("background-color: grey;");
    ui->btnP2Cat1HC->setChecked(false);
    ui->btnP2Cat1HC->setStyleSheet("background-color: grey;");
    ui->btnP2Cat1K->setChecked(false);
    ui->btnP2Cat1K->setStyleSheet("background-color: grey;");
    ui->btnP2Cat2C->setChecked(false);
    ui->btnP2Cat2C->setStyleSheet("background-color: grey;");
    ui->btnP2Cat2H->setChecked(false);
    ui->btnP2Cat2H->setStyleSheet("background-color: grey;");
    ui->btnP2Cat2HC->setChecked(false);
    ui->btnP2Cat2HC->setStyleSheet("background-color: grey;");
    ui->btnP2Cat2K->setChecked(false);
    ui->btnP2Cat2K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnStart_clicked()
{
    QSound::play("/horn.wav");
    ui->btnPlayer1AddScore->show();
    ui->pbPlayer2AddScore->show();
    ui->btnStart->hide();
    timer->start(1000);

}

void MainWindow::on_btnPause_clicked()
{
    timer->stop();
}

void MainWindow::on_btnSettings_clicked()
{
    Dialog *dlg = new Dialog();
    dlg->Init(ui->gbPlayer1->title(),ui->gbPlayer2->title());
    if(dlg->exec() == QDialog::Accepted)
    {
        ui->gbPlayer1->setTitle(dlg->GetPlayer1Name());
        ui->gbPlayer2->setTitle(dlg->GetPlayer2Name());
        time = chosen_time = dlg->GetRoundDuration();
        UpdateScoreLabels();
        UpdateTimeLabel();
    }
}

void MainWindow::UpdateTimeLabel()
{
    std::stringstream s;
    int tmp = time/60;
    s<<tmp<<":";
    tmp = time-tmp*60;
    if(tmp<10)s<<"0";
    s<<tmp;
    ui->lblTime->setText(QString(s.str().c_str()));
}

void MainWindow::UpdateScoreLabels()
{
    std::stringstream s;
    s<<score1;
    ui->lblScore1->setText(QString(s.str().c_str()));
    s.str("");
    s<<score2;
    ui->lblScore2->setText(QString(s.str().c_str()));
}

void MainWindow::on_pbPlayer2AddScore_clicked()
{
    score2++;
    UpdateScoreLabels();
}

void MainWindow::on_btnP2Cat1C_clicked()
{
    if(ui->btnP2Cat1C->isChecked()) ui->btnP2Cat1C->setStyleSheet("background-color: yellow;");
    else ui->btnP2Cat1C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat1K_clicked()
{
    if(ui->btnP2Cat1K->isChecked()) ui->btnP2Cat1K->setStyleSheet("background-color: yellow;");
    else ui->btnP2Cat1K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat1HC_clicked()
{
    if(ui->btnP2Cat1HC->isChecked()) ui->btnP2Cat1HC->setStyleSheet("background-color: yellow;");
    else ui->btnP2Cat1HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat1H_clicked()
{
    if(ui->btnP2Cat1H->isChecked()) ui->btnP2Cat1H->setStyleSheet("background-color: yellow;");
    else ui->btnP2Cat1H->setStyleSheet("background-color: grey;");
}
//-------------------
void MainWindow::on_btnP1Cat2C_clicked()
{
    if(ui->btnP1Cat2C->isChecked()) ui->btnP1Cat2C->setStyleSheet("background-color: yellow;");
        else ui->btnP1Cat2C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2K_clicked()
{
    if(ui->btnP1Cat2K->isChecked()) ui->btnP1Cat2K->setStyleSheet("background-color: yellow;");
        else ui->btnP1Cat2K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2HC_clicked()
{
    if(ui->btnP1Cat2HC->isChecked()) ui->btnP1Cat2HC->setStyleSheet("background-color: yellow;");
        else ui->btnP1Cat2HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2H_clicked()
{
    if(ui->btnP1Cat2H->isChecked()) ui->btnP1Cat2H->setStyleSheet("background-color: yellow;");
        else ui->btnP1Cat2H->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2C_clicked()
{
    if(ui->btnP2Cat2C->isChecked()) ui->btnP2Cat2C->setStyleSheet("background-color: yellow;");
        else ui->btnP2Cat2C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2K_clicked()
{
    if(ui->btnP2Cat2K->isChecked()) ui->btnP2Cat2K->setStyleSheet("background-color: yellow;");
        else ui->btnP2Cat2K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2HC_clicked()
{
    if(ui->btnP2Cat2HC->isChecked()) ui->btnP2Cat2HC->setStyleSheet("background-color: yellow;");
        else ui->btnP2Cat2HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2H_clicked()
{
    if(ui->btnP2Cat2H->isChecked()) ui->btnP2Cat2H->setStyleSheet("background-color: yellow;");
    else ui->btnP2Cat2H->setStyleSheet("background-color: grey;");
}
