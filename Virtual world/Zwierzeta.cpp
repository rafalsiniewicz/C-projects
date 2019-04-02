#include"Zwierzeta.h"
#include"Swiat.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
int Wilk::ilosc = 0;
int Owca::ilosc = 0;
void Zwierze::akcja(Swiat& _swiat)
{
	int x_rand = (std::rand() % 3) - 1;
	int y_rand = (std::rand() % 3) - 1;
	zmienPolozenie(x_rand, y_rand);
}
bool Zwierze::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	if (typeid(*this) == typeid(_organizm))
		cout << "ten sam gatunek";
	//cout << "kolizja";
	return true;
}
void Wilk::rysuj()
{ 
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y); 
	cout << "w"; 
}
bool Wilk::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	//cout << "kolizja wilkow";
	_swiat.rysujSwiat();
	Wilk* wilk = new Wilk;
	wilk->ustawSwiat(&_swiat);
	int x_rand;
	int y_rand;
	bool check;
	if (typeid(*this) == typeid(_organizm))
	{
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
		wilk->ustawPolozenie(x_rand, y_rand);
		_swiat.dodajOrganizm(wilk);
		/*vector<Organizm*>::iterator it1;
		vector<Organizm*>::iterator it2;
		Organizm* org = &_organizm;
		it1 = find(_swiat.zwrocOrganizmy().begin(), _swiat.zwrocOrganizmy().end(), org);
		it2 = find(_swiat.zwrocOrganizmy().begin(), _swiat.zwrocOrganizmy().end(), this);
		for (vector<Organizm*>::iterator i = _swiat.zwrocOrganizmy().begin(); i != _swiat.zwrocOrganizmy().end(); i++)
		{
			if (i != it1 && i != it2)
				(*i)->akcja(_swiat);
		}*/
		//_swiat.rysujSwiat();
		return true;
	}
	else
	{
		if (this->inicjatywa > _organizm.zwrocInicjatywa())
			_swiat.usunOrganizm(&_organizm);
		//_swiat.rysujSwiat();
		delete wilk;
		return false;
	}
	//cout << "wilk kolizja";
//cout << "kolizja";
}
void Owca::rysuj()
{
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y);
	cout << "o";
}
bool Owca::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	_swiat.rysujSwiat();
	Owca* owca = new Owca;
	owca->ustawSwiat(&_swiat);
	int x_rand;
	int y_rand;
	bool check;
	if (typeid(*this) == typeid(_organizm))
	{
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
		_swiat.dodajOrganizm(owca);
		//_swiat.rysujSwiat();
		return true;
	}
	else 
	{
		delete owca;
		return false;
	}
}
