#include "stdafx.h"
#include "TGiraffa.h"
#include "TZoo.h"

TGiraffa::TGiraffa()
{
}
TGiraffa::TGiraffa(const std::string& name) : TArtiodactyla(name)
{
	TGiraffa::SetReprodAge(2);
}
TGiraffa::~TGiraffa()
{
}
 void TGiraffa::Live(float time)
{
	if ((time >= 9.f && time <= 15.f)||(time>17.f && time <20))
		std::cout << GetName() << " is moving" << std::endl;
	else if (time > 15.f && time <= 17.f)
	{
		std::cout << GetName() << " is eating *omnomnom*" << std::endl;
	}
	else
	{
		TArtiodactyla::Live(time);
	}
}
 int TGiraffa::Aging()
 {
	 int Age = TGiraffa::GetAge();
		 if (Age == DeathAge)
		 {
			 return -1;
		 }
		 else
		 {
			 Age++;
			 TGiraffa::SetAge(Age);
			 return 0;
		 }
	 
 }
 std::string Names1[] = { "Erik(Giraffe)", "Egor(Giraffe)", "Roman(Giraffe)", "Maria(Giraffe)", "Sam(Giraffe)", "Chloe(Giraffe)", "*MELMAN*(Giraffe)"};
 TAnimal** TGiraffa::Born()
 {
		 TAnimal *Newobj = new TGiraffa(Names1[rand() % 7]);
		 std::cout << "New Animal Name is : " << Newobj->GetName();
		 Newobj->SetAge(0);
		 return &Newobj;
	 
 }
 size_t TGiraffa::GetKind()
 {
	 return Kind;
 }
