#include "stdafx.h"
#include "THippopotamus.h"


THippopotamus::THippopotamus()
{
}
THippopotamus::THippopotamus(const std::string& name) : TArtiodactyla(name)
{
	THippopotamus::SetReprodAge(1);
}
THippopotamus::~THippopotamus()
{
}
void THippopotamus::Live(float time)
{
	if ((time >= 9.f && time <= 12.f) || (time > 17.f && time < 19))
	{
		std::cout << GetName() << " is moving *boom boom*" << std::endl;
	}
	else if (time > 12.f && time <= 15.f)
	{
		std::cout << GetName() << " is swimming" << std::endl;
	}
	else if ((time > 15.f && time <= 17.f)||(time >=19.f && time < 20))
	{
		std::cout << GetName() << " is eating  *omnomnom*" << std::endl;
	}
	else
	{
		TArtiodactyla::Live(time);
	}
}
int THippopotamus::Aging()
{
	int Age = THippopotamus::GetAge();
	if (Age == DeathAge)
	{
		return -1;
	}
	else
	{
		Age++;
		THippopotamus::SetAge(Age);
		return 0;
	}

}
std::string Names2[] = { "*GLORIA*(Hippo)", "Big Al(Hippo)", "Seline(Hippo)", "John(Hippo)", "Angela(Hippo)", "Mia(Hippo)", "Columb(Hippo)" };
TAnimal** THippopotamus::Born()
{
	
		TAnimal *Newobj = new THippopotamus(Names2[rand()%7]);
		std::cout << "New Animal Name is : " << Newobj->GetName();
		Newobj->SetAge(0);
		return &Newobj;
}
size_t THippopotamus::GetKind()
{
	return Kind;
}
