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
	std::vector<float> x_coordinate;
	std::vector<float> y_coordinate;
	std::vector<unsigned int> health;
	std::vector<sf::Texture> texture;
	std::vector<sf::Sprite> image;
	std::vector<sf::IntRect> rect;
	char id;
	
public:
	Character(int _x = 150, int _y = 150, int _health = 100) {
		x_coordinate.push_back(_x);
		y_coordinate.push_back(_y);
		health.push_back(_health);
		std::cout << "Tworze character";
	}
	~Character() { std::cout << "Usuwam character"; }
	virtual void move(Game& game, int i) = 0;
	std::vector<float>& getX_coordinate() { return x_coordinate; }
	std::vector<float>& getY_coordinate() { return y_coordinate; }
	void changeX_coordinate(float change, int i) { x_coordinate[i] += change; }
	void changeY_coordinate(float change, int i) { y_coordinate[i] += change; }
	void putX_coordinate(float _x) { x_coordinate.push_back(_x); }
	void putY_coordinate(float _y) { y_coordinate.push_back(_y); }
	void setX_coordinate(float _x, int i) { x_coordinate[i] = _x; }
	void setY_coordinate(float _y, int i) { y_coordinate[i] = _y; }
	std::vector<unsigned int>& getHealth() { return health; }
	void setImage(const std::string& filename, const sf::IntRect rect, int i);
	void setImage(const std::string& filename, int i);
	std::vector<sf::Sprite>& getImage() { return image; }
	void setImagePosition(int i) { image[i].setPosition(x_coordinate[i], y_coordinate[i]); }
	void setRect(int left, int top, int width, int height);
	std::vector<sf::IntRect>& getRect() { return rect; }
	virtual char& getId() { return id; }
};
class Hero : public Character
{
private:
	bool direction = 1; //1-right, 0 -left
	bool up = 0; //0-ground, 1-up
	char id = 'h';

public:
	Hero() :Character() { std::cout << "Tworze hero"; }
	Hero(int _x = 150, int _y = 150, int _health = 100) :Character(_x, _y, _health) { std::cout << "Tworze hero"; }
	~Hero() { std::cout << "Usuwam hero"; }
	void move(Game& game, int i)override;
	void setDirection(bool _direction) { direction = _direction; }
	bool getDirection() { return direction; }
	void setUp(bool _up) { up = _up; }
	bool getUp() { return up; }
	char& getId() override { return id; }
	bool objectCollission(Game& game, int i);
	bool aboveObject(std::shared_ptr<Character>& _character, int i);
	bool isabove(Game& _game, int i);
	bool anyCollission(Game& game);
	bool isAboveAny(Game& _game);

};
#endif // !CHARACTERS_H_