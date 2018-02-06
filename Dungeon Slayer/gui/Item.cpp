//
// Created by Gio on 21/10/2017.
//
#include "core/constants.h"
#include "Item.h"

Item::Item(int type, int levelItem){
    this->type=type;
    this->levelItem=levelItem;
    QPixmap qp(enumImagesItem[type]);
    setPixmap(qp);
    switch(type){
        case 0: //HP POTION
            bonus.hp = 1*levelItem + rand() % levelItem;
            bonus.ap = 0;
            bonus.def = 0;
            bonus.str = 0;
            bonus.luck = 0;
            bonus.vel = 0;
            break;
        case 1: //AP POTION
            bonus.hp = 0;
            bonus.ap = 1*levelItem + rand() % levelItem;
            bonus.def = 0;
            bonus.str = 0;
            bonus.luck = 0;
            bonus.vel = 0;
            break;
        case 2: // STR POTION
            bonus.hp = 0;
            bonus.ap = 0;
            bonus.def = 0;
            bonus.str = 1*levelItem + rand() % levelItem;
            bonus.luck = 0;
            bonus.vel = 0;
            break;
        case 3: //RAND POTION
            bonus.hp = rand()%2*levelItem;
            bonus.ap = rand()%2*levelItem;
            bonus.def = 0;
            bonus.str = rand()%2*levelItem;
            bonus.luck = rand()%2*levelItem;
            bonus.vel = rand()%2*levelItem;
            break;
        case 4: //ARMOR
            bonus.hp = 2*levelItem;
            bonus.ap = 0;
            bonus.def = 1*levelItem;;
            bonus.str = 0;
            bonus.luck = 0;
            bonus.vel = 0;
            break;
        case 5: // WEAPON
            weaponDamage= 1 + rand() % (2*levelItem);
            weaponStr= levelItem + rand() % (2*levelItem);
            //str (se non hai abbiastanza str non la puoi indossare)
            break;
    }

}
