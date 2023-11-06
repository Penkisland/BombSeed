#pragma once
#include <string>

class Player;//forward decleration instead of using headers, but only ptr usable
#include "Control.h"
#include "Macros.h"

class Collectibles{
private:
    std::string icon = "";
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void Destroy();
};

class Healer : public Collectibles{
private:
    std::string icon = Hp;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void OnCollect(Player* p);
};

class Capsule : public Collectibles{
private:
    std::string icon = BombNum;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void OnCollect(Player& p);
};

class ShieldCap : public Collectibles{
private:
    std::string icon = Shield;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void OnCollect(Player& p);
};

class Potion : public Collectibles{
private:
    std::string icon = BombRange;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void OnCollect(Player& p);
};

class Goddess : public Collectibles{
private:
    std::string icon = Invencible;
public:
    virtual void Spawn(Coord _pos, std::string** map);
    void OnCollect(Player& p);
};

Collectibles* Get_Collectibles();