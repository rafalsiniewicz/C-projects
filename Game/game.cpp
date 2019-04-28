#include"game.h"

void Game::setWindow(int x, int y)
{
	window.create(vid.getFullscreenModes()[0], "adventure game", sf::Style::Fullscreen);
}
void Game::Show()
{
	window.clear();
	for (int i = 0; i < characters.size(); i++)
		for(int j =0 ; j < characters[i]->getX_coordinate().size();j++)
			window.draw(characters[i]->getImage()[j]);
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
		for (int j = 0; j < characters[i]->getX_coordinate().size(); j++)
		{
			//std::cout << characters[i]->getImage().size() << std::endl;
			characters[i]->move(*this,j);
			characters[i]->setImagePosition(j);
		}
	}
}