#ifndef GAME_H_
#define GAME_H_
#pragma once
#include<vector>
#include <algorithm> 
#include <memory>
#include"characters.h"
#include"objects.h"
class Game {
private:
	std::vector<std::shared_ptr<Character>> characters;
	sf::RenderWindow window;
	sf::VideoMode vid;
public:
	void setWindow(int x, int y);
	sf::RenderWindow& getWindow() { return window; }
	Game() {};
	void Show();
	void pushCharacter(std::shared_ptr<Character>& _character);
	void popCharacter(std::shared_ptr<Character>& _character);
	void Play();
	std::vector<std::shared_ptr<Character>>& getCharacters() { return characters; }
	sf::VideoMode& getVideoMode() { return vid; }
};
#endif