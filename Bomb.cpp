#include "Bomb.h"
#include "Player.h"
#include "UIManager.h"

void Bombs::DestroyBlocks(std::string **map, int _range, Coord _pos, Player &p)
{
    if (range == 0 || (map[_pos.x][_pos.y] != ObstacleBrick && map[_pos.x][_pos.y] != Bomb) || p.get_pos() == _pos)
    {
        return;
    }
    else if (p.get_pos() == _pos)
    {
        p.CountDownOverTime();
    }
    else
    {
        int probability = rand() % 10;
        if (probability >= 5)
        {
            Get_Collectibles()->Spawn(_pos, map);
        }
        else
        {
            map[_pos.x][_pos.y] = BombedBrick;
        }
    }
    // Recursive method of detecting blocks to explode, NOW DONT WORK, TODO
    if (_pos.y > 0)
    {
        DestroyBlocks(map, _range - 1, Coord(_pos.x, _pos.y - 1), p);
    }
    if (_pos.y < 14)
    {
        DestroyBlocks(map, _range - 1, Coord(_pos.x, _pos.y + 1), p);
    }
    if (_pos.x > 0)
    {
        DestroyBlocks(map, _range - 1, Coord(_pos.x - 1, _pos.y), p);
    }
    if (_pos.x < 14)
    {
        DestroyBlocks(map, _range - 1, Coord(_pos.x + 1, _pos.y), p);
    }
}
void Bombs::OnBomb(MapGenerator map, Player &p)
{
    std::string **tmp_map = map.get_map();
    DestroyBlocks(tmp_map, this->range, this->pos, p);
    map.set_map(tmp_map);
}
Bombs::Bombs(Coord _pos, int _range) : pos(_pos), range(_range){};

Coord Bombs::GetPos()
{
    return this->pos;
}

void Bombs::CountDown(MapGenerator map, Player &p)
{
    // Use to count down and decide when the bomb should explode
    this->count_down -= 1;
    if (this->count_down <= 0)
    {
        this->OnBomb(map, p);
        UIManager::bomb_count -= 1;
        UIManager::bomb_list.pop_back();
    }
}
