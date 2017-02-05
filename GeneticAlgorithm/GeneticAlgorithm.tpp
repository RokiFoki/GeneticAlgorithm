#ifndef GENETICALGORITHM_TPP
#define GENETICALGORITHM_TPP
#pragma once

template<typename T, int ParentsNumber, int ChildrenNumer>
GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::GeneticAlgorithm(std::vector<T*> *population, 
	EvaluationStrategy<T>* es, CrossoverStrategy<T, ParentsNumber, ChildrenNumer>* cs = nullptr, 
	MutateStrategy<T>* ms = nullptr, SelectionStrategy<T> *ss = nullptr) {

	this->crossoverStrategy = cs;
	this->evaluationStrategy = es;
	this->mutateStrategy = ms;
	this->selectionStrategy = ss,

	this->population = population;
}

template<typename T, int ParentsNumber, int ChildrenNumer>
GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::~GeneticAlgorithm() {
	for (T* p : *population) my_delete(p);
	my_delete(this->population);
	my_delete(this->evaluationStrategy);
	my_delete(this->mutateStrategy);
	my_delete(this->crossoverStrategy);
	my_delete(this->selectionStrategy);
}

template<typename T, int ParentsNumber, int ChildrenNumer>
void GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::get_new_population() {
	auto new_population = this->population;

	if (this->crossoverStrategy != nullptr) new_population = this->crossoverStrategy->crossover(new_population);
	if (this->mutateStrategy != nullptr) new_population = this->mutateStrategy->mutate(new_population);
	if (this->selectionStrategy != nullptr) {
		auto cmp = [](T* f, T* s) { return f->get_fitness() > s->get_fitness(); };
		sort(new_population->begin(), new_population->end(), cmp);

		new_population = this->selectionStrategy->selection(population, new_population);
	}

	if (new_population != this->population) for (T* p : *population) my_delete(p);
	this->population = new_population;
}

template<typename T, int ParentsNumber, int ChildrenNumer>
void GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::run(int n, bool useOldPopulation = false) {

	this->evaluationStrategy->evaluatePopulation(population);

	double global_max = -1, current_best;

	for (int i = 0; i < n; ++i) {
		this->pre_run_method();
		this->get_new_population();
		current_best = this->evaluationStrategy->evaluatePopulation(population);
		global_max = max(global_max, current_best);
		this->post_run_method();
		if (i % 1000 == 0) cout << "i " << i << " current_best: " << current_best << " global_max: " << global_max << endl;
	}
}

template<typename T, int ParentsNumber, int ChildrenNumer>
void GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::pre_run_method() {}
template<typename T, int ParentsNumber, int ChildrenNumer>
void GeneticAlgorithm<T, ParentsNumber, ChildrenNumer, Extends<T, Chromosom>>::post_run_method() {}


#endif