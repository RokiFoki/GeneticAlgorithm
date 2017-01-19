#ifndef GENETICALGORITHM_TPP
#define GENETICALGORITHM_TPP
#pragma once

template<typename T>
GeneticAlgorithm<T, Extends<T, Chromosom>>::GeneticAlgorithm(std::vector<T*> *population, EvaluationStrategy<T>* es, 
															 CrossoverStrategy<T>* cs = nullptr, MutateStrategy<T>*ms = nullptr) {
	this->evaluationStrategy = es;
	this->crossoverStrategy = cs;
	this->mutateStrategy = ms;

	this->population = population;
}

template<typename T>
GeneticAlgorithm<T, Extends<T, Chromosom>>::~GeneticAlgorithm() {
	for (T* p : *population) my_delete(p);
	my_delete(this->population);
	my_delete(this->evaluationStrategy);
	my_delete(this->mutateStrategy);
	my_delete(this->crossoverStrategy);
}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::run_step() {
	if(this->crossoverStrategy != nullptr) this->crossoverStrategy->crossover(population);
	if(this->mutateStrategy != nullptr) this->mutateStrategy->mutate(population);
}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::run(int n, bool useOldPopulation = false) {
	
	this->evaluationStrategy->evaluatePopulation(population);

	double global_max = -1, current_best;

	for (int i = 0; i < n; ++i) {
		this->pre_run_method();
		this->run_step();
		current_best = this->evaluationStrategy->evaluatePopulation(population);
		global_max = max(global_max, current_best);
		this->post_run_method();
		if(i%1000 == 0) cout << "i " << i << " current_best: " << current_best << " global_max: " << global_max << endl;
	}
}

template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::pre_run_method() {}
template<typename T>
void GeneticAlgorithm<T, Extends<T, Chromosom>>::post_run_method() {}


#endif