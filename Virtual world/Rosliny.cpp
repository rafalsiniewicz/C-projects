#include "Rosliny.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
int Trawa::ilosc = 0;
void Roslina::pokazObraz(RenderWindow& okno)
{
	okno.draw(sprite);
}
void Roslina::akcja(Swiat& _swiat)
{
	
}
void Trawa::akcja(Swiat& _swiat)
{
	int x_rand, y_rand;
	int prob = (std::rand() % 100);
	bool kolizja = false;
	if (prob <= 5)
	{
		Trawa* roslina = new Trawa;
		roslina->ustawSwiat(&_swiat);
		do {
			x_rand = (std::rand() % 3) - 1;
			y_rand = (std::rand() % 3) - 1;
			x_rand *= 30;
			y_rand *= 30;
		} while (zwrocObraz().getPosition().x + x_rand <= 50 || zwrocObraz().getPosition().x + x_rand >= 750 || zwrocObraz().getPosition().y + y_rand <= 50 || zwrocObraz().getPosition().y + y_rand >= 550);
		roslina->ustawPozycje(zwrocObraz().getPosition().x + x_rand, zwrocObraz().getPosition().y + y_rand);
		roslina->zwiekszOczekiwanie();
		vector<Organizm*> vec = _swiat.zwrocOrganizmy();
		int l=this->ilosc;
		for (int i = 0; i < this->ilosc-1; i++)
		{
			if (vec.size() - i - 1 >= 0)
			{
				if (vec[vec.size() - i - 1]->zwrocObraz().getGlobalBounds().intersects(roslina->zwrocObraz().getGlobalBounds()))
				{
					kolizja = true;
					delete roslina;
					break;
				}
			}
		}
		if(kolizja==false)
			_swiat.dodajOrganizm(roslina);


	}
}
bool Trawa::kolizja(Organizm& _organizm, Swiat& _swiat)
{
	if (_organizm.zwrocSila() == 4)
	{
		_organizm.ustawGlod(0);
		_swiat.usunOrganizm(this);
	}
	return false;
}


