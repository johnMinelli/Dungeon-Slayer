#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <time.h>




MainWindow::MainWindow(QWidget *parent)
        //: QWidget(parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->backgroundWidget->hide();
    ui->gameWidget->hide();


    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QGraphicsOpacityEffect *eff2 = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/unibo.png");
    QPixmap scaled=pic.scaled (WINDOW_WIDTH, WINDOW_HEIGHT);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->splashScreen->setPalette(palette);
    ui->splashScreen->setAutoFillBackground(true);
    ui->splashScreen->setGraphicsEffect(eff);
    ui->startScreen->setGraphicsEffect(eff2);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::Linear);
    anim->start(QPropertyAnimation::DeleteWhenStopped);
    QPropertyAnimation *anim2 = new QPropertyAnimation(eff2,"opacity");
    anim2->setDuration(5000);
    anim2->setStartValue(0);
    anim2->setEndValue(1);
    anim2->setEasingCurve(QEasingCurve::InExpo);
    anim2->start(QPropertyAnimation::DeleteWhenStopped);






///////////////////////////// Signals ////////////////////////////

    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(startGame()));
    connect(ui->actionQuit,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->inizia,SIGNAL(clicked(bool)),this,SLOT(startGame()));

    //BOTTONE INIZIA
    ui->inizia->setIcon(QIcon(":/Resources/Resources/splashBattle.png"));
    ui->inizia->setText("INIZIA");
    ui->inizia->setStyleSheet("color : white");
    ui->actionPause->setVisible(false);

    //NAME TEXT SETTINGS/CONNECT

    ui->playerStartName->setAlignment(Qt::AlignHCenter);
    connect(ui->playerStartName,SIGNAL(textChanged()),this,SLOT(setTextNameColor()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{

//initBase e freeMEMORY
    srand (time(NULL));
    if(level!=0){
        freeMEM();
    }

    clearFocus();
    ui->centralWidget->setFocus();

    this->player = new Personaggio(&inventory);
    QMatrix matrixP;
    matrixP.scale(0.03,0.03);
    player->setMatrix(matrixP);
    player->setFocus();
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    //START MESSAGE
    ui->MessageBoxW->setText("Benvenuto nel Dungeon!");

    //MAP SIGNALS
    connect(player, SIGNAL(nextLevel()), this, SLOT(createMap()));
    connect(player, SIGNAL(resumeLevel(bool)), this, SLOT(resumeMap(bool)));

    //INVENTORY SIGNALS
    connect(player, SIGNAL(signalStat()), this, SLOT(updateStat()));
    connect(player, SIGNAL(signalItem(bool)), this, SLOT(updateInventory(bool)));
    connect(player,SIGNAL(fullInventoryWarning(bool)),this,SLOT(printFullInventoryWarning(bool)));
    connect(player,SIGNAL(noWeaponWarning()),this,SLOT(printWeaponWarning()));


    //BATTLEMODE SIGNALS - when player'S polygon area collides with enemy
    connect(player,SIGNAL(battleMode(int)), this, SLOT(enterIntoBattleMode(int)));
    armaAnimationTimer = new QTimer(this);
    connect(armaAnimationTimer, SIGNAL(timeout()), this, SLOT(muoviArma()));

    //Setup Window
     ui->startScreen->hide();
     ui->splashScreen->hide();
     ui->backgroundWidget->show();
     ui->gameWidget->show();

    scene = new QGraphicsScene(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,this);
    ui->view->setScene(scene);

    //START MESSAGE OBIETTIVO
    startObjectiveMessage();
    QMatrix matrixS;
    matrixS.scale(2,2);
    ui->view->setMatrix(matrixS);


    if(level==0)
    {
      initGUI();
      if(ui->playerStartName->toPlainText()!="")
      {
          ui->PlayerName->setText(ui->playerStartName->toPlainText());
      }
      else
      {
          ui->PlayerName->setText("Hero");
      }
      playGameSoundtrack();
    }
    updateInventory(false);
    level=0;

//Creazione mappa
    createMap();
    ui->view->centerOn(player);
    updateStat();
}

//////////////////////////////////////////////////////////////////////////////////////////
/// GESTIONE MAP

void MainWindow::createMap()
{
    if(level!=0){
        updateInventory(false);
        floor floorLefted;
        floorLefted.leaves=*leaves;
        floorLefted.items=*items;
        floorLefted.enemies=*enemies;
        if(floorList.size()==level){
            floorList.at(level-1)= floorLefted;
        }else{
            floorList.push_back(floorLefted);
        }
    }
    level++;
    for(int i = 0; i != scene->items().size(); ) {
        scene->removeItem(scene->items().at(0));
    }
    scene->clear();
    leaves = new std::vector<Leaf*>;
    items = new std::vector<Item*>;
    enemies = new std::vector<Nemico*>;
    scene->setBackgroundBrush(QBrush(QImage(":/Resources/Resources/outdoor.png")));
    ui->levelLabel->setText("Level: " + QString::number(level));
    //let's generate the leaves
    Leaf *l;
    Leaf *root = new Leaf(0, 0, scene->width(), scene->height());
    leaves->push_back(root);
    bool doSplit = true;
    // we loop through every Leaf until no more Leafs can be split
    while (doSplit){
        doSplit = false;
        for (int i = 0; i < leaves->size(); i++) {
            l=leaves->at(i);
            if (l->leftChild == NULL && l->rightChild == NULL){ // if this Leaf is not already split...
                // if this Leaf is too big, or 75% chance...
                if (l->width > MAX_LEAF_SIZE || l->height > MAX_LEAF_SIZE || rand() % 100 > 25){
                    if (split(l)){ // split the Leaf!
                        // push the leaves in the Vector to complete the loop
                        leaves->push_back(l->leftChild);
                        leaves->push_back(l->rightChild);
                        doSplit = true;
                    }
                }
            }
        }
    }
    //create the small room in the tree map
    createRoom(root);
    //fill the map with stuff
    fillRoom();
}

bool MainWindow::split(Leaf* in)
{
    // Splitting the leaf into two children
    if (in->leftChild != NULL || in->rightChild != NULL )
        return false; // The leaf is already splitted! EXIT

    // determine direction of split
    bool splitH = ((rand() % 2) == 0);
    if (in->width > in->height && in->width / in->height >= 1.25)
        splitH = false;
    else if (in->height > in->width && in->height / in->width >= 1.25)
        splitH = true;

    //int max = (splitH ? in->height : in->width) - MIN_LEAF_SIZE; // determine the maximum height or width
    int max = (splitH ? in->height : in->width) ;
    //int split =  MIN_LEAF_SIZE + rand() % (max - MIN_LEAF_SIZE); // determine where we're going to split
    int split = max/2;


    int compare = LEAF_SIZE-level*40;
    if(compare<MIN_LEAF_SIZE){
       compare=MIN_LEAF_SIZE;
    }
    if (split < compare){
        return false; // the area is too small to split any more...
    }

    // create our left and right children based on the direction of the split
    if (splitH){
        in->leftChild = new Leaf(in->x, in->y, in->width, split);
        in->rightChild = new Leaf(in->x, in->y + split, in->width, in->height - split);
    } else{
        in->leftChild = new Leaf(in->x, in->y, split, in->height);
        in->rightChild = new Leaf(in->x + split, in->y, in->width - split, in->height);
    }
    return true; // split successful!
}

void MainWindow::createRoom(Leaf* in)
{
    // generates all the rooms for this Leaf and all of its children.
    if (in->leftChild != NULL || in->rightChild != NULL){
        // this leaf has been split so call method for the childrens
        if (in->leftChild != NULL){
            createRoom(in->leftChild);
        }
        if (in->rightChild != NULL){
            createRoom(in->rightChild);
        }
        // if there are both left and right children in this Leaf, create a hallway between them
        if (in->leftChild != NULL && in->rightChild != NULL){
            createHall(in);
        }
    }else{
        // create room only for the end leaf
        int op  = rand() % (in->width / 2);
        int op2  = rand() % (in->height / 2);
        QSize roomSize(in->width / 2 + op -1, in->height / 2 + op2 -1);
        //QPoint roomPos(in->x + (1 + qrand() % ((in->width - (int)roomSize.width() - 1) - 1)),in->y + (1 + qrand() % ((int)(in->height - (int) roomSize.height() - 1) - 1)));
        int op3  = rand() % (in->width - roomSize.width());
        int op4  = rand() % (in->height - roomSize.height());
        QPointF roomPos(in->x +1 + op3,in->y + 1 + op4);
        in->room = new Tile(roomPos.x(),roomPos.y(),roomSize.width(),roomSize.height());
        // print the room on the screen
        scene->addItem(in->room);
    }
}

void MainWindow::createHall(Leaf* in)
{
    Tile *l = in->leftChild->getRoom();
    Tile *r = in->rightChild->getRoom();
    //min + rand() % (max - min)
    int op1=rand()%(l->x+l->width - (2*HALL_SIZE));
    int op2=rand()%(l->y+l->height - (2*HALL_SIZE));
    int op3=rand()%(r->x+r->width - (2*HALL_SIZE));
    int op4=rand()%(r->y+r->height - (2*HALL_SIZE));
    QPointF point1 ((l->x+ HALL_SIZE) + op1, (l->y+ HALL_SIZE) + op2);
    QPointF point2 ((r->x+ HALL_SIZE) + op3, (r->y+ HALL_SIZE) + op4);

    //QPointF point2 ((r->x+ HALL_SIZE) + rand()%(int)((r->x+r->width - HALL_SIZE) - (r->x+ HALL_SIZE)) , (r->y+ HALL_SIZE) + rand()%(int)((r->y+r->height - HALL_SIZE) - (r->y+ HALL_SIZE)));
    //faccio un controllo di finezza
        if(point1.x()<l->x+HALL_SIZE)point1.setX(l->x);
        if(point1.x()>l->x+l->width-(2*HALL_SIZE))point1.setX(l->x+l->width - HALL_SIZE);
        if(point1.y()<l->y+HALL_SIZE)point1.setY(l->y);
        if(point1.y()>l->y+l->height-(2*HALL_SIZE))point1.setY(l->y+l->height - HALL_SIZE);
        if(point2.x()<r->x+HALL_SIZE)point2.setX(r->x);
        if(point2.x()>r->x+r->width-(2*HALL_SIZE))point2.setX(r->x+r->width - HALL_SIZE);
        if(point2.y()<r->y+HALL_SIZE)point2.setY(r->y);
        if(point2.y()>r->y+r->height-(2*HALL_SIZE))point2.setY(r->y+r->height - HALL_SIZE);
    double w = point2.x() - point1.x();
    double h = point2.y() - point1.y();

    if (w < 0){
        if (h < 0){
            if (rand()%100 < 50){
                in->halls.push_back(new Tile(point2.x(), point1.y(), fabs(w), HALL_SIZE));
                in->halls.push_back(new Tile(point2.x(), point2.y(), HALL_SIZE, fabs(h)+HALL_SIZE));
            }else{
                in->halls.push_back(new Tile(point2.x(), point2.y(), fabs(w)+HALL_SIZE, HALL_SIZE));
                in->halls.push_back(new Tile(point1.x(), point2.y(), HALL_SIZE, fabs(h)));
            }
        }else if (h > 0){
            if (rand()%100 < 50){
                in->halls.push_back(new Tile(point2.x(), point1.y(), fabs(w), HALL_SIZE));
                in->halls.push_back(new Tile(point2.x(), point1.y(), HALL_SIZE, fabs(h)));
            }else{
                in->halls.push_back(new Tile(point2.x(), point2.y(), fabs(w)+HALL_SIZE, HALL_SIZE));
                in->halls.push_back(new Tile(point1.x(), point1.y(), HALL_SIZE, fabs(h)+HALL_SIZE));
            }
        }else{ // if (h == 0)
            in->halls.push_back(new Tile(point2.x(), point2.y(), fabs(w), HALL_SIZE));
        }
    }else if (w > 0){
        if (h < 0){
            if (rand()%100 < 50){
                in->halls.push_back(new Tile(point1.x(), point2.y(), fabs(w), HALL_SIZE));
                in->halls.push_back(new Tile(point1.x(), point2.y(), HALL_SIZE, fabs(h)));
            }else{
                in->halls.push_back(new Tile(point1.x(), point1.y(), fabs(w)+HALL_SIZE, HALL_SIZE));
                in->halls.push_back(new Tile(point2.x(), point2.y(), HALL_SIZE, fabs(h)+HALL_SIZE));
            }
        }else if (h > 0){
            if (rand()%100 < 50){
                in->halls.push_back(new Tile(point1.x(), point1.y(), fabs(w)+HALL_SIZE, HALL_SIZE));
                in->halls.push_back(new Tile(point2.x(), point1.y(), HALL_SIZE, fabs(h)));
            }else{
                in->halls.push_back(new Tile(point1.x(), point2.y(), fabs(w), HALL_SIZE));
                in->halls.push_back(new Tile(point1.x(), point1.y(), HALL_SIZE, fabs(h)+HALL_SIZE));
            }
        }else{ // if (h == 0)
            in->halls.push_back(new Tile(point1.x(), point1.y(), fabs(w), HALL_SIZE));
        }
    }else{ // if (w == 0)
        if (h < 0){
            in->halls.push_back(new Tile(point2.x(), point2.y(), HALL_SIZE, fabs(h)));
        }else if (h > 0){
            in->halls.push_back(new Tile(point1.x(), point1.y(), HALL_SIZE, fabs(h)));
        }
    }
    //print all the halls from the vector
    for (int i = 0; i < in->halls.size(); ++i) {
        scene->addItem(in->halls.at(i));
    }
    //scene->addItem(new Tile(point1.x(), point1.y(),1,1));
    //scene->addItem(new Tile(point2.x(), point2.y(),1,1));
}

void MainWindow::fillRoom()
{
    Leaf *l;
    //                   -------PLAYER-------
    l=leaves->at(0);//nella root chiamo getRoom prende la prima stanza libera a caso
    Tile *current = l->getRoom();
    this->player->setPos(current->x+(current->width-player->sceneBoundingRect().width())/2,current->y+(current->height-player->sceneBoundingRect().height())/2);
    current->player=true;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->createPolygon();
    player->setZValue(1);
    scene->addItem(player);
    //                    -------STAIRS-------
    Item *obj = new Item(8,level);
    Nemico *actualEnemy = new Nemico();
    if(level!=1){
        items->push_back(obj);
        obj->setPos(current->x+(current->width-obj->pixmap().size().width())/2,current->y+((current->height-obj->pixmap().size().height())/2)-HALL_SIZE);
        scene->addItem(obj);
    }else{
        obj = new Item(5,level);
        items->push_back(obj);
        obj->setPos(player->x() +HALL_SIZE ,player->y()+HALL_SIZE);
        scene->addItem(obj);
    }
    //                    -------KEY-------
    l=leaves->at(1);//root->sx chiamo getRoom prende la prima stanza libera a caso e metto la chiave
    int ctrl=0;
    while(current->player && ctrl<500){current = l->getRoom(); ctrl++;}
    if(ctrl==500){
        current = l->getRoom();
    }
    obj = new Item(6,level);
    items->push_back(obj);
    int op1 = rand()%(current->width-obj->pixmap().size().width());
    int op2 = rand()%(current->height-obj->pixmap().size().height());
    obj->setPos(current->x+op1,current->y+op2);
    scene->addItem(obj);
    //                    -------EXIT-------
    l=leaves->at(2);//root->dx chiamo getRoom prende la prima stanza libera a caso e metto l'uscita
    current = l->getRoom();
    ctrl=0;
    while(current->player && ctrl<500){current = l->getRoom(); ctrl++;}
    if(ctrl==500){
        current = l->getRoom();
    }
    obj = new Item(7,level);
    items->push_back(obj);
    obj->setPos(current->x+(current->width-obj->pixmap().size().width())/2,current->y+((current->height-obj->pixmap().size().height())/2)+HALL_SIZE);
    scene->addItem(obj);
    //                    -------inventory-------
    int op3 = rand()%(1+(leaves->size()/4));
    int op4 = rand()%(1+(leaves->size()/4));
    int itemNumber=level+op3+(player->stat.luck / 5);
    int enemiesNumber=level+op4;
    while(itemNumber != 0 && enemiesNumber!=0){
        for (int i = 0; i < leaves->size(); i++) {
            l=leaves->at(i);
            if (l->leftChild == NULL && l->rightChild == NULL){
                current = l->getRoom();
                if(!current->player){
                    if(rand()%100<50 && current->item<=3){
                        if(itemNumber != 0){
                            current->item=current->item+1;
                            obj = new Item(rand()%6,level);
                            items->push_back(obj);
                            op1 = rand()%(current->width-obj->pixmap().size().width());
                            op2 = rand()%(current->height-obj->pixmap().size().height());
                            obj->setPos(current->x+op1,current->y+op2);
                            scene->addItem(obj);
                            itemNumber--;
                        }
                    }
                    //ENEMY
                    if(rand()%100<50 && current->enemy<=3){
                        if(enemiesNumber != 0){
                            actualEnemy = new Nemico();
                            QMatrix matrixE;
                            current->enemy=current->enemy+1;
                            //BOSS
                            if(level>4 && rand()%100>75 && !boss){
                                boss=true;
                                warningSplashIn();
                                actualEnemy->setId(-1);
                                actualEnemy->setPixmap(QPixmap (":/Resources/Resources/bigBoss.png"));
                                matrixE.scale(0.08,0.08);
                            }else{
                                actualEnemy->setId(counterEnemyId);
                                counterEnemyId++;
                                matrixE.scale(0.3,0.3);
                            }
                            actualEnemy->setMatrix(matrixE);
                            qDebug() << "id del nemico :" << counterEnemyId;
                            qDebug() << "id del nemico creato dell'array:" << actualEnemy->id;
                            qDebug() << actualEnemy->pixmap().size().width();
                            qDebug() << actualEnemy->sceneBoundingRect().height();
                            op1 = rand()%(current->width-(int)actualEnemy->sceneBoundingRect().height());
                            op2 = rand()%(current->height-(int)actualEnemy->sceneBoundingRect().height());
                            actualEnemy->setPos(current->x+op1,current->y+op2);
                            enemies->push_back(actualEnemy);
                            scene->addItem(actualEnemy);
                            enemiesNumber--;
                        }
                    }

                }
            }
        }
    }
}

///////////////////////////////////////

void MainWindow::resumeMap(bool nextORprev)
{
    if(nextORprev){
            //salvo lo stato del livello
            floor floorLefted;
            floorLefted.leaves=*leaves;
            floorLefted.items=*items;
            floorLefted.enemies=*enemies;
            floorList.at(level-1)= floorLefted;
            //svuoto la scena
            for(int i = 0; i != scene->items().size(); ) {
              scene->removeItem(scene->items().at(0));
            }
            scene->clear();
            scene->setBackgroundBrush(QBrush(QImage(":/Resources/Resources/outdoor.png")));
            //prendo i dati corrispondenti al nuovo livello
            level++;
            ui->levelLabel->setText("Level: " + QString::number(level));
            *leaves = floorList.at(level-1).leaves;
            *items = floorList.at(level-1).items;
            *enemies = floorList.at(level-1).enemies;
            //metto gli elementi e il player nella scena
            for(int i = 0; i < leaves->size(); i++) {
                if(leaves->at(i)->room!=NULL){
                    scene->addItem(leaves->at(i)->room);
                }
                for(int j = 0; j < leaves->at(i)->halls.size(); j++) {
                    scene->addItem(leaves->at(i)->halls.at(j));
                }
            }
            for(int i = 0; i < items->size(); i++) {
                scene->addItem(items->at(i));
                if(items->at(i)->type==8){
                    player->setPos(items->at(i)->pos().x(),items->at(i)->pos().y()+HALL_SIZE);
                    player->createPolygon();
                    scene->addItem(player);
                }
            }
            for(int i = 0; i < enemies->size(); i++) {
                scene->addItem(enemies->at(i));
            }
        }else if (!nextORprev) {
            //salvo lo stato del livello
            floor floorLefted;
            floorLefted.leaves=*leaves;
            floorLefted.items=*items;
            floorLefted.enemies=*enemies;
            if(floorList.size()<level){
                floorList.push_back(floorLefted);
            }else{
                floorList.at(level-1)= floorLefted;
            }
            //svuoto la scena
            for(int i = 0; i != scene->items().size(); ) {
              scene->removeItem(scene->items().at(0));
            }
            scene->clear();
            scene->setBackgroundBrush(QBrush(QImage(":/Resources/Resources/outdoor.png")));
            //prendo i dati corrispondenti al nuovo livello
            level--;
            ui->levelLabel->setText("Level: " + QString::number(level));
            *leaves = floorList.at(level-1).leaves;
            *items = floorList.at(level-1).items;
            *enemies = floorList.at(level-1).enemies;
            //metto gli elementi e il player nella scena
            for(int i = 0; i < leaves->size(); i++) {
                if(leaves->at(i)->room!=NULL){
                    scene->addItem(leaves->at(i)->room);
                }
                for(int j = 0; j < leaves->at(i)->halls.size(); j++) {
                    scene->addItem(leaves->at(i)->halls.at(j));
                }
            }
            for(int i = 0; i < items->size(); i++) {
                scene->addItem(items->at(i));
                if(items->at(i)->type==7){
                    player->setPos(items->at(i)->pos().x(),items->at(i)->pos().y()-HALL_SIZE);
                    player->createPolygon();
                    scene->addItem(player);
                }
            }
            for(int i = 0; i < enemies->size(); i++) {
                scene->addItem(enemies->at(i));
            }
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////
/// GESTIONE BATTLEMODE

////////////////SPLASH//////////////////////
void MainWindow::battleSplashIn()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/splashBattle.png");
    QPixmap scaled=pic.scaled (171, 141);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->battleSplash->setPalette(palette);
    ui->battleSplash->setAutoFillBackground(true);
    ui->battleSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(battleSplashOut()));

}
void MainWindow::battleSplashOut()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->battleSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::bloodSplashIn()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/bloodSplash.png");
    QPixmap scaled=pic.scaled (SPLASH_PlAYER_HIT_WIDTH, SPLASH_PlAYER_HIT_HEIGHT);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->playerHitSplash->setPalette(palette);
    ui->playerHitSplash->setAutoFillBackground(true);
    ui->playerHitSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(HIT_SPLASH_TIME);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InBounce);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(bloodSplashOut()));

}
void MainWindow::bloodSplashOut()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->playerHitSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(HIT_SPLASH_TIME);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutBounce);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    passTurnButton->setEnabled(true);

}

void MainWindow::enemyFireAttackSplashIn(int damageSuffered)
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/fireAttackSplash.png");
    QPixmap scaled=pic.scaled (SPLASH_ENEMY_HIT_WIDTH, SPLASH_ENEMY_HIT_HEIGHT);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->enemyHitSplash->setPalette(palette);
    ui->enemyHitSplash->setAutoFillBackground(true);
    ui->enemyHitSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(HIT_SPLASH_TIME);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InBounce);
    anim->start(QPropertyAnimation::DeleteWhenStopped);


    //MESSAGGI DI ATTACCO
    switch(damageSuffered)
    {
    case(0):
        ui->MessageBoxW->setText("Sei riuscito a schivare l'attacco, hai perso " + QString::number(damageSuffered) + " punti vita!");
        break;

    case(1):
        ui->MessageBoxW->setText("Il nemico ti sta attaccando, hai perso " + QString::number(damageSuffered) + " punto vita!");
        break;

    default:
         ui->MessageBoxW->setText("Il nemico ti sta attaccando, hai perso " + QString::number(damageSuffered) + " punti vita!");
        break;

    }


    updateStat();

    connect(anim,SIGNAL(finished()),this,SLOT(enemyFireAttackSplashOut()));




}
void MainWindow::enemyFireAttackSplashOut()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->enemyHitSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(HIT_SPLASH_TIME);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(enemyTurnEnded()));

}

void MainWindow::warningSplashIn()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/warningSplash.png");
    QPixmap scaled=pic.scaled (271, 121);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->messageSplash->setPalette(palette);
    ui->messageSplash->setAutoFillBackground(true);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);


    connect(anim,SIGNAL(finished()),this,SLOT(warningSplashOut()));

}
void MainWindow::warningSplashOut()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(bossObjectiveMessage()));

}


void MainWindow::enemyDefeatedSplashIn()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/enemyDefeated.png");
    QPixmap scaled=pic.scaled(271, 141);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->messageSplash->setPalette(palette);
    ui->messageSplash->setAutoFillBackground(true);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(enemyDefeatedSplashOut()));
}
void MainWindow::enemyDefeatedSplashOut()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);


}

void MainWindow::bossDefeatedSplashIn()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPalette palette = QPalette();
    QPixmap pic(":/Resources/Resources/bossDefeated.png");
    QPixmap scaled=pic.scaled(271, 141);
    palette.setBrush(this->backgroundRole(), QBrush(scaled));
    ui->messageSplash->setPalette(palette);
    ui->messageSplash->setAutoFillBackground(true);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    connect(anim,SIGNAL(finished()),this,SLOT(bossDefeatedSplashOut()));

}
void MainWindow::bossDefeatedSplashOut()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->messageSplash->setGraphicsEffect(eff);
    QPropertyAnimation *anim = new QPropertyAnimation(eff,"opacity");
    anim->setDuration(2500);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::OutCurve);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

    bossDefeatedObjectiveMessage();



}

///////////////MAIN METHOD//////////////////

void MainWindow::enterIntoBattleMode(int id)
{

    currentEnemyId = id;
    int i = 0;
    while(enemies->at(i)->id != currentEnemyId){
        i++;
    }

    //da utilizzare in exitBattleMode() per risettare la posizione del personaggio
    playerOldPosition = player->pos();

    //NUOVA SCENA PER LA BATTAGLIA E IMPOSTAZIONI VIEW
    battleScene = new QGraphicsScene();
    battleScene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
    battleScene->setBackgroundBrush(QBrush(QImage(":/Resources/Resources/rsz_battlearena.png")));

    QMatrix battleMatrixS;
    battleMatrixS.scale(0.75,0.66);
    ui->view->setMatrix(battleMatrixS);
    ui->view->setScene(battleScene);

    //INIZIALIZZO LA BATTLEMODE UI
    battleModeUI();
    drop->setEnabled(false);
    ui->MessageBoxW->setText("Hai incontrato un nemico! Preparati a combattere!");

    //CREO IL NEMICO E GLI SETTO LE STAT IN BASE AL LIVELLO , lo assegno a currentEnemy
    Nemico *enemy = enemies->at(i);
    enemy->setEnemyInitStats(this->level,player,currentEnemyId);
    enemy->setMaxHp();

    currentEnemy = enemy;
    showEnemyHPLabel(currentEnemy->stat.hp);


    //SETUP ENEMY
    if(currentEnemyId==-1){
        currentEnemy->setPos(338,3);
        currentEnemy->resetMatrix();
        QMatrix battleMatrixE;
        battleMatrixE.scale(0.2,0.2);
        currentEnemy->setMatrix(battleMatrixE);
    }else{
        currentEnemy->setPos(350,10);
        currentEnemy->resetMatrix();
        QMatrix battleMatrixE;
        battleMatrixE.scale(1,1);
        currentEnemy->setMatrix(battleMatrixE);
    }

    //SETUP PLAYER
    player->setPos(350,450);
    player->resetMatrix();
    QMatrix battleMatrixP;
    battleMatrixP.scale(0.15,0.15);
    player->setMatrix(battleMatrixP);

    //AGGIUNGO ALLA SCENA PLAYER E NEMICO
    battleScene->addItem(currentEnemy);
    battleScene->addItem(player);

    //SPLASH
    battleSplashIn();

    //SET BATTLEMODE TRUE
    battleModeActive = true;

    playerTurn();
}

void MainWindow::exitBattleMode(){

    battleModeActive = false;
    battleEnded = false;

    ui->enemyHPLabel->setHidden(true);
    ui->turnLabel->setVisible(false);

    drop->setEnabled(true);

    //Ditruggo i bottoni creati dalla battleUI
    ui->battleButton->removeWidget(attackButton);
    ui->battleButton->removeWidget(passTurnButton);
    delete attackButton;
    delete passTurnButton;


    for (int i = 0; i < enemies->size(); i++){
            if(enemies->at(i)->id==currentEnemyId){
                enemies->erase(enemies->begin()+i);
                i = enemies->size()+1;
            }
        }
    delete currentEnemy;

    if(currentEnemyId==-1)
    {// DANIEL se hai battutto il boss frase diversa e splash di vittoria alternativa
        ui->MessageBoxW->setText("Battaglia Finita! Sconfiggendo il nemico sei diventato più forte!");
        bossDefeatedSplashIn();
    }
    else
    {
        ui->MessageBoxW->setText("Battaglia Finita! Sconfiggendo il nemico sei diventato più forte!");
         enemyDefeatedSplashIn();
    }


    QMatrix matrixS;
    matrixS.scale(2,2);
    ui->view->setMatrix(matrixS);
    ui->view->setScene(scene);

    player->setFocus();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setPos(playerOldPosition);
    ui->view->centerOn(player);
    scene->addItem(player);

    QMatrix matrixP;
    matrixP.scale(0.03,0.03);
    player->setMatrix(matrixP);

    //actualEnemy->moveTimer->start(1000);
    player->stat.str =  player->stat.str + 1;
    player->stat.hp =  player->stat.hp + 1;
    player->stat.def =  player->stat.def + 1;
    player->stat.luck =  player->stat.luck + 1;
    player->stat.vel =  player->stat.vel + 1;
    updateStat();
}

void MainWindow::muoviArma()
{


  QList<QGraphicsItem *> collidingWeaponEnemy =tempWeapon->collidingItems();

  //COLLISIONI CON nemici
  for (int i = 0; i < collidingWeaponEnemy.size(); i++)
  {
      if (typeid(*(collidingWeaponEnemy[i])) == typeid(Nemico))
      {
          //Infliggo danno al nemico (basato sulla weapon DMG)
          currentEnemy->stat.hp = currentEnemy->stat.hp - player->getPlayerDamage();

          //AGGIORNA ENEMYHPLABEL
          updateEnemyHPLabel();

          //rimuovo la spada dalla battleScene
          battleScene->removeItem(tempWeapon);


          if(currentEnemy->stat.hp <= 0)
          {
              passTurnButton->setText("CONTINUA");
              battleEnded=true;
              battleScene->removeItem(collidingWeaponEnemy[i]);
          }

          if(player->getPlayerDamage() == 1)
            ui->MessageBoxW->setText("Hai inflitto " + QString::number(player->getPlayerDamage()) + " danno al nemico");
          else
             ui->MessageBoxW->setText("Hai inflitto " + QString::number(player->getPlayerDamage()) + " danni al nemico");


          attackButton->setEnabled(false);
          bloodSplashIn();
          armaAnimationTimer->stop();
          tempWeapon->setVisible(false);
          delete tempWeapon;
          return;
      }
  }
  QMatrix weaponSize ;
  weaponSize.scale(2,2);
  tempWeapon->setMatrix(weaponSize);
  tempWeapon->setVisible(true);
  tempWeapon->setPos(tempWeapon->x(),tempWeapon->y() - 20);


}

void MainWindow::moveWeapon()
{
  if(TurnActions < MAX_TURN_ACTIONS)
    {
        passTurnButton->setEnabled(false);
        increaseActionNumber();
        armaAnimationTimer->start(100);

    }
    else{
        ui->MessageBoxW->setText("<font color='red'>Hai già fatto abbastanza azioni per questo turno!</font>");
    }
}

void MainWindow::showEnemyHPLabel(int enemyHP)
{
    int hp = enemyHP;

    QFont hpFont("Arial",13,QFont::Bold);
    ui->enemyHPLabel->setTextFormat(Qt::RichText);
    ui->enemyHPLabel->setFont(hpFont);
    ui->enemyHPLabel->setStyleSheet("color: white");

    ui->enemyHPLabel->setText("HP: " + QString::number(enemyHP) + "/" + QString::number(enemyHP));



}

void MainWindow::updateEnemyHPLabel()
{

    QFont hpFont("Arial",13,QFont::Bold);
    ui->enemyHPLabel->setTextFormat(Qt::RichText);
    ui->enemyHPLabel->setFont(hpFont);
    ui->enemyHPLabel->setStyleSheet("color: white");

    int actualHp = currentEnemy->stat.hp;
    int maxHP = currentEnemy->maxHp;


    if(actualHp < 0)
        actualHp = 0;

    ui->enemyHPLabel->setText("HP: " + QString::number(actualHp) + "/" + QString::number(maxHP));


}

//////////////////TURNS/////////////////////

void MainWindow::playerTurn()
{

    if(!battleEnded)
    {

        qDebug() <<"Turno Giocatore" << turnNumber;
        ui->turnLabel->setText("<font color='blue'> TURNO GIOCATORE </font>");

        attackButton->setEnabled(true);
        passTurnButton->setEnabled(true);

        tempWeapon = new Item(5,this->level);
        tempWeapon->weaponDamage = player->weapon->weaponDamage;

        tempWeapon->setPos(player->x()+40 ,player->y()-30);
        tempWeapon->setVisible(false);
        battleScene->addItem(tempWeapon);

    }

    else
        exitBattleMode();


}

void MainWindow::enemyTurn()
{

    if(!battleEnded)
    {

         qDebug() <<"Turno Nemico " << turnNumber;
         ui->turnLabel->setText("<font color='red'> TURNO NEMICO </font>");

         attackButton->setEnabled(false);
         passTurnButton->setEnabled(false);

         int damageSuffered = currentEnemy->getEnemyDamage() - player->getReducedAmountDamage();

         if(damageSuffered < 0)
             damageSuffered = 0;

         player->stat.hp = player->stat.hp - damageSuffered;

         enemyFireAttackSplashIn(damageSuffered);



         //chiama enemyTurnEnded che chiama passTurn(true) e ripassa al PlayerTurn

    }

    else
        exitBattleMode();


}

void MainWindow::enemyTurnEnded()
{


    if(!(player->stat.hp > 0))
    {
        QPalette palette = QPalette();
        QPixmap pic(":/Resources/Resources/dead.png");
        palette.setBrush(this->backgroundRole(), QBrush(pic));
        ui->splashScreen->setPalette(palette);
        ui->startScreen->hide();
        ui->backgroundWidget->hide();
        ui->gameWidget->hide();
        ui->splashScreen->show();
    }

     passTurn(true);

}

void MainWindow::passTurn(bool calledBy)
{

    //FALSE CALLED BY PLAYER
    //TRUE CALLED BY ENEMY

    switch(calledBy)
    {
     //passa il turno al nemico
    case(false):
        ui->MessageBoxW->setText("");
        TurnActions = 0;
        turnNumber++;
        enemyTurn();
        break;

     //passa il turno al player
    case(true):
        ui->MessageBoxW->setText("");
        TurnActions = 0;
        turnNumber++;
        playerTurn();
        break;

    }

}

void MainWindow::printWeaponWarning()
{
    ui->MessageBoxW->setText("<font color='red'> ATTENTO! Procurati e indossa un'arma prima di combatttere! </font>");

}


////////////////////////////////////////////

void MainWindow::increaseActionNumber()
{
    if(battleModeActive)
        TurnActions++;
}

void MainWindow::battleModeUI()
{

    ui->turnLabel->setHidden(false);
    ui->enemyHPLabel->setHidden(false);
    //LABEL VITA PLAYER;

    attackButton = new QPushButton("ATTACCA");
    passTurnButton = new QPushButton("PASSA");
    attackButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    passTurnButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    ui->battleButton->addWidget(attackButton);
    ui->battleButton->addWidget(passTurnButton);
    attackButton->setEnabled(false);
    passTurnButton->setEnabled(false);



    connect(attackButton,SIGNAL(clicked(bool)),this,SLOT(moveWeapon()));
    connect(passTurnButton,SIGNAL(clicked(bool)),this,SLOT(passTurn(bool)));

}

//////////////////////////////////////////////////////////////////////////////////////////      GESTIONE UI
/// CREATE / UPDATE USER INTERFACE

void MainWindow::initGUI()
{
    //setto gli slot INVENTARIO
    QButtonGroup * inventoryButtons = new QButtonGroup;
    for (int i = 0; i < 8; ++i){
        char numstr[10];
        sprintf(numstr, "Slot%d", i+1);
        slot.push_back(new QPushButton(numstr));
        slot.at(i)->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        slot.at(i)->setDisabled(true);
        inventoryButtons->addButton( slot.at(i),i);
        ui->inventory->addWidget(slot.at(i),(i/4),(i%4));
    }

    //setto gli slot ARMOR e WEAPON
    weapon = new QPushButton("Weapon");
    armor = new QPushButton("Armor");
    weapon->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    armor->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    weapon->setDisabled(true);
    armor->setDisabled(true);
    QButtonGroup * armorWeaponButtons = new QButtonGroup();
    armorWeaponButtons->addButton(weapon,8);
    armorWeaponButtons->addButton(armor,9);
    ui->ItemDressed->addWidget(weapon);
    ui->ItemDressed->addWidget(armor);

    //setto i bottoni USE e DROP
    drop = new QPushButton("DROP");
    use = new QPushButton("USE");
    drop->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    use->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QButtonGroup * dropUseButtons = new QButtonGroup;
    dropUseButtons->addButton(use,1);
    dropUseButtons->addButton(drop,2);
    ui->DropUseLayout->addWidget(use);
    ui->DropUseLayout->addWidget(drop);


    //SETTO LA LABEL DELLA BATTLEMODE INVISIBILE
    ui->turnLabel->setHidden(true);
    ui->enemyHPLabel->setHidden(true);

    //SETTO L'IMMAGINE STATICA DEL PLAYER
    QPixmap playerImagePix(":/Resources/Resources/wolf.png");
    ui->PlayerImage->setPixmap(playerImagePix.scaled(ui->PlayerImage->width(),ui->PlayerImage->height(),Qt::KeepAspectRatio));

    //SETTO I CONNECTOR DEGLI SLOT DELLA GUI
    connect(inventoryButtons,SIGNAL(buttonClicked(int)),this,SLOT(inventoryButtonClicked(int)));
    //connect(armorWeaponButtons,SIGNAL(buttonClicked(int)),this,SLOT(weaponArmorDressedClicked(int)));
    connect(dropUseButtons,SIGNAL(buttonClicked(int)),this,SLOT(dropUseButtonClicked(int)));
    connect(armorWeaponButtons,SIGNAL(buttonClicked(int)),this,SLOT(weaponArmorButtonClicked(int)));

}

void MainWindow::updateInventory(bool activatedByCollider)
{
    //il collider attiva lo slot
    if(activatedByCollider){
        //remove from the scene and from the item vector
        scene->removeItem(inventory.at(inventory.size()-1));
        for (int i = 0; i < items->size(); i++) {
            if(items->at(i)==inventory.at(inventory.size()-1)){
                items->erase(items->begin()+i);
                i=items->size()+1;
            }
        }
        //STAMPO UN MESSAGGIO sull'item trovato
        printDroppedItemMessage();
    }

    //aggiorno gli slot dell'inventario
    int i = 0;
    for (; i < inventory.size(); i++){
        slot.at(i)->setIcon(QIcon(enumImagesItem[inventory.at(i)->type]));
        slot.at(i)->setDisabled(false);  //attiva i pulsanti contententi inventory
    }
    for (; i < slot.size(); i++){
        slot.at(i)->setIcon(QIcon(""));
        slot.at(i)->setDisabled(true);   //disattiva i pulsanti vuoti
    }

}

void MainWindow::updateStat()
{

    if(player->stat.hp < 0)
        player->stat.hp = 0;


    ui->HP->setText(QString::number(player->stat.hp));
    ui->DEF->setText(QString::number(player->stat.def));
    ui->VEL->setText(QString::number(player->stat.vel));
    ui->STR->setText(QString::number(player->stat.str));
    ui->LUCK->setText(QString::number(player->stat.luck));
    ui->AP->setText(QString::number(player->stat.ap));
}

///GESTIONE BOTTONI

void MainWindow::dropUseButtonClicked(int buttonId)
{

    qDebug() << "last selected item is" << this->lastSelectedInventoryItem;


    //QString itemName = getItemType(inventory.at(this->lastSelectedItem)->type);


    switch(buttonId)
    {

    case(1):        //USE BUTTON

        if(battleModeActive)
        {
            if(TurnActions < MAX_TURN_ACTIONS)
                useButtonProcedure();
            else
                ui->MessageBoxW->setText("Hai già fatto abbastanza azioni per questo turno!");
        }
        else
            useButtonProcedure();
        break;

    case(2):        //DROP BUTTON
        dropButtonProcedure();
        break;


    }


    //GESTIRE IL CASO IN CUI CLICCO SULLO SLOT VUOTO



}

void MainWindow::useButtonProcedure()
{
    //check item id , type (ARMA ARMATURA O POZIONE?)
    //prendi le stats dell'item e aggiungile a player parameters
    //stampa le stats aggiornate

    switch(lastSelectedInventoryItem)
    {

        //WEAPON SLOT CLICKED
        case(8):
            if(weapon->isEnabled() && inventory.size()<8)
            {

                inventory.push_back(player->weapon);
                player->weapon = nullptr;
                player->isWeaponDressed = false;
                updateInventory(false);
                weapon->setIcon(QIcon(""));
                weapon->setText("Weapon");
                weapon->setDisabled(true);
                player->isWeaponAlreadyDressed = false;
                this->use->setText("USE");

            }
            else
                ui->MessageBoxW->setText("Fai spazio nell'inventario!");
        break;

        //ARMOR SLOT CLICKED
        case(9):
            if(armor->isEnabled() && inventory.size()<8)
            {
                inventory.push_back(player->armor);
                player->setStat(-player->armor->bonus.hp,0,0,-player->armor->bonus.def,0,0);
                updateStat();
                player->armor = nullptr;
                updateInventory(false);
                armor->setIcon(QIcon(""));
                armor->setText("Armor");
                armor->setDisabled(true);
                player->isArmorAlreadyDressed = false;
                this->use->setText("USE");
            }

            else
                ui->MessageBoxW->setText("Fai spazio nell'inventario!");

         break;




        //INVENTORY SLOT CLICKED
        default:
            if (slot.at(this->lastSelectedInventoryItem)->isEnabled())
            {


                ////////////////////// KEY ///////////////////////////////////////
                if (inventory.at(this->lastSelectedInventoryItem)->type == 6)
                {
                    ui->MessageBoxW->setText("Non posso usare questa chiave quì...");
                       return;
                }


                ////////////////////// WEAPON ///////////////////////////////////////
                if (inventory.at(this->lastSelectedInventoryItem)->type == 5)
                {
                        ui->MessageBoxW->setText("Hai indossato un'arma");
                        dressWeapon();
                        increaseActionNumber();
                       return;
                }

                ////////////////////// ARMOR ///////////////////////////////////////
                if (inventory.at(this->lastSelectedInventoryItem)->type == 4)
                {
                        ui->MessageBoxW->setText("Hai indossato un'armatura");
                        dressArmor();
                        increaseActionNumber();
                       return;
                }



                ////////////////////// POTIONS ///////////////////////////////////////

                else
                    {
                    //stampo un messaggio sull'item usato
                    ui->MessageBoxW->setText("Hai usato " + getItemType(inventory.at(this->lastSelectedInventoryItem)->type));
                    //Sommo le statistiche dell'oggetto al player
                    player->setStat(inventory.at(this->lastSelectedInventoryItem)->bonus.hp,
                                    inventory.at(this->lastSelectedInventoryItem)->bonus.ap,
                                    inventory.at(this->lastSelectedInventoryItem)->bonus.str,
                                    inventory.at(this->lastSelectedInventoryItem)->bonus.def,
                                    inventory.at(this->lastSelectedInventoryItem)->bonus.luck,
                                    inventory.at(this->lastSelectedInventoryItem)->bonus.vel);

                    //updateStats
                    this->updateStat();
                    Item *use = inventory.at(lastSelectedInventoryItem);
                    inventory.erase(inventory.begin()+lastSelectedInventoryItem);
                    delete use;
                    updateInventory(false);
                    increaseActionNumber();
                    }
            }

            else
                ui->MessageBoxW->setText("No Slot Selected");
        break;

    }

}

void MainWindow::dropButtonProcedure()
{

    switch(lastSelectedInventoryItem)
    {

        //WEAPON SLOT CLICKED
        case(8):
            if(weapon->isEnabled() && inventory.size()<8)
            {
                //elimino l'arma e de-alloco la memoria ad essa relativa
                delete player->weapon;
                player->weapon = nullptr;
                player->isWeaponDressed = false;
                weapon->setIcon(QIcon(""));
                weapon->setText("Weapon");
                weapon->setDisabled(true);
                player->isWeaponAlreadyDressed = false;
                this->use->setText("USE");
                ui->MessageBoxW->setText("Hai buttato l'arma!");

            }
            else
                ui->MessageBoxW->setText("Fai spazio nell'inventario!");
        break;

        //ARMOR SLOT CLICKED
        case(9):
            if(armor->isEnabled() && inventory.size()<8)
            {
                //elimino l'armatura e de-alloco la memoria ad essa relativa
                delete player->armor;
                player->setStat(-player->armor->bonus.hp,0,0,-player->armor->bonus.def,0,0);
                updateStat();
                player->armor = nullptr;
                updateInventory(false);
                armor->setIcon(QIcon(""));
                armor->setText("Armor");
                armor->setDisabled(true);
                player->isArmorAlreadyDressed = false;
                this->use->setText("USE");
                ui->MessageBoxW->setText("Hai buttato l'armatura!");
            }

            else
                ui->MessageBoxW->setText("Fai spazio nell'inventario!");

         break;



        default:

            if (slot.at(this->lastSelectedInventoryItem)->isEnabled())
            {
                if (inventory.at(this->lastSelectedInventoryItem)->type == 6)  //KEY
                    ui->MessageBoxW->setText("Questa è meglio che la tenga, potrebbe servirmi...");

                else
                    {
                    //stampo un messaggio di avviso sul'item buttato
                    ui->MessageBoxW->setText("Hai buttato " + getItemType(inventory.at(this->lastSelectedInventoryItem)->type));
                    //Butto l'oggetto alla posizione lastSelectedItem
                    inventory.erase(inventory.begin()+lastSelectedInventoryItem);
                    updateInventory(false);
                    }
            }

            else
                ui->MessageBoxW->setText("No Slot Selected");

        break;

    }


}

///DRESS FUNCTIONS

void MainWindow::dressWeapon()
{

    if(!(player->stat.str < inventory.at(this->lastSelectedInventoryItem)->weaponStr))
    {

        if(player->isWeaponAlreadyDressed)
            ui->MessageBoxW->setText("Stai già indossando un'arma, selezionala e premi take off per rimetterla nell'inventario");



        else
        {
        //assegno l'arma al player
        player->weapon = inventory.at(lastSelectedInventoryItem);
        //tolgo l'item dall'inventario e lo stampo nello slotweapon
        inventory.erase(inventory.begin()+lastSelectedInventoryItem);
        updateInventory(false);
        player->isWeaponDressed = true;
        weapon->setEnabled(true);
        weapon->setText("");
        weapon->setIcon(QIcon(enumImagesItem[player->weapon->type]));
        player->isWeaponAlreadyDressed= true;
        }

    }



    else
        ui->MessageBoxW->setText("Hai bisogno di almeno " + QString::number(inventory.at(this->lastSelectedInventoryItem)->weaponStr)
                                + " str per indossare quest'arma!");



}

void MainWindow::dressArmor()
{
    if(player->isArmorAlreadyDressed)
        ui->MessageBoxW->setText("Stai già indossando un'armatura, selezionala e premi take off per rimetterla nell'inventario");


    else
        {
        //assegno l'item al player
        player->armor = inventory.at(lastSelectedInventoryItem);
        //tolgo l'item dall'inventario e lo stampo nello slotarmor e sommo le statistiche
        inventory.erase(inventory.begin()+lastSelectedInventoryItem);
        player->setStat(player->armor->bonus.hp,0,0,player->armor->bonus.def,0,0);
        updateInventory(false);
        updateStat();
        armor->setEnabled(true);
        armor->setText("");
        armor->setIcon(QIcon(enumImagesItem[player->armor->type]));
        player->isArmorAlreadyDressed= true;
        }

}

///PRINT STATISTICS

void MainWindow::inventoryButtonClicked(int id)
{

    this->lastSelectedInventoryItem = id;
    this->use->setText("USE");
    QString space = " ";

    switch(inventory.at(id)->type)
    {

    case(0):        //HP POTION
          ui->MessageBoxW->setText("Pozione della vita  HP: +" + QString::number(inventory.at(id)->bonus.hp));
       break;

    case(1):        //AP POTION
          ui->MessageBoxW->setText("Pozione delle abilità  AP: +" + QString::number(inventory.at(id)->bonus.ap));
        break;

    case(2):        //STR POTION
          ui->MessageBoxW->setText("Pozione dell forza  STR: +" + QString::number(inventory.at(id)->bonus.str));
       break;

    case(3):        //RAND POTION
          ui->MessageBoxW->setText("Pozione casuale  HP: +" + QString::number(inventory.at(id)->bonus.hp)
                                          + space + " AP: +" + QString::number(inventory.at(id)->bonus.ap)
                                          + space + " DEF: +" + QString::number(inventory.at(id)->bonus.def)
                                          + space + " STR: +" + QString::number(inventory.at(id)->bonus.str)
                                          + space + " LUCK: +" + QString::number(inventory.at(id)->bonus.luck)
                                          + space + " VEL: +" + QString::number(inventory.at(id)->bonus.vel));
        break;

    case(4):        //ARMOR
          ui->MessageBoxW->setText("'Armatura Imperiale'  HP: +" + QString::number(inventory.at(id)->bonus.hp)
                                + space + "DEF: +" + QString::number(inventory.at(id)->bonus.def) );
        break;

    case(5):        //WEAPON
        if(!(player->stat.str < inventory.at(id)->weaponStr))
          ui->MessageBoxW->setText("'Spada Flagello del Drago'  Danno: +" + QString::number(inventory.at(id)->weaponDamage)
                 + space + space + " Forza necessaria: " + QString::number(inventory.at(id)->weaponStr));
        else
            ui->MessageBoxW->setText("'Spada Flagello del Drago'  Danno: +" + QString::number(inventory.at(id)->weaponDamage)
                   + space + space + "<font color='red'> Forza necessaria: </font>" + QString::number(inventory.at(id)->weaponStr));


        break;

    case(6):        //KEY
          ui->MessageBoxW->setText("Chiave d'oro misteriosa..." );
        break;


    default:        //EMPTY SLOT
          ui->MessageBoxW->setText("Slot vuoto" );
        break;

    }


    //GESTIRE IL CASO IN CUI CLICCO SULLO SLOT VUOTO

}

void MainWindow::weaponArmorButtonClicked(int buttonId)
{

    qDebug() << "last selected item is" << buttonId;
    this->lastSelectedInventoryItem = buttonId;
    this->use->setText("TOGLI");


    switch(buttonId)
    {

    case(8):
        ui->MessageBoxW->setText("'Spada Flagello del Drago'  Danno: +" + QString::number(player->weapon->weaponDamage) );
        break;

    case(9):
        ui->MessageBoxW->setText("'Armatura Imperiale'  HP: +" + QString::number(player->armor->bonus.hp)
                               + "   DEF: +" + QString::number(player->armor->bonus.def));
        break;
    default:
        break;
    }




}

///MESSAGEBOX FUNCTIONS

void MainWindow::printDroppedItemMessage()
{
    //switch sul tipo dell'ultimo item inserito nell'inventario

    switch(inventory.at(inventory.size()-1)->type)
    {

    case(0):        //HP POTION
          ui->MessageBoxW->setText("Hai trovato una pozione per la vita!");
         break;

    case(1):        //AP POTION
          ui->MessageBoxW->setText("Hai trovato una pozione per i punti abilità!");
         break;

    case(2):        //STR POTION
          ui->MessageBoxW->setText("Hai trovato una pozione per la forza!");
         break;

    case(3):        //RAND POTION
          ui->MessageBoxW->setText("Hai trovato una pozione misteriosa...!");
         break;

    case(4):        //ARMOR
          ui->MessageBoxW->setText("Hai trovato un'armatura!");
         break;

    case(5):        //WEAPON
          ui->MessageBoxW->setText("Hai trovato un'arma!");
         break;

    case(6):        //WEAPON
          ui->MessageBoxW->setText("Hai trovato una chiave misteriosa...!");
         break;
    }


}

void MainWindow::printFullInventoryWarning(bool isFull)
{
    if(isFull)
        ui->MessageBoxW->setText("Non posso caricare altri oggetti, devo liberarmi di qualcosa...");

}

///UTILITY

QString MainWindow::getItemType(int item)
{

    switch(item)
    {
    case(0):        //HP POTION
         return "'Pozione della Vita'";
       break;

    case(1):        //AP POTION
          return "'Pozione delle Abilità'";
        break;

    case(2):        //STR POTION
           return "'Pozione delle Forza'";
       break;

    case(3):        //RAND POTION
            return "'Pozione casuale'";
        break;

    case(4):        //ARMOR
            return "'Armatura Imperiale'";
        break;

    case(5):        //WEAPON
          return "'Spada Flagello del Drago'";
        break;

    case(6):        //KEY
          return "Chiave d'oro misteriosa...";;
        break;


    }
}

void MainWindow::startObjectiveMessage()
{
    ui->Obiettivi->setWordWrap(true);
    ui->Obiettivi->setText("Obiettivo:\n Raccogli l'arma e avventurati nel Dungeon ma attento ai nemici!");

}

void MainWindow::bossObjectiveMessage()
{

    ui->Obiettivi->setWordWrap(true);
    ui->Obiettivi->setText("Obiettivo:\n Attento! Il Colosso della Lava si aggira in queste grotte, distruggilo per vincere!");



}

void MainWindow::bossDefeatedObjectiveMessage()
{

    ui->Obiettivi->setWordWrap(true);
    ui->Obiettivi->setText("Obiettivo:\n Congratulazioni! Hai sconfitto il Colosso della lava!");


}

void MainWindow::setTextNameColor()
{

    ui->playerStartName->setTextColor(QColor(255,255,255));

}

//////////////////////////////////////////////////////////////////////////////////////////
/// GESTIONE INPUT

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    switch (key)
    {
        case Qt::Key_A:
        case Qt::Key_Left:
            player->blocca_left();
            break;
        case Qt::Key_W:
        case Qt::Key_Up:
            player->blocca_up();
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            player->blocca_right();
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            player->blocca_down();
            break;

        case Qt::Key_1: if(slot.at(0)->isEnabled()){inventoryButtonClicked(0);} break;
        case Qt::Key_2: if(slot.at(1)->isEnabled()){inventoryButtonClicked(1);} break;
        case Qt::Key_3: if(slot.at(2)->isEnabled()){inventoryButtonClicked(2);} break;
        case Qt::Key_4: if(slot.at(3)->isEnabled()){inventoryButtonClicked(3);} break;
        case Qt::Key_5: if(slot.at(4)->isEnabled()){inventoryButtonClicked(4);} break;
        case Qt::Key_6: if(slot.at(5)->isEnabled()){inventoryButtonClicked(5);} break;
        case Qt::Key_7: if(slot.at(6)->isEnabled()){inventoryButtonClicked(6);} break;
        case Qt::Key_8: if(slot.at(7)->isEnabled()){inventoryButtonClicked(7);} break;
        case Qt::Key_Space:  if(battleModeActive && attackButton->isEnabled()){this->moveWeapon();} break;

        default:
            break;
    }
    ui->gameWidget->setFocus();
    ui->view->centerOn(player);
}

//////////////////////////////////////////////////////////////////////////////////////////
/// GESTIONE MEMORIA

void MainWindow::freeMEM()
{
    for(int i=0;i<floorList.size();i++)
    {
        for(int j=0;j<floorList.at(i).leaves.size();j++){
            delete floorList.at(i).leaves.at(j);
            floorList.at(i).leaves.at(j) = NULL;
        }
        for(int j=0;j<floorList.at(i).items.size();j++){
            delete floorList.at(i).items.at(j);
            floorList.at(i).items.at(j) = NULL;
        }
        for(int j=0;j<floorList.at(i).enemies.size();j++){
            delete floorList.at(i).items.at(j);
            floorList.at(i).items.at(j) = NULL;
        }
        floorList.erase(floorList.begin()+i);
    }
    floorList.clear();
    floorList.shrink_to_fit();
    inventory.clear();
    inventory.shrink_to_fit();

    //RESET VARIABLES
    battleEnded = false;
    battleModeActive = false;
    playerWin = false;
    boss = false;
    TurnActions = 0;



    /*
    for(int i=0;i<leaves->size();i++){
       if(leaves->at(i) != NULL)
       delete leaves->at(i);
    }

    for(int i=0;i<items->size();i++){
       if(items->at(i) != NULL)
       delete items->at(i);
    }

    for(int i=0;i<enemies->size();i++){
       if(enemies->at(i) != NULL)
       delete enemies->at(i);
    }
    */
    delete leaves;
    delete items;
    delete enemies;
    delete player;
    delete scene;

    if(battleModeActive){
        ui->battleButton->removeWidget(attackButton);
        ui->battleButton->removeWidget(passTurnButton);
        delete attackButton;
        delete passTurnButton;
        ui->enemyHPLabel->setHidden(true);
        use->setEnabled(true);
        drop->setEnabled(true);
    }

    weapon->setIcon(QIcon(""));
    weapon->setText("Weapon");
    weapon->setDisabled(true);
    armor->setIcon(QIcon(""));
    armor->setText("Armor");
    armor->setDisabled(true);

}

//////////////////////////////////////////////////////////////////////////////////////////
/// GESTIONE SUOND

void MainWindow::playGameSoundtrack()
{

    QMediaPlaylist* gameSoundTrack = new QMediaPlaylist();
    gameSoundTrack->addMedia(QUrl("qrc:/Sounds/Sounds/Soundtrack gameRemixVersion faded.mp3"));
    gameSoundTrack->setPlaybackMode(QMediaPlaylist::Loop);



    QMediaPlayer* music = new QMediaPlayer();
    music->setPlaylist(gameSoundTrack);
    music->setVolume(70);
    music->play();
}

