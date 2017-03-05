#pragma once
#include "TProboscidea.h"
#include "iostream"
class TElephas :
	public TProboscidea
{
	size_t DeathAge = 4;
	size_t ReprodAge = 2;
	size_t Kind = 2;
public:
	TElephas(const std::string& name);
	void Live(float time);
	int Aging();
	TAnimal** Born();
	size_t GetKind();
	TElephas();
	~TElephas();
};
