#pragma once
#include "TCarnivora.h"
class TTigris :
	public TCarnivora
{
	size_t DeathAge = 3;
	size_t ReprodAge = 2;
	size_t Kind = 4;
public:
	TTigris(const std::string& name);
	void Live(float time);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	TTigris();
	~TTigris();
};
