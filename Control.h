#ifdef Control
#endif
#ifndef Control
#define Control
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define SET_BOMB 'f'
class Coord {
public:
    int x = 0, y = 0;
    Coord(int _x, int _y) : x(_x), y(_y){};
    
    bool operator!=(const Coord& rhs) const {
        return (this->x != rhs.x) || (this->y != rhs.y);
    }

    bool operator==(const Coord& rhs) const {
        return (this->x == rhs.x) && (this->y == rhs.y);
    }
};

// 自定义哈希函数
struct CoordHash {
    std::size_t operator()(const Coord& key) const {
        return std::hash<int>()(key.x) ^ std::hash<int>()(key.y);
    }
};

// 自定义相等性比较函数
struct CoordEqual {
    bool operator()(const Coord& lhs, const Coord& rhs) const {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }
};


#endif