#ifndef BITMUTATION_H
#define BITMUTATION_H

#pragma once

#include <vector>
#include "MutateStrategy.h"
#include "BinaryVector.h"


class BitMutation : public MutateStrategy<BinaryVector> {

public:
	BitMutation(int mutatePercentige);

	void virtual mutate(std::vector<BinaryVector*> *population) override;
private:
	int mutatePercentige;

};

#endif