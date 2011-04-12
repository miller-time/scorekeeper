#include <string>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"
#include "optionsdialog.h"
#include "playerwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), num_players(0)
{
    ui->setupUi(this);
    connect(ui->addplayerButton, SIGNAL(clicked()), this, SLOT(addPlayer()));
    connect(ui->actionAdd_Player, SIGNAL(triggered()), this, SLOT(addPlayer()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    on_actionOptions_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPlayer()
{
    addPlayerDialog addPlayerDialogBox;
    if (addPlayerDialogBox.exec())
    {
        QString qname = addPlayerDialogBox.getName();
        std::string name = qname.toStdString();
        if (backend.nameExists(name)) {
            QMessageBox::information(this, "Player Already Exists",
                                     "That player name already exists, please choose another.");
            return;
        }
        PlayerWidget * newplayer = new PlayerWidget(this, qname);
        connect(newplayer, SIGNAL(addPoints(QString,int)), this, SLOT(addPoints(QString,int)));
        ui->playerGrid->addWidget(newplayer);
        backend.addPlayer(name, newplayer);
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionOptions_triggered()
{
    optionsDialog options(this, QString::fromStdString(backend.getTitle()));
    if (options.exec()) {
        QString title = options.getTitle();
        ui->titleLabel->setText(title);
        backend.setTitle(title.toStdString());
    }
}

void MainWindow::on_restartButton_clicked()
{
    backend.zeroScores();
}

void MainWindow::addPoints(QString who, int howmuch)
{
    backend.addPoints(who.toStdString(), howmuch);
}

void MainWindow::on_endButton_clicked()
{
    string winner = backend.getWinner();
    QMessageBox::information(this, "Winner!", "And the winner is...\n" + QString::fromStdString(winner) + "!!!");
}
