#ifndef SELECTIONCROSSOVERSTRATEGY_TPP
#define SELECTIONCROSSOVERSTRATEGY_TPP
#pragma once

#include "SelectionCrossoverStrategy.h"
#include "util.h"

template<typename T>
SelectionCrossoverStrategy<T, Extends<T, Chromosom>>::SelectionCrossoverStrategy() { }

template<typename T>
SelectionCrossoverStrategy<T, Extends<T, Chromosom>>::~SelectionCrossoverStrategy() { }

#endif