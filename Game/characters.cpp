#include "characters.h"
#include"game.h"
#define STEP 10
#define JUMP 20
//const float step = 10;

void Hero::move(Game& game)
{
	//std::cout << "qqqqqqqqqqq";
	bool pressed = 0;
	Sleep(10);
	static bool saved = 0;
	static std::vector<float> primal_coordinates;
	if (saved == 0)
	{
		
		for (int i = 0; i < game.getCharacters().size(); i++)
			if (game.getCharacters()[i]->getId() != 'h')
				primal_coordinates.push_back(game.getCharacters()[i]->getX_coordinate());
		saved = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pressed = 1;
		if (getDirection() == 0)
		{
			if (getX_coordinate() > 5 * STEP && objectCollission(game)==1)
				changeX_coordinate(-STEP);
			/*bool isabove = 0;
			float temp;

			for (int i = 0; i < game.getCharacters().size(); i++)
			{
				if (game.getCharacters()[i]->getId() != 'h')
				{
					if (aboveObject(game.getCharacters()[i]) == true)
					{
						isabove = 1;
						temp = game.getCharacters()[i]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;

					}
				}
			}
			if (isabove == true)
				this->setY_coordinate(temp);*/
			if (isabove(game))
				std::cout<<"";
			else
			{
				while (this->getY_coordinate() < game.getWindow().getSize().y - 200)
				{
					this->changeY_coordinate(STEP);
					/*bool isabove = 0;
					float temp;

					for (int i = 0; i < game.getCharacters().size(); i++)
					{
						if (game.getCharacters()[i]->getId() != 'h')
						{
							if (aboveObject(game.getCharacters()[i]) == true)
							{
								isabove = 1;
								temp = game.getCharacters()[i]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;

							}
						}
					}
					if (isabove == true)
						this->setY_coordinate(temp);*/
					isabove(game);
				}
			}
			for (int i = 0, j = 0; i < game.getCharacters().size(); i++)
			{
				if (game.getCharacters()[i]->getId() != 'h')
				{
					if(game.getCharacters()[i]->getX_coordinate() != primal_coordinates[j] && objectCollission(game)==1)
						game.getCharacters()[i]->changeX_coordinate(STEP);
					j++;
				}
			}
			if (getRect().left <= 300)
				getRect().left = 316;
			else if (getRect().left >= 300 && getRect().left <= 350)
				getRect().left += 45;
			else if (getRect().left >= 350 && getRect().left <= 500)
				getRect().left += 48;
			if (getRect().left >= 500)
			{
				getRect().left = 316;
				Sleep(5);
			}
			Sleep(20);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setUp(1);
				for (int i = 0; i < 2; i++)
				{
					changeY_coordinate(-2 * JUMP);
					changeX_coordinate(-2 * JUMP);
					setImagePosition();
					getRect().left = 60;
					getRect().top = 320;
					this->setImage("images/player.png", getRect());
					game.Show();
					Sleep(5);
				}
				Sleep(100);
				for (int i = 0; i < 2; i++)
				{
					/*if(i<1)
						changeY_coordinate(2 * JUMP);
					else if (i == 1 && isabove == 0)
						changeY_coordinate(2 * JUMP);
					else
						this->setY_coordinate(temp);
					changeX_coordinate(-2 * JUMP);*/
					changeX_coordinate(-2 * JUMP);
					bool isabove = 0;
					float temp;
					for (int j = 0; j < game.getCharacters().size(); j++)
					{
						if (game.getCharacters()[j]->getId() != 'h')
						{
							if (aboveObject(game.getCharacters()[j]) == true)
							{
								isabove = 1;
								temp = game.getCharacters()[j]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;
								
							}
						}
					}
					if(i<1)
						changeY_coordinate(2 * JUMP);
					if (i == 1 && isabove == 0)
						changeY_coordinate(2 * JUMP);
					else if(i==1 && isabove==1)
						this->setY_coordinate(temp);
					setImagePosition();
					getRect().left = 20;
					getRect().top = 110;
					this->setImage("images/player.png", getRect());
				}
				game.Show();
			}
		}
		else
		{
			setDirection(0);
			getImage().setScale({ -1, 1 });
			changeX_coordinate(STEP);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pressed = 1;
		//std::cout << "wall left" << game.getCharacters()[1]->getX_coordinate() << std::endl;
		//std::cout << "wall right" << game.getCharacters()[1]->getX_coordinate()+ game.getCharacters()[1]->getImage().getGlobalBounds().width<< std::endl;
		if (getDirection() == 1)
		{
			//std::cout << this->getX_coordinate() << std::endl;
			if (this->getX_coordinate() <= game.getWindow().getSize().x / 2 && objectCollission(game) == 1)
				changeX_coordinate(STEP);
			else
			{
				/*bool isabove = 0;
				float temp;

				for (int i = 0; i < game.getCharacters().size(); i++)
				{
					if (game.getCharacters()[i]->getId() != 'h')
					{
						if (aboveObject(game.getCharacters()[i]) == true)
						{
							isabove = 1;
							temp = game.getCharacters()[i]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;
							
						}
					}
				}
				if(isabove==true)
					this->setY_coordinate(temp);*/
				if (isabove(game))
					std::cout << "";
				else
				{
					while (this->getY_coordinate() < game.getWindow().getSize().y - 200)
					{
						this->changeY_coordinate(STEP);
						/*bool isabove = 0;
						float temp;

						for (int i = 0; i < game.getCharacters().size(); i++)
						{
							if (game.getCharacters()[i]->getId() != 'h')
							{
								if (aboveObject(game.getCharacters()[i]) == true)
								{
									isabove = 1;
									temp = game.getCharacters()[i]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;
								
								}
							}
						}
						if (isabove == true)
							this->setY_coordinate(temp);*/
						if (isabove(game))
							std::cout << "";
					}
				}

				setImagePosition();
				for (int i = 0; i < game.getCharacters().size(); i++)
				{
					if (game.getCharacters()[i]->getId()!='h')
					{
						if (objectCollission(game) == 1)
							game.getCharacters()[i]->changeX_coordinate(-STEP);
						game.Show();
					}
				}
						
			}

			if (getRect().left <= 300)
				getRect().left = 316;
			else if (getRect().left >= 300 && getRect().left <= 350)
				getRect().left += 45;
			else if (getRect().left >= 350 && getRect().left <= 500)
				getRect().left += 48;
			if (getRect().left >= 500)
			{
				getRect().left = 316;
				Sleep(5);
			}
			Sleep(20);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setUp(1);
				if (this->getX_coordinate() <= game.getWindow().getSize().x / 2 && objectCollission(game) == 1)
				{
					for (int i = 0; i < 2; i++)
					{
						changeY_coordinate(-2 * JUMP);
						if (this->getX_coordinate() < game.getWindow().getSize().x / 2)
							changeX_coordinate(2 * JUMP);
						setImagePosition();
						getRect().left = 60;
						getRect().top = 320;
						this->setImage("images/player.png", getRect());
						game.Show();
						Sleep(5);
					}
					Sleep(100);
					for (int i = 0; i < 2; i++)
					{
						bool isabove = 0;
						float temp;
						for (int j = 0; j < game.getCharacters().size(); j++)
						{
							if (game.getCharacters()[j]->getId() != 'h')
							{
								if (aboveObject(game.getCharacters()[j]) == true)
								{
									isabove = 1;
									temp = game.getCharacters()[j]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;

								}
							}
						}
						if (i < 1)
							changeY_coordinate(2 * JUMP);
						if (i == 1 && isabove == 0)
							changeY_coordinate(2 * JUMP);
						else if (i == 1 && isabove == 1)
							this->setY_coordinate(temp);
						if (this->getX_coordinate() < game.getWindow().getSize().x / 2)
							changeX_coordinate(2 * JUMP);
						setImagePosition();
						getRect().left = 20;
						getRect().top = 110;
						this->setImage("images/player.png", getRect());
					}
				}
				else
				{
					for (int j = 0; j < 2; j++)
					{
						changeY_coordinate(-2 * JUMP);
						setImagePosition();
						getRect().left = 60;
						getRect().top = 320;
						this->setImage("images/player.png", getRect());
						game.Show();
					}
					for (int j = 0; j < 2; j++)
					{
						for (int i = 0; i < game.getCharacters().size(); i++)
						{
							if (game.getCharacters()[i]->getId() != 'h')
							{
								game.getCharacters()[i]->changeX_coordinate(-2*JUMP);
								game.getCharacters()[i]->setImagePosition();
								game.Show();
							}
						}
					}
							

						//Sleep(5);
					
						
					game.Show();
					Sleep(100);
						
					for (int j = 0; j < 2; j++)
					{
		
						for (int i = 0; i < game.getCharacters().size(); i++)
						{
							if (game.getCharacters()[i]->getId() != 'h')
							{
								game.getCharacters()[i]->changeX_coordinate(-2*JUMP);
								game.getCharacters()[i]->setImagePosition();
								game.Show();
							}
						}
					}
					bool isabove = 0;
					float temp;
					for (int i = 0; i < game.getCharacters().size(); i++)
					{
						if (game.getCharacters()[i]->getId() != 'h')
						{
							if (aboveObject(game.getCharacters()[i])==true)
							{
								isabove = 1;
								temp = game.getCharacters()[i]->getImage().getGlobalBounds().top-this->getImage().getLocalBounds().height;
								
							}
						}
					}
					for (int j = 0; j < 2; j++)
					{
						if (j < 1)
							changeY_coordinate(2 * JUMP);
						else if (j == 1 && isabove == 0)
							changeY_coordinate(2 * JUMP);
						else
							this->setY_coordinate(temp);
						/*if(isabove==1)
							this->setY_coordinate(temp);
						else
							changeY_coordinate(2 * JUMP);*/
						setImagePosition();
						getRect().left = 20;
						getRect().top = 110;
						this->setImage("images/player.png", getRect());
						game.Show();
					}

				}
				/*for (int i = 0; i < 2; i++)
				{
					changeY_coordinate(-2 * JUMP);
					if (this->getX_coordinate() < game.getWindow().getSize().x / 2)
						changeX_coordinate(2 * JUMP);
					setImagePosition();
					getRect().left = 60;
					getRect().top = 320;
					this->setImage("images/player.png", getRect());
					game.Show();
					Sleep(5);
				}
				Sleep(100);
				for (int i = 0; i < 2; i++)
				{
					changeY_coordinate(2 * JUMP);
					if (this->getX_coordinate() < game.getWindow().getSize().x / 2)
						changeX_coordinate(2 * JUMP);
					setImagePosition();
					getRect().left = 20;
					getRect().top = 110;
					this->setImage("images/player.png", getRect());
				}*/
				game.Show();
			}
		}
		else
		{
			setDirection(1);
			getImage().setScale({ 1, 1 });
			changeX_coordinate(-STEP);
		}

	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		//changeY_coordinate(STEP);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getUp()==0)
	{
		pressed = 1;
		for (int i = 0; i < 2; i++)
		{
			changeY_coordinate(-2 * JUMP);
			setImagePosition();
			getRect().left = 60;
			getRect().top = 320;
			this->setImage("images/player.png", getRect());
			game.Show();
			Sleep(5);
		}
		/*changeY_coordinate(-STEP);
		setImagePosition();
		getRect().left = 115;
		getRect().top = 290;
		this->setImage("images/player.png", getRect());
		game.Show();*/
		Sleep(100);
		for (int i = 0; i < 2; i++)
		{
			changeY_coordinate(2 * JUMP);
			setImagePosition();
			getRect().left = 20;
			getRect().top = 110;
			this->setImage("images/player.png", getRect());
		}
		game.Show();


	}
	/*else */
	if (pressed==0)
		setRect(20, getRect().top, getRect().width, getRect().height);
	this->setImage("images/player.png", getRect());
	setUp(0);
}
void Character::setImage(const std::string& filename, const sf::IntRect rect)
{
	//std::cout << "aaaa";
	texture.loadFromFile(filename);
	image.setTexture(texture);
	image.setTextureRect(rect);
}
void Character::setImage(const std::string& filename)
{
	//std::cout << "aaaa";
	texture.loadFromFile(filename);
	image.setTexture(texture);
	image.setTextureRect(rect);
}
void Character::setRect(int _left, int _top, int _width, int _height)
{
	rect.left = _left;
	rect.top = _top;
	rect.width = _width;
	rect.height = _height;

}
bool Hero::objectCollission(Game& game)
{
	bool go = 1;
	for (int i = 0; i < game.getCharacters().size(); i++)
	{
		if (game.getCharacters()[i]->getId() != 'h' && game.getCharacters()[i]->getImage().getGlobalBounds().intersects(this->getImage().getGlobalBounds()))
		{
			go = 0;
			break;
		}
	}
	return go;
}
bool Hero::aboveObject(std::shared_ptr<Character>& _character)
{
	if (this->getX_coordinate() >= _character->getX_coordinate() && this->getX_coordinate() <= _character->getImage().getGlobalBounds().width + _character->getX_coordinate()&&this->getY_coordinate()<_character->getY_coordinate())
		return true;
	else return false;
}	
bool Hero::isabove(Game& _game)
{
	bool above = 0;
	float temp;

	for (int i = 0; i < _game.getCharacters().size(); i++)
	{
		if (_game.getCharacters()[i]->getId() != 'h')
		{
			if (aboveObject(_game.getCharacters()[i]) == true)
			{
				above = 1;
				temp = _game.getCharacters()[i]->getImage().getGlobalBounds().top - this->getImage().getLocalBounds().height;

			}
		}
	}
	if (above == true)
		this->setY_coordinate(temp);
	return above;
}