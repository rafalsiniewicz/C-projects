#include "Swiat.h"
#include "Rosliny.h"
#include "Zwierzeta.h"
//#include "Organizm.h"
//using namespace std;
int main()
{
	const int number_of_organisms = 5;
	Swiat swiat;
	Wilk* wilk[number_of_organisms];
	//cout << wilk[0].zwrocInicjatywa();
	//Owca* owca[number_of_organisms];
	for (int i = 0,j=10; i < number_of_organisms; i++,j+=2)
	{
		//owca[i] = new Owca;
		wilk[i] = new Wilk;
		wilk[i]->ustawPolozenie(j, j);
		wilk[i]->ustawSwiat(&swiat);
		//owca[i]->ustawPolozenie(j+i, j+i);
		swiat.dodajOrganizm(wilk[i]);
		//swiat.dodajOrganizm(owca[i]);
	}
	//swiat.pokazOrganizmy();
	for (int i = 0; i < 100; i++)
	{
		swiat.wykonajTure();
		//swiat.pokazOrganizmy();
		swiat.rysujSwiat();
		//cout << wilk[0]->ile() << " wilkow";
		//cout << owca[0]->ile() << " owiec";
	}
	system("pause");
	return 0;
}