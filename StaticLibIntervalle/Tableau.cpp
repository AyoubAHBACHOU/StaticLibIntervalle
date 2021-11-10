#include "pch.h"
#include "Tableau.h"
#include <iostream>
#include <assert.h>
using namespace Math;
using namespace std;

Math::Tableau::Tableau(unsigned int i)
{
	if(i>0)
		this->taille = i;
	else {
		this->taille = 1;
	}
	this->tab = new float[i]();
	//pour test
	/*if (this->tab) {
		for (int k = 0; k < this->taille; k++)
		{
			this->tab[k] = 0.0;
		}
	}*/
	
}

Math::Tableau::Tableau(const Tableau& t)
{
	this->taille = t.taille;
	this->tab = new float[t.taille];
	for (int i = 0; i < this->taille; i++)
	{
		this->tab[i] = t.tab[i];
	}
}

Tableau& Math::Tableau::operator=(const Tableau& T)
{
	if (this != &T)
	{
		this->taille = T.taille;
		if (this->tab) {
			delete[] this->tab;
			this->tab = 0;
		}
		this->tab = new float[T.taille];
		for (int i = 0; i < T.taille; i++)
		{
			this->tab[i] = T.tab[i];
		}
	}
	return *this;
}

float& Math::Tableau::operator[](int indice) const
{
	assert(indice >= 0 && indice < this->taille);
	try {
		if (indice < 0 || indice >= this->taille)
			throw "indice invalide";
		return this->tab[indice];
	}
	catch (char* e) {
		cout << e << endl;
	}
}

void Math::Tableau::print() const
{
	for (int i = 0; i < this->taille; i++)
	{
		cout << this->tab[i] << '\t';
	}
	cout << endl;
		
}

Math::Tableau::~Tableau()
{
	if (this->tab)
	{
		delete[] this->tab;
		this->tab = 0;
	}
}





