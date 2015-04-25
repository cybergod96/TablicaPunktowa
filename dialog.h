#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    int GetRoundDuration();
    QString GetPlayer1Name();
    QString GetPlayer2Name();
    void Init(QString p1, QString p2);

private slots:
    void on_Dialog_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
