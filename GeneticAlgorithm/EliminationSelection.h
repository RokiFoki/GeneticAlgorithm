#ifndef ELIMINATIONSELECTION_H
#define ELIMINATIONSELECTION_H

#pragma once

#include "util.h"
#include "SelectionStrategy.h"
#include "Chromosom.h"

#include <vector>


template<typename T>
class EliminationSelection : public SelectionStrategy<T>
{
public:
	EliminationSelection();
	virtual ~EliminationSelection();

	virtual std::vector<T*> *selection(std::vector<T*> *population, std::vector<T*> *new_generation) override;
};

#include "EliminationSelection.tpp"

#endif

