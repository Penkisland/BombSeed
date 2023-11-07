#pragma once
#include"Macros.h"
#include "Player.h"
#include "Collectibles.h"
#include <vector>
#include <unordered_map>
#include <iostream>

class Collectibles;
class Bombs;
class UIManager{
private:
public:
    static int bomb_count;
    static std::vector<Bombs> bomb_list;
    static std::unordered_map<Coord, Collectibles*, CoordHash, CoordEqual> collectible_list;
    static void DisplayInfo(Player &p);
};