#pragma once
#ifndef ORGANIZM_H
#define ORGANIZM_H
#include<iostream>
#include"Swiat.h"
using std::cout;
using std::endl;
//class Swiat;
class Organizm
{
private:
	int sila;
	int inicjatywa;
	bool koliduje=false;
	struct polozenie
	{
		int x;
		int y;
	};
	struct polozenie miejsce;
	Swiat swiat;
public:
	virtual void akcja(Swiat& _swiat) {};
	virtual bool kolizja(Organizm& _organizm, Swiat& _swiat);
	virtual void id() = 0;
	virtual void rysuj() = 0;
	Organizm() { 
		//cout << "tworze organizm" << endl; 
	}
	virtual ~Organizm() { 
		//cout << "usuwam organizm"<< endl; 
	}
	virtual int zwrocSila()const { return sila; }
	virtual int zwrocInicjatywa()const { return inicjatywa; }
	void ustawSila(int _sila) { sila = _sila; }
	int zwrocSila(int _sila) const{ return sila; }
	void ustawInicjatywa(int _inicjatywa) { inicjatywa = _inicjatywa; }
	void ustawPolozenie(int _x, int _y) { miejsce.x = _x; miejsce.y = _y; }
	void zmienPolozenie(int _x, int _y) { miejsce.x = miejsce.x + _x; miejsce.y = miejsce.y + _y; }
	struct polozenie zwrocPolozenie() { return miejsce; }
	Swiat& zwrocSwiat() { return swiat;}
	void ustawSwiat(Swiat* _swiat) { swiat = *_swiat; }
	void ustawKolizje(bool _koliduje) { koliduje = _koliduje; }
	bool zwrocKolizje() { return koliduje; }
	//virtual void dodaj(Swiat& _swiat) {};
};

#endif
