#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnPlayer1AddScore->setEnabled(false);
    ui->pbPlayer2AddScore->setEnabled(false);
    ui->btnP1Cat1C->setEnabled(false);
    ui->btnP1Cat1H->setEnabled(false);
    ui->btnP1Cat1K->setEnabled(false);
    ui->btnP1Cat2K->setEnabled(false);
    ui->btnP1Cat1HC->setEnabled(false);
    ui->btnP1Cat2C->setEnabled(false);
    ui->btnP1Cat2H->setEnabled(false);
    ui->btnP1Cat2HC->setEnabled(false);

    ui->btnP2Cat1K->setEnabled(false);
    ui->btnP2Cat2K->setEnabled(false);
    ui->btnP2Cat1C->setEnabled(false);
    ui->btnP2Cat1H->setEnabled(false);
    ui->btnP2Cat1HC->setEnabled(false);
    ui->btnP2Cat2C->setEnabled(false);
    ui->btnP2Cat2H->setEnabled(false);
    ui->btnP2Cat2HC->setEnabled(false);
    ui->btnPause->setEnabled(false);
    timer = new QTimer(this);
    sound = new QSound(":/sound/horn.wav");
    connect(timer,SIGNAL(timeout()),this,SLOT(tick()));
    score1 = score2 = time = chosen_time = 0;
    settings = false;
    UpdateScoreLabels();
    UpdateTimeLabel();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete sound;
    delete ui;
}

void MainWindow::tick()
{
    time -= 1;
    if(time == 0)
    {
        timer->stop();
        sound->play();
        ui->btnStart->setEnabled(true);
        ui->btnPause->setEnabled(false);
        ui->btnSettings->setEnabled(true);
        ui->btnReset->setEnabled(true);
    }

    //warning
    if(time == 30 || time == 10) { sound->play(); }

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
    ui->btnStart->setEnabled(true);
    ui->btnPlayer1AddScore->setEnabled(false);
    ui->pbPlayer2AddScore->setEnabled(false);

    ui->btnP1Cat1C->setEnabled(false);
    ui->btnP1Cat1H->setEnabled(false);
    ui->btnP1Cat1HC->setEnabled(false);
    ui->btnP1Cat2C->setEnabled(false);
    ui->btnP1Cat2H->setEnabled(false);
    ui->btnP1Cat2HC->setEnabled(false);
    ui->btnP1Cat1K->setEnabled(false);
    ui->btnP1Cat2K->setEnabled(false);

    ui->btnP2Cat1K->setEnabled(false);
    ui->btnP2Cat2K->setEnabled(false);
    ui->btnP2Cat1C->setEnabled(false);
    ui->btnP2Cat1H->setEnabled(false);
    ui->btnP2Cat1HC->setEnabled(false);
    ui->btnP2Cat2C->setEnabled(false);
    ui->btnP2Cat2H->setEnabled(false);
    ui->btnP2Cat2HC->setEnabled(false);
    ui->btnSettings->setEnabled(true);

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
    if(!settings) {QMessageBox::warning(this,"Uwaga","Nie ustawiono czasu trwania i nazw zawodników!"); return;}
    sound->play();
    ui->btnPlayer1AddScore->setEnabled(true);
    ui->pbPlayer2AddScore->setEnabled(true);
    ui->btnP1Cat1C->setEnabled(true);
    ui->btnP1Cat1H->setEnabled(true);
    ui->btnP1Cat1HC->setEnabled(true);
    ui->btnP1Cat2C->setEnabled(true);
    ui->btnP1Cat2H->setEnabled(true);
    ui->btnP1Cat2HC->setEnabled(true);
    ui->btnP1Cat1K->setEnabled(true);
    ui->btnP1Cat2K->setEnabled(true);

    ui->btnP2Cat1K->setEnabled(true);
    ui->btnP2Cat2K->setEnabled(true);
    ui->btnP2Cat1C->setEnabled(true);
    ui->btnP2Cat1H->setEnabled(true);
    ui->btnP2Cat1HC->setEnabled(true);
    ui->btnP2Cat2C->setEnabled(true);
    ui->btnP2Cat2H->setEnabled(true);
    ui->btnP2Cat2HC->setEnabled(true);
    ui->btnStart->setEnabled(false);
    ui->btnPause->setEnabled(true);
    ui->btnReset->setEnabled(false);
    ui->btnSettings->setEnabled(false);
    timer->start(1000);

}

void MainWindow::on_btnPause_clicked()
{
    timer->stop();
    ui->btnStart->setEnabled(true);
    ui->btnPause->setEnabled(false);
    ui->btnReset->setEnabled(true);
    ui->btnSettings->setEnabled(true);
}

void MainWindow::on_btnSettings_clicked()
{
    settings = true;
    Dialog *dlg = new Dialog();
    dlg->Init(ui->gbPlayer1->title(),ui->gbPlayer2->title(),chosen_time);
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

    if(score1-score2 == 8 || score2-score1 == 8)
    {
        timer->stop();
        sound->play();
        ui->btnPlayer1AddScore->setEnabled(false);
        ui->pbPlayer2AddScore->setEnabled(false);
        ui->btnPause->setEnabled(false);
        ui->btnStart->setEnabled(true);
        ui->btnSettings->setEnabled(true);
        ui->btnReset->setEnabled(true);

        ui->btnP1Cat1C->setEnabled(false);
        ui->btnP1Cat1H->setEnabled(false);
        ui->btnP1Cat1K->setEnabled(false);
        ui->btnP1Cat2K->setEnabled(false);
        ui->btnP1Cat1HC->setEnabled(false);
        ui->btnP1Cat2C->setEnabled(false);
        ui->btnP1Cat2H->setEnabled(false);
        ui->btnP1Cat2HC->setEnabled(false);

        ui->btnP2Cat1K->setEnabled(false);
        ui->btnP2Cat2K->setEnabled(false);
        ui->btnP2Cat1C->setEnabled(false);
        ui->btnP2Cat1H->setEnabled(false);
        ui->btnP2Cat1HC->setEnabled(false);
        ui->btnP2Cat2C->setEnabled(false);
        ui->btnP2Cat2H->setEnabled(false);
        ui->btnP2Cat2HC->setEnabled(false);

    }
}

void MainWindow::on_pbPlayer2AddScore_clicked()
{
    score2++;
    UpdateScoreLabels();
}

void MainWindow::on_btnP2Cat1C_clicked()
{
    if(ui->btnP2Cat1C->isChecked()) {ui->btnP2Cat1C->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat1C->setStyleSheet("background-color: grey;");

}

void MainWindow::on_btnP2Cat1K_clicked()
{
    if(ui->btnP2Cat1K->isChecked()) {ui->btnP2Cat1K->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat1K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat1HC_clicked()
{
    if(ui->btnP2Cat1HC->isChecked()) {ui->btnP2Cat1HC->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat1HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat1H_clicked()
{
    if(ui->btnP2Cat1H->isChecked()) {ui->btnP2Cat1H->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat1H->setStyleSheet("background-color: grey;");
}
//-------------------
void MainWindow::on_btnP1Cat2C_clicked()
{
    if(ui->btnP1Cat2C->isChecked()) {ui->btnP1Cat2C->setStyleSheet("background-color: yellow;"); CheckPenalties();}
        else ui->btnP1Cat2C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2K_clicked()
{
    if(ui->btnP1Cat2K->isChecked()) {ui->btnP1Cat2K->setStyleSheet("background-color: yellow;"); CheckPenalties();}
        else ui->btnP1Cat2K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2HC_clicked()
{
    if(ui->btnP1Cat2HC->isChecked()) {ui->btnP1Cat2HC->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP1Cat2HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP1Cat2H_clicked()
{
    if(ui->btnP1Cat2H->isChecked()) {ui->btnP1Cat2H->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP1Cat2H->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2C_clicked()
{
    if(ui->btnP2Cat2C->isChecked()) {ui->btnP2Cat2C->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat2C->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2K_clicked()
{
    if(ui->btnP2Cat2K->isChecked()) {ui->btnP2Cat2K->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat2K->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2HC_clicked()
{
    if(ui->btnP2Cat2HC->isChecked()) {ui->btnP2Cat2HC->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat2HC->setStyleSheet("background-color: grey;");
}

void MainWindow::on_btnP2Cat2H_clicked()
{
    if(ui->btnP2Cat2H->isChecked()) {ui->btnP2Cat2H->setStyleSheet("background-color: yellow;"); CheckPenalties();}
    else ui->btnP2Cat2H->setStyleSheet("background-color: grey;");
}

void MainWindow::CheckPenalties()
{
    if((       ui->btnP1Cat1C->isChecked() && ui->btnP1Cat1K->isChecked()
            && ui->btnP1Cat1HC->isChecked()&& ui->btnP1Cat1H->isChecked()
            && ui->btnP1Cat2C->isChecked() && ui->btnP1Cat2H->isChecked()
            && ui->btnP1Cat2HC->isChecked()&& ui->btnP1Cat2K->isChecked()) ||

            (   ui->btnP2Cat1C->isChecked() && ui->btnP2Cat1K->isChecked()
             && ui->btnP2Cat1HC->isChecked()&& ui->btnP2Cat1H->isChecked()
             && ui->btnP2Cat2C->isChecked() && ui->btnP2Cat2H->isChecked()
             && ui->btnP2Cat2HC->isChecked()&& ui->btnP2Cat2K->isChecked()))
    {
        sound->play();
        timer->stop();
        ui->btnPlayer1AddScore->setEnabled(false);
        ui->pbPlayer2AddScore->setEnabled(false);
        ui->btnStart->setEnabled(true);
        ui->btnPause->setEnabled(false);
        ui->btnSettings->setEnabled(true);
        ui->btnReset->setEnabled(true);
    }
}
