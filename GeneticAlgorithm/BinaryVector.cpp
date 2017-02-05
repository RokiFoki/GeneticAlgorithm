#ifndef BINARYVECTOR_CPP
#define BINARYVECTOR_CPP
#pragma once

#include <vector>
#include "BinaryVector.h"

BinaryVector::BinaryVector(std::vector<bool> *source) {
	this->source = source;
	this->_size = this->source->size();
}

BinaryVector::~BinaryVector() {
	my_delete(source);
}

int BinaryVector::size() { 
	return this->_size; 
}

void BinaryVector::change_bit(int position){
	this->source->at(position) = !this->source->at(position);
	this->set_evaluation_needed();
}

std::vector<bool> BinaryVector::get_source() { 
	return *source; 
}

#endif