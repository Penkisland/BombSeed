#include "Player.h"
#include "Control.h"
#include "UIManager.h"

int Player::get_hp()
{
    return this->health;
}

int Player::get_bomb()
{
    return this->bomb_count;
}

// state machine determines what style of the character should be right now
std::string Player::get_state()
{
    return this->state;
}

// state checks
bool Player::get_protect_state()
{
    return this->is_under_protect;
}
bool Player::get_invecible_state()
{
    return this->is_invencible;
}

// to get the previous block where the player stands
void Player::set_on_what(std::string obj)
{
    this->on_what = obj;
}

Coord Player::get_pos()
{
    return this->pos;
}

// converts the state of the character
void Player::StateConvert()
{
    if (this->invicible_time == 0)
    {
        this->state = this->idle;
    }
    if (this->shield_time == 0)
    {
        this->state = this->idle;
    }
    if (this->invencible_time == 0)
    {
        this->state = this->idle;
    }
}

// about the timer of the player
void Player::CountDown(int item)
{
    item -= 1;
}

// player behaviours
void Player::Heal()
{
    this->health += 1;
}
void Player::MaxHealthUp()
{
    this->max_health += 1;
}
void Player::BombRestore()
{
    if (bomb_count < bomb_max)
    {
        this->bomb_count += 1;
    }
}
void Player::MaxBombUp()
{
    this->bomb_max += 1;
    BombRestore();
}

void Player::PlaceBomb(MapGenerator map)
{
    Bombs bomb = Bombs(this->pos, this->bomb_range);
    map.set_element(Bomb, bomb.GetPos());
    this->bomb_count -= 1;
    UIManager::bomb_count += 1;
    UIManager::bomb_list.push_back(bomb);
    this->on_what = Bomb;
    if (Move(UP, map) || Move(DOWN, map) || Move(LEFT, map) || Move(RIGHT, map))
    {
        return;
    }
    /*
        自动移动会失灵，需要在实现算法时添加是否能够自动移动的条件判断
    */
}

// using the return val to decide if the auto move after placing a bombs is valid
bool Player::Move(int key, MapGenerator map)
{
    Coord prev_coord = this->pos;
    switch (key)
    {
    case UP:
        if (pos.x > 0)
        {
            if (map.get_element(Coord(pos.x - 1, pos.y)) == NullBlrick || map.get_element(Coord(pos.x - 1, pos.y)) == BombedBrick)
            {
                this->pos.x -= 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = map.get_element(this->pos);
                map.set_element(this->state, this->pos);
            }
            else if (UIManager::collectible_list.count(Coord(pos.x - 1, pos.y)) > 0)
            {
                this->pos.x -= 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = NullBlrick;
                map.set_element(this->state, this->pos);
            }
        }
        return false;
    case DOWN:
        if (pos.x < map.get_height() - 1)
        {
            if (map.get_element(Coord(pos.x + 1, pos.y)) == NullBlrick || map.get_element(Coord(pos.x + 1, pos.y)) == BombedBrick)
            {
                this->pos.x += 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = map.get_element(this->pos);
                map.set_element(this->state, this->pos);
            }
            else if (UIManager::collectible_list.count(Coord(pos.x + 1, pos.y)) > 0)
            {   
                this->pos.x += 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = NullBlrick;
                map.set_element(this->state, this->pos);
            }
        }
        return false;
    case LEFT:
        if (pos.y > 0)
        {
            if (map.get_element(Coord(pos.x, pos.y - 1)) == NullBlrick || map.get_element(Coord(pos.x, pos.y - 1)) == BombedBrick)
            {
                this->pos.y -= 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = map.get_element(this->pos);
                map.set_element(this->state, this->pos);
            }
            else if (UIManager::collectible_list.count(Coord(pos.x, pos.y - 1)) > 0)
            {
                 this->pos.y -= 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = NullBlrick;
                map.set_element(this->state, this->pos);
            }
        }
        return false;
    case RIGHT:
        if (pos.y < map.get_width() - 1)
        {
            if (map.get_element(Coord(pos.x, pos.y + 1)) == NullBlrick || map.get_element(Coord(pos.x, pos.y + 1)) == BombedBrick)
            {
                this->pos.y += 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = map.get_element(this->pos);
                map.set_element(this->state, this->pos);
            }
            else if (UIManager::collectible_list.count(Coord(pos.x, pos.y + 1)) > 0)
            {
                this->pos.y += 1;
                map.set_element(this->on_what, prev_coord);
                this->on_what = NullBlrick;
                map.set_element(this->state, this->pos);
            }
        }
        return false;
    case SET_BOMB:
        this->PlaceBomb(map);
        return false;
    default:
        return false;
    }
    return true;
}

Player::Player(int playerStyle)
{
    switch (playerStyle)
    {
    case 1:
        this->idle = Character1;
        this->state = Character1;
        break;
    case 2:
        this->idle = Character2;
        this->state = Character2;
        break;
    case 3:
        this->idle = Character3;
        this->state = Character3;
        break;
    case 4:
        this->idle = Character4;
        this->state = Character4;
        break;
    default:
        break;
    }
}

void Player::SetPlayer(int x, int y)
{
    this->pos.x = x;
    this->pos.y = y;
}

void Player::Hurt()
{
    if (!is_under_protect && !is_invencible)
    {
        this->health -= 1;
        this->state = CharacterInvencible;
        CountDown(this->invicible_time);
    }
    else if (is_under_protect && !is_invencible)
    {
        ShieldOff();
        StateConvert();
    }
    if (this->health <= 0)
    {
        Death();
    }
}

void Player::Death()
{
    std::cout << "you lose" << std::endl;
    exit(0);
}

void Player::UnderProtect()
{
    this->state = CharacterShield;
    this->is_under_protect = true;
    CountDown(this->shield_time);
}

void Player::Invence()
{
    this->is_invencible = true;
    this->state = Shield;
    CountDown(this->invencible_time);
}

void Player::InvenceOver()
{
    this->is_invencible = false;
    this->invencible_time = this->invencible_time_max;
}

void Player::ShieldOff()
{
    this->shield_time = this->shield_time_max;
    this->is_under_protect = false;
}

void Player::Recover()
{
    this->invicible_time = this->invisible_max;
}

// main timer
void Player::CountDownOverTime()
{
    if (this->invicible_time < this->invencible_time_max)
    {
        CountDown(this->invicible_time);
    }
    if (this->shield_time < this->shield_time_max)
    {
        CountDown(this->shield_time);
    }
    if (this->invencible_time < this->invencible_time_max)
    {
        CountDown(this->invencible_time);
    }
    StateConvert();
} // use every turn

void Player::RangeUp()
{
    this->bomb_range += 1;
}