#ifndef PARENTSELECTIONSTRATEGY_H
#define PARENTSELECTIONSTRATEGY_H
#pragma once

#include <vector>
#include "util.h"
#include "Chromosom.h"

template<typename T, int ParentsNumber=2, typename Sfinae = void> class ParentSelectionStrategy;

template<typename T, int ParentsNumber>
class ParentSelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>> {
public:
	ParentSelectionStrategy();
	~ParentSelectionStrategy();

	// TODO maybe use template method pattern to make sure std::vector<T*>.size() == ParentsNumber (template parameter)
	virtual std::vector<T*>* selection(std::vector<T*> *population) = 0; 
};

#include "ParentSelectionStrategy.tpp"

#endif