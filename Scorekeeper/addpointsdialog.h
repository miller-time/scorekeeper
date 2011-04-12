#ifndef ADDPOINTSDIALOG_H
#define ADDPOINTSDIALOG_H

#include <QDialog>

namespace Ui {
    class addpointsDialog;
}

class addpointsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addpointsDialog(QWidget *parent = 0);
    ~addpointsDialog();
    int getPoints();

private:
    Ui::addpointsDialog *ui;
};

#endif // ADDPOINTSDIALOG_H
