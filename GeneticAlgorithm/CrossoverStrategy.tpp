#ifndef CROSSOVERSTRATEGY_TPP
#define CROSSOVERSTRATEGY_TPP
#pragma once

#include "CrossoverStrategy.h"
#include "util.h"

template<typename T>
CrossoverStrategy<T, Extends<T, Chromosom>>::CrossoverStrategy() { }

template<typename T>
CrossoverStrategy<T, Extends<T, Chromosom>>::~CrossoverStrategy() { }

#endif