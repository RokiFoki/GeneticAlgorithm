#ifndef BINARYVECTOR_H
#define BINARYVECTOR_H

#include <vector>
#include "Chromosom.h"
#include "util.h"


class BinaryVector : public Chromosom {
public:
	BinaryVector(std::vector<bool> *source);

	~BinaryVector() {
		my_delete(source);
	}

	std::vector<bool> get_source() { return *source; }

	int size() { return this->_size; }

	void change_bit(int position) {
		this->source->at(position) = !this->source->at(position);
		this->set_evaluation_needed();
	}

private:
	std::vector<bool> *source;
	int _size;
};

#endif