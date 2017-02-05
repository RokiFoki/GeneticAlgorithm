#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#pragma once

#include <vector> 	

#include "util.h"
#include "Chromosom.h"
#include "EvaluationStrategy.h"
#include "CrossoverStrategy.h"
#include "MutateStrategy.h"
#include "SelectionStrategy.h"


template<typename T, int ParentsNumber, int ChildrenNumer, typename Sfinae = void> class GeneticAlgorithm;

template<typename T, int ParentsNumber, int ChildrenNumer>
class GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>> {
public:
	GeneticAlgorithm(std::vector<T*> *population, EvaluationStrategy<T>* es, 
		CrossoverStrategy<T, ParentsNumber, ChildrenNumer>* cs = nullptr, MutateStrategy<T>* ms = nullptr, 
		SelectionStrategy<T> *ss = nullptr);

	~GeneticAlgorithm();

	void run(int itertion_number, bool use_old_population = false);

private:
	void get_new_population();

protected:
	void virtual pre_run_method();
	void virtual post_run_method();

	std::vector<T*> *population;

	EvaluationStrategy<T> *evaluationStrategy;
	CrossoverStrategy<T, ParentsNumber, ChildrenNumer> *crossoverStrategy;
	MutateStrategy<T> *mutateStrategy;
	SelectionStrategy<T> *selectionStrategy;
};

#include "GeneticAlgorithm.tpp"

#endif