#include "stdafx.h"
#include "TArtiodactyla.h"

TArtiodactyla::TArtiodactyla()
{
}
TArtiodactyla::TArtiodactyla(const std::string& name) : TAnimal(name)
{}

TArtiodactyla::~TArtiodactyla()
{
}
void TArtiodactyla::Live(float Time)
{
	if ((Time >= 0.f && Time <= 10.f)||(Time >= 20.f))
	{
		std::cout << GetName() << " is sleeping *zzzz*" << std::endl;
	}
}
