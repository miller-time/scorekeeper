#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    ui->playerGrid->addWidget((new QLabel("Player 1")), 0, 0, Qt::AlignLeft);
    ui->playerGrid->addWidget((new QLabel("Player 2")), 1, 0, Qt::AlignLeft);
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
