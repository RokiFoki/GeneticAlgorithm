#ifndef SELECTIONSTRATEGY_H
#define SELECTIONSTRATEGY_H
#pragma once

#include <vector>
#include "util.h"
#include "Chromosom.h"

template<typename T, int ParentsNumber=2, typename Sfinae = void> class SelectionStrategy;

template<typename T, int ParentsNumber>
class SelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>> {
public:
	SelectionStrategy();
	~SelectionStrategy();

	// TODO maybe use template method pattern to make sure std::vector<T*>.size() == ParentsNumber (template parameter)
	virtual std::vector<T*> selection(std::vector<T*> *population) = 0; 
};

#include "SelectionStrategy.tpp"

#endif