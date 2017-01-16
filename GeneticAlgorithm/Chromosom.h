#pragma once
class Chromosom
{
public:
	Chromosom();
	~Chromosom();

	void virtual mutate() = 0;
	void virtual mate(Chromosom&) = 0;
};

