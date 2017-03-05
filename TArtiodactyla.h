#pragma once
#include "TAnimal.h"
class TArtiodactyla :
	public TAnimal
{
public:
	TArtiodactyla();
	TArtiodactyla::TArtiodactyla(const std::string& name); 
	virtual~TArtiodactyla();
	virtual void Live(float Time);
};
