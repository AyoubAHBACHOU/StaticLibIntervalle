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

TableauBorne::TableauBorne(const TableauBorne& T) :Tableau( T)
{
	this->Binf = T.Binf;
	this->Bsup = T.Bsup;
}

TableauBorne& TableauBorne::operator=(const TableauBorne& T) 
{
	if (this != &T)
	{
		this->Tableau::operator=(T);
		this->Binf = T.Binf;
		this->Bsup = T.Bsup;
	}
	return *this;
}

const float& TableauBorne::operator[](int indice) const
{
	return this->Tableau::operator[](indice);
}

void TableauBorne::operator()(int indice, float newEm)
{
	assert(newEm >= this->Binf && newEm <= this->Bsup);
	this->Tableau::operator[](indice) = newEm;
}

void TableauBorne::afficher() const
{
	this->print();
	/*cout << "[ ";
	for (int k = 0; k < this->taille; k++)
		cout << this->tab[k] << ' ';
	cout << "] " <<endl;*/
}

