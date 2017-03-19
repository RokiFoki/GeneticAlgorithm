#ifndef RULETTEWHEELSELECTION_H
#define RULETTEWHEELSELECTION_H

#pragma once

#include "BinaryVector.h"
#include "ParentSelectionStrategy.h"

template<typename T, int ParentNumber=2>
class RuletteWheelSelection : public ParentSelectionStrategy<T, ParentNumber> {
public:
	RuletteWheelSelection(int k);
	virtual ~RuletteWheelSelection();

	std::vector<BinaryVector*>* selection(std::vector<BinaryVector*> *population) override;

private:
	int k;
	std::vector<std::pair<double, int>> *percentages;

	void initialize(int populationSize);

};

#include "RuletteWheelSelection.tpp"

#endif