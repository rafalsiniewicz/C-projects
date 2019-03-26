#include "Zwierzeta.h"
#include"Swiat.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using std::cout;

void Zwierze::akcja()
{
	int x_rand = (std::rand() % 3) - 1;
	int y_rand = (std::rand() % 3) - 1;
	zmienPolozenie(x_rand, y_rand);
}
Organizm& Zwierze::kolizja(Organizm& _organizm)
{
	if (typeid(*this) == typeid(_organizm))
		cout << "ten sam gatunek";
	cout << "kolizja";
	return _organizm;
}
void Wilk::rysuj()
{ 
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y); 
	cout << "w"; 
}
Organizm& Wilk::kolizja(Organizm& _organizm)
{
	if (typeid(*this) == typeid(_organizm))
		cout << "wilk kolizja";
	cout << "kolizja";
	return _organizm;
}
void Owca::rysuj()
{
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y);
	cout << "o";
}
Organizm& Owca::kolizja(Organizm& _organizm)
{
	if (typeid(*this) == typeid(_organizm))
		cout << "owca kolizja";
	cout << "kolizja";
	return _organizm;
}
