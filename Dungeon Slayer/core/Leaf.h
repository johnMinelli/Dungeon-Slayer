//
// Created by Gio on 09/08/2017.
//

#ifndef LEAF_H
#define LEAF_H

#include "stdio.h"
#include <QWidget>
#include <QGraphicsItem>
#include "gui/Tile.h"
typedef Tile *ptrTile;



class Leaf {

public:
    Leaf(int X, int Y, int Width, int Height);
    ~Leaf();

    int y, x; // the position and size of this Leaf
    int width, height;
    Leaf* leftChild; // the Leaf's left child Leaf
    Leaf* rightChild; // the Leaf's right child Leaf
    Tile* room = NULL; // the room that is inside this Leaf
    std::vector <Tile*> halls;

    ptrTile getRoom();
};

#endif

