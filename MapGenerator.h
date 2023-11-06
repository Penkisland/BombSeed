#pragma once
#include "Macros.h"
#include "Control.h"
#include <iostream>

class Player;

class MapGenerator {
private:
	int width = 0, height = 0;
	std::string** map = nullptr;
	std::string start_point = "";
public:
	std::string** get_map() const;
	std::string get_start_point() const;
	void set_map(std::string** in_map);
	void set_element(std::string obj, Coord pos);
	std::string get_element(Coord pos);
	int get_width() const;
	int get_height() const;
	void generate();
	void display() const;
	MapGenerator(int _width, int _height);
	void Init(Player& p);
};