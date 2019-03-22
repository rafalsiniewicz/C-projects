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
public:
	Zwierze() { cout << "tworze zwierze" << endl; }
	~Zwierze() { cout << "usuwam zwierze" << endl; }
	void akcja();
	void kolizja();
	void id() { cout << "Zwierze"; }
	void rysuj()override {}
};
class Wilk : public Zwierze
{
private:
public:
	Wilk(){ cout << "tworze wilka" << endl; }
	~Wilk() { cout << "usuwam wilka" << endl; }
	void kolizja();
	void id() { cout << "Wilk"; }
	void rysuj(); 
};
class Owca : public Zwierze
{
private:
public:
	Owca() { cout << "tworze owce" << endl; }
	void kolizja();
	virtual void id() { cout << "Owca"; }
	void rysuj();
};
class Lis : public Zwierze
{
private:
public:
	Lis();
	void kolizja();
	virtual void id() { cout << "Lis"; }
	void rysuj() { cout << "l"; }
};

#endif