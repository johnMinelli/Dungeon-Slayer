#include <time.h>
#include "Personaggio.h"
#include "Nemico.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsItem>
#include <QList>
#include <qmath.h>
#include <QPointF>
#include <QLineF>
#include <QVector>
#include <QPolygonF>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QDebug>



Personaggio::Personaggio(std::vector<Item*> *items, QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    srand (time(NULL));
    QPixmap qp(":/Resources/Resources/wolf.png");
    setPixmap(qp);
    this->inventory=items;
    stat.hp = 6 + rand()%5;
    stat.ap = rand()%5;
    stat.str = 2 + rand()%5;
    stat.luck = 1 + rand()%5;
    stat.vel = 1 + rand()%5;
    stat.def =1 + rand()%5;

}

///////////////////////////////////////////////////////////////

//crea il poligono intorno al personaggio per gestire collisione per modalità battaglia
void Personaggio::createPolygon()
{
    if(polygonArea!=NULL)
    {
            delete polygonArea;
    }
    int SCALE_FACTOR = 1000;
    QVector<QPointF>polyPoints;
    polyPoints << QPointF(0, -1) << QPointF(1, -1) << QPointF(1.5, -0.5) << QPointF(2, 0) << QPointF(2, 1) << QPointF(1.5, 1.5) << QPointF(1, 2) << QPointF(0, 2) << QPointF(-0.5, 1.5) << QPointF(-1, 1) << QPointF(-1, 0) << QPointF(-0.5, -0.5);
    QPointF polyCenter(0, 0);
    polyCenter = polyCenter * SCALE_FACTOR;
    //ridimensiona i punti in base alla scala che vogliamo utilizzare
    for (int i = 0; i < polyPoints.size(); i++)
    {
            polyPoints[i] = polyPoints[i] * SCALE_FACTOR;
    }
    //polygono con ai vertici i nostri punti
    QPolygonF enemyPoligon(polyPoints);
    polygonArea = new QGraphicsPolygonItem(enemyPoligon, this);
    polygonArea->setBrush(QBrush(QColor(Qt::transparent)));
    polygonArea->setPen(QPen(QColor(Qt::transparent)));
}


//ritorna la distanza da un'item
double Personaggio::distanceToEnemy(QGraphicsItem *item)
{
  QLineF linePlayerEnemy(pos(),item->pos());
  return linePlayerEnemy.length();
}

//SOMMA I VALORI PASSATI ALLE STATS ATTUALI
void Personaggio::setStat(int hp,int ap,int str,int def,int luck,int vel){
    this->stat.hp+=hp;
    this->stat.ap+=ap;
    this->stat.str+=str;
    this->stat.def+=def;
    this->stat.luck+=luck;
    this->stat.vel+=vel;
    //signalStat();
}

//CHECKINVETORY
bool Personaggio::checkFullInventory()
{
    if(inventory->size()<8)
        return false;
    else
        return true;
}



///////////////////////////////////////////////////////////////
/// COLLIDER MOVEMENT
void Personaggio::blocca_left()
{

    setPos(x() - 10, y());

    colliding_item = collidingItems();
    collidingEnemies = polygonArea->collidingItems();


    op1 = false;
    op2 = false;
    op3 = false;
    op4 = false;

    //COLLISIONI CON PARTI DI MAPPA E ITEMS
    collidingItemsMap();

    //MOVE
    moveLeft();

    //COLLISIONI CON nemici
    collidingEnemy();
}

void Personaggio::blocca_right()
{
    setPos(x() + 10, y());

    colliding_item = collidingItems();
    collidingEnemies = polygonArea->collidingItems();

    op1 = false;
    op2 = false;
    op3 = false;
    op4 = false;


    //COLLISIONI CON PARTI DI MAPPA E ITEMS
    collidingItemsMap();

    //MOVE
    moveRight();

    //COLLISIONI CON nemici
    collidingEnemy();
}

void Personaggio::blocca_up()
{
    setPos(x(), y() - 10);

    colliding_item = collidingItems();
    collidingEnemies = polygonArea->collidingItems();

    op1 = false;
    op2 = false;
    op3 = false;
    op4 = false;


    //COLLISIONI CON PARTI DI MAPPA E ITEMS
    collidingItemsMap();

    //MOVE
    moveUp();

    //COLLISIONI CON nemici
    collidingEnemy();
}

void Personaggio::blocca_down()
{
    setPos(x(), y() + 10);

    colliding_item = collidingItems();
    collidingEnemies = polygonArea->collidingItems();

    op1 = false;
    op2 = false;
    op3 = false;
    op4 = false;


    collidingItemsMap();

    moveDown();

    //COLLISIONI CON nemici

    collidingEnemy();
}



///////////////////////////////////////////////////////////////
///COLLIDING FUNCTIONS

void Personaggio::collidingItemsMap()
{

    for (int i = 0; i < colliding_item.size(); i++)
    {
        if (typeid(*(colliding_item[i])) == typeid(Tile)) {//COLLISIONI CON PARTI DI MAPPA
            Tile* stacked =  dynamic_cast <Tile*>(colliding_item[i]);
            if(!op1){
                op1=stacked->boundRect->contains(this->pos());
            }
            if(!op2){
                op2=stacked->boundRect->contains(sceneBoundingRect().x()+sceneBoundingRect().width(),this->pos().y());
            }
            if(!op3){
                op3=stacked->boundRect->contains(this->pos().x(),sceneBoundingRect().y()+sceneBoundingRect().height());
            }
            if(!op4){
                op4=stacked->boundRect->contains(sceneBoundingRect().x()+sceneBoundingRect().width(),sceneBoundingRect().y()+sceneBoundingRect().height());
            }
        }else if(typeid(*(colliding_item[i])) == typeid(Item)) {//COLLISIONI CON ITEM
            Item* a = dynamic_cast <Item*>(colliding_item[i]);
            if(a->type==7){     //SE L'ITEM E' LA BOTOLA (trapdoor)
                if(a->levelItem==level){
                    for (int j = 0; j < inventory->size() ; ++j) {      //controllo se ho la chiave nell'inventario
                        if(inventory->at(j)->type==6){
                            Item *key = inventory->at(j);
                            inventory->erase(inventory->begin()+j);
                            delete key;
                            level++;
                            nextLevel();    //se ho la chiave -> next level
                        }
                    }
                }else{
                   resumeLevel(true);
                }
            }else if(a->type==8){     //SE L'ITEM E' LA SCALA (stairs)
                resumeLevel(false);
            }else{  // ALTRIMENTI Inseriscilo nel vettore inventario degli item
                if(!checkFullInventory()){
                    inventory->push_back(a);
                    signalItem(true);       //signalItem lancia UpdateInventory
                }else{
                    fullInventoryWarning(checkFullInventory());
                }
            }
        }
    }




}

void Personaggio::collidingEnemy()
{
bool c = isWeaponDressed;

        for (int i = 0; i < collidingEnemies.size(); i++)
        {
            if (typeid(*(collidingEnemies[i])) == typeid(Nemico))
            {

                if(isWeaponDressed)
                {

                    Nemico* a = dynamic_cast <Nemico*>(collidingEnemies[i]);
                    scene()->removeItem(collidingEnemies[i]);

                    battleMode(a->id);
                    return;
                }
                else
                    noWeaponWarning();
            }
        }




}

///////////////////////////////////////////////////////////////
///MOVE

void Personaggio::moveLeft()
{

    if(!(op1 && op2 && op3 && op4)){
        setPos(x() + 10,y());
    }


}
void Personaggio::moveRight()
{
    if(!(op1 && op2 && op3 && op4)){
        setPos(x() - 10,y());
    }

}
void Personaggio::moveUp()
{

    if(!(op1 && op2 && op3 && op4)){
        setPos(x(),y() + 10);
    }

}
void Personaggio::moveDown()
{
    if(!(op1 && op2 && op3 && op4)){
        setPos(x(),y() - 10);
    }

}

///////////////////////////////////////////////////////////////
///BATTLEMODE

int Personaggio::getPlayerDamage()
{

    int apBonus = this->stat.ap/10;

    int damage = this->weapon->weaponDamage + apBonus;

    return damage;

}

int Personaggio::getReducedAmountDamage()
{

    int reducedAmount = this->stat.def / 10;

    return reducedAmount;

}

