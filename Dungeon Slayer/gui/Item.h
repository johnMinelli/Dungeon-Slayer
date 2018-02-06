//
// Created by Gio on 21/10/2017.
//

#ifndef NEW64_ITEM_H
#define NEW64_ITEM_H

#include <QtWidgets>
#include <core/constants.h>

class Item : public QObject,  public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Item(int type, int levelItem);
    int type;
    parameters bonus;
    int levelItem;
    int weaponDamage;
    int weaponStr;
};


#endif //NEW64_ITEM_H
