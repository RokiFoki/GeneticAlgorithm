#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "GeneticAlgorithm.h"
#include "Chromosom.h"
#include "EvaluationStrategy.h"
#include "BinaryVector.h"
#include "BitMutation.h"

using namespace std;


class SumEvolutionStrategy : public EvaluationStrategy<BinaryVector> {

	virtual double evaluate(BinaryVector& bv, std::vector<BinaryVector*> *population) {
		if (!bv.evaluation_needed()) return bv.get_fitness();

		double res = 0;
		for (auto item : bv.get_source()) res += item;
		
		bv.set_fintess(res);
		return res;
	}

	virtual double evaluatePopulation(std::vector<BinaryVector*>* population) {
		double max_ = -100000;
		for (BinaryVector* chromosom : *population) {
			max_ = max(max_, evaluate(*chromosom, population));
		}

		return max_;
	}
};

class OnePointRuletteWheelStrategy : public CrossoverStrategy<BinaryVector> {
private:
	double *percentages;

public:
	OnePointRuletteWheelStrategy(int k, int populationSize) {
		this->percentages = new double[populationSize]; // population_size can be aded later
		// add binary search

		double last = 0;

		for (int i = 0; i < populationSize; ++i) {
			int left = populationSize - i;
			percentages[i] = (100-last) * k / left + last;
			last = percentages[i];
		}
	}
	~OnePointRuletteWheelStrategy() {
		delete[] this->percentages;
	}

	pair<BinaryVector*, BinaryVector*> find_two(std::vector<BinaryVector*> *population) {
		pair<BinaryVector*, BinaryVector*> pair;

		int r = rand() % 100;
		int i;
		for (i = 0; i < population->size() - 1; ++i) if (this->percentages[i] > r) break;
		pair.first = population->at(i);

		r = rand() % 100;
		for (i = 0; i < population->size() - 1; ++i) if (this->percentages[i] > r) break;
		pair.second = population->at(i);

		return pair;
	}

	pair<BinaryVector*, BinaryVector*> mutate(pair<BinaryVector*, BinaryVector*> parents) {
		int k = 250;
		auto genom1 = parents.first->get_source();
		auto genom2 = parents.second->get_source();

		vector<bool> *first = new vector<bool>(genom1.begin(), genom1.begin() + k);
		first->insert(first->end(), genom2.begin() + k, genom2.end());

		vector<bool> *second = new vector<bool>(genom2.begin(), genom2.begin() + k);
		second->insert(second->end(), genom1.begin() + k, genom1.end());

		pair<BinaryVector*, BinaryVector*> childrend = make_pair(new BinaryVector(first), new BinaryVector(second));
		return childrend;
	}

	virtual void crossover(std::vector<BinaryVector*> *population) override {
		int elithism = 3;
		auto new_population = new vector<BinaryVector*>();
		
		auto cmp = [](BinaryVector* f, BinaryVector* s) {return f->get_fitness() > s->get_fitness();  };
		sort(population->begin(), population->end(), cmp);

		for (int i = 0; i < elithism; ++i) new_population->push_back(population->at(i));

		while (new_population->size() < population->size()) {
			pair<BinaryVector*, BinaryVector*> mate_pair = this->find_two(population); 
			pair<BinaryVector*, BinaryVector*> children_pair = this->mutate(mate_pair);

			new_population->push_back(children_pair.first);
			new_population->push_back(children_pair.second);
		}

		for (int i = elithism; i < population->size(); ++i) {
			delete population->at(i);
			population->at(i) = nullptr;

			population->at(i) = new_population->at(i);
		}
	}
};


int main() {
	srand(time(0));

	int population_size = 10;
	vector<BinaryVector*> *population = new vector<BinaryVector*>();
	for (int i = 0; i < population_size; ++i) {
		vector<bool>* vec = new vector<bool>();
		for (int j = 0; j < 500; ++j) vec->push_back(rand() % 2 == 0);

		BinaryVector *bv = new BinaryVector(vec);
		population->push_back(bv);
	}

	SumEvolutionStrategy *es = new SumEvolutionStrategy();
	BitMutation *ms = new BitMutation(10, 2);
	OnePointRuletteWheelStrategy *cs = new OnePointRuletteWheelStrategy(3, population_size);
	GeneticAlgorithm<BinaryVector> ga(population, es, cs, ms);

	ga.run(1000000);

	return 0;
}