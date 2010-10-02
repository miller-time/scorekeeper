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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    int num_players;
    Score backend;
};

#endif // MAINWINDOW_H
