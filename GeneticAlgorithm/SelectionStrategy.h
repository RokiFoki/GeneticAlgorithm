#ifndef SELECTIONSTRATEGY_H
#define SELECTIONSTRATEGY_H
#pragma once

#include <vector>
#include "util.h"
#include "Chromosom.h"

template<typename T, typename Sfinae = void> class SelectionStrategy;

template<typename T>
class SelectionStrategy<T, Extends<T, Chromosom>> {
public:
	SelectionStrategy();
	~SelectionStrategy();

	virtual std::vector<T*>* selection(std::vector<T*> *population, std::vector<T*> *children) = 0;
};


#include "SelectionStrategy.tpp"

#endif