#ifndef PARENTSELECTIONSTRATEGY_TPP
#define PARENTSELECTIONSTRATEGY_TPP
#pragma once

#include "ParentSelectionStrategy.h"

template<typename T, int ParentsNumber>
ParentSelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>>::ParentSelectionStrategy() { }

template<typename T, int ParentsNumber>
ParentSelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>>::~ParentSelectionStrategy() { }

#endif