#pragma once
#ifndef SWIAT_H
#define SWIAT_H
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iostream>
//#include"Organizm.h"
//#include"Zwierzeta.h"
#include<Windows.h>
void gotoxy(int x, int y);
using std::vector;
using std::cout;
using std::endl;
class Organizm;
class Swiat
{
private:
	vector<Organizm*> organizmy;
	int counter;
public:
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(Organizm* _organizm);
	void usunOrganizm(Organizm* _organizm);
	void pokazOrganizmy();
	vector<Organizm*> zwrocOrganizmy() { return organizmy; }
	int iloscOrganizmow() { return counter; }
	Swiat() { 
		//cout << "tworze swiat" << endl; 
		counter = 0; }
	~Swiat() { 
		cout << "usuwam swiat" << endl;
	}
};

#endif
