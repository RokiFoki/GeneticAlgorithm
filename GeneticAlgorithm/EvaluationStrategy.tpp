#ifndef EVALUATIONSTRATEGY_TPP
#define EVALUATIONSTRATEGY_TPP
#pragma once

#include "EvaluationStrategy.h"
#include "util.h"

template<typename T>
EvaluationStrategy<T, Extends<T, Chromosom>>::EvaluationStrategy() { }

template<typename T>
EvaluationStrategy<T, Extends<T, Chromosom>>::~EvaluationStrategy() { }

#endif