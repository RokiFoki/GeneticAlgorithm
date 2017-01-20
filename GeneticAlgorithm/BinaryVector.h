#ifndef BINARYVECTOR_H
#define BINARYVECTOR_H

#include <vector>
#include "Chromosom.h"
#include "util.h"


class BinaryVector : public Chromosom {
public:
	BinaryVector(std::vector<bool> *source);

	~BinaryVector();

	std::vector<bool> get_source() { return *source; }

	int size();

	void change_bit(int position);

private:
	std::vector<bool> *source;
	int _size;
};

#endif