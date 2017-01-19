#ifndef MUTATESTRATEGY_TPP
#define MUTATESTRATEGY_TPP
#pragma once

#include "MutateStrategy.h"
#include "util.h"

template<typename T>
MutateStrategy<T, Extends<T, Chromosom>>::MutateStrategy() { }

template<typename T>
MutateStrategy<T, Extends<T, Chromosom>>::~MutateStrategy() { }

#endif