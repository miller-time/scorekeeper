#include <iostream>
#include "playerwidget.h"
#include "ui_playerwidget.h"
#include "addpointsdialog.h"
using std::cout;

PlayerWidget::PlayerWidget(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::PlayerWidget)
{
    ui->setupUi(this);
    ui->nameLabel->setText(name);
    ui->points->setText(QString("0"));
}

PlayerWidget::~PlayerWidget()
{
    delete ui;
}

void PlayerWidget::zeroScore()
{
    ui->points->setText(QString("0"));
}

void PlayerWidget::on_addpointsButton_clicked()
{
    addpointsDialog dialog;
    if (dialog.exec()) {
        int howmuch = dialog.getPoints();
        int current = ui->points->text().toInt();
        ui->points->setText(QString("").setNum(howmuch + current));
        emit addPoints(ui->nameLabel->text(), howmuch);
    }
}
