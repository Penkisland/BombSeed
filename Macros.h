#ifdef Macros
#endif // Macros
#ifndef Macros
#include <string>
#define Macros
//All the emojis and a class to fetch what to spawn on the map
#define HoneyBrick "🍯"
#define BottleBrick "🏺"
#define SunFlowerBrick "🌻"
#define RedBrick "🟥"
#define GreenBrick "🟩"
#define BlueBrick "🟦"
#define BlackBrick "⬛"
#define ObstacleBrick "🧱"
#define BombedBrick "💥"
#define NullBlrick "◻ "
//players
#define Character1 "🦸"
#define Character2 "🦹"
#define Character3 "🧝️"
#define Character4 "🧛"
#define CharacterInvencible "👼" // 角色无敌状态
#define CharacterShield "👒" // 角色护盾状态
//Items
#define Hp "💖"
//#define Speed " "
#define Bomb "💣"
#define BombNum "💊"
#define Shield "🔰"
#define BombRange "🧪"
#define Invencible "🗽"

class Objects {
private:
public:
	static std::string get_object(int ind) {
		switch (ind)
		{
			case 0:
				return HoneyBrick;
			case 1:
				return BottleBrick;
			case 2:
				return SunFlowerBrick;
			case 3:
				return RedBrick;
			case 4:
				return GreenBrick;
			case 5:
				return BlueBrick;
			case 6:
				return BlackBrick;
			case 7:
				return ObstacleBrick;
			case 8:
				return BombedBrick;
			case 9:
				return NullBlrick;
			default:
				return "";
		}
	}
};
#endif // !Macros

