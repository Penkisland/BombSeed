#ifdef PLAYER
#endif
#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "Control.h"
#include <string>
#include "Mapgenerator.h"
#include "Macros.h"
#include"Bomb.h"
#include "Collectibles.h"

class Player{
private:
    int health = 1, max_health = 1;
    int bomb_count = 2, bomb_max = 2;
    int bomb_range = 1;
    int invicible_time = 30, invisible_max = 30;
    int invencible_time = 15, invencible_time_max = 15;
    int shield_time = 15, shield_time_max = 15;
    int speed = 2;
    //used for state machine
    bool is_under_protect = false, is_invencible = false;
    std::string idle = Character1, state = Character1, on_what = "";
    Coord pos = Coord(0, 0);
public:
    int get_hp();
    int get_bomb();
    std::string get_state();
    bool get_protect_state();
    bool get_invecible_state();
    void set_on_what(std::string obj);
    Coord get_pos();
    void StateConvert();
    void CountDown(int item);
    void Heal();
    void MaxHealthUp();
    void BombRestore();
    void MaxBombUp();
    void PlaceBomb(MapGenerator map);
    bool Move(int key, MapGenerator map);
    Player(int playerStyle);
    void SetPlayer(int x, int y);
    void Hurt();
    void Death();
    void UnderProtect();
    void Invence();
    void InvenceOver();
    void ShieldOff();
    void Recover();
    void CountDownOverTime();
    void RangeUp();
};
#endif