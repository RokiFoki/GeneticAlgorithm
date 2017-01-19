#ifndef BINARYVECTOR_CPP
#define BINARYVECTOR_CPP
#pragma once


#include "BinaryVector.h"

BinaryVector::BinaryVector(std::vector<bool> *source) {
	this->source = source;
	this->_size = this->source->size();
}

#endif