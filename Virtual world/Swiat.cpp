#include "Swiat.h"

using std::cout;
/*void Swiat::wykonajTure()
{
	for (int i = 0; i < zwierzeta.size(); i++)
	{
		zwierzeta[i].akcja();
	}
}
void Swiat::rysujSwiat()
{
	Sleep(1000);
	system("cls");
	for (int i = 0; i < zwierzeta.size(); i++)
	{
		zwierzeta[i].rysuj();
	}
}
void Swiat::dodajZwierze(Wilk& _organizm)
{
	cout << "dodaje zwierze" << typeid(_organizm).name() <<endl;
	zwierzeta.push_back(_organizm);
	Sleep(1000);
}*/
void Swiat::wykonajTure()
{
	srand(time(NULL));
	for (int i = 0; i < organizmy.size(); i++)
	{
		organizmy[i]->akcja();
	}
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
	organizmy.push_back(_organizm);
	Sleep(1000);
}
/*
void Swiat::usunOrganizm(Organizm& _organizm)
{
	vector<Organizm&>::iterator it;
	it = find(organizmy.begin(), organizmy.end(), _organizm);
	organizmy.erase(it);
}*/
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

