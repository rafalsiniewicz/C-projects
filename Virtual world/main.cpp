#include "Swiat.h"
#include "Rosliny.h"
#include "Zwierzeta.h"
#include "Organizm.h"
//using namespace std;
int main()
{
	const int number_of_organisms = 10;
	Swiat swiat;
	Wilk wilk[number_of_organisms];
	Owca owca[number_of_organisms];
	for (int i = 0,j=10; i < number_of_organisms; i++,j+=2)
	{
		wilk[i].ustawPolozenie(j, j);
		owca[i].ustawPolozenie(2 * j, 2 * j);
		swiat.dodajOrganizm(&wilk[i]);
		swiat.dodajOrganizm(&owca[i]);
	}
	//swiat.pokazOrganizmy();
	for (int i = 0; i < 100; i++)
	{
		swiat.wykonajTure();
		//swiat.pokazOrganizmy();
		swiat.rysujSwiat();
	}
	system("pause");
	return 0;
}