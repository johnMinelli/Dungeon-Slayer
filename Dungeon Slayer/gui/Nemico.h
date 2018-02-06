#ifndef NEMICO_H
#define NEMICO_H

#include <QGraphicsPixmapItem>
#include <qobject.h>
#include "./core/constants.h"
#include <QTimer>
#include "Personaggio.h"
#include "gui/Tile.h"
#include "gui/Item.h"

class Nemico:public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  QTimer *moveTimer;
      Nemico(QGraphicsItem *parent = 0);
      parameters stat;
      int maxHp = 0;
      int id;

      void setId(int currentId);
      void setStats(int hp);


      void setMaxHp();

      //Calcola il danno inflitto dal nemico
      int getEnemyDamage();

      //Inizializza le statistiche del nemico sulla base del livello
      void setEnemyInitStats(int level, Personaggio* player, int enemyId);


  public slots:
      void randomMove();
};

#endif // NEMICO_H
