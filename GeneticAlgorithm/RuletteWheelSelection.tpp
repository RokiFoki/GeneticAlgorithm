#ifndef RULETTEWHEELSELECTION_CPP
#define RULETTEWHEELSELECTION_CPP

#pragma once

#include "RuletteWheelSelection.h"
#include <algorithm>
#include <vector>



template<typename T, int ParentsNumber>
RuletteWheelSelection<T, ParentsNumber>::RuletteWheelSelection(int k) {
	this->percentages = nullptr;
	this->k = k;
};


template<typename T, int ParentsName>
RuletteWheelSelection<T, ParentsName>::~RuletteWheelSelection() { }


template<typename T, int ParentsNumber>
void RuletteWheelSelection<T, ParentsNumber>::initialize(int populationSize) {
	this->percentages = new std::vector<std::pair<double, int>>(populationSize);

	double last = 0;

	for (int i = 0; i < populationSize; ++i) {
		int left = populationSize - i;
		percentages->at(i) = std::make_pair((1 - last) * k / left + last, i);
		last = percentages->at(i).first;
	}
}


template<typename T, int ParentsNumber>
std::vector<BinaryVector*>* RuletteWheelSelection<T, ParentsNumber>::selection(std::vector<BinaryVector*> *population) {
	if (this->percentages == nullptr) this->initialize(population->size());

	std::vector<BinaryVector*>* parents = new std::vector<BinaryVector*>(ParentsNumber);

	auto cmp = [](double rnd, std::pair<double, int> const& value) { return value.first >= rnd; };

	for (int i = 0; i < ParentsNumber; ++i) {
		double r = 1.0 * rand() / RAND_MAX;

		auto index = std::upper_bound(this->percentages->begin(), this->percentages->end(), r, cmp)->second;
		parents->at(i) = population->at(index);
	}

	return parents;
}



#endif