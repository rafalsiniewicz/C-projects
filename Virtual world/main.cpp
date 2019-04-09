//#define NOMINMAX
//#include <SFML/Graphics.hpp>
#include "Swiat.h"
#include "Rosliny.h"
#include "Zwierzeta.h"

//#include "Organizm.h"
//using namespace std;
int main()
{
	/*const int number_of_organisms = 10;
	Swiat swiat;
	Wilk* wilk[number_of_organisms];
	//cout << wilk[0].zwrocInicjatywa();
	Owca* owca[number_of_organisms];
	Lis* lis[number_of_organisms];
	for (int i = 0, j = 10; i < number_of_organisms; i++, j += 2)
	{
		wilk[i] = new Wilk;
		owca[i] = new Owca;
		lis[i] = new Lis;
		wilk[i]->ustawPolozenie(j, j);
		owca[i]->ustawPolozenie(j, j);
		lis[i]->ustawPolozenie(2 * j, 2 * j);
		swiat.dodajOrganizm(wilk[i]);
		swiat.dodajOrganizm(owca[i]);
		swiat.dodajOrganizm(lis[i]);

	}
	//swiat.pokazOrganizmy();
	for (int i = 0; i < 1000; i++)
	{
		swiat.rysujSwiat();
		swiat.wykonajTure();
		//swiat.pokazOrganizmy();
		
		//cout << wilk[0]->ile() << " wilkow";
		//cout << owca[0]->ile() << " owiec";
		//cout << lis[0]->ile() << " lisow";
	}
	system("pause");
	return 0;*/

	srand(time(NULL));
	RenderWindow okno(sf::VideoMode(800, 600), "");
	const int number_of_organisms = 7;
	Swiat swiat(&okno);
	Wilk* wilk[number_of_organisms];
	//cout << wilk[0].zwrocInicjatywa();
	Owca* owca[number_of_organisms];
	//Lis* lis[number_of_organisms];
	Trawa* trawa[number_of_organisms];
	int x_rand, y_rand;
	for (int i = 0, j = 30, k = 300; i < number_of_organisms; i++, j += 100, k-=30)
	{
		x_rand = 30 * ((std::rand() % 25) + 1);
		y_rand = 30 * ((std::rand() % 19) + 1);
		wilk[i] = new Wilk;
		owca[i] = new Owca;
		//lis[i] = new Lis;
		trawa[i] = new Trawa;
		wilk[i]->ustawPozycje(x_rand, y_rand);
		x_rand = 30 * ((std::rand() % 25) + 1);
		y_rand = 30 * ((std::rand() % 19) + 1);
		owca[i]->ustawPozycje(x_rand, y_rand);
		//lis[i]->ustawPolozenie(2 * j, 2 * j);
		x_rand = 30 * ((std::rand() % 25) + 1);
		y_rand = 30 * ((std::rand() % 19) + 1);
		trawa[i]->ustawPozycje(x_rand, y_rand);
		//wilk[i]->dodajObraz();
		//owca[i]->dodajObraz();
		//lis[i]->dodajObraz();
		swiat.dodajOrganizm(wilk[i]);
		swiat.dodajOrganizm(owca[i]);
		//swiat.dodajOrganizm(lis[i]);
		swiat.dodajOrganizm(trawa[i]);

	}
	swiat.dodajObraz();
	while (swiat.zwrocOkno()->isOpen())
	{
		Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
				okno.close();

		} //while
		okno.clear();

		/*Texture texture;
		Sprite wolf;
		Sprite grass;
		texture.loadFromFile("Images/grass.jpg");
		grass.setTexture(texture);
		okno.draw(grass);
		texture.loadFromFile("Images/wolf.png");
		wolf.setTexture(texture);
		okno.draw(wolf);*/
		swiat.pokazSwiat();
		swiat.wykonajTure();
		//cout << trawa[0]->ile() << " traw";
		
		
		
			//swiat.pokazOrganizmy();

			//cout << wilk[0]->ile() << " wilkow";
			//cout << owca[0]->ile() << " owiec";
			//cout << lis[0]->ile() << " lisow";

		
	} //while
	return 0;
}