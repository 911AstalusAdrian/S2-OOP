#include <QFont>
#include <QBrush>
#include <QColor>
#include "model.h"


TModel::TModel(Service& s, int mineCount, int dimensions, std::vector<Player>& playerList, QObject *parent): QAbstractTableModel{parent}, list{playerList}, mineNr{mineCount}, size{dimensions}, serv{s}
{}

int TModel::rowCount(const QModelIndex &parent) const {
    return size;
}

int TModel::columnCount(const QModelIndex &parent) const {
    return size;
}

QVariant TModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        return QString('A' + section);
    }
    if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        return section + 1;
    }
    return QVariant();
}



QVariant TModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();

    if(row == size)
        return QVariant();

    int val = serv.tableData[row][col];

    if(role == Qt::DisplayRole){
        if(val == 9){
            return QString::fromStdString("*");
        }
        else if(val == 2 || val == 1){
            return QString::fromStdString(std::to_string(serv.getMinefieldValue(row, col)));
        }
    }

    if(role == Qt::BackgroundRole){
        if(val == 9){
            return QBrush{QColor{255, 0, 0}};
        }
        else if(val == 2  || val == 1){
            return QBrush{QColor{176,224,230}};
        }
        return QBrush{QColor{144,238,144}};
    }

    if(role == Qt::ForegroundRole){
        return QBrush{QColor{0,0,0}};
    }

    if (role == Qt::TextAlignmentRole )
        return Qt::AlignCenter;

    if(role == Qt::FontRole){
        QFont font = QFont("Times", 20);
        return font;
    }

    return QVariant();
}


