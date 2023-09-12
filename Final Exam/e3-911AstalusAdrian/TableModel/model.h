#ifndef A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#define A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#endif //A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#include <QAbstractTableModel>
#include "../Player/player.h"
#include "../Service/service.h"

class TModel: public QAbstractTableModel{
private:
    Service& serv;
    std::vector<Player> list;
    int mineNr, size;
public:
    TModel(Service & s, int mineCount, int dimensions, std::vector<Player>& playerList, QObject* parent = NULL);
    ~TModel() = default;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};