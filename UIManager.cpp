#include "UIManager.h"
#include <vector>
#include <unordered_map>

// Use to manage all the existing object on the map
//  TODO: Add codes to display resources(ep. Hp, bombs)
int UIManager::bomb_count;
std::vector<Bombs> UIManager::bomb_list;

std::unordered_map<Coord, Collectibles*, CoordHash, CoordEqual> UIManager::collectible_list;


void UIManager::DisplayInfo(Player &p)
{
    for(int i = 0; i < p.get_hp(); i++){
        std::cout << Hp;
    }
    std::cout << std::endl;
    for(int i = 0; i < p.get_bomb(); i++){
        std::cout << Bomb;
    }
    std::cout << std::endl;
}