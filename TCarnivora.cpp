#include "stdafx.h"
#include "TCarnivora.h"

TCarnivora::TCarnivora()
{
}
TCarnivora::TCarnivora(const std::string& name) : TAnimal(name)
{}

TCarnivora::~TCarnivora()
{
}
void TCarnivora::Live(float Time)
{
	if (Time >= 0.f && Time <= 9.f)
	{
		std::cout << GetName() << " is sleeping *zzzz*" << std::endl;
	}
}
