#include "Swiat.h"
#include "Rosliny.h"
#include "Zwierzeta.h"
#include "Organizm.h"
//using namespace std;
int main()
{
	Swiat swiat;
	Wilk wilk1, wilk2, wilk3;
	Owca owca1, owca2, owca3;
	Sleep(5000);
	vector<Wilk> wilk;
	vector<Owca> owca;
	wilk.push_back(wilk1);
	wilk.push_back(wilk2);
	wilk.push_back(wilk3);
	owca.push_back(owca1);
	owca.push_back(owca2);
	owca.push_back(owca3);
	Sleep(50000);
	for (int i = 0,j=10; i < wilk.size(); i++,j+=2)
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