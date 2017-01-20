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
#include "SelectionCrossover.h"
#include "RuletteWheelSelection.h"
#include "OnePointCrossover.h"

using namespace std;


class SumEvaluationStrategy : public EvaluationStrategy<BinaryVector> {

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

int main() {

	srand((unsigned)time(0));

	int population_size = 1000;
	vector<BinaryVector*> *population = new vector<BinaryVector*>();
	for (int i = 0; i < population_size; ++i) {
		vector<bool>* vec = new vector<bool>();
		for (int j = 0; j < 200; ++j) vec->push_back(rand() % 2 == 0);

		BinaryVector *bv = new BinaryVector(vec);
		population->push_back(bv);
		cout << i << endl;
	}

	SumEvaluationStrategy *es = new SumEvaluationStrategy();
	BitMutation *ms = new BitMutation(10, 2);

	SelectionStrategy<BinaryVector> *rws = new RuletteWheelSelection(population_size, 3);
	CrossoverStrategy<BinaryVector> *opc = new OnePointCrossover();
	SelectionCrossover<BinaryVector> *sc = new SelectionCrossover<BinaryVector>(rws, opc);
	GeneticAlgorithm<BinaryVector> ga(population, es, sc, ms);

	ga.run(1000000);

	return 0;
}