#ifndef SELECTIONCROSSOVER_TPP
#define SELECTIONCROSSOVER_TPP

#pragma once

#include "SelectionCrossover.h"

template <typename T, int ParentsNumber, int ChildrenNumber, int Iterations>
SelectionCrossover<T, ParentsNumber, ChildrenNumber, Iterations>::SelectionCrossover(
		ParentSelectionStrategy<T, ParentsNumber>* selectionStrategy, 
		CrossoverStrategy<T, ParentsNumber, ChildrenNumber>* crossoverStrategy) {

	this->selectionStrategy = selectionStrategy;
	this->crossoverStrategy = crossoverStrategy;
}


template <typename T, int ParentsNumber, int ChildrenNumber, int Iterations>
SelectionCrossover<T, ParentsNumber, ChildrenNumber, Iterations>::~SelectionCrossover() {
	my_delete(this->selectionStrategy);
	my_delete(this->crossoverStrategy);
}


template <typename T, int ParentsNumber, int ChildrenNumber, int Iterations>
std::vector<T*>* SelectionCrossover<T, ParentsNumber, ChildrenNumber, Iterations>::crossover(std::vector<T*> *population) {
	auto new_population = new vector<T*>();

	auto cmp = [](T* f, T* s) { return f->get_fitness() > s->get_fitness(); };
	sort(population->begin(), population->end(), cmp);

	for(int i = 0; i < Iterations; ++i) {
		std::vector<T*> *parents  = selectionStrategy->selection(population);
		std::vector<T*> *children = crossoverStrategy->crossover(parents);

		for (int i = 0; i < ChildrenNumber; ++i) {
			new_population->push_back(children->at(i));
		}
	}
	
	return new_population;
}

#endif