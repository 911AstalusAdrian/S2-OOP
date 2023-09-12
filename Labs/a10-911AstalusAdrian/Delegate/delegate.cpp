#include "delegate.h"
#include <QPixmap>
#include <QPainter>


PictureDelegate::PictureDelegate(QWidget *parent):QStyledItemDelegate{parent} {

}

void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {

    QString dog = index.model()->data(index, Qt::DisplayRole).toString();

    if(index.column() != 4){
        QStyledItemDelegate::paint(painter,option,index);
        return;
    }

    if(dog.contains("Shepherd")){
        QPixmap pixMap("Shepherd.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Bulldog")){
        QPixmap pixMap("Bulldog.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Boxer")){
        QPixmap pixMap("Boxer.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Poodle")){
        QPixmap pixMap("Poodle.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Doberman")){
        QPixmap pixMap("Doberman.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Husky")){
        QPixmap pixMap("Husky.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Hound")){
        QPixmap pixMap("Hound.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    if(dog.contains("Shiba")){
        QPixmap pixMap("Shiba.jpeg");
        painter->drawPixmap(option.rect, pixMap);
    }
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.column() == 4)
    {
        return QSize(320, 100);
    }

    return QStyledItemDelegate::sizeHint(option, index);
}
