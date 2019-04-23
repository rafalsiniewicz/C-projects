#pragma once
#ifndef CHARACTERS_H_
#define CHARACTERS_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows.h"
#include<string>
class Game;
class Character
{
private:
	float x_coordinate;
	float y_coordinate;
	unsigned int health;
	sf::Texture texture;
	sf::Sprite image;
	sf::IntRect rect;
	char id;
public:
	Character(int _x=150, int _y=150, int _health=100) :x_coordinate(_x), 
		y_coordinate(_y), health(_health) {
		std::cout << "Tworze character";
	}
	~Character() { std::cout << "Usuwam character"; }
	virtual void move(Game& game)=0;
	int getX_coordinate()const { return x_coordinate; }
	int getY_coordinate()const { return y_coordinate; }
	void changeX_coordinate(float change) { x_coordinate+=change; }
	void changeY_coordinate(float change) { y_coordinate+=change; }
	void setX_coordinate(float _x) { x_coordinate = _x; }
	void setY_coordinate(float _y) { y_coordinate = _y; }
	unsigned int getHealth()const { return health; }
	void setImage(const std::string& filename, const sf::IntRect rect);
	void setImage(const std::string& filename);
	sf::Sprite& getImage() { return image; }
	void setImagePosition(){ image.setPosition(x_coordinate, y_coordinate); }
	void setRect(int left, int top, int width, int height);
	sf::IntRect& getRect() { return rect; }
	virtual char& getId() { return id; }
};
class Hero: public Character
{
private:
	bool direction = 1; //1-right, 0 -left
	bool up = 0; //0-ground, 1-up
	char id = 'h';
	
public:
	Hero() :Character() { std::cout << "Tworze hero"; }
	Hero(int _x = 150, int _y = 150, int _health = 100) :Character(_x, _y, _health) { std::cout << "Tworze hero"; }
	~Hero() { std::cout << "Usuwam hero"; }
	void move(Game& game)override;
	void setDirection(bool _direction) { direction = _direction; }
	bool getDirection() { return direction; }
	void setUp(bool _up) { up = _up; }
	bool getUp() { return up; }
	char& getId() override{ return id; }
	bool objectCollission(Game& game);
	bool aboveObject(std::shared_ptr<Character>& _character);
	bool isabove(Game& _game);

};
#endif // !CHARACTERS_H_