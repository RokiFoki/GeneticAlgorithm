#ifndef CROSSOVERSTRATEGY_H
#define CROSSOVERSTRATEGY_H
#pragma once

#include <vector>
#include "util.h"
#include "Chromosom.h"

template<typename T, int ParentsNumber=2, int ChildrenNumber=2, typename Sfinae = void> class CrossoverStrategy;

template<typename T, int ParentsNumber, int ChildrenNumber>
class CrossoverStrategy<T, ParentsNumber, ChildrenNumber, Extends<T, Chromosom>> {
public:
	CrossoverStrategy();
	~CrossoverStrategy();

	// TODO maybe use template method pattern to make sure population.size() == ChildrenNumber (template parameter) && ParentsNumber as return
	virtual std::vector<T*>* crossover(std::vector<T*> *population) = 0;
};


#include "CrossoverStrategy.tpp"

#endif
