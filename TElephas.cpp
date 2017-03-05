#include "stdafx.h"
#include "TElephas.h"
#include "TZoo.h"

TElephas::TElephas()
{
}
TElephas::TElephas(const std::string& name) : TProboscidea(name)
{
	TElephas::SetReprodAge(2);
}
TElephas::~TElephas()
{
}
void TElephas::Live(float time)
{
	if (time >= 7.f && time <= 15.f)
	{
		std::cout << GetName() << " is moving *booom booom*" << std::endl;
	}
	else if (time > 15.f && time <= 17.f)
	{
		std::cout << GetName() << " is eating *omnomnom*" << std::endl;
	}
	if (time > 17.f && time < 22)
	{
		std::cout << GetName() << " is moving his big ears" << std::endl;
	}
	else
	{
		TProboscidea::Live(time);
	}
}
int TElephas::Aging()
{
	int Age = TElephas::GetAge();
	if (Age == DeathAge)
	{
		return -1;
	}
	else
	{
		Age++;
		TElephas::SetAge(Age);
		return 0;
	}

}
std::string Names3[] = { "Erik(Elephant)", "Egor(Elephant)", "Roman(Elephant)", "Maria(Elephant)", "Sam(Elephant)", "Chloe(Elephant)", "*Big Joseph*(Elephant)" };
TAnimal** TElephas::Born()
{
	TAnimal *Newobj = new TElephas(Names3[rand() % 7]);
	std::cout << "New Animal Name is : " << Newobj->GetName();
	Newobj->SetAge(0);
	return &Newobj;

}
size_t TElephas::GetKind()
{
	return Kind;
}
