#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::GetRoundDuration()
{
    if(ui->rb330->isChecked()) return 210;
    else if(ui->rb300->isChecked()) return 180;
    else if(ui->rb230->isChecked()) return 150;
    else if(ui->rb200->isChecked()) return 120;
    else if(ui->rb130->isChecked()) return 90;
    else if(ui->rb100->isChecked()) return 60;
}

QString Dialog::GetPlayer1Name()
{
    return ui->txtPlayer1Name->toPlainText();
}

QString Dialog::GetPlayer2Name()
{
    return ui->txtPlayer2Name->toPlainText();
}

void Dialog::on_Dialog_accepted()
{
    if(!(ui->rb100->isChecked() || ui->rb130->isChecked() || ui->rb200->isChecked() || ui->rb230->isChecked() || ui->rb300->isChecked() || ui->rb330->isChecked()))
        QMessageBox::warning(this,"Uwaga","Musisz wybrać czas trwania rundy!");
    if(ui->txtPlayer1Name->toPlainText().isEmpty() || ui->txtPlayer2Name->toPlainText().isEmpty())
        QMessageBox::warning(this,"Uwaga","Musisz wpisać nazwy zawodników!");

}

void Dialog::Init(QString p1, QString p2)
{
    ui->txtPlayer1Name->setPlainText(p1);
    ui->txtPlayer2Name->setPlainText(p2);
}
