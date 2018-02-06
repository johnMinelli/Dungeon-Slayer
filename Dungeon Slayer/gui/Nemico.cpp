#include "Nemico.h"
#include "QTimer"
#include <QPixmap>
#include <stdlib.h>
#include <typeinfo>

Nemico::Nemico(QGraphicsItem *parent)
{
    QPixmap pixEnemy(":/Resources/Resources/spirit_of_fright.png");
    setPixmap(pixEnemy);


    this->stat.hp = 1;




    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(randomMove()));
    moveTimer->start(1000);
}

void Nemico::setStats(int hp)
{
  this->stat.hp+=hp;

}

void Nemico::setMaxHp()
{

    maxHp = this->stat.hp;

}



void Nemico::setId(int currentId)
{
  id=currentId;
}

void Nemico::randomMove()
{
    int randNumb = rand() % 20 + 10;
    int r = rand() % 4 + 1;
    if (r == 1)
    {
        //down block
        bool grounded=false;
        setPos(x(), y() + randNumb);
        //boundingRect().setX(x()+10)
        QList<QGraphicsItem *> colliding_map = collidingItems(Qt::ContainsItemShape);
        QList<QGraphicsItem *> colliding_item = collidingItems();
        for (int i = 0; i < colliding_map.size(); i++)
        {
            if (typeid(*(colliding_map[i])) == typeid(Tile)) {
                //perfect
                i=colliding_map.size()+1;
                grounded=true;
            }
        }
        if(!grounded){
            setPos(x(),y() - randNumb);
        }
        for (int i = 0; i < colliding_item.size(); i++)
        {
            if (typeid(*(colliding_item[i])) == typeid(Item)) {
                return;
            }
        }

    }
    else if (r == 2)
    {
          //upblock
          bool grounded=false;
          setPos(x() + randNumb, y());
          //boundingRect().setX(x()+10)
          QList<QGraphicsItem *> colliding_map = collidingItems(Qt::ContainsItemShape);
          QList<QGraphicsItem *> colliding_item = collidingItems();
          for (int i = 0; i < colliding_map.size(); i++)
          {
              if (typeid(*(colliding_map[i])) == typeid(Tile)) {
                  //perfect
                  i=colliding_map.size()+1;
                  grounded=true;
              }
          }
          if(!grounded){
              setPos(x() - randNumb,y());
          }
          for (int i = 0; i < colliding_item.size(); i++)
          {
              if (typeid(*(colliding_item[i])) == typeid(Item)) {
                  return;
              }
          }
    }
    else if (r == 3)
    {
          bool grounded=false;
          setPos(x(), y() - randNumb);
          //boundingRect().setX(x()+10)
          QList<QGraphicsItem *> colliding_map = collidingItems(Qt::ContainsItemShape);
          QList<QGraphicsItem *> colliding_item = collidingItems();
          for (int i = 0; i < colliding_map.size(); i++)
          {
              if (typeid(*(colliding_map[i])) == typeid(Tile)) {
                  //perfect
                  i=colliding_map.size()+1;
                  grounded=true;
              }
          }
          if(!grounded){
              setPos(x(),y() + randNumb);
          }
          for (int i = 0; i < colliding_item.size(); i++)
          {
              if (typeid(*(colliding_item[i])) == typeid(Item)) {
                  return;
              }
          }
    }
    else if (r == 4)
    {
        bool grounded=false;
        setPos(x() - randNumb, y());
        QList<QGraphicsItem *> colliding_map = collidingItems(Qt::ContainsItemShape);
        QList<QGraphicsItem *> colliding_item = collidingItems();

        //COLLISIONI CON PARTI DI MAPPA
        for (int i = 0; i < colliding_map.size(); i++)
            {
            if (typeid(*(colliding_map[i])) == typeid(Tile)) {
                //perfect
                i=colliding_map.size()+1;
                grounded=true;
                    }
            }

        //MOVIMENTO
        if(!grounded){
            setPos(x() + randNumb,y());
        }

        //COLLISIONI CON OGGETTI ITEMS
        for (int i = 0; i < colliding_item.size(); i++)
        {
            if (typeid(*(colliding_item[i])) == typeid(Item)) {
                return;
            }
        }
    }
}

//Calcola il danno inflitto dal nemico
int Nemico::getEnemyDamage()
{

    int damage = rand() % (this->stat.str + 1);

    return damage;

}

//Inizializza le statistiche del nemico sulla base del livello
void Nemico::setEnemyInitStats(int level, Personaggio* player, int enemyId)
{
    int randVariable = rand() % 3;

    //BOSS
    if(enemyId == -1)
    {
        this->stat.hp = level + (randVariable * level) + player->stat.hp;
        this->stat.str =1 + (1 * level) + player->stat.ap/10 + player->stat.str/10;
        this->stat.ap = 0;
        this->stat.vel = 0;
        this->stat.def = 0;
        this->stat.luck = 0;


    }
    else
    {


        this->stat.hp = level + (randVariable * level);
        this->stat.str =1 + (1 * level);
        this->stat.ap = 0;
        this->stat.vel = 0;
        this->stat.def = 0;
        this->stat.luck = 0;
    }



}
