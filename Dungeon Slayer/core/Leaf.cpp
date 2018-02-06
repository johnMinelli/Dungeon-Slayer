//
// Created by Gio on 09/08/2017.
//
#include "Leaf.h"

    Leaf::Leaf(int X, int Y, int Width, int Height){
        x = X;
        y = Y;
        width = Width;
        height = Height;
        room = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    Leaf::~Leaf()
    {
        if(room!=NULL){
        delete room;
        }
        for(int i=0;i<halls.size();i++){
            delete halls.at(i);
        }
    }

    ptrTile Leaf::getRoom() {
        // iterate all the way through these leafs to find a room, if one exists.
        if (room != NULL){
            return room;
        }else {
            Tile* lRoom = NULL;
            Tile* rRoom = NULL;
            if (leftChild != NULL) {
                lRoom = leftChild->getRoom();
            }
            if (rightChild != NULL){
                rRoom = rightChild->getRoom();
            }
            if (lRoom == NULL && rRoom == NULL) {
                return NULL;
            } else if (rRoom == NULL){
                return lRoom;
            }else if (lRoom == NULL) {
                return rRoom;
            }else if (rand()%100 > 50) {
                return lRoom;
            }else{
                return rRoom;
            }
        }
}

