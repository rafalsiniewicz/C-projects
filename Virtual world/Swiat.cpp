#include "Swiat.h"
#include "Organizm.h"
#include<cstdlib>
#include<algorithm>
using std::cout;
void Swiat::wykonajTure()
{
	//bool start;
	srand(time(NULL));
	for (int i = 0; i < organizmy.size(); i++)
	{
		//start = false;
		for (int j = 0; j < organizmy.size(); j++)
			if (organizmy[i]->zwrocPolozenie().x == organizmy[j]->zwrocPolozenie().x && organizmy[i]->zwrocPolozenie().y == organizmy[j]->zwrocPolozenie().y && i != j)
			{
				organizmy[i]->kolizja(*organizmy[j], *this);
			}
		//if(start == false)
		organizmy[i]->akcja(*this);
	}
	//cout << counter;
}
void Swiat::rysujSwiat()
{
	Sleep(1000);
	system("cls");
	for (int i = 0; i < organizmy.size(); i++)
	{
		organizmy[i]->rysuj();
	}
}
void Swiat::dodajOrganizm(Organizm* _organizm)
{
	//cout << "dodaje organizm" << typeid(_organizm).name() << endl;
	counter++;
	organizmy.push_back(_organizm);
	Sleep(1000);
}
void Swiat::usunOrganizm(Organizm* _organizm)
{
	vector<Organizm*>::iterator it;
	it = find(organizmy.begin(), organizmy.end(), _organizm);
	organizmy.erase(it);
	delete _organizm;
}
void Swiat::pokazOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		cout << typeid(organizmy[i]).name() << organizmy[i]->zwrocPolozenie().x << organizmy[i]->zwrocPolozenie().y<<endl ;
	}
	Sleep(1000);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

