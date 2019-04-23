#include"characters.h"
#include"game.h"
#include"objects.h"
#include<cmath>
int main()
{
	Game game;
	game.setWindow(1200, 800);
	std::shared_ptr<Character> hero;
	hero = std::make_shared<Hero>(0,game.getWindow().getSize().y-200);
	std:: cout << hero.get() << std::endl;
	hero->setRect(20, 110, 49, 90);
	hero->setImage("images/player.png");
	game.pushCharacter(hero);
	std::shared_ptr<Character> object;
	object = std::make_shared<Object>(1000, game.getWindow().getSize().y - 150);
	object->setRect(0, 0, 200, 40);
	object->setImage("images/wall.png");
	game.pushCharacter(object);
	/*-----------------*/
	std::shared_ptr<Character>	tab[100];
	for (int i = 0,j=10; i < 100; i++,j+=50)
	{
		tab[i] = std::make_shared<Object>(1200+10*j, game.getWindow().getSize().y - 150+ 50*sin(j));
		tab[i]->setRect(0, 0, 200, 40);
		tab[i]->setImage("images/wall.png");
		game.pushCharacter(tab[i]);
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