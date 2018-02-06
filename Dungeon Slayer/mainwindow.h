#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTimer>
#include <QDebug>
#include <QPointF>
#include <QGraphicsScene>
#include "core/constants.h"
#include "core/Leaf.h"
#include "gui/Item.h"
#include "gui/Tile.h"
#include "gui/Personaggio.h"
#include "gui/Nemico.h"

#include <QMatrix>
#include <QMultimedia>
#include <QMediaPlaylist>
#include <QMediaPlayer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int level=0;
    Personaggio *player;

    /////////////////////////////////////////
    //INVENTORY

    std::vector<Item*> inventory;

    /////////////////////////////////////////
    //BATTLE
    Nemico *currentEnemy;

    Item* tempWeapon;


    void exitBattleMode();

    /////////////////////////////////////////
    //BATTLE BOOLEAN
    bool battleEnded = false;
    bool battleModeActive = false;
    bool playerWin = false;
    bool boss = false;
    int currentEnemyId;

    //Counter ID dei nemici
    int counterEnemyId=0;

    struct floor{
        std::vector<Leaf*> leaves;
        std::vector<Item*> items;
        std::vector<Nemico*> enemies;
    };

private:
/////////////////////////////////////////
//VARIABLES
    int lastSelectedInventoryItem = 0;
    QPointF playerOldPosition;
    int turnNumber = 0;
    int TurnActions = 0;

    QTimer *armaAnimationTimer;


//////////////////////////////////////////
/// FUNCTION
    void createRoom(Leaf *in);
    void createHall(Leaf *in);
    bool split(Leaf *in);
    void fillRoom();
    void initGUI();
    void freeMEM();

    void increaseActionNumber();
    void battleModeUI();
    void playerTurn();
    void enemyTurn();

    void battleSplashIn();
    void bloodSplashIn();
    void enemyDefeatedSplashIn();
    void enemyFireAttackSplashIn(int damageSuffered);
    void bossDefeatedSplashIn();
    void warningSplashIn();
    void startObjectiveMessage();

    //ENEMY HP LABEL
    void showEnemyHPLabel(int enemyHP);
    void updateEnemyHPLabel();






/////////////////////////////////////////
//PUBLIC SLOTS

public slots:
    void startGame();
    void createMap();
    void resumeMap(bool nextORprev);
    void updateStat();
    void updateInventory(bool activatedByCollider);

    void printDroppedItemMessage();
    void inventoryButtonClicked(int id);

    void dropUseButtonClicked(int);
    void weaponArmorButtonClicked(int);

    void useButtonProcedure();
    void dropButtonProcedure();
    void printFullInventoryWarning(bool isFull);

    void enterIntoBattleMode(int id);
    void moveWeapon();

    void passTurn(bool calledBy);

    void battleSplashOut();
    void bloodSplashOut();
    void enemyDefeatedSplashOut();
    void enemyFireAttackSplashOut();
    void warningSplashOut();
    void bossDefeatedSplashOut();
    void printWeaponWarning();

    void muoviArma();
    void enemyTurnEnded();

    //BOS MESSAGE WARNING
    void bossObjectiveMessage();
    void bossDefeatedObjectiveMessage();

    //TEXT NAME COLOR
    void setTextNameColor();




private:


    void dressWeapon();
    void dressArmor();



    /////////////////////////////////////////
    //KEYPRESSED EVENT
    void keyPressEvent(QKeyEvent *event);

    Ui::MainWindow *ui;

    //Scena Principale di Gioco e Battaglia
    QGraphicsScene *scene;
    QGraphicsScene *battleScene = NULL;

    //ARRAYS
    std::vector<floor> floorList;
    std::vector<Leaf*>* leaves;
    std::vector<Item*>* items;
    std::vector<Nemico*>* enemies;

    //Button Inventario
    std::vector<QPushButton*> slot;

    //Button Weapon e Armor
    QPushButton * weapon;
    QPushButton * armor;


    //DropUseButton
    QPushButton * drop;
    QPushButton * use;

    //BattleButton
    QPushButton *attackButton;
    QPushButton *passTurnButton;

    //UTILIY FUNCTION
    QString getItemType(int item);

    //Sounds
    void playGameSoundtrack();

};

#endif // MAINWINDOW_H
