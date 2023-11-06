#pragma once
#include"Macros.h"
#include "Player.h"
#include <vector>

class Bombs;
class UIManager{
private:
public:
    static int bomb_count;
    static std::vector<Bombs> bomb_list;
};