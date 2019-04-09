#include"Zwierzeta.h"
#include"Swiat.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
int Wilk::ilosc = 0;
int Owca::ilosc = 0;
int Lis::ilosc = 0;
void Zwierze::akcja(Swiat& _swiat)
{
	int x_rand, y_rand;
	do {
		x_rand = (std::rand() % 3) - 1;
		y_rand = (std::rand() % 3) - 1;
		x_rand *= 30;
		y_rand *= 30;
	} while (zwrocObraz().getPosition().x + x_rand <= 50 || zwrocObraz().getPosition().x + x_rand >= 750 || zwrocObraz().getPosition().y + y_rand <= 50 || zwrocObraz().getPosition().y + y_rand >= 550);
	ustawPozycje(zwrocObraz().getPosition().x + x_rand, zwrocObraz().getPosition().y + y_rand);
}
bool Zwierze::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	if (typeid(*this) == typeid(_organizm))
		cout << "ten sam gatunek";
	//cout << "kolizja";
	return true;
}
void Zwierze::dodajObraz()
{}
void Zwierze::pokazObraz(RenderWindow& okno)
{
	okno.draw(sprite);
}
void Wilk::rysuj()
{ 
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y); 
	cout << "w"; 
}
bool Wilk::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	//cout << "kolizja wilkow";
	if (typeid(*this) == typeid(_organizm))
	{
		Wilk* wilk = new Wilk;
		wilk->ustawSwiat(&_swiat);
		int x_rand;
		int y_rand;
		bool check;
		do {
			check = true;
			x_rand = _organizm.zwrocObraz().getPosition().x + 30*((std::rand() % 3) - 1);
			y_rand = _organizm.zwrocObraz().getPosition().y + 30*((std::rand() % 3) - 1);
			for (int i = 0; i < _swiat.zwrocOrganizmy().size(); i++)
			{
				if (abs(x_rand - _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().x) <= 60 && abs(y_rand - _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().y) <= 60)
				{
					if (x_rand == _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().x && y_rand == _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().y)
					{
						cout << "zle wspolrzedne";
						check = false;
						break;
					}
				}
			}
		} while (check == false);
		wilk->ustawPozycje(x_rand, y_rand);
		//wilk->dodajObraz();
		_swiat.dodajOrganizm(wilk);
		//cout << "aaaaaa";
		//_swiat.rysujSwiat();
		/*vector<Organizm*>& copy = _swiat.zwrocOrganizmy();
		vector<Organizm*>::iterator it1;
		vector<Organizm*>::iterator it2;
		Organizm* org = &_organizm;
		it1 = find(copy.begin(), copy.end(), org);
		it2 = find(copy.begin(), copy.end(), this);
		for (vector<Organizm*>::iterator i = copy.begin(); i != copy.end(); i++)
		{
			if (i != it1 && i != it2)
				(*i)->akcja(_swiat);
			//_swiat.rysujSwiat();
		}
		_swiat.rysujSwiat();
		for (int i = 0; i < copy.size(); i++)
		{
			for (int j = 0; j < copy.size(); j++)
			{
				if (copy[i]->zwrocPolozenie().x != _organizm.zwrocPolozenie().x && copy[i]->zwrocPolozenie().y != _organizm.zwrocPolozenie().y && copy[i]->zwrocPolozenie().x == copy[j]->zwrocPolozenie().x && copy[i]->zwrocPolozenie().y == copy[j]->zwrocPolozenie().y && i!=j)
				{
					//cout << "kolizja nowych";
					copy[j]->kolizja(*copy[j], _swiat);
					
				}
			}
		}
		//_swiat.rysujSwiat();*/
		return true;
	}
	else
	{
		if (this->inicjatywa > _organizm.zwrocInicjatywa())
		{
			_swiat.pokazSwiat();
			Texture _texture;
			Sprite _sprite;
			_texture.loadFromFile("Images/dead.png");
			_sprite.setTexture(_texture);
			_sprite.setPosition(_organizm.zwrocObraz().getPosition().x, _organizm.zwrocObraz().getPosition().y);
			_swiat.zwrocOkno()->draw(_sprite);
			_swiat.zwrocOkno()->display();
			//Sleep(1000);
			_swiat.usunOrganizm(&_organizm);
		}
		//_swiat.rysujSwiat();
		//delete wilk;
		return false;
	}
	//cout << "wilk kolizja";
//cout << "kolizja";
}
void Wilk::dodajObraz()
{
	texture.loadFromFile("Images/wolf.png");
	sprite.setTexture(texture);
}
void Owca::rysuj()
{
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y);
	cout << "o";
}
bool Owca::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	
	if (typeid(*this) == typeid(_organizm))
	{
		/*Owca* owca = new Owca;
		owca->ustawSwiat(&_swiat);
		int x_rand;
		int y_rand;
		bool check;
		do {
			check = true;
			x_rand = _organizm.zwrocPolozenie().x + (std::rand() % 6) - 1;
			y_rand = _organizm.zwrocPolozenie().y + (std::rand() % 6) - 1;

			for (int i = 0; i < _swiat.zwrocOrganizmy().size(); i++)
			{
				if (abs(x_rand - _swiat.zwrocOrganizmy()[i]->zwrocPolozenie().x) <= 2 && abs(y_rand - _swiat.zwrocOrganizmy()[i]->zwrocPolozenie().y) <= 2)
				{
					if (x_rand == _swiat.zwrocOrganizmy()[i]->zwrocPolozenie().x && y_rand == _swiat.zwrocOrganizmy()[i]->zwrocPolozenie().y)
					{
						cout << "zle wspolrzedne";
						check == false;
						break;
					}
				}
			}
		} while (check == false);
		owca->ustawPolozenie(x_rand, y_rand);
		_swiat.dodajOrganizm(owca);*/

		Owca* owca = new Owca;
		owca->ustawSwiat(&_swiat);
		int x_rand;
		int y_rand;
		bool check;
		do {
			check = true;
			x_rand = _organizm.zwrocObraz().getPosition().x + 30 * ((std::rand() % 3) - 1);
			y_rand = _organizm.zwrocObraz().getPosition().y + 30 * ((std::rand() % 3) - 1);
			for (int i = 0; i < _swiat.zwrocOrganizmy().size(); i++)
			{
				if (abs(x_rand - _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().x) <= 60 && abs(y_rand - _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().y) <= 60)
				{
					if (x_rand == _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().x && y_rand == _swiat.zwrocOrganizmy()[i]->zwrocObraz().getPosition().y)
					{
						cout << "zle wspolrzedne";
						check = false;
						break;
					}
				}
			}
		} while (check == false);
		owca->ustawPozycje(x_rand, y_rand);
		//wilk->dodajObraz();
		_swiat.dodajOrganizm(owca);

		
		return true;
	}
	else
	{
		if (this->inicjatywa < _organizm.zwrocInicjatywa())
		{
			_swiat.pokazSwiat();
			Texture _texture;
			Sprite _sprite;
			_texture.loadFromFile("Images/dead.png");
			_sprite.setTexture(_texture);
			_sprite.setPosition(_organizm.zwrocObraz().getPosition().x, _organizm.zwrocObraz().getPosition().y);
			_swiat.zwrocOkno()->draw(_sprite);
			_swiat.zwrocOkno()->display();
			//Sleep(1000);
			_swiat.usunOrganizm(this);
		}
		//_swiat.rysujSwiat();
		//delete wilk;
		return false;
	}
}
void Owca::dodajObraz()
{
	texture.loadFromFile("Images/sheep.png");
	sprite.setTexture(texture);
}
void Lis::rysuj()
{
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y);
	cout << "l";
}
void Lis::akcja(Swiat& _swiat)
{
	int x_rand = (std::rand() % 3) - 1;
	int y_rand = (std::rand() % 3) - 1;
	zmienPolozenie(x_rand, y_rand);
	//cout << "lis";
}