#pragma once
#include <iostream>
namespace Math {
	class Tableau
	{
	protected:
		unsigned int taille;
		float* tab;
	public:
		Tableau(unsigned int i);
		Tableau (const Tableau& t);
		Tableau& operator=(const Tableau& T);
		float& operator[](int indice) const;
		void print();
		~Tableau();

	};
}


