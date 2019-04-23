#include"game.h"

void Game::setWindow(int x, int y)
{
	window.create(vid.getFullscreenModes()[0], "adventure game", sf::Style::Fullscreen);
}
void Game::Show()
{
	window.clear();
	for (int i = 0; i < characters.size(); i++)
		window.draw(characters[i]->getImage());
	window.display();

}
void Game::pushCharacter(std::shared_ptr<Character>& _character)
{
	characters.push_back(_character);
	std::cout << _character.get() << std::endl;
	//std::cout << "aaaa";
}
void Game::popCharacter(std::shared_ptr<Character>& _character)
{
	std::cout << _character.get() << std::endl;
	auto it = std::find(characters.begin(), characters.end(), _character);
	characters.erase(it);
	//std::cout << "aaaaaaa";
	//_character.reset();
	//_character.reset(nullptr);
}

void Game::Play()
{
	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->move(*this);
		characters[i]->setImagePosition();
	}
}