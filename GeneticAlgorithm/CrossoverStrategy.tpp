#ifndef CROSSOVERSTRATEGY_TPP
#define CROSSOVERSTRATEGY_TPP
#pragma once

#include "util.h"
#include "CrossoverStrategy.h"
#include "Chromosom.h"

template<typename T, int ParentsNumber, int ChildrenNumber>
CrossoverStrategy<T, ParentsNumber, ChildrenNumber, Extends<T, Chromosom>>::CrossoverStrategy() { }


template<typename T, int ParentsNumber, int ChildrenNumber>
CrossoverStrategy<T, ParentsNumber, ChildrenNumber, Extends<T, Chromosom>>::~CrossoverStrategy() { }

#endif