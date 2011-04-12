#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "score.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addPlayer();
    void addPoints(QString, int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    int num_players;
    Score backend;

private slots:
    void on_endButton_clicked();
    void on_restartButton_clicked();
    void on_actionOptions_triggered();
};

#endif // MAINWINDOW_H
