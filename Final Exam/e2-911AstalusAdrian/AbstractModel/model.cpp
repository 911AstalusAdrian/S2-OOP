#include "model.h"
#include <QBrush>
#include <QColor>

TableModel::TableModel(Service &newService): service{newService} {
    std::string giftShop = service.giftShop();
    rows = giftShop.at(1) - '0' - 1;
    giftShop[1] = 0;
    cols = giftShop.at(0) - 64;
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return rows+1;
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return cols+1;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    std::string data;
    if(role == Qt::DisplayRole) {
        std::vector<Building> allB = service.getBuildingsServ();
        for (auto building:allB) {
            std::vector<int> coords = service.getBuildingCoordinates(building);
            for (int c:coords) {
                if (row == c % 10 && col == c / 10) {
                    return QString::fromStdString(building.getArea());
                }
            }
        }
    }

    if(role == Qt::BackgroundRole){
        if(row == rows && col == cols){
            return QBrush{QColor{0, 0, 0}};
        }

    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("1");
                case 1:
                    return QString("2");
                case 2:
                    return QString("3");
                case 3:
                    return QString("4");
                    case 4:
                    return QString("5");
                    case 5:
                    return QString("6");
                    case 6:
                    return QString("7");
                    case 7:
                    return QString("8");
                    case 8:
                    return QString("9");
                default:
                    break;
            }
        }
        if(orientation == Qt::Vertical){
            switch (section) {
                case 0:
                    return QString("A");
                case 1:
                    return QString("B");
                case 2:
                    return QString("C");
                case 3:
                    return QString("D");
                case 4:
                    return QString("E");
                case 5:
                    return QString("F");
                case 6:
                    return QString("G");
                case 7:
                    return QString("H");
                case 8:
                    return QString("I");
                default:
                    break;
            }
        }
    }
    return QVariant();
}