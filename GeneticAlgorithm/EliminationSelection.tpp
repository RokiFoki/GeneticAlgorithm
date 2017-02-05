#ifndef ELIMINATIONSELECTION_TPP
#define ELIMINATIONSELECTION_TPP
#pragma once

#include "EliminationSelection.h"

template<typename T>
EliminationSelection<T>::EliminationSelection() { };

template<typename T>
EliminationSelection<T>::~EliminationSelection() { }

template<typename T>
std::vector<T*>* EliminationSelection<T>::selection(std::vector<T*> *population, std::vector<T*> *new_generation) {
	int generationSize = new_generation->size();
	int populationSize = population->size();

	for (int i = 0; i < generationSize; ++i) {
		if (populationSize - i - 1 < 0) break;

		my_delete(population->at(populationSize - i - 1));
		population->at(populationSize - i - 1) = new_generation->at(generationSize - i - 1);
	}

	return population;
}

#endif