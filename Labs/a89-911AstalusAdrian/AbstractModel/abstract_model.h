#ifndef A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#define A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#endif //A89_911ASTALUSADRIAN_ABSTRACT_MODEL_H
#include <QAbstractTableModel>
#include "../Dog/dog.h"

class AbstractModel: public QAbstractTableModel{
private:
    std::vector<Dog> &list;
public:
    AbstractModel(std::vector<Dog>& dogList, QObject* parent = NULL);
    ~AbstractModel();
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};