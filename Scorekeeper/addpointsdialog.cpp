#include "addpointsdialog.h"
#include "ui_addpointsdialog.h"

addpointsDialog::addpointsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addpointsDialog)
{
    ui->setupUi(this);
    ui->points->setFocus();
}

addpointsDialog::~addpointsDialog()
{
    delete ui;
}

int addpointsDialog::getPoints()
{
    return ui->points->text().toInt();
}
