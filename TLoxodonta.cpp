#include "stdafx.h"
#include "TLoxodonta.h"
#include "TZoo.h"

TLoxodonta::TLoxodonta()
{
}
TLoxodonta::TLoxodonta(const std::string& name) : TProboscidea(name)
{
	TLoxodonta::SetReprodAge(2);
}
TLoxodonta::~TLoxodonta()
{
}
void TLoxodonta::Live(float time)
{
	if (time >= 7.f && time <= 15.f)
	{
		std::cout << GetName() << " is moving *booom booom*" << std::endl;
	}
	else if (time > 15.f && time <= 17.f)
	{
		std::cout << GetName() << " is eating leaves and sing a song with his trunk!" << std::endl;
	}
	if (time > 17.f && time < 22)
	{
		std::cout << GetName() << " is moving his big ears " << std::endl;
	}
	else
	{
		TProboscidea::Live(time);
	}
}
int TLoxodonta::Aging()
{
	int Age = TLoxodonta::GetAge();
	if (Age == DeathAge)
	{
		return -1;
	}
	else
	{
		Age++;
		TLoxodonta::SetAge(Age);
		return 0;
	}

}
std::string Names4[] = { "Erik(Loxodonta)", "Emma(Loxodonta)", "Ryan(Loxodonta)", "Maria(Loxodonta)", "Sam(Loxodonta)", "Chloe(Loxodonta)", "*Giant Mike*(Loxodonta)" };
TAnimal** TLoxodonta::Born()
{
	TAnimal *Newobj = new TLoxodonta(Names4[rand() % 7]);
	std::cout << "New Animal Name is : " << Newobj->GetName();
	Newobj->SetAge(0);
	return &Newobj;

}
size_t TLoxodonta::GetKind()
{
	return Kind;
}
