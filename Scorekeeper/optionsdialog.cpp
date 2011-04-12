#include <QMessageBox>
#include "optionsdialog.h"
#include "ui_optionsdialog.h"

optionsDialog::optionsDialog(QWidget *parent, QString title) :
    QDialog(parent),
    ui(new Ui::optionsDialog)
{
    ui->setupUi(this);
    ui->titleEdit->setText(title);
}

optionsDialog::~optionsDialog()
{
    delete ui;
}

QString optionsDialog::getTitle()
{
    return ui->titleEdit->text();
}
