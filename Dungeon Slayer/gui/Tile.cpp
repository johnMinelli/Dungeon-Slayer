//
// Created by Gio on 14/10/2017.
//

#include "Tile.h"


Tile::Tile(int x, int y, int width, int height){
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    player=false;
    item=0;
    enemy=0;
    boundRect = new QRectF(x, y, width, height);
    //maincolor.setHsv(rand()%200,rand()%200,rand()%200);
}

QRectF Tile::boundingRect() const {
    return *boundRect;
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        painter->fillRect(*boundRect,QBrush(QImage(":/Resources/Resources/floor.png")));

    //painter->fillRect(*boundRect, QBrush(maincolor));
}
