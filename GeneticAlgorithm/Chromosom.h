#ifndef CHROMOSOM_H
#define CHROMOSOM_H
#pragma once

class Chromosom
{
public:
	Chromosom();
	~Chromosom();

	bool evaluation_needed();
	void set_evaluation_needed();
	void set_fintess(double fintess);
	double get_fitness();

private:
	bool fitness_calculated;
	double fintess;
};

#endif

