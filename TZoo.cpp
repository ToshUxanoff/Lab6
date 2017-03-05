#include "stdafx.h"
#include "TZoo.h"
#include "TAnimal.h"
#include "TGiraffa.h"
#include <ctime>

size_t dead = 0;
TZoo::TZoo(std::string Name, size_t capacity)
	: Capacity(capacity)
	, NumAnimals(0)
	, Time(0)
	, Name(Name)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}
std::string TZoo::GetZooName()
{
	return Name;
}
void TZoo::SetNumAnimals(int i)
{
	NumAnimals = i;
}
bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	if (newAnimal == nullptr)
	{
		return false;
	}
	if (NumAnimals == Capacity)
	{
		return false;
	}
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
}
TAnimal** Removal(TAnimal ** Animals, size_t NumAnimals)
{
	size_t a = 0;
	for (size_t i = 0; i < NumAnimals; i++)
	{
		size_t buf = i;
		size_t buf2 = i;
		a = i;
		if (Animals[i] == nullptr || Animals[i - 1] == nullptr)
		{
			while (Animals[buf2] == nullptr && buf2 < NumAnimals) //Находит не нуллптр элемент или прекращает перестановку если не найден
			{
				buf2++;
				a++;
			}
			if (buf2 == NumAnimals)
			{
				break;
			}
			while (Animals[buf - 1] == nullptr)
			{
				buf--;
			}
			if (Animals[buf - 1] != nullptr)
			{
				Animals[buf] = Animals[a];
				Animals[a] = nullptr;
			}
		}
		else
		{
			continue;
		}
	}
	return Animals;
}
TAnimal** Ageing(TAnimal** Animals, size_t NumAnimals, size_t &dead)
{
	int Aging = 0;
	for (size_t i = 0; i < NumAnimals; i++)
	{
		if (Animals[i] != nullptr)
		{
			Aging = Animals[i]->Aging();
			if (Aging == -1)
			{
				std::cout << "\t!!!Message///" << Animals[i]->GetName() << " has died of an old age. Sorrow!\n" << std::endl;
				Animals[i] = nullptr;
				dead++;
			}
		}
	}
	return Animals;
}
bool CanTheyBorn(TAnimal ** Animals, size_t NumAnimals, size_t i)
{
	
	if ((Animals[i] != nullptr) && (Animals[i]->GetAge() >= Animals[i]->GetReprodAge()))
	{
		int Kind = Animals[i]->GetKind();
		for (size_t j = i + 1; j < NumAnimals; j++)
		{
			int Kind2 = Animals[j]->GetKind();
			if (Kind == Kind2 && (rand() % 10 < 5))
			{
				return true;
			}
		}
	}
	return false;
}
 int TZoo::GetNumAnimals()
{
	return NumAnimals;
}
int TZoo::Work()
{
	srand(time(0));
	std::cout << "\t\t\tZoo:" << GetZooName() <<". Number of animals: "<< NumAnimals << std::endl;
	dead = 0;
	for (size_t i = 0; i < NumAnimals; i++)
	{ 
		if (Animals[i] != nullptr)
		{
			std::cout << Time << '-';
			Animals[i]->Live(Time);	
		}
	}
	if (NumAnimals == 0)
	{
		std::cout << "There is no animals left anymore..." << std::endl;
		return-1;
	}
	Time += STEP;
	if (Time > 24.f)
	{
		Time -= 24.f;
		Animals = Ageing(Animals, NumAnimals, dead); //старение животных. либо смерть
		Animals = Removal(Animals, NumAnimals); //смещение всего массива животных (позицию умерших занимают живые)
		NumAnimals -= dead;
		for (size_t i = 0; i < NumAnimals; i++)
		{
			if (CanTheyBorn(Animals, NumAnimals, i) == true && NumAnimals != Capacity) //проверка возможности рождение и само рождение.
			{
				std::cout << "\n ///New animal was born! ";
				TAnimal* newanimal = *Animals[i]->Born();
				AddNewAnimal(&newanimal);
			}
		}
	}
	return 0;
}
void TZoo::Transfer(TZoo& dest, int i)
{
	if (i > NumAnimals - 1)
	{
		std::cout << "Uncorrect number!";
		return;
	}
	else if (dest.GetNumAnimals() == 0 || this->GetNumAnimals() == 0)
	{
		std::cout << "there are no animals for transfer" << std::endl;
		return;
	}
	else if (Animals[i] != nullptr)
	{
		TAnimal* buf = nullptr;
		int number = 0;
		int itterations = 0;
		for (int j = 0; j < dest.NumAnimals; j++)
		{
			if (Animals[i]->GetKind() == dest.Animals[j]->GetKind())
			{
				number = j;
				break;
			}
			else
			{
				itterations++;
			}
		}
		if (itterations != dest.NumAnimals)
		{
			buf = Animals[i];
			Animals[i] = dest.Animals[number];
			dest.Animals[number] = buf;
		}
		else
		{
			std::cout << "Exchange cannot be realized!" << std::endl;
		}
		buf = nullptr;
	}
}

TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}
