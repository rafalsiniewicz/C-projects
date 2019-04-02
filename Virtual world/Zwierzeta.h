#pragma once
#ifndef ZWIERZETA_H
#define ZWIERZETA_H
#include<vector>
#include"Organizm.h"
//using std::vector;
using std::cout;
using std::endl;

class Zwierze : public Organizm
{
private:
	int sila;
	int inicjatywa;
public:
	Zwierze() { 
		//cout << "tworze zwierze" << endl; 
	}
	~Zwierze() { 
		cout << "usuwam zwierze" << endl; 
	}
	void akcja(Swiat& _swiat);
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	void id() { cout << "Zwierze"; }
	void rysuj()override {}
	int zwrocInicjatywa()const { return inicjatywa; }
};
class Wilk : public Zwierze
{
private:
	static const int sila = 9;
	static const int inicjatywa = 5;
	static int ilosc;
public:
	Wilk(){ 
		//cout << "tworze wilka" << endl; 
		ilosc++;
	}
	~Wilk() { 
		cout << "usuwam wilka" << endl;
		ilosc--;
	}
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	void id() { cout << "Wilk"; }
	void rysuj(); 
	int zwrocInicjatywa()const { return inicjatywa; }
	int ile() { return ilosc; }
};
class Owca : public Zwierze
{
private:
	static const int sila = 4;
	static const int inicjatywa = 4;
	static int ilosc;
public:
	Owca() { 
		cout << "tworze owce" << endl; 
		ilosc++;
	}
	~Owca()
	{
		cout << "usuwam owce" << endl;
		ilosc--;
	}
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	virtual void id() { cout << "Owca"; }
	void rysuj();
	int zwrocInicjatywa()const { return inicjatywa; }
	int ile() { return ilosc; }
};
class Lis : public Zwierze
{
private:
public:
	Lis();
	//void kolizja();
	virtual void id() { cout << "Lis"; }
	void rysuj() { cout << "l"; }
};

#endif