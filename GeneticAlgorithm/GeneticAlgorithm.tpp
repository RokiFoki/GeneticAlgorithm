#pragma once
#include "GeneticAlgorithm.h"
#include "Chromosom.h"
#include <vector>

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::mutate() {

}

template<typename T>
std::vector<T>* GeneticAlgorithm<T, Extends<T, Chromosom>>::get_initial_population() {
	return std::vector<T>();  
}


template<typename T>
GeneticAlgorithm<T, Extends<T, Chromosom>>::~GeneticAlgorithm()
{
}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::crossover() {

}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::run(int n, bool useOldPopulation = false) {
	if (!useOldPopulation || this->population == nullptr) {
		std::vector<Chromosom> *population = get_initial_population();
	}

	for (int i = 0; i < n; ++i) {
		// method before
		this->run_step();
		// method afrer
	}
}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::run_step() {}

template<typename T>
GeneticAlgorithm<T, Extends<T, Chromosom>>::GeneticAlgorithm()
{
	this->population = nullptr;
};


