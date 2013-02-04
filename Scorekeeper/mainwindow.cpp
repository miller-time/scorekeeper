#include <QInputDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QTime>

#include "scorekeepermodel.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime::currentTime().msec());
    randomInsults << " is adopted." << " doesn't even know what is happening"
                  << " is an IDIOT! HAHA!!" << " needs to catch up"
                  << " is a pothead, Focker." << " is playing Golf.";

    ui->setupUi(this);
    model = new ScorekeeperModel();
    ui->tableView->setModel(model);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addPlayer()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removePlayer()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(restart()));

    connect(model, SIGNAL(setSubmitButton(QModelIndex)),
            this, SLOT(setSubmitButton(QModelIndex)));
    connect(model, SIGNAL(clearSubmitButton(QModelIndex)),
            this, SLOT(clearSubmitButton(QModelIndex)));

    connect(model, SIGNAL(theCurrentLoserIs(QString)),
            this, SLOT(announceIdiot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPlayer()
{
    QString name = QInputDialog::getText(this, "New Player", "Name:");
    if (!name.isEmpty()) {
        if (!model->playerExists(name))
            model->addPlayer(name);
        else
            QMessageBox::information(this, "Player Already Exists",
                                     "That player name already exists, please choose another.");
    }
}

void MainWindow::removePlayer()
{
    QModelIndexList selectedColumns = ui->tableView->selectionModel()->selectedColumns();
    foreach (QModelIndex mi, selectedColumns) {
        QString name = model->headerData(mi.column()).toString();
        model->removePlayer(name);
    }
}

void MainWindow::restart()
{
    model->clear();
}

void MainWindow::setSubmitButton(const QModelIndex &mi)
{
    QPushButton *submitButton = new QPushButton();
    submitButton->setIcon(QIcon(":/icons/submit.png"));
    connect(submitButton, SIGNAL(clicked()), model, SLOT(submitScores()));
    ui->tableView->setIndexWidget(mi, submitButton);
}

void MainWindow::clearSubmitButton(const QModelIndex &mi)
{
    ui->tableView->setIndexWidget(mi, 0);
}

void MainWindow::announceIdiot(const QString &name)
{
    QString insult = randomInsults.at(qrand() % randomInsults.count());
    QMessageBox::information(this, "LoL Loser", name+insult);
}
