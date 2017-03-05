#include "stdafx.h"
#include "TTigris.h"
#include "TZoo.h"

TTigris::TTigris()
{
}
TTigris::TTigris(const std::string& name) : TCarnivora(name)
{
	TTigris::SetReprodAge(2);
}
TTigris::~TTigris()
{
}
void TTigris::Live(float time)
{
	if (time >= 9.f && time <= 15.f)
	{
		std::cout << GetName() << " is walks and growls *rrr*" << std::endl;
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
int TTigris::Aging()
{
	int Age = TTigris::GetAge();
	if (Age == DeathAge)
	{
		return -1;
	}
	else
	{
		Age++;
		TTigris::SetAge(Age);
		return 0;
	}

}
std::string Names5[] = { "Donatello(Tiger)", "Sweet(Tiger)", "Splinter(Tiger)", "Helen(Tiger)", "Michael(Tiger)", "Ada(Tiger)", "Joseph(Tiger)" };
TAnimal** TTigris::Born()
{
	TAnimal *Newobj = new TTigris(Names5[rand() % 7]);
	std::cout << "New Animal Name is : " << Newobj->GetName();
	Newobj->SetAge(0);
	return &Newobj;

}
size_t TTigris::GetKind()
{
	return Kind;
}
