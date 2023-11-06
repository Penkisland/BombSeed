#pragma once
#include "MapGenerator.h"
#include "Macros.h"
#include "Control.h"
#include "Collectibles.h"
#include <string.h>

class Player;

class Bombs{
private:
    int range = 1;
    int count_down = 2, max = 2;
    Coord pos = Coord(0, 0);
public:
    void DestroyBlocks(std::string** map, int _range, Coord _pos, Player& p);
    void OnBomb(MapGenerator map, Player& p);
    Bombs(Coord _pos, int _range);
    Coord GetPos();
    void CountDown(MapGenerator map, Player &p);
};