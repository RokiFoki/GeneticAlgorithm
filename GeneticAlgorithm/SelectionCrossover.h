#ifndef SELECTIONCROSSOVER_H
#define SELECTIONCROSSOVER_H

#pragma once

#include <vector>
#include "SelectionCrossoverStrategy.h"
#include "util.h"
#include "Chromosom.h"
#include "SelectionStrategy.h"
#include "CrossoverStrategy.h"

template <typename T, int ParentsNumber=2, int ChildrenNumber=2>
class SelectionCrossover : public SelectionCrossoverStrategy<T, Extends<T, Chromosom>>
{
public:
	SelectionCrossover(SelectionStrategy<T, ParentsNumber>*, CrossoverStrategy<T, ParentsNumber, ChildrenNumber>*);
	~SelectionCrossover();

	virtual void crossover(std::vector<T*> *population, int elitism=0) override;
private:
	SelectionStrategy<T, ParentsNumber> *selectionStrategy;
	CrossoverStrategy<T, ParentsNumber, ChildrenNumber> *crossoverStrategy;

};

#include "SelectionCrossover.tpp"

#endif