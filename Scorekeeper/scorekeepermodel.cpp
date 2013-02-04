#include <QDebug>
#include <QLabel>
#include <QLineEdit>

#include "scorekeepermodel.h"

ScorekeeperModel::ScorekeeperModel(QObject *parent) :
    QAbstractTableModel(parent),
    numRows(0)
{
}

ScorekeeperModel::~ScorekeeperModel()
{
}

void ScorekeeperModel::addPlayer(const QString &name)
{
    if (!playerExists(name)) {
        bool firstPlayer = nameList.isEmpty();
        int column = nameList.count();
        beginInsertColumns(QModelIndex(), column, column);
        if (firstPlayer) {
            numRows = 1;
            beginInsertRows(QModelIndex(), 0, 0);
        }
        nameList.append(name);
        QList<int> zeroList;
        for (int i = 0; i < numRows; ++i)
            zeroList.append(0);
        scoreTable.insert(name, zeroList);
        endInsertColumns();
        if (firstPlayer) {
            endInsertRows();
            beginInsertColumns(QModelIndex(), column+1, column+1);
            endInsertColumns();
        }
        emit clearSubmitButton(submitButtonIndex);
        submitButtonIndex = index(numRows - 1, column+1);
        emit setSubmitButton(submitButtonIndex);
    }
}

void ScorekeeperModel::removePlayer(const QString &name)
{
    int column = nameList.indexOf(name);
    if (column != -1) {
        bool lastPlayer = nameList.count() == 1;
        beginRemoveColumns(QModelIndex(), column, column);
        if (lastPlayer)
            beginRemoveRows(QModelIndex(), 0, 0);
        nameList.removeAt(column);
        scoreTable.remove(name);
        endRemoveColumns();
        if (lastPlayer) {
            endRemoveRows();
            beginRemoveColumns(QModelIndex(), 0, 0);
            endRemoveColumns();
        }
    }
}

bool ScorekeeperModel::playerExists(const QString &name)
{
    return nameList.contains(name);
}

void ScorekeeperModel::clear()
{
    beginResetModel();
    foreach (QString name, nameList) {
        scoreTable[name].clear();
        scoreTable[name].append(0);
    }
    numRows = 1;
    endResetModel();
    submitButtonIndex = index(0, nameList.count());
    emit setSubmitButton(submitButtonIndex);
}

int ScorekeeperModel::rowCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? numRows : 0;
}

int ScorekeeperModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return nameList.isEmpty() ? 0 : nameList.count() + 1;
}

QVariant ScorekeeperModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        if (index.column() == nameList.count()) {
            return QVariant();
        }
        return scoreTable.value(nameList.at(index.column())).at(index.row());
    }
    return QVariant();
}

QVariant ScorekeeperModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section >= 0 && section < nameList.count()) {
            return nameList.at(section);
        }
    }
    return QVariant();
}

Qt::ItemFlags ScorekeeperModel::flags(const QModelIndex &index) const
{
    if (index.column() != nameList.count() && (index.row() == numRows-1))
            return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}

bool ScorekeeperModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole && index.column() < nameList.count()) {
        scoreTable[nameList.at(index.column())][index.row()] = value.toInt();
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

void ScorekeeperModel::submitScores()
{
    int lowestScore = INT_MAX;
    QString loser;
    int rc = rowCount();
    beginInsertRows(QModelIndex(), rc, rc);
    foreach (QString name, nameList) {
        // lookup current score and new value to add.
        QList<int> scoreHistory = scoreTable.value(name);
        int score;
        if (scoreHistory.count() == 1) {
            score = scoreHistory.at(0);
        } else {
            int currentScorePos = scoreHistory.count() - 2;
            score = scoreHistory.at(currentScorePos) + scoreHistory.at(currentScorePos + 1);
        }
        if (score < lowestScore) {
            lowestScore = score;
            loser = name;
        }
        // add new subtotal to the end
        scoreTable[name].append(score);
    }
    ++numRows;
    endInsertRows();

    // clear the submit button
    emit clearSubmitButton(submitButtonIndex);

    // add new edit row
    beginInsertRows(QModelIndex(), rc+1, rc+1);
    foreach (QString name, nameList) {
        scoreTable[name].append(0);
    }
    ++numRows;
    endInsertRows();

    // add new submit button
    submitButtonIndex = index(rc+1, nameList.count());
    emit setSubmitButton(submitButtonIndex);

    emit theCurrentLoserIs(loser);
}
