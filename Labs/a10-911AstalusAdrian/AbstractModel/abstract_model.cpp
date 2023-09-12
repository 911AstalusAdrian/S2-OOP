#include <QFont>
#include <QBrush>
#include <QColor>
#include "abstract_model.h"


AbstractModel::AbstractModel(std::vector<Dog>& dogList, QObject *parent): QAbstractTableModel{parent}, list{dogList}
{}

AbstractModel::~AbstractModel() {
}

int AbstractModel::rowCount(const QModelIndex &parent) const {
    return (int)list.size();
}

int AbstractModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant AbstractModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
            case 0:
                return QString("Breed");
            case 1:
                return QString("Name");
            case 2:
                return QString("Age");
            case 3:
                return QString("Link");
            case 4:
                return QString("Photo");
            default:
                break;
        }
    }

    return QVariant();
}



QVariant AbstractModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    std::vector<Dog> dogs = list;

    if(row == dogs.size())
        return QVariant();

    Dog d = list[row];
    if(role == Qt::DisplayRole){
        switch (col) {
            case 0:
                return QString::fromStdString(d.getBreed());
            case 1:
                return QString::fromStdString(d.getName());
            case 2:
                return QString::fromStdString(to_string(d.getAge()));
            case 3:
                return QString::fromStdString(d.getPhoto());
            case 4:
                return QString::fromStdString(d.getBreed());
            default:
                break;
        }
    }

    if(role == Qt::BackgroundRole){
        if(row % 2 == 1)
            return QBrush{QColor{239,201,175}};
        else
            return QBrush{QColor{31,138,192}};
    }

    if(role == Qt::ForegroundRole){
        if(row % 2 == 1)
            return QBrush{QColor{31,138,192}};
        else
            return QBrush{QColor{239,201,175}};
    }

    return QVariant();
}


