//
// Created by Gio on 14/10/2017.
//

#ifndef NEW64_ROOM_H
#define NEW64_ROOM_H
#include <QGraphicsItem>
#include <QtWidgets>


class Tile : public QGraphicsItem {
public:
    int x, y, width, height;
    bool player;
    int item;
    int enemy;
    QRectF *boundRect;
    Tile(int x, int y, int width, int height);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    QColor maincolor;

};
#endif //NEW64_ROOM_H
