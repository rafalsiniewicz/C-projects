#include "characters.h"
#include"game.h"
#define STEP 10
#define JUMP 20
//const float step = 10;

void Hero::move(Game& game, int i)
{
	//std::cout << "qqqqqqqqqqq";
	bool pressed = 0;
	Sleep(10);
	static bool saved = 0;
	static std::vector<float> primal_xcoordinates;
	if (saved == 0)
	{
		
		for (int i = 0; i < game.getCharacters().size(); i++)
			if (game.getCharacters()[i]->getId() != 'h')
				for (int j = 0; j < game.getCharacters()[i]->getX_coordinate().size(); j++)
					primal_xcoordinates.push_back(game.getCharacters()[i]->getX_coordinate()[j]);
		saved = 1;
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pressed = 1;
		if (getDirection() == 0)
		{
			for (int j = 0; j < getX_coordinate().size(); j++)
				if (getX_coordinate()[j] > 5 * STEP && anyCollission(game) == 1)
				{
					for (int i = 0; i < game.getCharacters().size(); i++)
						if (game.getCharacters()[i]->getId() != 'h')
							if (game.getCharacters()[i]->getX_coordinate()[0] == primal_xcoordinates[0] && anyCollission(game) == 1)
							{
								if (isAboveAny(game) == 1)
									std::cout << "";
								changeX_coordinate(-STEP, j);
								//std::cout << "aaa" << std::endl;
							}
				}
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
			for (int j = 0; j < getX_coordinate().size(); j++)
			{
				if (isAboveAny(game) == 1)
					std::cout << "";
				else
				{
		
					while (this->getY_coordinate()[j] < game.getWindow().getSize().y - 200)
					{
						this->changeY_coordinate(STEP, j);
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
						if(isAboveAny(game)==1)
							break;
					}
				}
			}
			for (int i = 0; i < game.getCharacters().size(); i++)
			{
				if (game.getCharacters()[i]->getId() != 'h')
				{
					for (int k = 0; k < game.getCharacters()[i]->getX_coordinate().size(); k++)
					{
						if (game.getCharacters()[i]->getX_coordinate()[k] != primal_xcoordinates[k] && anyCollission(game) == 1)
							game.getCharacters()[i]->changeX_coordinate(STEP,k);
						
					}
					//j++;
				}
			}
			for (int k = 0; k < getX_coordinate().size(); k++)
			{
				if (getRect()[k].left <= 300)
					getRect()[k].left = 316;
				else if (getRect()[k].left >= 300 && getRect()[k].left <= 350)
					getRect()[k].left += 45;
				else if (getRect()[k].left >= 350 && getRect()[k].left <= 500)
					getRect()[k].left += 48;
				if (getRect()[k].left >= 500)
				{
					getRect()[k].left = 316;
					Sleep(5);
				}
			}
			Sleep(20);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setUp(1);
				for (int i = 0; i < 2; i++)
				{
					for (int k = 0; k < getX_coordinate().size(); k++)
					{
						changeY_coordinate(-2 * JUMP,k);
						changeX_coordinate(-2 * JUMP,k);
						setImagePosition(k);
						getRect()[k].left = 60;
						getRect()[k].top = 320;
						this->setImage("images/player.png", getRect()[k],k);
						game.Show();
					}
					Sleep(5);
				}
				Sleep(100);
				
					/*if(i<1)
						changeY_coordinate(2 * JUMP);
					else if (i == 1 && isabove == 0)
						changeY_coordinate(2 * JUMP);
					else
						this->setY_coordinate(temp);
					changeX_coordinate(-2 * JUMP);*/
				for (int k = 0; k < getX_coordinate().size(); k++)
					for(int i = 0; i < 2; i++)
						changeX_coordinate(-2 * JUMP,k);
				std::vector<bool> isabove;
				float temp;
				for (int j = 0; j < game.getCharacters().size(); j++)
				{
					if (game.getCharacters()[j]->getId() != 'h')
					{
						for (int k = 0; k < game.getCharacters()[j]->getX_coordinate().size(); k++)
						{
							if (aboveObject(game.getCharacters()[j],k) == true)
							{
								isabove.push_back(1);
								temp = game.getCharacters()[j]->getImage()[k].getGlobalBounds().top - this->getImage()[0].getLocalBounds().height;

							}
							else
								isabove.push_back(0);
						}
					}
				}
				for (int i = 0; i < 2; i++)
				{
					for (int k = 0; k < getX_coordinate().size(); k++)
					{
						if (i < 1)
							changeY_coordinate(2 * JUMP,k);
						if (i == 1)
						{
							if (std::find(isabove.begin(), isabove.end(), 1) != isabove.end())
								this->setY_coordinate(temp,0);
							else
								changeY_coordinate(2 * JUMP, k);
						}
						setImagePosition(k);
						getRect()[k].left = 20;
						getRect()[k].top = 110;
						this->setImage("images/player.png", getRect()[k],k);
					}
				}
			game.Show();
			}
		}
		else
		{
			setDirection(0);
			for (int k = 0; k < getX_coordinate().size(); k++)
			{
				getImage()[k].setScale({ -1, 1 });
				changeX_coordinate(STEP,k);
			}
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
			for (int k = 0; k < getX_coordinate().size(); k++)
			{
				if (this->getX_coordinate()[k] <= game.getWindow().getSize().x / 2 && anyCollission(game) == 1)
				{
					if (isAboveAny(game) == 1)
						std::cout << "";
					changeX_coordinate(STEP, k);
				
				}
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

					if (isAboveAny(game)==1)
						std::cout << "";
					else
					{
						while (this->getY_coordinate()[k] < game.getWindow().getSize().y - 200)
						{
							this->changeY_coordinate(STEP, k);
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
							if (isAboveAny(game)==1)
								break;
						}
					}

					setImagePosition(k);


					for (int i = 0; i < game.getCharacters().size(); i++)
					{
							
							if (game.getCharacters()[i]->getId() != 'h')
							{
								for (int j = 0; j < game.getCharacters()[i]->getX_coordinate().size(); j++)
								{
									if (anyCollission(game) == 1)
										game.getCharacters()[i]->changeX_coordinate(-STEP, j);
								}
								
										
								game.Show();
							}
						
					}

				}
			}

			for (int k = 0; k < getX_coordinate().size(); k++)
			{
				if (getRect()[k].left <= 300)
					getRect()[k].left = 316;
				else if (getRect()[k].left >= 300 && getRect()[k].left <= 350)
					getRect()[k].left += 45;
				else if (getRect()[k].left >= 350 && getRect()[k].left <= 500)
					getRect()[k].left += 48;
				if (getRect()[k].left >= 500)
				{
					getRect()[k].left = 316;
					Sleep(5);
				}
			}
			Sleep(20);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setUp(1);
				for (int k = 0; k < getX_coordinate().size(); k++)
				{
					if (this->getX_coordinate()[k] <= game.getWindow().getSize().x / 2)
					{
						for (int i = 0; i < 2; i++)
						{
							changeY_coordinate(-2 * JUMP, k);
							changeX_coordinate(2 * JUMP, k);
							if (anyCollission(game) == 0)
								changeX_coordinate(-2 * JUMP, k);
							setImagePosition(k);
							getRect()[k].left = 60;
							getRect()[k].top = 320;
							this->setImage("images/player.png", getRect()[k], k);
							game.Show();
							Sleep(5);
							
						}
						Sleep(100);
						
						std::vector<bool> isabove;
						float temp;
						for (int i = 0; i < 2; i++)
						{
							changeX_coordinate(2 * JUMP, k);
							if (anyCollission(game) == 0)
							{
								std::cout << "aaa" << std::endl;
								changeX_coordinate(-2 * JUMP, k);
							}
						}
							
						for (int i = 0; i < 2; i++)
						{
							if (i < 1)
							{
								//if (anyCollission(game) == 1)
									changeY_coordinate(2 * JUMP, k);
								for (int j = 0; j < game.getCharacters().size(); j++)
								{
									if (game.getCharacters()[j]->getId() != 'h')
									{
										for (int t = 0; t < game.getCharacters()[j]->getX_coordinate().size(); t++)
										{
											if (aboveObject(game.getCharacters()[j], t) == true)
											{
												isabove.push_back(1);
												temp = game.getCharacters()[j]->getImage()[t].getGlobalBounds().top - this->getImage()[0].getLocalBounds().height;
												//std::cout << game.getCharacters()[j]->getImage()[t].getGlobalBounds().top << std::endl;
												//std::cout << getImage()[0].getGlobalBounds().top << std::endl;
												std::cout << temp << std::endl;
											}
											else
												isabove.push_back(0);
										}
									}
								}
								//std::cout << "a" << std::endl;
							}
							if (i == 1)
							{
								if (std::find(isabove.begin(), isabove.end(), 1) != isabove.end())
									this->setY_coordinate(temp,0);
								else 
									if (anyCollission(game) == 1)
										changeY_coordinate(2 * JUMP, k);
							}
							setImagePosition(k);
							getRect()[k].left = 20;
							getRect()[k].top = 110;
							this->setImage("images/player.png", getRect()[k], k);
							
						}
					}

					else
					{
						for (int j = 0; j < 2; j++)
						{
							
								changeY_coordinate(-2 * JUMP, k);
								setImagePosition(k);
								getRect()[k].left = 60;
								getRect()[k].top = 320;
								this->setImage("images/player.png", getRect()[k], k);
								game.Show();
							
						}
						for (int j = 0; j < 2; j++)
						{
							for (int i = 0; i < game.getCharacters().size(); i++)
							{
								if (game.getCharacters()[i]->getId() != 'h')
								{
									for (int t = 0; t < game.getCharacters()[i]->getX_coordinate().size(); t++)
									{
										game.getCharacters()[i]->changeX_coordinate(-2 * JUMP, t);
										if (anyCollission(game) == 0)
										{
											//std::cout << "aaa" << std::endl;
											game.getCharacters()[i]->changeX_coordinate(2 * JUMP, t);
										}
										game.getCharacters()[i]->setImagePosition(t);
										if(t%2 == 0)
											game.Show();
									}
								}
							}
						}


						Sleep(5);


						game.Show();
						//Sleep(100);

						
						for (int j = 0; j < 2; j++)
						{
							for (int i = 0; i < game.getCharacters().size(); i++)
							{
								if (game.getCharacters()[i]->getId() != 'h')
								{
									for (int t = 0; t < game.getCharacters()[i]->getX_coordinate().size(); t++)
									{
										game.getCharacters()[i]->changeX_coordinate(-2 * JUMP, t);
										if (anyCollission(game) == 0)
										{
											//std::cout << "aaa" << std::endl;
											game.getCharacters()[i]->changeX_coordinate(2 * JUMP, t);
										}
										game.getCharacters()[i]->setImagePosition(t);
										
									}
								}
							}
						}
						game.Show();
						std::vector<bool> isabove;
						float temp;

						for (int j = 0; j < 2; j++)
						{
							if (j < 1)
							{
								changeY_coordinate(2 * JUMP, k);
								for (int i = 0; i < game.getCharacters().size(); i++)
								{
									if (game.getCharacters()[i]->getId() != 'h')
									{
										for (int t = 0; t < game.getCharacters()[i]->getX_coordinate().size(); t++)
										{
											if (aboveObject(game.getCharacters()[i], t) == true)
											{
												isabove.push_back(1);
												temp = game.getCharacters()[i]->getImage()[t].getGlobalBounds().top - this->getImage()[0].getLocalBounds().height;

											}
											else
												isabove.push_back(0);
										}

									}
								}
							}
							else if (j == 1)
							{
								if (std::find(isabove.begin(), isabove.end(), 1) != isabove.end())
									this->setY_coordinate(temp,0);
								else
									changeY_coordinate(2 * JUMP, k);
							}
							/*if(isabove==1)
								this->setY_coordinate(temp);
							else
								changeY_coordinate(2 * JUMP);*/
							setImagePosition(k);
							getRect()[k].left = 20;
							getRect()[k].top = 110;
							this->setImage("images/player.png", getRect()[k], k);
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
		}
		else
		{
			for (int k = 0; k < getX_coordinate().size(); k++)
			{
				setDirection(1);
				getImage()[k].setScale({ 1, 1 });
				changeX_coordinate(-STEP, k);
			}
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			//changeY_coordinate(STEP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getUp()==0)
	{
		pressed = 1;
		for (int k = 0; k < getX_coordinate().size(); k++)
		{
			for (int i = 0; i < 2; i++)
			{
				changeY_coordinate(-2 * JUMP, k);
				setImagePosition(k);
				getRect()[k].left = 60;
				getRect()[k].top = 320;
				this->setImage("images/player.png", getRect()[k], k);
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
				changeY_coordinate(2 * JUMP, k);
				setImagePosition(k);
				getRect()[k].left = 20;
				getRect()[k].top = 110;
				this->setImage("images/player.png", getRect()[k],k);
			}
			game.Show();
		}


	}
	/*else */
	if (pressed==0)
		for (int k = 0; k < getX_coordinate().size(); k++)
			setRect(20, getRect()[k].top, getRect()[k].width, getRect()[k].height);
	for (int k = 0; k < getX_coordinate().size(); k++)
		this->setImage("images/player.png", getRect()[k],k);
	setUp(0);
}
void Character::setImage(const std::string& filename, const sf::IntRect rect, int i)
{
	//std::cout << "aaaa";
	texture[i].loadFromFile(filename);
	image[i].setTexture(texture[i]);
	image[i].setTextureRect(rect);
}
void Character::setImage(const std::string& filename, int i)
{
	//std::cout << "aaaa";
	sf::Texture* _texture = new sf::Texture;
	sf::Sprite* _image = new sf::Sprite;
	_texture->loadFromFile(filename);
	_image->setTexture(*_texture);
	_image->setTextureRect(rect[i]);
	texture.push_back(*_texture);
	image.push_back(*_image);
}
void Character::setRect(int _left, int _top, int _width, int _height)
{
	sf::IntRect* _rect = new sf::IntRect(_left,_top,_width,_height);
	rect.push_back(*_rect);

}
bool Hero::objectCollission(Game& game, int k)
{
	bool go = 1;
	for (int i = 0; i < game.getCharacters().size(); i++)
	{
		if (game.getCharacters()[i]->getId() != 'h' && game.getCharacters()[i]->getImage()[k].getGlobalBounds().intersects(this->getImage()[0].getGlobalBounds()))
		{
			go = 0;
			break;
		}
		
	}
	return go;
}
bool Hero::aboveObject(std::shared_ptr<Character>& _character, int i)
{
	if (this->getX_coordinate()[0]+this->getImage()[0].getGlobalBounds().width >= _character->getX_coordinate()[i] && this->getX_coordinate()[0] <= _character->getImage()[i].getGlobalBounds().width + _character->getX_coordinate()[i] && this->getY_coordinate()[0]+this->getImage()[0].getGlobalBounds().height/2 < _character->getY_coordinate()[i])
		return true;
	else return false;
}	
bool Hero::isabove(Game& _game, int k)
{
	bool above = 0;
	float temp;

	for (int i = 0; i < _game.getCharacters().size(); i++)
	{
		if (_game.getCharacters()[i]->getId() != 'h')
		{
			if (aboveObject(_game.getCharacters()[i],k) == true)
			{
				above = 1;
				temp = _game.getCharacters()[i]->getImage()[k].getGlobalBounds().top - this->getImage()[0].getLocalBounds().height;

			}
		}
	}
	if (above == true)
		this->setY_coordinate(temp,0);
	return above;
}
bool Hero::anyCollission(Game& game)
{
	bool go = 1;
	for (int i = 0; i < game.getCharacters().size(); i++)
	{
		if (game.getCharacters()[i]->getId() != 'h')
		{
			for (int k = 0; k < game.getCharacters()[i]->getX_coordinate().size(); k++)
			{
				if (game.getCharacters()[i]->getImage()[k].getGlobalBounds().intersects(this->getImage()[0].getGlobalBounds()))
				{
					go = 0;
					
					break;
				}
			}
		}
	}
	//std::cout << go << std::endl;
	return go;
}
bool Hero::isAboveAny(Game& _game)
{
	bool above = 0;
	float temp;

	for (int i = 0; i < _game.getCharacters().size(); i++)
	{
		if (_game.getCharacters()[i]->getId() != 'h')
		{
			for (int p = 0; p < _game.getCharacters()[i]->getX_coordinate().size(); p++)
			{
				if (aboveObject(_game.getCharacters()[i], p) == true)
				{
					above = 1;
					temp = _game.getCharacters()[i]->getImage()[p].getGlobalBounds().top - this->getImage()[0].getLocalBounds().height;

				}
			}
		}
	}
	if (above == true)
		this->setY_coordinate(temp,0);
	return above;
}