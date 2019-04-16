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
		//cout << "usuwam zwierze" << endl; 
	}
	void akcja(Swiat& _swiat);
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	void rysuj()override {}
	int zwrocInicjatywa()const { return inicjatywa; }
	int zwrocSila() const override{ return sila; }
	void dodajObraz() override;
	void pokazObraz(RenderWindow& okno) override;
	//void dodaj(Swiat& _swiat) {}
};
class Wilk : public Zwierze
{
private:
	int sila;
	int inicjatywa;
	static int ilosc;
public:
	Wilk(int _sila=9, int _inicjatywa=5):sila(_sila),inicjatywa(_inicjatywa){ 
		//cout << "tworze wilka" << endl; 
		texture.loadFromFile("Images/wolf.png");
		sprite.setTexture(texture);
		ilosc++;
	}
	~Wilk() { 
		//cout << "usuwam wilka" << endl;
		ilosc--;
	}
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	void rysuj(); 
	int zwrocInicjatywa()const { return inicjatywa; }
	int ile() { return ilosc; }
	int zwrocSila() const override { return sila; }
	void dodajObraz() override;
	//void pokazObraz(RenderWindow& okno) override;
	/*void dodaj(Swiat& _swiat) 
	{
		//cout << this->zwrocSila();
		//_swiat.counter++;
		_swiat.zwrocOrganizmy().push_back(this);
		Sleep(1000);
	}*/
};
class Owca : public Zwierze
{
private:
	int sila;
	int inicjatywa;
	static int ilosc;
public:
	Owca(int _sila=4, int _inicjatywa=4) : sila(_sila), inicjatywa(_inicjatywa){
		//cout << "tworze owce" << endl; 
		texture.loadFromFile("Images/sheep.png");
		sprite.setTexture(texture);
		ilosc++;
	}
	~Owca()
	{
		//cout << "usuwam owce" << endl;
		ilosc--;
	}
	bool kolizja(Organizm& _organizm, Swiat& _swiat);
	void rysuj();
	int zwrocInicjatywa()const { return inicjatywa; }
	int ile() { return ilosc; }
	int zwrocSila() const override { return sila; }
	void dodajObraz() override;
	//void pokazObraz(RenderWindow& okno) override;
	/*void dodaj(Swiat& _swiat)
	{
		//cout << this->zwrocSila();
		//_swiat.counter++;
		_swiat.zwrocOrganizmy().push_back(this);
		Sleep(1000);
	}*/
};
class Lis : public Zwierze
{
private:
	int sila;
	int inicjatywa;
	static int ilosc;
public:
	Lis(int _sila = 3, int _inicjatywa = 7) : sila(_sila), inicjatywa(_inicjatywa) {
		//cout << "tworze lisa" << endl; 
		ilosc++;
	}
	~Lis()
	{
		//cout << "usuwam lisa" << endl;
		ilosc--;
	}
	bool kolizja(Organizm& _organizm, Swiat& _swiat) { return true; }
	void rysuj();
	int zwrocInicjatywa()const { return inicjatywa; }
	int ile() { return ilosc; }
	int zwrocSila() const override { return sila; }
	void akcja(Swiat& _swiat) override;
};

#endif