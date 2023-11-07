#pragma once
#include <string>

class Player;//forward decleration instead of using headers, but only ptr usable
class MapGenerator;
#include "Control.h"
#include "Macros.h"
#include "UIManager.h"

class Collectibles{
private:
    std::string icon = "";
    
public:
    Coord pos = Coord(0, 0);
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void Oncollect(Player &p, MapGenerator &map);
    void Destroy();
    Coord get_pos();
};

class Healer : public Collectibles{
private:
    std::string icon = Hp;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void OnCollect(Player& p, MapGenerator& map);
};

class Capsule : public Collectibles{
private:
    std::string icon = BombNum;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void OnCollect(Player& p, MapGenerator& map);
};

class ShieldCap : public Collectibles{
private:
    std::string icon = Shield;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void OnCollect(Player& p, MapGenerator& map);
};

class Potion : public Collectibles{
private:
    std::string icon = BombRange;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void OnCollect(Player& p, MapGenerator& map);
};

class Goddess : public Collectibles{
private:
    std::string icon = Invencible;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    virtual void OnCollect(Player& p, MapGenerator& map);
};

Collectibles* Get_Collectibles();