#ifndef SCOREKEEPERMODEL_H
#define SCOREKEEPERMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class ScorekeeperModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ScorekeeperModel(QObject *parent = 0);
    virtual ~ScorekeeperModel();

    void addPlayer(const QString &name);
    void removePlayer(const QString &name);
    bool playerExists(const QString &name);
    void clear();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

signals:
    void setSubmitButton(const QModelIndex &mi);
    void clearSubmitButton(const QModelIndex &mi);
    void theCurrentLoserIs(const QString &name);

public slots:
    void submitScores();

private:
    int numRows;
    QStringList nameList;
    QMap <QString, QList<int> > scoreTable;
    QModelIndex submitButtonIndex;
};

#endif // SCOREKEEPERMODEL_H
