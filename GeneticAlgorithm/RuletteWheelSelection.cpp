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
		percentages[i] = std::make_pair((100. - last) * k / left + last, i);
		last = percentages[i].first;
	}
}


RuletteWheelSelection::~RuletteWheelSelection() { }


//bool cmp(int const& rnd, std::pair<double, int> const& value) {
//	return value.first <= rnd;
//}

std::vector<BinaryVector*> RuletteWheelSelection::selection(std::vector<BinaryVector*> *population) {
	std::vector<BinaryVector*> parents(2);

	auto cmp = [](int rnd, std::pair<double, int> const& value) { return value.first > rnd; };

	int r = rand() % 100;
	
	auto index = std::upper_bound(this->percentages.begin(), this->percentages.end(), r, cmp)->second;
	parents[0] = population->at(index);


	r = rand() % 100;
	index = std::upper_bound(this->percentages.begin(), this->percentages.end(), r, cmp)->second;
	parents[1] = population->at(index);

	return parents;
}

#endif