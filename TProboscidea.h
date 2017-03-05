#pragma once
#include "TAnimal.h"
class TProboscidea :
	public TAnimal
{
public:
	TProboscidea();
	TProboscidea::TProboscidea(const std::string& name);
	virtual~TProboscidea();
	virtual void Live(float Time);
};
