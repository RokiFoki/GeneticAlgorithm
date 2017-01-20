#ifndef RULETTEWHEELSELECTION_CPP
#define RULETTEWHEELSELECTION_CPP

#pragma once

#include "RuletteWheelSelection.h"
#include <algorithm>
#include <vector>



RuletteWheelSelection::RuletteWheelSelection(int populationSize, int k) {
	this->percentages = std::vector<std::pair<double, int>>(populationSize); // population_size can be aded later

	double last = 0;

	for (int i = 0; i < populationSize; ++i) {
		int left = populationSize - i;
		percentages[i] = std::make_pair((1 - last) * k / left + last, i);
		last = percentages[i].first;
	}
}


RuletteWheelSelection::~RuletteWheelSelection() { }


//bool cmp(int const& rnd, std::pair<double, int> const& value) {
//	return value.first <= rnd;
//}

std::vector<BinaryVector*> RuletteWheelSelection::selection(std::vector<BinaryVector*> *population) {
	std::vector<BinaryVector*> parents(2);

	auto cmp = [](double rnd, std::pair<double, int> const& value) { return value.first >= rnd; };

	double r = 1.0 * rand() / RAND_MAX;
	
	auto index = std::upper_bound(this->percentages.begin(), this->percentages.end(), r, cmp)->second;
	parents[0] = population->at(index);

	r = 1.0 * rand() / RAND_MAX;

	index = std::upper_bound(this->percentages.begin(), this->percentages.end(), r, cmp)->second;
	parents[1] = population->at(index);

	return parents;
}

#endif