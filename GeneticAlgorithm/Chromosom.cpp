#ifndef CHROMOSOM_CPP
#define CHROMOSOM_CPP

#include "Chromosom.h"

Chromosom::Chromosom() {
	this->fitness_calculated = false;
}

Chromosom::~Chromosom() { }

bool Chromosom::evaluation_needed() {
	return !this->fitness_calculated;
}

void Chromosom::set_fintess(double fintess) {
	this->fitness_calculated = true;
	this->fintess = fintess;
}

double Chromosom::get_fitness() {
	return this->fintess;
}

void Chromosom::set_evaluation_needed() {
	this->fitness_calculated = false;
}

#endif