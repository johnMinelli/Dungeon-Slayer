#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

#include <QGraphicsPixmapItem>
#include <qobject.h>
#include <gui/Item.h>
#include "core/constants.h"
#include <QPointF>
#include <typeinfo>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <qtimer.h>
#include <QLineF>
#include "gui/Tile.h"
#include "ui_mainwindow.h"



class Personaggio :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
    Personaggio(std::vector<Item*> *inventory, QGraphicsItem *parent = 0);
    parameters stat;

    int level=1;

    std::vector<Item*> *inventory;

    Item* weapon;
    Item* armor;

    //////////////////////////////////////////////////////////////
    //MOVIMENTI PRINCIPALI

    void blocca_left();
    void blocca_right();
    void blocca_up();
    void blocca_down();
    void setStat(int hp,int ap,int str,int def,int luck,int vel);

    //////////////////////////////////////////////////////////////
    //BOOL CHECK
    bool checkFullInventory();
    bool isWeaponAlreadyDressed = false;
    bool isArmorAlreadyDressed = false;
    bool isWeaponDressed = false;
    QPointF destinationPoint;

    //////////////////////////////////////////////////////////////
    //BOOL OP
    bool op1,op2,op3,op4;

    //////////////////////////////////////////////////////////////
    //COLLIDING QLIST
    QList<QGraphicsItem *> colliding_item;
    QList<QGraphicsItem *> collidingEnemies;

    void createPolygon();
    QGraphicsPolygonItem *polygonArea = NULL;
    double distanceToEnemy(QGraphicsItem *item);
    QTimer *itemDetectionTimer;

    //////////////////////////////////////////////////////////////
    //COLLIDING

    void collidingItemsMap();
    void collidingEnemy();

    //////////////////////////////////////////////////////////////
    //MOVE

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    //DANNO INFLITTO
    int getPlayerDamage();
    //DANNO RIDOTTO
    int getReducedAmountDamage();


signals:
    void signalItem(bool activatedByCollider);
    void signalStat();
    void nextLevel();
    void resumeLevel(bool nextORprev);
    void fullInventoryWarning(bool isFull);
    void noWeaponWarning();

    void battleMode(int id);

};
#endif
