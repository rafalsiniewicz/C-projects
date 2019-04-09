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
	int x_rand, y_rand;
	int prob = (std::rand() % 100);
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
		_swiat.dodajOrganizm(roslina);
	}
}
//void Trawa::akcja(Swiat& _swiat)
//{
//}


