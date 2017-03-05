#pragma once
#include "TArtiodactyla.h"
#include "iostream"
class TGiraffa :
	public TArtiodactyla
{
	size_t DeathAge = 3;
	size_t ReprodAge = 1;
	size_t Kind = 0;
public:
	TGiraffa(const std::string& name);
	void Live(float time);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	TGiraffa();
	~TGiraffa();
};
