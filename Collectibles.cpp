#include "Collectibles.h"
#include "Player.h"
#include "Bomb.h"
void Collectibles::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void Collectibles::Destroy()
{
}

void Healer::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void Healer::OnCollect(Player *p)
{
    p->Heal();
    Destroy();
}

void Capsule::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void Capsule::OnCollect(Player &p)
{
    p.MaxBombUp();
    Destroy();
}

void ShieldCap::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void ShieldCap::OnCollect(Player &p)
{
    p.UnderProtect();
    Destroy();
}

void Potion::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void Potion::OnCollect(Player &p)
{
    p.RangeUp();
    Destroy();
}

void Goddess::Spawn(Coord _pos, std::string **map)
{
    map[_pos.x][_pos.y] = this->icon;
}
void Goddess::OnCollect(Player &p)
{
    p.Invence();
    Destroy();
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