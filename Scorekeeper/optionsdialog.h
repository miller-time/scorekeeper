#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
    class optionsDialog;
}

class optionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit optionsDialog(QWidget *parent = 0, QString title = "");
    ~optionsDialog();

    QString getTitle();

private:
    Ui::optionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
