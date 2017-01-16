#pragma once
#include <vector> 	
#include <type_traits>

#include "Chromosom.h"

template <typename Derived, typename Base>
using Extends = typename std::enable_if<std::is_base_of<Base, Derived>::value>::type;

template<typename T, typename Sfinae = void> class GeneticAlgorithm;

template<typename T>
class GeneticAlgorithm<T, Extends<T, Chromosom>> {
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	void run(int n, bool useOldPopulation = false);

private:
	void run_step();
	std::vector<T>* get_initial_population();
	void mutate();
	void crossover();

	std::vector<T> *population;
};

#include "GeneticAlgorithm.tpp"
