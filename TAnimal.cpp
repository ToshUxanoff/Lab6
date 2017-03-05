#include"stdafx.h"
#include "TAnimal.h"


TAnimal::TAnimal()
	: Name()
	, Age(0)
{ }

TAnimal::TAnimal(const std::string & name)
	: Name(name)
	, Age(0)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}
size_t TAnimal::GetReprodAge() const
{
	return ReprodAge;
}
void TAnimal::SetReprodAge(size_t Age)
{
	ReprodAge = Age;
}
TAnimal::~TAnimal()
{

}
void TAnimal::SetAge(size_t age)
{
	Age = age;
}
