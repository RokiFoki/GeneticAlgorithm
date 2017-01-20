#ifndef RULETTEWHEELSELECTION_H
#define RULETTEWHEELSELECTION_H

#pragma once

#include "BinaryVector.h"
#include "SelectionStrategy.h"

class RuletteWheelSelection : public SelectionStrategy<BinaryVector, 2> {
public:
	RuletteWheelSelection(int populationSize, int k);
	~RuletteWheelSelection();

	std::vector<BinaryVector*> selection(std::vector<BinaryVector*> *population) override;

private:
	std::vector<std::pair<double, int>> percentages;
};

#endif