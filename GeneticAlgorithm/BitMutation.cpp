#ifndef BITMUTATION_CPP
#define BITMUTATION_CPP

#pragma once

#include "BitMutation.h"
#include "BinaryVector.h"

BitMutation::BitMutation(int mutatePercentige, int bitEexpectationChange) {
	this->mutatePercentige = mutatePercentige;
	this->bitEexpectationChange = bitEexpectationChange;
}

void BitMutation::mutate(std::vector<BinaryVector*> *population) {
	for (BinaryVector* bv : *population) {
		if (rand() % 100 < mutatePercentige) {
			for (int i = 0; i < bv->size(); ++i) {
				if (rand() % 100 < bitEexpectationChange) {
					bv->change_bit(i);
				}
			}
		}
	}
};

#endif