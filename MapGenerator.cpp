#include "MapGenerator.h"
#include "Player.h"

std::string **MapGenerator::get_map() const
{
    return this->map;
}
std::string MapGenerator::get_start_point() const
{
    return this->start_point;
}
void MapGenerator::set_map(std::string **in_map)
{
    this->map = in_map;
}
void MapGenerator::set_element(std::string obj, Coord pos)
{
    this->map[pos.x][pos.y] = obj;
}
std::string MapGenerator::get_element(Coord pos)
{
    return this->map[pos.x][pos.y];
}
int MapGenerator::get_width() const
{
    return this->width;
}
int MapGenerator::get_height() const
{
    return this->height;
}
void MapGenerator::generate()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = Macros::Objects::get_object(rand() % 10);
        }
    }
}
void MapGenerator::display() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << map[i][j];
            if ((j + 1) % width == 0)
            {
                std::cout << std::endl;
            }
        }
    }
}
MapGenerator::MapGenerator(int _width, int _height) : width(_width), height(_height)
{
    map = new std::string *[_height] {};
    for (int i = 0; i < _height; i++)
    {
        map[i] = new std::string[_width]{};
    }
}

void MapGenerator::Init(Player &p)
{
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (this->map[i][j] == NullBlrick)
            {
                this->start_point = map[i][j];
                p.set_on_what(this->start_point);
                this->map[i][j] = p.get_state();
                p.SetPlayer(i, j);
                return;
            }
        }
    }
}