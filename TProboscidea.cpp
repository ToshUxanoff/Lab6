#include "stdafx.h"
#include "TProboscidea.h"

TProboscidea::TProboscidea()
{
}
TProboscidea::TProboscidea(const std::string& name) : TAnimal(name)
{}

TProboscidea::~TProboscidea()
{
}
void TProboscidea::Live(float Time)
{
	if ((Time >= 0.f && Time <= 7.f) || (Time >= 22.f))
	{
		std::cout << GetName() << " is sleeping *zzzz*" << std::endl;
	}
}
