#pragma once
#include "TCarnivora.h"
class TLeo :
	public TCarnivora
{
	size_t DeathAge = 3;
	size_t ReprodAge = 2;
	size_t Kind = 5;
public:
	TLeo(const std::string& name);
	void Live(float time);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	TLeo();
	~TLeo();
};
