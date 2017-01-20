#ifndef BITMUTATION_CPP
#define BITMUTATION_CPP

#pragma once

#include "BitMutation.h"
#include "BinaryVector.h"

BitMutation::BitMutation(int mutatePercentige) {
	this->mutatePercentige = mutatePercentige;
}

void BitMutation::mutate(std::vector<BinaryVector*> *population) {
	for (BinaryVector* bv : *population) {
		if (rand() % 100 < mutatePercentige) {
			bv->change_bit(rand() % bv->size());
		}
	}
};

#endif