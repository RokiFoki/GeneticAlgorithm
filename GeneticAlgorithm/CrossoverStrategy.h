#ifndef CROSSOVERSTRATEGY_H
#define CROSSOVERSTRATEGY_H

#pragma once

#include <vector>

#include "util.h"
#include "Chromosom.h"

template<typename T, typename Sfinae = void> class CrossoverStrategy;

template <typename T>
class CrossoverStrategy<T, Extends<T, Chromosom>> {
public:
	CrossoverStrategy();
	~CrossoverStrategy();

	virtual void crossover(std::vector<T*> *population) = 0;
};

#include "CrossoverStrategy.tpp"

#endif
