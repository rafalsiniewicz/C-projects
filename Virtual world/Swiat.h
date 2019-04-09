#pragma once
#ifndef SWIAT_H
#define SWIAT_H
#define NOMINMAX
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <SFML/Graphics.hpp>
//#include"Organizm.h"
//#include"Zwierzeta.h"
#include<Windows.h>
using namespace sf;
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
	Texture texture;
	Sprite sprite;
	RenderWindow* okno;
public:
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(Organizm* _organizm);
	void usunOrganizm(Organizm* _organizm);
	void pokazOrganizmy();
	vector<Organizm*>& zwrocOrganizmy() { return organizmy; }
	int iloscOrganizmow() { return counter; }
	Swiat(RenderWindow* _okno): okno(_okno){ 
		//cout << "tworze swiat" << endl; 
		counter = 0; }
	Swiat() {
		counter = 0;
	}
	~Swiat() { 
		//cout << "usuwam swiat" << endl;
	}
	void pokazSwiat();
	void dodajObraz();
	RenderWindow* zwrocOkno() { return okno; }
};

#endif
