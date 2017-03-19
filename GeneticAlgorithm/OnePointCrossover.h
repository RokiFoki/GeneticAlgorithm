#ifndef ONEPOINTCROSSOVER_H
#define ONEPOINTCROSSOVER_H

#pragma once

#include <vector>
#include "CrossoverStrategy.h"
#include "BinaryVector.h"


class OnePointCrossover : public CrossoverStrategy<BinaryVector, 2, 2> {
public:
	OnePointCrossover();
	virtual ~OnePointCrossover();
	
	virtual std::vector<BinaryVector*> *crossover(std::vector<BinaryVector*> *parents) override;
};

#endif
