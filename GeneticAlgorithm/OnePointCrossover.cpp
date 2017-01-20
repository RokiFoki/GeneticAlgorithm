#ifndef ONEPOINTCROSSOVER_CPP
#define ONEPOINTCROSSOVER_CPP

#pragma once

#include "OnePointCrossover.h"
#include <cstdlib>
#include <ctime>


OnePointCrossover::OnePointCrossover() {
	srand((unsigned)time(0));
}

OnePointCrossover::~OnePointCrossover() { }

std::vector<BinaryVector*> OnePointCrossover::crossover(std::vector<BinaryVector*> parents) {
	auto genom1 = parents.at(0)->get_source();
	auto genom2 = parents.at(1)->get_source();

	int k = rand() % genom1.size();

	std::vector<bool> *first = new std::vector<bool>(genom1.begin(), genom1.begin() + k);
	first->insert(first->end(), genom2.begin() + k, genom2.end());

	std::vector<bool> *second = new std::vector<bool>(genom2.begin(), genom2.begin() + k);
	second->insert(second->end(), genom1.begin() + k, genom1.end());
	
	std::vector<BinaryVector*> children{ new BinaryVector(first), new BinaryVector(second) };

	return children;
}

#endif