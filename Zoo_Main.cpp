#include "stdafx.h"
#include "TZoo.h"
#include "TAnimal.h"
#include "TArtiodactyla.h"
#include "TGIraffa.h"
#include "THippopotamus.h"
#include "TProboscidea.h"
#include "TElephas.h"
#include "TLoxodonta.h"
#include "TCarnivora.h"
#include "TTigris.h"
#include "TLeo.h"
#include "thread"
int _tmain(int argc, _TCHAR* argv[])
{
	
	TZoo zoo1("Vostochniy",10);
	TZoo zoo2("MagicZoo", 10);
#pragma region Животные, сидящие в зоопарках изначально
	TAnimal *MyGiraffa1 = new TGiraffa("Adam(Giraffe)");
	TAnimal *MyGiraffa2 = new TGiraffa("Eva(GIraffe)");
	TAnimal *MyHippo1 = new THippopotamus("Gloria(Hippo)");
	TAnimal *MyHippo2 = new THippopotamus("Mark(Hippo)");
	TAnimal *MyHippo3 = new THippopotamus("Big Joe(Hippo)");
	TAnimal *MyElephant1 = new TElephas("Eugene(Elephant)");
	TAnimal *MyElephant2 = new TElephas("Giant Jacob(Elephant)");
	TAnimal *MyLoxodonta1 = new TLoxodonta("Eugene(Loxodonta)");
	TAnimal *MyLoxodonta2 = new TLoxodonta("Giant James(Loxodonta)");
	TAnimal *MyTigris1 = new TTigris("Tommy(Tiger)");
	TAnimal *MyTigris2 = new TTigris("Mia(Tiger)");
	TAnimal *MyLeo1 = new TLeo("Sarah(Leo)");
	TAnimal *MyLeo2 = new TLeo("Logan(Leo)");
	if (!zoo2.AddNewAnimal(&MyGiraffa1))
	{
		delete MyGiraffa1;
	}
	if (!zoo1.AddNewAnimal(&MyHippo1))
	{
		delete MyHippo1;
	}
	if (!zoo2.AddNewAnimal(&MyHippo3))
	{
		delete MyHippo3;
	}
	if (!zoo2.AddNewAnimal(&MyGiraffa2))
	{
		delete MyGiraffa2;
	}
	if (!zoo1.AddNewAnimal(&MyHippo2))
	{
		delete MyHippo2;
	}
	if (!zoo2.AddNewAnimal(&MyElephant1))
	{
		delete MyElephant1;
	}
	if (!zoo2.AddNewAnimal(&MyElephant2))
	{
		delete MyElephant2;
	}

	if (!zoo1.AddNewAnimal(&MyLoxodonta1))
	{
		delete MyLoxodonta1;
	}
	if (!zoo1.AddNewAnimal(&MyLoxodonta2))
	{
		delete MyLoxodonta2;
	}
	if (!zoo1.AddNewAnimal(&MyTigris1))
	{
		delete MyTigris1;
	}
	if (!zoo2.AddNewAnimal(&MyTigris2))
	{
		delete MyTigris2;
	}
	if (!zoo2.AddNewAnimal(&MyLeo1))
	{
		delete MyLeo1;
	}
	if (!zoo1.AddNewAnimal(&MyLeo2))
	{
		delete MyLeo2;
	}
#pragma endregion
	int position = -1;
	for (int i = 0; i < 100; i++)
	{
		int Alive1 = zoo1.Work();
		int Alive2 = zoo2.Work();
		if (i % 10 == 0 && i !=0)
		{
			std::cout << "\n???Don't you want to transfer animals? Enter '-1' if isn't present, or anykey - for exchange.\n This key will mean number of the chosen animal :";
			std::cin >> position;
			if (position != -1)
			{
				zoo1.Transfer(zoo2, position);
			}
		}
		if (Alive1 == -1 && Alive2 == -1)
		{
			break;
		}
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	system("pause");
	return 0;
}
