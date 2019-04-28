#pragma once
#ifndef OBJECTS_H
#define OBJECTS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows.h"
#include<string>
#include"characters.h"
class Object: public Character
{
private:
	char id = 'o';
public:
	Object(int _x = 150, int _y = 150) :Character(_x,_y) {
		std::cout << "Tworze object";
	}
	~Object() { std::cout << "Usuwam object"; }
	void move(Game& game, int i) override {};
	char& getId() override { return id; }
	
};




#endif // !OBJECTS_H
