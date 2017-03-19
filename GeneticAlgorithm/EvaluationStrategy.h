#ifndef EVALUATIONSTRATEGY_H
#define EVALUATIONSTRATEGY_H

#pragma once

#include <vector>

#include "util.h"
#include "Chromosom.h"

template<typename T, typename Sfinae = void> class EvaluationStrategy;

template <typename T>
class EvaluationStrategy<T, Extends<T, Chromosom>> {
public:
	EvaluationStrategy();
	virtual ~EvaluationStrategy();

	virtual double evaluate(T&, std::vector<T*>*) = 0;
	virtual double evaluatePopulation(std::vector<T*>*) = 0;
};

#include "EvaluationStrategy.tpp"

#endif
