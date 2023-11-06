#pragma once
#include"Macros.h"
#include "Player.h"
#include <vector>
#include <iostream>

class Bombs;
class UIManager{
private:
public:
    static int bomb_count;
    static std::vector<Bombs> bomb_list;
    static void DisplayInfo(Player &p);
};