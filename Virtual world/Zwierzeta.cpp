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
void Wilk::rysuj()
{ 
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y); 
	cout << "w"; 
}
void Owca::rysuj()
{
	gotoxy(zwrocPolozenie().x, zwrocPolozenie().y);
	cout << "o";
}

