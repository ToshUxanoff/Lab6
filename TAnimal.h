#pragma once
#include "string"

class TAnimal
{
	std::string Name;
	size_t Age;
	size_t ReprodAge;
public:
	TAnimal();
	TAnimal(const std::string & Name);
	virtual void Live(float Time) = 0;
	std::string GetName() const;
	size_t GetReprodAge() const;
	void SetReprodAge(size_t Age);
	virtual int Aging() = 0;
	virtual TAnimal** Born() = 0;
	virtual size_t GetKind() = 0;
	size_t GetAge() const;
	void SetAge(size_t age);
	virtual~TAnimal();
};
