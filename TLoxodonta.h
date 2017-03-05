#pragma once
#include "TProboscidea.h"
class TLoxodonta :
	public TProboscidea
{
	size_t DeathAge = 4;
	size_t ReprodAge = 2;
	size_t Kind = 3;
public:
	TLoxodonta(const std::string& name);
	void Live(float time);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	TLoxodonta();
	~TLoxodonta();
};
