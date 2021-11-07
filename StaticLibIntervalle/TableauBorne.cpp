#include "pch.h"
#include "TableauBorne.h"
#include <iostream>
#include <assert.h>
using namespace Math;
using namespace std;

TableauBorne::TableauBorne(int nbelm, float bI, float bS):Tableau(nbelm)
{
	if (bS < bI)
	{
		this->Binf = bS;
		this->Bsup = bI;
	}
	else {
		this->Binf = bI;
		this->Bsup = bS;
	}	
}

void TableauBorne::operator()(int indice, float newEm)
{
	assert((newEm >= this->Binf && newEm <= this->Bsup) && (indice >= 0 && indice < this->taille));
	this->tab[indice] = newEm;
}

void TableauBorne::afficher() const
{
	cout << "[ ";
	for (int k = 0; k < this->taille; k++)
		cout << this->tab[k] << ' ';
	cout << "] " <<endl;
}

