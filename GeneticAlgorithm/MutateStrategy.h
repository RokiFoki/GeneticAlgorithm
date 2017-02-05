#ifndef MUTATESTRATEGY_H
#define MUTATESTRATEGY_H

#pragma once

#include <vector>

#include "util.h"
#include "Chromosom.h"

template<typename T, typename Sfinae = void> class MutateStrategy;

template <typename T>
class MutateStrategy<T, Extends<T, Chromosom>> {
public:
	MutateStrategy();
	~MutateStrategy();

	virtual std::vector<T*>* mutate(std::vector<T*> *population) = 0;
};

#include "MutateStrategy.tpp"

#endif
