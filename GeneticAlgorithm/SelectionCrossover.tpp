#ifndef SELECTIONCROSSOVER_TPP
#define SELECTIONCROSSOVER_TPP

#pragma once

#include "SelectionCrossover.h"

template <typename T, int ParentsNumber, int ChildrenNumber>
SelectionCrossover<T, ParentsNumber, ChildrenNumber>::SelectionCrossover(
	SelectionStrategy<T, ParentsNumber>* selectionStrategy, 
	CrossoverStrategy<T, ParentsNumber, ChildrenNumber>* crossoverStrategy) {
	this->selectionStrategy = selectionStrategy;
	this->crossoverStrategy = crossoverStrategy;
}

template <typename T, int ParentsNumber, int ChildrenNumber>
SelectionCrossover<T, ParentsNumber, ChildrenNumber>::~SelectionCrossover() { 
	my_delete(this->selectionStrategy);
	my_delete(this->crossoverStrategy);
}

template <typename T, int ParentsNumber, int ChildrenNumber>
void SelectionCrossover<T, ParentsNumber, ChildrenNumber>::crossover(std::vector<T*> *population, int elitism=0) {
	auto new_population = new vector<T*>();

	auto cmp = [](T* f, T* s) { return f->get_fitness() > s->get_fitness(); };
	sort(population->begin(), population->end(), cmp);

	for (int i = 0; i < elitism; ++i) new_population->push_back(population->at(i));

	while (new_population->size() < population->size()) {
		std::vector<T*> parents  = selectionStrategy->selection(population);
		std::vector<T*> children = crossoverStrategy->crossover(parents);

		for (int i = 0; i < ChildrenNumber; ++i) {
			new_population->push_back(children[i]);
		}
	}

	for (int i = elitism; i < population->size(); ++i) {
		my_delete(population->at(i));

		population->at(i) = new_population->at(i);
	}
}

#endif