#include "MapGenerator.h"
#include "Player.h"
#include "Bomb.h"
#include "Macros.h"
#include "Collectibles.h"
#include "UIManager.h"
#include <conio.h>
#include <iostream>
#include <ctime>

int main()
{
	system("chcp 65001 && cls");
	std::srand(unsigned(std::time(NULL)));
	MapGenerator Map(15, 15);
	Map.generate();
	Player player = Player(1);
	Map.Init(player);
	Map.display();

	while(true){
		char cmd = _getch();
		player.Move(cmd, Map);
		system("cls");
		player.CountDownOverTime();
		if(UIManager::bomb_count > 0){
			for(auto& item : UIManager::bomb_list){
				item.CountDown(Map, player);
			}
		}
		Map.display();
	}
	
	system("pause");
	return 0;
}