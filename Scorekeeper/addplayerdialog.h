#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>

namespace Ui {
    class addPlayerDialog;
}

class addPlayerDialog : public QDialog {
    Q_OBJECT
public:
    addPlayerDialog(QWidget *parent = 0);
    ~addPlayerDialog();
    QString getName();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::addPlayerDialog *ui;
};

#endif // ADDPLAYERDIALOG_H
