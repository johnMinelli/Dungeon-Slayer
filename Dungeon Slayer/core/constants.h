//
// Created by Gio on 14/10/2017.
//

#ifndef NEW64_CONSTANTS_H
#define NEW64_CONSTANTS_H

//window
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

//mapRAND
const int MAX_LEAF_SIZE = 400;
const int LEAF_SIZE = 340;
const int MIN_LEAF_SIZE = 80;
const int HALL_SIZE=30;

//SplashWidgetSize
const int SPLASH_ENEMY_HIT_WIDTH = 101;
const int SPLASH_ENEMY_HIT_HEIGHT = 80;

const int SPLASH_PlAYER_HIT_WIDTH = 101;
const int SPLASH_PlAYER_HIT_HEIGHT = 80;

//Battle
const int MAX_TURN_ACTIONS = 1;
const int HIT_SPLASH_TIME = 1500; //3000 perchè IN+OUT

//items
enum enumItems{
    potionHP,
    potionAP,
    potionSTR,
    potionRAND,
    armor,
    weapon,
    key,
    trapdoor,
    ladder
};

const char enumImagesItem[][50] = {
    ":/Resources/Resources/potionHP.png" ,
    ":/Resources/Resources/potionAP.png" ,
    ":/Resources/Resources/potionSTR.png" ,
    ":/Resources/Resources/potionRAND.png" ,
    ":/Resources/Resources/armor.png",
    ":/Resources/Resources/weapon.png",
    ":/Resources/Resources/key.png",
    ":/Resources/Resources/trapdoor.png",
    ":/Resources/Resources/ladder.png"
};

enum enumStats{
    health,
    actionpoint,
    damage,
    defense,
    strenght
};

struct parameters{
    int hp;
    int ap;
    int str;
    int def;
    int luck;
    int vel;
};

#endif //NEW64_CONSTANTS_H
