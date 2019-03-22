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
	Roslina();
	~Roslina();
};
class Trawa :public Roslina
{
private:
public:
	Trawa();
	void kolizja();
};
class Mlecz :public Roslina
{
private:
public:
	Mlecz();
	void kolizja();
};

#endif