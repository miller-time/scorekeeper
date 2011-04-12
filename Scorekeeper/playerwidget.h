#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>

namespace Ui {
    class PlayerWidget;
}

class PlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerWidget(QWidget *parent = 0, QString name = "");
    ~PlayerWidget();
    void zeroScore();

signals:
    void addPoints(QString, int);

private:
    Ui::PlayerWidget *ui;

private slots:
    void on_addpointsButton_clicked();
};

#endif // PLAYERWIDGET_H
