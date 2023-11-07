#include "Collectibles.h"
#include "Player.h"
#include "MapGenerator.h"
#include "Bomb.h"
void Collectibles::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}

void Collectibles::Oncollect(Player &p, MapGenerator &map){};

Coord Collectibles::get_pos(){
    return this->pos;
}

void Collectibles::Destroy()
{ 
    UIManager::collectible_list.erase(UIManager::collectible_list.find(this->pos));
}

void Healer::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}
void Healer::OnCollect(Player &p, MapGenerator &map)
{
    p.Heal();
    Destroy();
    p.set_on_what(NullBlrick);
}

void Capsule::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}
void Capsule::OnCollect(Player &p, MapGenerator &map)
{
    p.MaxBombUp();
    Destroy();
    p.set_on_what(NullBlrick);
}

void ShieldCap::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}
void ShieldCap::OnCollect(Player &p, MapGenerator &map)
{
    p.UnderProtect();
    Destroy();
    p.set_on_what(NullBlrick);
}

void Potion::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}
void Potion::OnCollect(Player &p, MapGenerator &map)
{
    p.RangeUp();
    Destroy();
    p.set_on_what(NullBlrick);
}

void Goddess::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
    UIManager::collectible_list.insert(std::pair<Coord, Collectibles*>(this->pos, this));
}
void Goddess::OnCollect(Player &p, MapGenerator &map)
{
    p.Invence();
    Destroy();
    p.set_on_what(NullBlrick);
}

Collectibles *Get_Collectibles()
{
    int ind = rand() % 5;
    switch (ind)
    {
    case 0:
        return new Healer();
    case 1:
        return new Capsule();
    case 2:
        return new ShieldCap();
    case 3:
        return new Potion();
    case 4:
        return new Goddess();
    default:
        return nullptr;
        break;
    }
}