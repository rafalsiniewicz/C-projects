#pragma once
#ifndef ROSLINY_H
#define ROSLINY_H
#include<vector>
#include"Organizm.h"
//using std::vector;
using std::cout;


class Roslina : public Organizm
{
private:
	const int inicjatywa = 0;
public:
	Roslina() {};
	~Roslina() {};
	void akcja(Swiat& _swiat) ;
	void pokazObraz(RenderWindow& okno) override;
	void id()override {}
	void rysuj()override { cout << "r"; }
};
class Trawa :public Roslina
{
private:
	int sila;
	int inicjatywa;
	static int ilosc;
public:
	Trawa(int _sila=0, int _inicjatywa=0):sila(_sila),inicjatywa(_inicjatywa) {
		texture.loadFromFile("Images/grass.jpg");
		sprite.setTexture(texture);
		ilosc++;
	}
	void kolizja();
	//void akcja(Swiat& _swiat);
	void id()override { cout << "trawa"; }
	void rysuj()override { cout << "t"; }
	int ile() { return ilosc; }
};
class Mlecz :public Roslina
{
private:
public:
	Mlecz();
	void kolizja();
};

#endif