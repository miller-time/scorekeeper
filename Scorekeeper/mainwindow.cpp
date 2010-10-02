#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), num_players(0)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->addplayerButton, SIGNAL(clicked()), this, SLOT(addPlayer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPlayer()
{
    ui->playerGrid->addWidget((new QLabel("New Player")), num_players, 0, Qt::AlignLeft);
    ui->playerGrid->addWidget((new QLabel("0")), num_players, 1, Qt::AlignLeft);
    ui->playerGrid->addWidget(new QPushButton("Add Points"), num_players++, 2, Qt::AlignRight);
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
