#ifndef SELECTIONCROSSOVERSTRATEGY_H
#define SELECTIONCROSSOVERSTRATEGY_H

#pragma once

#include <vector>

#include "util.h"
#include "Chromosom.h"

template<typename T, typename Sfinae = void> class SelectionCrossoverStrategy;

template <typename T>
class SelectionCrossoverStrategy<T, Extends<T, Chromosom>> {
public:
	SelectionCrossoverStrategy();
	~SelectionCrossoverStrategy();

	virtual void crossover(std::vector<T*> *population, int elitism=0) = 0;
};

#include "SelectionCrossoverStrategy.tpp"

#endif
