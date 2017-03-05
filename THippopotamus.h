#pragma once
#include "TArtiodactyla.h"
class THippopotamus :
	public TArtiodactyla
{
	size_t DeathAge = 2;
	size_t ReprodAge = 1;
	size_t Kind = 1;
public:
	void Live(float time);
	THippopotamus(const std::string& name);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	THippopotamus();
	~THippopotamus();
};
