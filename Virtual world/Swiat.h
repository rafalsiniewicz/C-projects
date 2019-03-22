#pragma once
#ifndef SWIAT_H
#define SWIAT_H
#include<vector>
#include<cstdlib>
#include<ctime>
//#include"Organizm.h"
#include"Zwierzeta.h"
#include<Windows.h>
void gotoxy(int x, int y);
using std::vector;
using std::cout;
class Organizm;
class Swiat
{
private:
	vector<Organizm*> organizmy;
	//Organizm* tab[100];
	//vector<Wilk> zwierzeta;
public:
	void wykonajTure();
	void rysujSwiat();
	//virtual void dodajZwierze(Wilk& _organizm);
	void dodajOrganizm(Organizm* _organizm);
	//void usunOrganizm(Organizm& _organizm);
	void pokazOrganizmy();
	Swiat() { cout << "tworze swiat" << endl; }
	~Swiat() { cout << "usuwam swiat" << endl; }
};

#endif
