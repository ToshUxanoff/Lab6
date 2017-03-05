#pragma once
#include "TAnimal.h"
class TCarnivora :
	public TAnimal
{
public:
	TCarnivora();
	TCarnivora::TCarnivora(const std::string& name);
	~TCarnivora();
	virtual void Live(float Time);
};
