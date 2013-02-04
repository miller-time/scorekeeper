#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class ScorekeeperModel;
class QLineEdit;
class QModelIndex;
class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addPlayer();
    void removePlayer();
    void restart();
    void setSubmitButton(const QModelIndex &mi);
    void clearSubmitButton(const QModelIndex &mi);
    void announceIdiot(const QString &name);

private:
    Ui::MainWindow *ui;
    ScorekeeperModel *model;
    QList<QLineEdit*> scoreInputs;
    QStringList randomInsults;
};

#endif // MAINWINDOW_H
