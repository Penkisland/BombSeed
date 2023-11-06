#ifdef Control
#endif
#ifndef Control
#define Control
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define SET_BOMB 'f'
class Coord
{
public:
    int x = 0, y = 0;
    Coord(int _x, int _y) : x(_x), y(_y){};

    bool operator!=(Coord rhs)
    {
        if (this->x == rhs.x && this->y == rhs.y)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool operator==(Coord rhs)
    {
        if (this->x == rhs.x && this->y == rhs.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif