#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#pragma once

#include <vector> 	

#include "util.h"
#include "Chromosom.h"
#include "EvaluationStrategy.h"
#include "CrossoverStrategy.h"
#include "MutateStrategy.h"


template<typename T, typename Sfinae = void> class GeneticAlgorithm;

template<typename T>
class GeneticAlgorithm<T, Extends<T, Chromosom>> {
public:
	GeneticAlgorithm(std::vector<T*> *population, EvaluationStrategy<T>* es, 
					 CrossoverStrategy<T>* cs = nullptr, MutateStrategy<T>* ms = nullptr);

	~GeneticAlgorithm();

	void run(int n, bool useOldPopulation = false);

private:
	void run_step();
	void virtual pre_run_method();
	void virtual post_run_method();

protected:
	std::vector<T*> *population;
	EvaluationStrategy<T> *evaluationStrategy;
	CrossoverStrategy<T> *crossoverStrategy;
	MutateStrategy<T> *mutateStrategy;
};

#include "GeneticAlgorithm.tpp"

#endif