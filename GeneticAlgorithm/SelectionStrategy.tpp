#ifndef SELECTIONSTRATEGY_TPP
#define SELECTIONSTRATEGY_TPP
#pragma once

#include "SelectionStrategy.h"

template<typename T, int ParentsNumber>
SelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>>::SelectionStrategy() { }

template<typename T, int ParentsNumber>
SelectionStrategy<T, ParentsNumber, Extends<T, Chromosom>>::~SelectionStrategy() { }

#endif