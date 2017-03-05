#include "stdafx.h"
#include "TLeo.h"
#include "TZoo.h"

TLeo::TLeo()
{
}
TLeo::TLeo(const std::string& name) : TCarnivora(name)
{
	TLeo::SetReprodAge(2);
}
TLeo::~TLeo()
{
}
void TLeo::Live(float time)
{
	if (time >= 9.f && time <= 15.f)
	{
		std::cout << GetName() << " is lies on a grass and dreams" << std::endl;
	}
	else if (time > 15.f && time <= 17.f)
	{
		std::cout << GetName() << " is eats and purr *purrrr*" << std::endl;
	}
	if (time > 17.f && time <= 24.f)
	{
		std::cout << GetName() << " is licks himself and poses for a photo" << std::endl;
	}
	else
	{
		TCarnivora::Live(time);
	}
}
int TLeo::Aging()
{
	int Age = TLeo::GetAge();
	if (Age == DeathAge)
	{
		return -1;
	}
	else
	{
		Age++;
		TLeo::SetAge(Age);
		return 0;
	}

}
std::string Names6[] = { "Ashley(Leo)", "Olivia(Leo)", "Emily(Leo)", "William(Leo)", "King Michael(Leo)", "Christopher(Leo)", "*Alex*(Leo)" };
TAnimal** TLeo::Born()
{
	TAnimal *Newobj = new TLeo(Names6[rand() % 7]);
	std::cout << "New Animal Name is : " << Newobj->GetName();
	Newobj->SetAge(0);
	return &Newobj;

}
size_t TLeo::GetKind()
{
	return Kind;
}
