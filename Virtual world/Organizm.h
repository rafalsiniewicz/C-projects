#pragma once
#ifndef ORGANIZM_H
#define ORGANIZM_H
#include<iostream>
//#include"Swiat.h"
using std::cout;
using std::endl;
class Swiat;
class Organizm
{
private:
	int sila;
	int inicjatywa;
	struct polozenie
	{
		int x;
		int y;
	};
	struct polozenie miejsce;
	// Swiat& swiat;
public:
	virtual void akcja() {};
	void kolizja();
	virtual void id() = 0;
	virtual void rysuj() = 0;
	Organizm() { cout << "tworze organizm" << endl; }
	virtual ~Organizm() { cout << "usuwam organizm"<< endl; }
	int zwrocSila() { return sila; }
	int zwrocInicjatywa() { return inicjatywa; }
	void ustawSila(int _sila) { sila = _sila; }
	void ustawInicjatywa(int _inicjatywa) { inicjatywa = _inicjatywa; }
	void ustawPolozenie(int _x, int _y) { miejsce.x = _x; miejsce.y = _y; }
	void zmienPolozenie(int _x, int _y) { miejsce.x = miejsce.x + _x; miejsce.y = miejsce.y + _y; }
	struct polozenie zwrocPolozenie() { return miejsce; }
};

#endif
