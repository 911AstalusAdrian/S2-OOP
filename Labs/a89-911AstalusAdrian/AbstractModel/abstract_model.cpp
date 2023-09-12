#include "abstract_model.h"


AbstractModel::AbstractModel(std::vector<Dog>& dogList, QObject *parent): QAbstractTableModel(parent), list(dogList)
{}

AbstractModel::~AbstractModel() {
}

int AbstractModel::rowCount(const QModelIndex &parent) const {
    return list.size();
}

int AbstractModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant AbstractModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    std::vector<Dog> dogs = list;

    if(row == dogs.size())
        return QVariant();

    Dog d = dogs[row];
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch (col) {
            case 0:
                return QString::fromStdString(d.getBreed());
            case 1:
                return QString::fromStdString(d.getName());
            case 2:
                return QString::fromStdString(to_string(d.getAge()));
            case 3:
                return QString::fromStdString(d.getPhoto());
            default:
                break;
        }
    }

    return QVariant{};
}


