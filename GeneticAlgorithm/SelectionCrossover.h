#ifndef SELECTIONCROSSOVER_H
#define SELECTIONCROSSOVER_H

#pragma once

#include <vector>
#include "util.h"
#include "Chromosom.h"
#include "ParentSelectionStrategy.h"
#include "CrossoverStrategy.h"

template <typename T, int ParentsNumber=2, int ChildrenNumber=2, int Iterations=1>
class SelectionCrossover : public CrossoverStrategy<T, ParentsNumber, ChildrenNumber*Iterations>
{
public:
	SelectionCrossover(ParentSelectionStrategy<T, ParentsNumber>*, CrossoverStrategy<T, ParentsNumber, ChildrenNumber>*);
	~SelectionCrossover();

	virtual std::vector<T*>* crossover(std::vector<T*> *population) override; 
private:
	ParentSelectionStrategy<T, ParentsNumber> *selectionStrategy;
	CrossoverStrategy<T, ParentsNumber, ChildrenNumber> *crossoverStrategy;

};

#include "SelectionCrossover.tpp"

#endif