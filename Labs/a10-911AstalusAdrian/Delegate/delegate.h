#pragma once
#ifndef A10_911ASTALUSADRIAN_1_DELEGATE_H
#define A10_911ASTALUSADRIAN_1_DELEGATE_H
#endif //A10_911ASTALUSADRIAN_1_DELEGATE_H
#include <QStyledItemDelegate>

class PictureDelegate: public QStyledItemDelegate{
public:
    PictureDelegate(QWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};