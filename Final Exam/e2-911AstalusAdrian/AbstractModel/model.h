#pragma once
#ifndef E2_911ASTALUSADRIAN_MODEL_H
#define E2_911ASTALUSADRIAN_MODEL_H
#endif //E2_911ASTALUSADRIAN_MODEL_H
#include <QAbstractTableModel>
#include "../Service/service.h"

class TableModel: public QAbstractTableModel {
private:
    Service& service;
    int rows, cols;
public:
    explicit TableModel(Service& newService);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void update();
};
