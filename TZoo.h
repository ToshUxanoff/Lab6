#pragma once
#include "TAnimal.h"
const float STEP = 1;

class TZoo
{
	typedef TAnimal * TPtrAnimal;
	TPtrAnimal * Animals;
	size_t Capacity;
	size_t NumAnimals;
	std::string Name;
	float Time;
public:
	void Transfer(TZoo& destination, int position_for_transfer);
	int GetNumAnimals();
	void SetNumAnimals(int i);
	TZoo(std::string Name,size_t capacity);
	std::string GetZooName();
	bool AddNewAnimal(TAnimal ** newAnimal);
	int Work();
	~TZoo();
};
