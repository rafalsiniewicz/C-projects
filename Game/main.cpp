#include"characters.h"
#include"game.h"
#include"objects.h"
#include <cstdlib>
#include <ctime>
int main()
{
	Game game;
	game.setWindow(1200, 800);
	std::shared_ptr<Character> hero;
	hero = std::make_shared<Hero>(0,game.getWindow().getSize().y-200);
	std:: cout << hero.get() << std::endl;
	hero->setRect(20, 110, 49, 90);
	hero->setImage("images/player.png",0);
	game.pushCharacter(hero);
	std::shared_ptr<Character> object;
	object = std::make_shared<Object>(100, game.getWindow().getSize().y - 300);
	object->setRect(0, 0, 200, 40);
	object->setImage("images/wall.png",0);
	game.pushCharacter(object);
	/*-----------------*/
	srand(time(NULL));
	for (int i = 0,j=400; i < 100; i++,j+=450)
	{
		object->setRect(0, 0, 200, 40);
		object->putX_coordinate(j);
		object->putY_coordinate(game.getWindow().getSize().y - 150 - (std::rand() % 200) + 0);
		object->setImage("images/wall.png",i);
	}
	//game.pushCharacter(hero);
	//game.popCharacter(game.getCharacters()[0]);
	//hero->move();
	//hero->setImagePosition();
	//game.popCharacter(hero);
	while (game.getWindow().isOpen())
	{
		sf::Event event;
		while (game.getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game.getWindow().close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					game.getWindow().create(game.getVideoMode().getFullscreenModes()[0], "adventure game");


		} //while
		//game.getWindow().clear();
		game.Play();
		//game.getWindow().draw(hero.getImage());
		//game.getWindow().display();
		game.Show();
	} //while
	game.popCharacter(hero);
	system("pause");
	return 0;
}