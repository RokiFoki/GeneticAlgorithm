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
#include "EliminationSelection.h"


#define POPULATION_SIZE 10
#define CHROMOSOME_SIZE 50000


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

	vector<BinaryVector*> *population = new vector<BinaryVector*>();
	for (int i = 0; i < POPULATION_SIZE; ++i) {
		vector<bool>* vec = new vector<bool>();
		for (int j = 0; j < CHROMOSOME_SIZE; ++j) vec->push_back(rand() % 2 == 0);

		BinaryVector *bv = new BinaryVector(vec);
		population->push_back(bv);
	}

	SumEvaluationStrategy *es = new SumEvaluationStrategy();
	BitMutation *ms = new BitMutation(10);

	ParentSelectionStrategy<BinaryVector> *rws = new RuletteWheelSelection<BinaryVector>(3);
	CrossoverStrategy<BinaryVector> *opc = new OnePointCrossover();
	CrossoverStrategy<BinaryVector, 2, 2> *cs = new SelectionCrossover<BinaryVector, 2, 2, 1>(rws, opc);
	SelectionStrategy<BinaryVector> *ss = new EliminationSelection<BinaryVector>();
	
	GeneticAlgorithm<BinaryVector, 2, 2> ga(population, es, cs, ms, ss);

	ga.run(1000000);
	
	return 0;
}